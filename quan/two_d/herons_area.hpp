#ifndef QUAN_TWO_D_HERONS_AREA_HPP_INCLUDED
#define QUAN_TWO_D_HERONS_AREA_HPP_INCLUDED

#include <quan/two_d/vect.hpp>

/*
  herons formula for area of a triangle
*/

namespace quan{ namespace two_d{

   template <typename T>
   inline
   typename quan::meta::binary_op<
     T,quan::meta::times,T
   >::type 
   herons_area(vect<T> const & p1, vect<T> const & p2, vect<T> const & p3)
   {
      auto x = magnitude(p2-p1);
      auto y = magnitude(p3-p2);
      auto z = magnitude(p3-p1);

      auto s = (x + y + z)/2;
      auto a = sqrt(s * ( s - x) * (s - y) * ( s - z));

      return a;
   }

}}

#endif // QUAN_TWO_D_HERONS_AREA_HPP_INCLUDED
