#ifndef QUAN_META_ASM_HI_NIBBLE_MASK_HPP_INCLUDED
#define QUAN_META_ASM_HI_NIBBLE_MASK_HPP_INCLUDED

// Copyright Andrew Little 2007
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

