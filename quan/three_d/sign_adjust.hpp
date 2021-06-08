#ifndef QUAN_THREE_D_SIGN_ADJUST_HPP_INCLUDED
#define QUAN_THREE_D_SIGN_ADJUST_HPP_INCLUDED

#include <quan/three_d/vect.hpp>

namespace quan{ namespace three_d{


   /**
    * &brief equiv to v * diagonal_matrix {
            sign.x,      0, 0     ,
            0     , sign.y, 0     ,
            0     ,      0, sign.z
      }
   **/

   template <typename T>
   inline constexpr 
   quan::three_d::vect<T> 
   sign_adjust ( quan::three_d::vect<T> const & v, quan::three_d::vect<int> const & sign)
   {
      return { 
         v.x * sign.x,
         v.y * sign.y,
         v.z * sign.z
      };
   }

}}
#endif // QUAN_THREE_D_SIGN_ADJUST_HPP_INCLUDED
