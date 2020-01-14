#ifndef QUAN_THREE_D_SPHERE_HPP_INCLUDED
#define QUAN_THREE_D_SPHERE_HPP_INCLUDED

#include <quan/three_d/vect.hpp>

namespace quan{ namespace three_d{

   template <typename LengthType>
   struct sphere{
      typedef LengthType length_type;
      typedef quan::three_d::vect<length_type> point_type;
      constexpr sphere(length_type const & radius_in, point_type const & centre_in = point_type{})
      : centre{centre_in},radius{radius_in}{}

      point_type  centre;
      length_type radius;
   };

}}

#endif // QUAN_THREE_D_SPHERE_HPP_INCLUDED
