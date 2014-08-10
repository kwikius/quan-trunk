#ifndef QUAN_META_ASM_HI_NIBBLE_HPP_INCLUDED
#define QUAN_META_ASM_HI_NIBBLE_HPP_INCLUDED

// Copyright Andrew Little 2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/asm/hi_nibble_mask.hpp>
#include <quan/meta/asm/nibble_shift.hpp>

namespace quan{ namespace meta{namespace asm_{
   template <typename T, T v>
   struct hi_nibble{

      static const T value = static_cast<T>((v & hi_nibble_mask<T>::value) >> nibble_shift<T>::value);
   };
}}}//quan::meta::asm

#endif

