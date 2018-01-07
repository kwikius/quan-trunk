#ifndef QUAN_TWO_D_CUBIC_SPLINE_HPP_INCLUDED
#define QUAN_TWO_D_CUBIC_SPLINE_HPP_INCLUDED

#include <cassert>
#include <vector>
#include <quan/two_d/out/vect.hpp>

/*
 Copyright (c) 2017 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./

  converted to C++ from 
  https://github.com/clolsonus/madesigner/madesigner/madlib/spline.py
#
# originally from  a Perl module by
#
# John A.R. Williams <J.A.R.Williams@aston.ac.uk>
#
# PYTHON PORT (combines spline and derivative perl modules into a single 
# spline python module)
#
# Curtis L. Olson <curtolson ata flightgear dota org >
#
*/

namespace quan { namespace two_d{ namespace detail{ 

   // input is a list of 2d coordinates
   // preconditons
   // points.length() points must be greater than 1
   // x values of adjacent points must be separate to avoid divsion by zero
   // xvalues should be incremental
   // output is a list of derivatives
   template <typename PointType>
   std::vector<decltype(typename PointType::value_type{} / typename PointType::value_type{1} )>
   inline derivative1 ( std::vector <PointType> const & points)
   {
      std::size_t const n = points.size()-1;
      assert(n > 0);

      typedef decltype(typename PointType::value_type{} /typename PointType::value_type{1} ) result_value_type;
      std::vector<result_value_type> out;
      out.resize(n+1,result_value_type{});
      auto constexpr zero = typename PointType::value_type{0};

      auto const divisor0 = (points[1].x - points[0].x);
      assert( divisor0 != zero);
      out[0] = (points[1].y - points[0].y) / divisor0;

      for ( uint32_t i = 1; i < n; ++i){
         auto const divisor = (points[i+1].x - points[i-1].x);
         assert( divisor != zero);
         out[i] = (points[i+1].y - points[i-1].y) / divisor;
      }

      auto const divisorN = points[n].x - points[n-1].x;
      assert( divisorN != zero);
      out[n] = (points[n].y - points[n-1].y) / divisorN ; 

      return out;
   }

   // input is a list of 2d coordinates
   // preconditons
   // points.length() points must be greater than 1
   // x values of adjacent points must be separate to avoid divsion by zero
   // xvalues should be incremental
   // output is a list of derivatives
   template <typename PointType>
   std::vector<decltype(typename PointType::value_type{} / typename PointType::value_type{1} )> 
   inline derivative2( std::vector<PointType> const & points)
   {
      auto const n = points.size()-1;

      assert( n > 0);

      typedef typename PointType::value_type value_type;
      typedef decltype(value_type{} / value_type{1} ) res_value_type;
      std::vector<res_value_type> y2;
      std::vector<res_value_type> u;

      y2.resize(n+1);
      u.resize(n+1);
      y2[0] = res_value_type{0};
      y2[n] = res_value_type{0};
      u[0] = res_value_type{0};
      for ( auto i = 1U; i < n; ++i){
         value_type const dvsor1 = (points[i+1].x-points[i-1].x);
         assert (dvsor1 != value_type{0.0});
         value_type const dvsor2 = (points[i].x-points[i-1].x);
         assert (dvsor2 != value_type{0.0});
         res_value_type const sig = dvsor2/dvsor1;
         res_value_type const p = sig * y2[i-1] + res_value_type{2};
         assert (p != res_value_type{0});
         y2[i] = (sig-1.0) / p;
         u[i] = (value_type{6.0}*( (points[i+1].y-points[i].y)/(points[i+1].x-points[i].x)-(points[i].y-points[i-1].y)/
         dvsor2)/dvsor1-sig*u[i-1])/p;
      }
      
      for ( int i = static_cast<int>(n)-1; i != -1; --i){
         y2[i] = y2[i]*y2[i+1]+u[i];
      }

      return y2;
   }

