#ifndef QUAN_ASM_LO_NIBBLE_HPP_INCLUDED
#define QUAN_ASM_LO_NIBBLE_HPP_INCLUDED

#include <quan/meta/asm/lo_nibble.hpp>
#include <quan/meta/asm/hi_nibble.hpp>
#include <quan/static_assert.hpp>
#include <type_traits>

namespace quan{ namespace asm_{

   template <typename T>
   inline
   T lo_nibble ( T const & v){
      return  v & quan::meta::asm_::lo_nibble_mask<T>::value;
   };

   template <typename T>
   inline 
   T hi_nibble (T const & v){
     /* return static_cast<T>(
      (v & quan::meta::asm_::hi_nibble_mask<T>::value) 
         >> quan::meta::asm_::nibble_shift<T>::value);*/
      return static_cast<T>(v >> quan::meta::asm_::nibble_shift<T>::value);
   };

}}
#endif

