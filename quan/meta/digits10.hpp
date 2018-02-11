#ifndef QUAN_META_DIGITS_10_HPP_INCLUDED
#define QUAN_META_DIGITS_10_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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
#include <quan/meta/numdigits.hpp>

#include <quan/where.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#include <cfloat>
#else
#include <float.h>
#include <quan/std/tr1/is_integral.hpp>
#endif
namespace quan{ namespace meta{

 template <typename I, typename Where = void> struct digits10{};

 template<typename I> struct digits10
   <I,typename quan::where_<std::is_integral<I> >::type>{

   static const int value = (static_cast<int64_t>(quan::meta::numdigits<I>::value) * 643 )/ 2136; 
   typedef digits10 type;
 };

 template <> struct digits10<float>{
    static const int value = FLT_DIG;
    typedef digits10 type;
 };

template <> struct digits10<double>{
    static const int value = DBL_DIG;
    typedef digits10 type;
 };

template <> struct digits10<long double>{
    static const int value = LDBL_DIG;
    typedef digits10 type;
 };
  
}}//quan::meta

#endif
