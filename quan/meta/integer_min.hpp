#ifndef QUAN_META_INTEGER_MIN_HPP_INCLUDED
#define QUAN_META_INTEGER_MIN_HPP_INCLUDED

// Copyright Andrew Little 2007. All rights reserved

#include <quan/config.hpp>
#ifndef __AVR__
#include <climits>

#include <type_traits>
#else
#include <limits.h>
#include <type_traits>
namespace std{
   using std::integral_constant;
}
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

   template<>
   struct integer_min<signed long long> : std::integral_constant<signed long long,LLONG_MIN>{};
  
   template<>
   struct integer_min<unsigned long long> : std::integral_constant<unsigned long long,0>{};
 

#endif
}}

#endif

