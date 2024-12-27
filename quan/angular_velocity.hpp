#ifndef QUAN_ANGULAR_VELOCITY_HPP_INCLUDED
#define QUAN_ANGULAR_VELOCITY_HPP_INCLUDED

#include <quan/angle.hpp>
#include <quan/reciprocal_time.hpp>

namespace quan{ namespace angular_velocity{

   using rad_per_s = quan::reciprocal_time_<
      quan::angle::rad
   >::per_s ;

   using deg_per_s = quan::reciprocal_time_<
      quan::angle::deg
   >::per_s ;

   using rev_per_s = quan::reciprocal_time_<
      quan::angle::rev
   >::per_s ;

  namespace literals{
      constexpr inline
      deg_per_s operator "" _deg_per_s ( long double v)
      {
         return deg_per_s{quan::angle::deg{v}};
      }

      constexpr inline
      rad_per_s operator "" _rad_per_s ( long double v)
      {
         return rad_per_s{quan::angle::rad{v}};
      }

      constexpr inline
      rev_per_s operator "" _rev_per_s ( long double v)
      {
         return rev_per_s{quan::angle::rev{v}};
      }
   }//literals

}}//quan::angular_velocity

#define QUAN_USING_ANGULAR_VELOCITY \
using rad_per_s = quan::angular_velocity::rad_per_s; \
using deg_per_s = quan::angular_velocity::deg_per_s; \
using namespace quan::angular_velocity::literals;

#endif // QUAN_ANGULAR_VELOCITY_HPP_INCLUDED
