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

#include <quan/asm/nibble.hpp>
#include <quan/static_assert.hpp>
#include <type_traits>
#include <type_traits>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/asm/extended_reg.hpp>
#include <quan/where.hpp>

namespace quan{ namespace asm_{

   template <typename T>
   inline
   extended_reg<T> extended_mul_unsigned(T  lhs, T rhs)
   {
      QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
      static const T shift = quan::meta::asm_::nibble_shift<T>::value;
      static const T lo_mask = quan::meta::asm_::lo_nibble_mask<T>::value;
      extended_reg<T> res;
      res.sign = 1;
      //lo
      res.lo = lo_nibble(lhs) * lo_nibble(rhs);
      //mid1
      T reg = lo_nibble(lhs) * hi_nibble(rhs);
      res.hi = hi_nibble(reg);
      reg &= lo_mask;
      reg += hi_nibble(res.lo);
      res.lo = lo_nibble(res.lo) | (lo_nibble(reg) << shift);
      res.hi += hi_nibble(reg);
      //mid2
      reg = hi_nibble(lhs) * lo_nibble(rhs);
      res.hi += hi_nibble(reg);
      reg &= lo_mask;
      reg += hi_nibble(res.lo);
      res.lo = lo_nibble(res.lo) | (lo_nibble(reg) << shift);
      res.hi += hi_nibble(reg);
      //hi
      res.hi += hi_nibble(lhs) * hi_nibble(rhs);
      
      return res;
   }

   template <typename T>
   inline
   extended_reg<
      typename quan::meta::signed_to_unsigned<T>::type
   > extended_mul_signed(T  lhs, T rhs)
   {
      QUAN_STATIC_ASSERT((std::is_signed<T>::value));
      typedef typename quan::meta::signed_to_unsigned<
         T
      >::type unsigned_type;

      int lhs_sign = lhs >=0?1:-1;
      unsigned_type lhs_u = static_cast<unsigned_type>((lhs_sign > 0)?lhs:-lhs);

      int rhs_sign = rhs >=0? 1:-1;
      unsigned_type rhs_u = static_cast<unsigned_type>((rhs_sign > 0)?rhs:-rhs);

      extended_reg<unsigned_type> u_reg 
      = extended_mul_unsigned(lhs_u,rhs_u);
      u_reg.sign = lhs_sign * rhs_sign;

      return u_reg;
   }

   template <typename T>
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
   typename quan::where_<
      std::is_unsigned<T>,
      extended_reg<T>
   >::type extended_mul(T lhs, T rhs)
   {
      return extended_mul_unsigned(lhs,rhs);
   }

}}//quan::asm_

#endif

