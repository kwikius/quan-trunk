#ifndef QUAN_ASM_EXTENDED_ADD_HPP_INCLUDED
#define QUAN_ASM_EXTENDED_ADD_HPP_INCLUDED
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
#include <quan/meta/signed_unsigned.hpp>
#include <quan/asm/extended_reg.hpp>

namespace quan{ namespace asm_{

 template <typename T>
   inline 
   extended_reg<T> extended_add_unsigned(T lhs, T rhs)
   {
       QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
       extended_reg<T> res;
       res.sign = extended_reg<T>::positive;
       static const T shift = quan::meta::asm_::nibble_shift<T>::value;
       static const T lo_mask = quan::meta::asm_::lo_nibble_mask<T>::value;
       res.lo = lo_nibble(lhs) + lo_nibble(rhs);
      
       T reg = hi_nibble(res.lo) + hi_nibble(lhs);
       res.lo = lo_nibble(res.lo) | ( lo_nibble(reg) << shift);
       res.hi = hi_nibble(reg);
       reg = hi_nibble(res.lo) + hi_nibble(rhs);
       res.lo = lo_nibble(res.lo) | ( lo_nibble(reg) << shift);
       res.hi += hi_nibble(reg);
       return res;
   }

}}//quan::asm_

#endif

