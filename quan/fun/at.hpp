#ifndef QUAN_FUN_AT_HPP_INCLUDED1
#define QUAN_FUN_AT_HPP_INCLUDED1
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

#include <stdint.h>
#include <stddef.h>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/access_modifiers.hpp>
#include <type_traits>

namespace quan{ namespace fun{

   template <int I,typename T>
   typename at_seq<I,T, quan::fun::as_const_ref>::type
   at(T const & in)
   {
      return at_seq<I,T,as_const_ref>{}(in);
   }

   template <int I,typename T>
   typename at_seq<I,T,quan::fun::as_ref>::type
   at(T & in)
   {
      return at_seq<I,T, quan::fun::as_ref>{}(in);
   }

//   template <size_t I,typename T, size_t N>
//   T at( T (& ar)[N])
//   {
//      static_assert( I < N, "array index out of range");
//      return ar[I];
//   }
  
}}//quan::fun

#endif
