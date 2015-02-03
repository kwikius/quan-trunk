#ifndef QUAN_META_ASM_HI_NIBBLE_MASK_HPP_INCLUDED
#define QUAN_META_ASM_HI_NIBBLE_MASK_HPP_INCLUDED

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

#include <quan/meta/asm/nibble_shift.hpp>
#include <quan/meta/asm/lo_nibble_mask.hpp>

namespace quan{ namespace meta{namespace asm_{

   template <typename Int> 
   struct hi_nibble_mask
   : std::integral_constant<
      Int, 
     static_cast<Int>((lo_nibble_mask<Int>::value) << (nibble_shift<Int>::value))>{};

}}}//quan::meta::asm_

#endif

