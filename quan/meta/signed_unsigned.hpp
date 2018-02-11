#ifndef QUAN_META_SIGNED_UNSIGNED_HPP_INCLUDED
#define QUAN_META_SIGNED_UNSIGNED_HPP_INCLUDED

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

#include <quan/undefined.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/eval_if.hpp>
#if defined QUAN_AVR_NO_CPP_STDLIB
#include <quan/std/tr1/is_signed.hpp>
#include <quan/std/tr1/is_unsigned.hpp>
#else
#include <type_traits>
#endif
#include <quan/meta/identity.hpp>

namespace quan{ namespace meta{

   template < typename T>
   struct signed_to_unsigned;

   template<> struct signed_to_unsigned<signed char> {typedef unsigned char type;};
   template<> struct signed_to_unsigned<short> {typedef unsigned short type;};
   template<> struct signed_to_unsigned<int> {typedef unsigned int type;};
   template<> struct signed_to_unsigned<long> {typedef unsigned long type;};
#if (defined QUAN_HAS_LONG_LONG)
   template<> struct signed_to_unsigned<long long> {typedef unsigned long long type;};
#endif

   template < typename T>
   struct unsigned_to_signed;

   template<> struct unsigned_to_signed<unsigned char> {typedef signed char type;};
   template<> struct unsigned_to_signed<unsigned short> {typedef short type;};
   template<> struct unsigned_to_signed<unsigned int> {typedef int type;};
   template<> struct unsigned_to_signed<unsigned long> {typedef long type;};
#if (defined QUAN_HAS_LONG_LONG)
   template<> struct unsigned_to_signed<unsigned long long> {typedef long long type;};
#endif

   template <typename I>
   struct to_unsigned : quan::meta::eval_if<
      std::is_signed<I>,
      signed_to_unsigned<I>,
      quan::meta::if_<
         std::is_unsigned<I>,
         I,
         quan::undefined
      >
   >{};

   template <typename I>
   struct to_signed : quan::meta::eval_if<
      std::is_unsigned<I>,
      unsigned_to_signed<I>,
      quan::meta::if_<
         std::is_signed<I>,
         I,
         quan::undefined
      >
   >{};

}}//quan::meta


#endif

