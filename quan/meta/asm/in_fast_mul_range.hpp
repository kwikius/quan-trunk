#ifndef QUAN_META_ASM_IN_FAST_MUL_RANGE_HPP_INCLUDED
#define QUAN_META_ASM_IN_FAST_MUL_RANGE_HPP_INCLUDED

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
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <type_traits>
#include <quan/meta/asm/abs.hpp>
#include <quan/meta/asm/lo_nibble_mask.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/if.hpp>

namespace quan{ namespace meta{ namespace asm_{

template <typename T ,T TL,T TR>
struct in_fast_mul_range_signed {
   static const T abs_lhs = abs<T,TL>::value;
   static const T abs_rhs = abs<T,TR>::value;
   static const T mask = lo_nibble_mask<T>::value;
   typedef quan::meta::bool_<(
   (abs_lhs ==1) || (abs_rhs ==1) || (TL==0) || (TR==0)
   || (
      (abs_lhs <= mask/2)&& (abs_rhs <= mask))
   || (
      (abs_rhs <= mask/2)&& (abs_lhs <= (mask)))
   )> type;
   static const bool value = type::value;
};

template <typename T ,T TL,T TR>
struct in_fast_mul_range_unsigned : quan::meta::bool_<(
   (TL ==1) || (TR==1) || (TL==0) || (TR==0)
   || (
      (TL <= (quan::meta::asm_::lo_nibble_mask<T>::value) +1)
      && 
      (TR <= (quan::meta::asm_::lo_nibble_mask<T>::value))
   ||
      (TL <= (quan::meta::asm_::lo_nibble_mask<T>::value))
      && 
      (TR <= (quan::meta::asm_::lo_nibble_mask<T>::value) +1)
   )
)>{};

template <typename T,T TL,T TR>
struct in_fast_mul_range : quan::meta::if_<
   std::is_signed<T>,
   in_fast_mul_range_signed<T,TL,TR>,
   in_fast_mul_range_unsigned<T,TL,TR>
>::type {};

}}}//quan::meta::asm_

#endif

