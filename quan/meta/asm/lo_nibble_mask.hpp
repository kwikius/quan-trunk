#ifndef QUAN_META_ASM_LO_NIBBLE_MASK_HPP_INCLUDED
#define QUAN_META_ASM_LO_NIBBLE_MASK_HPP_INCLUDED
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

#include <quan/config.hpp>
#include <quan/meta/asm/nibble_shift.hpp>
#include <quan/static_assert.hpp>

namespace quan{ namespace meta{namespace asm_{

   namespace detail{

      template <int N>
      struct lo_nibble_mask_c;

      template<>
      struct lo_nibble_mask_c<1>{
         enum {value = 0x10};
      };

      template<int N>
      struct lo_nibble_mask_c{
         enum {value = 0x10 * (lo_nibble_mask_c<N-1>::value)};
      };
      
   }

   template <typename Int>
   struct lo_nibble_mask
   : std::integral_constant<
      Int, (detail::lo_nibble_mask_c<(size_of<Int>::value)>::value -1)
   >{};
#if (defined QUAN_HAS_LONG_LONG)
   template <>
   struct lo_nibble_mask<long long>
   : std::integral_constant<
      long long , 0xffffffffLL
   >{
      QUAN_STATIC_ASSERT((sizeof(long long) == 8));
   };

   template <>
   struct lo_nibble_mask<unsigned long long>
   : std::integral_constant<
     unsigned long long , 0xffffffffLL
   >{
       QUAN_STATIC_ASSERT((sizeof(long long) == 8));
   };
#endif
}}}//quan::meta::asm_
#endif