   template <typename PointType>
   typename PointType::value_type 
   inline spline_impl(
      std::vector<PointType> const & points,
      std::vector<decltype(typename PointType::value_type{} / typename PointType::value_type{1} )> const & y2,  // derivative2
      std::size_t index,  // point to look found from binsearch
      typename PointType::value_type const & v // + offset from x at index
   ) 
   {
      assert( index < points.size()-1);
      std::size_t const klo = index;
      std::size_t const khi = index +1;

      typedef typename PointType::value_type value_type;
      typedef decltype(value_type{} / value_type{1} ) res_value_type;
 
      value_type const h = points[khi].x - points[klo].x;
      assert( h != value_type{0});
      res_value_type const a = (points[khi].x - v) / h ;
      res_value_type const b = (v - points[klo].x) / h ;

      return a * points[klo].y + b * points[khi].y  + ((a*a*a-a)* y2[klo] + (b*b*b-b) * y2[khi]) * (h*h) / value_type{6.0};
   }

   /*
     Either x values increase with index
     or x values decrease with index
     but shouldnt do both or coincide
     e.g for (i = 1 ; i < points.size(); ++i){
       if ( ( points[i].x > points[i-1].x){
          switch (curve_type){
            
            case increasing_x:
               break;
            case unknown:
               curve_type = increasing_x;
               break;
            case decreasing_x:
            default:
               assert false
          }
       } else{
           if ( points[i].x < points[i-1].x){
               switch (curve_type){
                  case decreasing_x:
                     break;
                  case unknown:
                     curve_type = decreasing_x;
                     break;
                  case increasing_x:
                  default:
                     assert false
              }
           }else{
               assert ( false  && "coincident x" )
           }

        }
     }
   */
   template <typename PointType>
   std::size_t 
   inline binsearch(
         std::vector<PointType> const & points, 
         typename PointType::value_type const & v)
   {
      std::size_t num_points = points.size();
      std::size_t klo = 0U;
      std::size_t khi = num_points - 1U;
      
      while ( (khi - klo) > 1U){
         
         auto const k = (khi + klo)/2U;
         
         auto const xlo = points[klo].x;
         auto const xhi = points[khi].x;
         if ( xhi > xlo){
            if ( points[k].x > v){
               khi = k;
            }else{
               klo = k;
            }
         }else{
            if ( points[k].x < v){
               khi = k;
            }else{
               klo = k;
            }
         }
      }
      return klo;
   }
}}}

namespace quan{ namespace two_d{

/*
   The spline curve is made from a set of control points
   A y value can be returned for any x value between the value of the points first and last x value
*/
   
     template <typename ValueType>
     struct cubic_spline{
         
         cubic_spline():m_points_modified{false}{}

         void push_back(quan::two_d::vect<ValueType> const & pt)
         {
            m_points.push_back(pt);
            m_points_modified = true;
         }

         ValueType operator ()(ValueType const & x) const
         {
            // must have more than one point
            // arguably one could have one point if the arg i its y value
            assert(m_points.size() > 1); 
            assert ( ( x >= front().x ) && ( x <= back().x ) );
            // if the curve points are modified then it is necessary to recalc the derivatives
            // also check enough pts

            if ( m_points_modified){
               m_deriv2_pts = quan::two_d::detail::derivative2(m_points);
               m_points_modified = false;
            }
            
            auto const idx = quan::two_d::detail::binsearch(m_points,x);

            return quan::two_d::detail::spline_impl(m_points,m_deriv2_pts,idx,x);
         }
         quan::two_d::vect<ValueType> const & front() const { return m_points.front();}

         quan::two_d::vect<ValueType> const & back() const { return m_points.back();}
         private:
         std::vector<quan::two_d::vect<ValueType> > m_points;
         mutable std::vector<decltype(ValueType{}/ValueType{1})> m_deriv2_pts;
         mutable bool m_points_modified;
         
     };
}}


#endif // QUAN_TWO_D_CUBIC_SPLINE_HPP_INCLUDED
