#ifndef QUAN_ASM_EXTENDED_MUL_HPP_INCLUDED
#define QUAN_ASM_EXTENDED_MUL_HPP_INCLUDED
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

#include <type_traits>
#include <quan/sign.hpp>
#include <quan/abs.hpp>
#include <quan/asm/nibble.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/asm/extended_reg.hpp>
#include <quan/where.hpp>

namespace quan{ namespace asm_{

   // always positive
   template <typename T>
   inline constexpr
   extended_reg<T> extended_mul_unsigned(T const & lhs, T const & rhs)
   {
      static_assert(std::is_unsigned<T>::value,"");

      const T low  = lo_nibble(lhs) * lo_nibble(rhs);
      const T midL = lo_nibble(lhs) * hi_nibble(rhs);
      const T midR = hi_nibble(lhs) * lo_nibble(rhs);
      const T hi   = hi_nibble(lhs) * hi_nibble(rhs);

      constexpr T nibble_shift = quan::meta::asm_::nibble_shift<T>::value;

      const T lo_msb_r1 = hi_nibble(low) + lo_nibble(midL);
      const T lo_msb_r2 = lo_nibble(lo_msb_r1) + lo_nibble(midR);
      const T hi_lsb_r1 = lo_nibble(hi) + hi_nibble(midL);
      const T hi_lsb_r2 = lo_nibble(hi_lsb_r1) + hi_nibble(midR);

      const T hi_lsb_r3 = hi_nibble(lo_msb_r1) + lo_nibble(hi_lsb_r2);
      const T hi_lsb_r4  = hi_nibble(lo_msb_r2) + lo_nibble(hi_lsb_r3);
      const T hi_msb_r1  = hi_nibble(hi) + hi_nibble(hi_lsb_r1);
      const T hi_msb_r2  = lo_nibble(hi_msb_r1) + hi_nibble(hi_lsb_r2);

      const T hi_msb_r3  = lo_nibble(hi_msb_r2) + hi_nibble(hi_lsb_r3);
      const T hi_msb_r4 = lo_nibble(hi_msb_r3) + hi_nibble(hi_lsb_r4);
      const T lo_reg = lo_nibble(low) | (lo_nibble(lo_msb_r2) << nibble_shift);
      const T hi_reg = (lo_nibble(hi_lsb_r4)) | (lo_nibble(hi_msb_r4) << nibble_shift);

      return {hi_reg,lo_reg,1};
      
   }


   template <typename T>
   inline constexpr
   extended_reg<
      typename quan::meta::signed_to_unsigned<T>::type
   > extended_mul_signed(T  lhs, T rhs)
   {
      static_assert(std::is_signed<T>::value,"");
      typedef typename quan::meta::signed_to_unsigned<
         T
      >::type unsigned_type;

      auto const u_reg = extended_mul_unsigned(
         static_cast<unsigned_type>(quan::abs(lhs)),
         static_cast<unsigned_type>(quan::abs(rhs))
      );

      return {u_reg.hi, u_reg.lo, quan::sign(lhs) * quan::sign(rhs)};
   }

   template <typename T>
   inline constexpr
   typename quan::where_<
      std::is_signed<T>,
      extended_reg<
         typename quan::meta::signed_to_unsigned<T>::type
      >
   >::type extended_mul(T lhs, T rhs)
   {
      return extended_mul_signed(lhs,rhs);
   }

   template <typename T>
   inline constexpr
   typename quan::where_<
      std::is_unsigned<T>,
      extended_reg<T>
   >::type extended_mul(T lhs, T rhs)
   {
      return extended_mul_unsigned(lhs,rhs);
   }

}}//quan::asm_

#endif

