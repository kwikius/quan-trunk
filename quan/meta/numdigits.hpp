#ifndef QUAN_META_NUMDIGITS_HPP_INCLUDED
#define QUAN_META_NUMDIGITS_HPP_INCLUDED
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

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_integral.hpp>
#include <quan/std/tr1/is_signed.hpp>
#endif
#include <quan/meta/numbits.hpp>
#include <quan/where.hpp>

namespace quan{ namespace meta{
 
   template<typename I, typename Where = void> struct numdigits;

   template <typename I> struct numdigits<
		I, typename quan::where_<std::is_integral<I> >::type
   > {
         static const int value =  quan::meta::numbits<I>::value - (std::is_signed<I>::value ? 1: 0);
         typedef numdigits type;
   };
}}

#endif // QUAN_META_NUMDIGITS_HPP_INCLUDED
