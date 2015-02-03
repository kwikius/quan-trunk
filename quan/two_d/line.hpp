#ifndef QUAN_TWO_D_LINE_HPP_INCLUDED
#define QUAN_TWO_D_LINE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2003-2014 Andy Little.

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
 */

/*
    simple 2d line.
    Note that this is identical to 3d line
    except for namespace.
*/
#include <quan/two_d/vect.hpp>
#include <quan/cmath.hpp>

namespace quan{ namespace two_d{
   // add scale by a quantity
   // add subtract by vector
    template <typename PointType>
    struct line{
        typedef PointType point_type;
        
        line(point_type const & from_in ,point_type const & to_in)
        : from(from_in),to(to_in){}
        template<typename T1>
        line(line<T1> const & in)
        : from(in.from),to(in.to){}
        point_type from,to;
        line() : from(point_type()),to(point_type()){}
        template <typename Vect>
        line& operator-=(Vect const & v)
        {
            this->from -= v;
            this->to -= v;
            return *this;
        }
        template <typename Vect>
        line& operator +=(Vect const & v)
        {
            this->from += v;
            this->to += v;
            return *this;
        }
        typename PointType::value_type length() const
        {
            return magnitude(this->to - this->from);
        }
    };

   template <typename Pt>
   inline
   vect<
      typename quan::meta::binary_op<
         typename Pt::value_type,
         quan::meta::divides,
         typename Pt::value_type
      >::type
   >  
   direction_vector(line<Pt> const & in)
   {
      return unit_vector(in.to - in.from);
   }

   // parallel irrespective of start end
   template <typename Pt1, typename Pt2>
   inline
   bool are_parallel(line<Pt1> const & in1,line<Pt2> const & in2,
   quan::angle::rad const & epsilon = quan::angle::rad(1e-5))
   {
      typedef typename quan::meta::binary_op<
         typename Pt1::value_type,quan::meta::divides,typename Pt2::value_type
      >::type value_type;
      typedef quan::two_d::vect<value_type> dvect;
      dvect v1 = direction_vector(in1);
      dvect v2 = direction_vector(in2);
      using std::abs;
      value_type dprod1 = std::acos(abs(dot_product(v1,v2)));
      if (abs(dprod1) > abs(epsilon.numeric_value())){
         return false;
      }
      value_type dprod2 = std::acos(abs(dot_product(-v1,v2)));
      if (abs(dprod2) > abs(epsilon.numeric_value())){
         return false;
      }
      return true;
   }

   template <typename Pt1, typename Pt2>
   std::pair<
      bool,
      typename quan::meta::binary_op<
         Pt1,
         quan::meta::minus,
         Pt2
      >::type
   > intersect(
      line<Pt1> const & in1, 
      line<Pt2> const & in2, 
      quan::angle::rad const & epsilon = quan::angle::rad(1e-6))
   {
      typedef typename quan::meta::binary_op<
         Pt1,
         quan::meta::minus,
         Pt2
      >::type  result_vect_type;
      typedef std::pair<
         bool,
         result_vect_type
      > result_type;

      if (are_parallel(in1,in2,epsilon)){
         return result_type(
            false, 
            result_vect_type(
               typename result_vect_type::value_type(0),
               typename result_vect_type::value_type(0)
            )
         );
      }
      
      Pt1 base1 = in1.from;
      Pt1 dir1 =  in1.to - in1.from;
      Pt2 base2 = in2.from;
      Pt2 dir2 =  in2.to - in2.from;
      typename quan::meta::binary_op<
         typename Pt1::value_type,
         quan::meta::times,
         typename Pt2::value_type
      >::type div_type = (dir1.x * dir2.y - dir1.y * dir2.x);
      // check for 0;
      
      typedef typename quan::meta::binary_op<
        typename Pt1::value_type,
         quan::meta::divides,
        typename Pt2::value_type
      >::type mu_type;
      mu_type mu =((base2.x - base1.x) * dir2.y - (base2.y - base1.y) * dir2.x)/ div_type ;
     // mu_type lambda = ((base2.x - base1.x) * dir1.y - (base2.y - base1.y) * dir1.x)/ div_type;
      return result_type(
         true,
         result_vect_type( base1 + mu * dir1)
      );
   }
   
   template <typename Pt1, typename Pt2>
   bool is_laying(line<Pt1> const & src, line<Pt2> const & target)
   {
      typedef typename quan::meta::binary_op<
         Pt1, quan::meta::minus,Pt2
      >::type vect_type;

      std::pair<bool,vect_type> intersect_pt = intersect(src,target);
      if (!intersect_pt.first){
         return false;
      }
      typename vect_type::value_type mag_target = magnitude(target.to - target.from);
      vect_type v1 (target.from - intersect_pt.second);
      if (magnitude(v1) > mag_target) return false;
      vect_type v2 (target.to -intersect_pt.second);
      if(magnitude(v2) > mag_target) return false;
      return true;
   }

}}//quan::two_d

#endif
