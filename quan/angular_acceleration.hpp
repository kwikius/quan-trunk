#ifndef QUAN_ANGULAR_ACCELERATIION_HPP_INCLUDED
#define QUAN_ANGULAR_ACCELERATION_HPP_INCLUDED

#include <quan/angle.hpp>
#include <quan/reciprocal_time2.hpp>

namespace quan{ namespace angular_acceleration{

   using rad_per_s2 = quan::reciprocal_time2_<
      quan::angle::rad
   >::per_s2 ;

   using deg_per_s2 = quan::reciprocal_time2_<
      quan::angle::deg
   >::per_s2 ;

  namespace literals{
      constexpr inline
      deg_per_s2 operator "" _deg_per_s2 ( long double v)
      {
         return deg_per_s2{quan::angle::deg{v}};
      }

      constexpr inline
      rad_per_s2 operator "" _rad_per_s2 ( long double v)
      {
         return deg_per_s2{quan::angle::rad{v}};
      }
   }//literals

}}//quan::angular_acceleration

#define QUAN_USING_ANGULAR_ACCELERATION \
using rad_per_s2 = quan::angular_acceleration::rad_per_s2; \
using deg_per_s2 = quan::angular_acceleraaion::deg_per_s2; \
using namespace quan::angular_acceleration::literals;

#endif // QUAN_ANGULAR_ACCELERATION_HPP_INCLUDED
