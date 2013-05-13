#ifndef QUAN_META_INTEGER_MAX_HPP_INCLUDED
#define QUAN_META_INTEGER_MAX_HPP_INCLUDED

// Copyright Andrew Little 2007. All rights reserved

#include <quan/config.hpp>
#ifndef __AVR__
#include <climits>
#include <type_traits>
#else
#include <quan/avr/limits.hpp>
#include <quan/std/tr1/integral_constant.hpp>
#endif

namespace quan{ namespace meta{

   template <typename T>
   struct integer_max;

   template<>
   struct integer_max<signed char> : std::integral_constant<signed char,SCHAR_MAX>{};
   
   template<>
   struct integer_max<unsigned char> : std::integral_constant<unsigned char,UCHAR_MAX>{};
 
   template<>
   struct integer_max<signed short> : std::integral_constant<signed short,SHRT_MAX>{};
 
   template<>
   struct integer_max<unsigned short> : std::integral_constant<unsigned short,USHRT_MAX>{};
 
   template<>
   struct integer_max<signed int> : std::integral_constant<signed int,INT_MAX>{};
  
   template<>
   struct integer_max<unsigned int> : std::integral_constant<unsigned int,UINT_MAX>{};
 
   template<>
   struct integer_max<signed long> : std::integral_constant<signed long,LONG_MAX>{};
  
   template<>
   struct integer_max<unsigned long> : std::integral_constant<unsigned long,ULONG_MAX>{};
  
#if (defined QUAN_HAS_LONG_LONG)

   template<>
   struct integer_max<signed long long> : std::integral_constant<signed long long,LLONG_MAX>{};
  
   template<>
   struct integer_max<unsigned long long> : std::integral_constant<unsigned long long,ULLONG_MAX>{};
 

#endif
}}

#endif

