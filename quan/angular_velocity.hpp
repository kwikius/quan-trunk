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

  namespace literals{
      constexpr inline 
      deg_per_s operator "" _deg_per_s ( long double v)
      {
         return deg_per_s{quan::angle::deg{v}};
      }

      constexpr inline 
      rad_per_s operator "" _rad_per_s ( long double v)
      {
         return deg_per_s{quan::angle::rad{v}};
      }
   }//literals

}}//quan::angular_velocity

#endif // QUAN_ANGULAR_VELOCITY_HPP_INCLUDED
