#ifndef QUAN_META_INTEGER_MIN_HPP_INCLUDED
#define QUAN_META_INTEGER_MIN_HPP_INCLUDED

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

#include <quan/config.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <climits>
#include <type_traits>
#else
#include <quan/avr/limits.hpp>
//#include <quan/avr/limits.hpp>
#include <quan/std/tr1/integral_constant.hpp>
#endif

namespace quan{ namespace meta{

   template <typename T>
   struct integer_min;

   template<>
   struct integer_min<signed char> : std::integral_constant<signed char,SCHAR_MIN>{};
   
   template<>
   struct integer_min<unsigned char> : std::integral_constant<unsigned char,0>{};
 
   template<>
   struct integer_min<signed short> : std::integral_constant<signed short,SHRT_MIN>{};
 
   template<>
   struct integer_min<unsigned short> : std::integral_constant<unsigned short,0>{};
 
   template<>
   struct integer_min<signed int> : std::integral_constant<signed int,INT_MIN>{};
  
   template<>
   struct integer_min<unsigned int> : std::integral_constant<unsigned int,0>{};
 
   template<>
   struct integer_min<signed long> : std::integral_constant<signed long,LONG_MIN>{};
  
   template<>
   struct integer_min<unsigned long> : std::integral_constant<unsigned long,0>{};
  
#if (defined QUAN_HAS_LONG_LONG)

#if defined __AVR__
#if ! defined LLONG_MIN
#define LLONG_MIN (-__LONG_LONG_MAX__ - 1)
#endif
#endif

   template<>
   struct integer_min<signed long long> : std::integral_constant<signed long long,LLONG_MIN>{};
  
   template<>
   struct integer_min<unsigned long long> : std::integral_constant<unsigned long long,0>{};
 

#endif
}}

#endif

