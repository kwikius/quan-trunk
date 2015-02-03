#ifndef QUAN_TWO_D_CONSTRUCTION_LINE_HPP_INCLUDED
#define QUAN_TWO_D_CONSTRUCTION_LINE_HPP_INCLUDED

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
//
 
 
 

#include <quan/two_d/vect.hpp>
#include <quan/two_d/line.hpp>


namespace quan{namespace two_d{

   template <typename T>
   struct construction_line{
      typedef T value_type;
      typedef typename quan::meta::binary_op<
         T, quan::meta::divides,T
      >::type numeric_type;
      typedef quan::two_d::vect<T> base_type;
      typedef quan::two_d::vect<numeric_type> direction_type;
      base_type base;
      //always in unit_vector format
      direction_type direction;
   
      template <typename B1, typename D1>
      construction_line( 
         quan::two_d::vect<B1> const & base_in, 
         quan::two_d::vect<D1> const & dir_in
      ): base(base_in), direction(unit_vector(dir_in)){}
      
      template <typename P1>
      construction_line(line<P1> const & line_in)
      :base(line_in.from),direction(direction_vector(line_in)){}

      template <typename B1>
      construction_line( 
         quan::two_d::vect<B1> const & base_in, 
         quan::angle::rad dir_in
      ): base(base_in), direction(unit_vector(dir_in)){}
      
   };


   template <typename T>
   inline
   typename construction_line<T>::direction_type
   direction_vector(construction_line<T> const & in)
   {
      return in.direction;
   }

   // parallel irrespective of start end
   template <typename T1, typename T2>
   inline
   bool are_parallel(construction_line<T1> const & in1,construction_line<T2> const & in2,
   quan::angle::rad const & epsilon = quan::angle::rad(1e-6))
   {
      typedef quan::meta::binary_op<
         typename construction_line<T1>::numeric_type,
         quan::meta::divides,
         typename construction_line<T2>::numeric_type
      >::type value_type;
      typedef quan::two_d::vect<value_type> dvect;
      dvect v1 = in1.direction;
      dvect v2 = in2.direction;
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

   template <typename T1, typename T2>
   std::pair<
      bool,
      typename quan::meta::binary_op<
         quan::two_d::vect<T1>,
         quan::meta::minus,
         quan::two_d::vect<T2>
      >::type
   > intersect(
      construction_line<T1> const & in1, 
      construction_line<T2> const & in2, 
      quan::angle::rad const & epsilon = quan::angle::rad(1e-6))
   {
      typedef typename quan::meta::binary_op<
         quan::two_d::vect<T1>,
         quan::meta::minus,
         quan::two_d::vect<T2>
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
      
      typename construction_line<T1>::base_type base1 = in1.base;
      typename construction_line<T1>::direction_type dir1 =  in1.direction;
      typename construction_line<T2>::base_type base2 = in2.base;
      typename construction_line<T2>::direction_type dir2 =  in2.direction;
      typename quan::meta::binary_op<
         typename construction_line<T1>::numeric_type,
         quan::meta::times,
         typename construction_line<T2>::numeric_type
      >::type div_type = (dir1.x * dir2.y - dir1.y * dir2.x);
     // std::cout << typeid(div_type).name() <<'\n';
      // check for 0;
      
      typedef typename quan::meta::binary_op<
        typename construction_line<T1>::value_type,
         quan::meta::minus,
        typename construction_line<T2>::value_type
      >::type mu_type;
     // std::cout << typeid(mu_type).name() <<'\n';
      mu_type mu =((base2.x - base1.x) * dir2.y - (base2.y - base1.y) * dir2.x)/ div_type ;
      mu_type lambda = ((base2.x - base1.x) * dir1.y - (base2.y - base1.y) * dir1.x)/ div_type;
      return result_type(
         true,
         result_vect_type(base1 + mu * dir1)
      );
   }
   
   template <typename T1, typename Pt2>
   bool is_laying(construction_line<T1> const & src, line<Pt2> const & target)
   {
      typedef typename quan::meta::binary_op<
         T1, quan::meta::minus,typename Pt2::value_type
      >::type value_type;
      construction_line<value_type> cons_target(target.from,target.to - target.from);
      std::pair<bool,quan::two_d::vect<value_type> > intersect_pt = intersect(src,cons_target);
      if (!intersect_pt.first){
         return false;
      }
      typename value_type mag_target = target.length();
      quan::two_d::vect<value_type> v1 (target.from - intersect_pt.second);
      if (magnitude(v1) > mag_target) return false;
      quan::two_d::vect<value_type> v2 (target.to -intersect_pt.second);
      if(magnitude(v2) > mag_target) return false;
      return true;
   }
}}
#endif

