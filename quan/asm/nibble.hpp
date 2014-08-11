#ifndef QUAN_ASM_LO_NIBBLE_HPP_INCLUDED
#define QUAN_ASM_LO_NIBBLE_HPP_INCLUDED
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

