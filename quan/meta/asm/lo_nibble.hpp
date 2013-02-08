#ifndef QUAN_META_ASM_LO_NIBBLE_HPP_INCLUDED
#define QUAN_META_ASM_LO_NIBBLE_HPP_INCLUDED

#include <quan/meta/asm/lo_nibble_mask.hpp>

namespace quan{ namespace meta{namespace asm_{

   template <typename T, T v>
   struct lo_nibble{
      static const T value = v & lo_nibble_mask<T>::value;
   };
}}}//quan::meta::asm

#endif

