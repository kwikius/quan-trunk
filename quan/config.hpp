#ifndef QUAN_CONFIG_HPP_INCLUDED
#define QUAN_CONFIG_HPP_INCLUDED
/*
 Copyright (c) 2003-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/
// TODO 
// sort for  __CYGWIN__
// and   __MINGW32__

#if defined (__linux__)
   #define QUAN_OS_LINUX
#else
   #if (defined (_WIN16) || defined (_WIN32))
      #define QUAN_OS_WINDOWS
   #else
      #if defined __MBED__
         #define QUAN_MBED_ONLINE_COMPILER
      #endif
   #endif
#endif

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#if (defined __AVR__) 
#define QUAN_NO_EXCEPTIONS
#define QUAN_NO_RTTI
#if defined abs
#undef abs
#endif
#if ! defined (QUAN_AVR_HAS_CPP_STDLIB)
#define QUAN_AVR_NO_CPP_STDLIB
#endif
#endif

#if (defined QUAN_MBED_ONLINE_COMPILER)
   #ifndef QUAN_NO_EXCEPTIONS
      #define QUAN_NO_EXCEPTIONS
   #endif
   #ifndef QUAN_NO_RTTI
      #define QUAN_NO_RTTI
   #endif
#endif

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cstdint>
#else
#include <stdint.h>
#define QUAN_USE_QUAN_STD_TR1
#endif

#if ( defined(QUAN_STM32F4) || defined(QUAN_STM32F3)  || defined(QUAN_STM32F0) || defined(QUAN_STM32L4) )
#include <quan/stm32/config.hpp>
#endif

/*
    Various Configuration options for Quan
*/
//1 or 2
#define QUAN_BIGINT_VERSION 2

#if (defined __cplusplus) && ( __cplusplus >= 201103L)
#define QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
#define QUAN_HAS_CONSTEXPR
#define QUAN_CONSTEXPR constexpr
#else
#define QUAN_CONSTEXPR 
#endif

#ifndef QUAN_HAS_CONSTEXPR
#error constexpr not defined
#endif

#if defined (_MSC_VER)
#define NOMINMAX
#else
#if defined min
#undef min
#endif
#if defined max
#undef max
#endif
#endif

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <climits>
#else
#include <limits.h>
#endif

#ifndef QUAN_VERSION_MESSAGE
#define QUAN_VERSION_MESSAGE
//#pragma message ("quan version 1")
#endif
//increment this number on major changes
#define QUAN_VERSION 2

//-------------------------------------------------------
//Default epsilon used by compare function

#ifndef QUAN_FLOAT_EPSILON
#define QUAN_FLOAT_EPSILON 0.0
#endif
//-------------------------------------------------------

// define to prevent implicit unit conversions
// Then unit versions must use explicit form.
// note: not implemented on all functions
//#define QUAN_DISALLOW_IMPLICIT_UNIT_CONVERSIONS

//-------------------------------------------------------
//Default floating point type for fixed_quantities
#ifndef QUAN_FLOAT_TYPE
#if defined QUAN_AVR_NO_CPP_STDLIB
 #define QUAN_FLOAT_TYPE double
#else
 #define QUAN_FLOAT_TYPE double
#endif
#endif
//----------------------
// for compliance with TR1 stsndard mods
//#define QUAN_TR1_COMPLIANT

//-----------------------
// The following macros set out the range of static Pow(V,E) functions
// Used to return rational powers of 10 as a double, float, int respectively.
// This useage is designed to prevent for example truncation of pow of 10 as int etc.

#ifndef QUAN_MAX_FLOAT_POW10_EXPONENT
#define QUAN_MAX_FLOAT_POW10_EXPONENT  38
#endif
#ifndef QUAN_MAX_DOUBLE_POW10_EXPONENT
#define QUAN_MAX_DOUBLE_POW10_EXPONENT 67
#endif
#ifndef QUAN_MAX_LONG_DOUBLE_POW10_EXPONENT
#define QUAN_MAX_LONG_DOUBLE_POW10_EXPONENT 100
#endif

#define QUAN_MIN_POS_INTEGER_FP_EXPONENT 10

//----------------------------------------------

// Define so that fixed_quantity wont have a user defined default ctor
// Theoretically gives a performance advantage.
// Disadvantage is that member value is not initialsised
// doesnt seem to make much difference either way in practise.
// #define QUAN_T1_QUANTITY_DONT_DEFINE_DEFAULT_CTOR
//-------------------------------------------------------
// could make this long long now?
// 32bit int for use in rational parameters.
// Must be a macro rather than a typedef
// for use in non-type template parameters
// (note:This may actually be incorrect,
// but cured a previous issue with gcc)

#ifndef QUAN_AVR_NO_CPP_STDLIB
#define RATIONAL_INT_TYPE int64_t
#else
#define RATIONAL_INT_TYPE int32_t
#endif

//#define int64_t int64_t
/*
#if  (INT_MAX >= 0x7fffffff)
#define int64_t int
#elif (LONG_MAX >= 0x7fffffff)
#define int64_t long
#else
// long should be at least 32 bits so should never get here
#error need to define a 32-bit int in <quan/config.hpp>
#endif
#define int64_t_MAX 0x7fffffff
*/

//-------------------------------------------------------

#if (defined _MSC_VER && _MSC_VER ==1400)
// If defined, in VC8.0 causes operators to be defined at global scope
// VC8 has problems with ADL on complicated types
// This isnt a bug in VC8. Its a problem in the overload resolution somewhere
#define QUAN_SUPPRESS_VC8_ADL_BUG
#endif
//-------------------------------------------------------

// define to allow physical constants to be defined in headers
// According to the standard this doesnt violate ODR rules.
// Works OK in gcc4.0
// but fails to work in VC7.1, VC8.0, when other global constants
// are initialised from them probably due to order of initialisation issues
// IOW its probably a bit dodgy
#define QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS

//---------------------------------------------
// required by MSVC
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#define QUAN_MEMBER_TEMPLATE
#else
#define QUAN_MEMBER_TEMPLATE template
#endif
//------------------------------------
// Many calculations result in so-called anonymous quantities
// (See the docs for rationale).
// However in many cases there is a reasonable named quantity result.
// (e.g. length, area, reciprocal_length)
// Select this option to allow the desired anonymous quantities
// to automatically be tranformed to named quantities.
// The most important effect is to change the input/output format.
// gives less verbose and neater output

// if defined certain anonymous quantities are 'hoisted'
// see e.g quan/components/of_length.hpp (at the end of header)for
// example of how this is implemented

// This will cause a change in output format
// for hoisted anonymus quantities
// and certain quantities cannot be output direct
// and will need to be converted .e.g area in m2 e-5
// would need to be convetred to mm2 etc.
// This should be caught at compile time.


#define QUAN_ENABLE_SELECTED_HOISTED_QUANTITIES

//prevent conversion of math angle to numeric
//#define QUAN_NO_MATH_ANGLE_NUMERIC_CONVERSION
// may not have if 
#ifndef QUAN_AVR_NO_CPP_STDLIB
   #define QUAN_HAS_LONG_LONG
   #if defined __AVR__
      #if ! defined LLONG_MAX
         #define LLONG_MAX 0x7fffffffffffffff
         #define LLONG_MIN (-__LONG_LONG_MAX__ - 1)
         #define ULLONG_MAX 0xffffffffffffffff
      #endif
   #endif
#endif


#endif // QUAN_CONFIG_HPP_INCLUDED
