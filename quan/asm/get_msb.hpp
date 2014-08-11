#ifndef QUAN_ASM_GET_MSB_HPP_INCLUDED
#define QUAN_ASM_GET_MSB_HPP_INCLUDED
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

#include <quan/meta/numbits.hpp>
#include <type_traits>
#include <quan/where.hpp>
#include <quan/asm/get_bit.hpp>

namespace quan{ namespace asm_{

   template <typename I>
   inline
   typename quan::where_<
      std::is_integral<I>,
      bool 
   >::type
   get_msb( I const val)
   {
     return quan::asm_::get_bit< quan::meta::numbits<I>::value - 1 >(val);
   }
}}

#endif // QUAN_GET_MSB_HPP_INCLUDED
