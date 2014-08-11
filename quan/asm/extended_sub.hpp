#ifndef QUAN_ASM_EXTENDED_SUB_HPP_INCLUDED
#define QUAN_ASM_EXTENDED_SUB_HPP_INCLUDED
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
   extended_reg<T> extended_sub_unsigned(T lhs, T rhs)
   {
       QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
       extended_reg<T> res;
       res.hi =0;
       if ( lhs >= rhs){
           res.lo = lhs - rhs;
           res.sign = extended_reg<T>::positive;
       }
       else{
          res.lo = rhs - lhs;
          res.sign = extended_reg<T>::negative;
       }  
       return res;
   }

}}//quan::asm_

#endif

