#ifndef QUAN_META_ASM_NIBBLE_SHIFT_HPP_INCLUDED
#define QUAN_META_ASM_NIBBLE_SHIFT_HPP_INCLUDED

// Copyright Andrew Little 2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/size_of.hpp>
#include <type_traits>

namespace quan{ namespace meta{ namespace asm_{

   template <typename Int>
   struct nibble_shift : std::integral_constant <int,size_of<Int>::value * 4>{};

}}}//quan::meta::asm_
#endif

