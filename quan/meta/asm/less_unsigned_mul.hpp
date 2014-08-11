
#ifndef QUAN_META_ASM_LESS_UNSIGNED_MUL_HPP_INCLUDED
#define QUAN_META_ASM_LESS_UNSIGNED_MUL_HPP_INCLUDED

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

#include <quan/meta/bool.hpp>

namespace quan{ namespace meta{ namespace asm_{

   // use with mulregs
   template <typename MulL,typename MulR>
   struct less_unsigned_mul : quan::meta::bool_<
      (
         ((MulL::hi_reg) < (MulR::hi_reg))? true
         : (((MulL::hi_reg) > (MulR::hi_reg))? false 
         : (MulL::lo_reg) < (MulR::lo_reg))
      )
   >{
      //QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
   };

}}}//quan::meta::asm_

#endif

