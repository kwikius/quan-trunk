#ifndef QUAN_THREE_D_SPHERE_HPP_INCLUDED
#define QUAN_THREE_D_SPHERE_HPP_INCLUDED

#include <quan/three_d/vect.hpp>

namespace quan{ namespace three_d{

   template <typename LengthType>
   struct sphere{
      typedef LengthType length_type;
      typedef quan::three_d::vect<length_type> point_type;
      point_type  centre;
      length_type radius;
   };

}}

#endif // QUAN_THREE_D_SPHERE_HPP_INCLUDED
