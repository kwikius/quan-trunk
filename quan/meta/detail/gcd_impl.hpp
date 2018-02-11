#ifndef QUAN_META_DETAIL_GCD_IMPL_HPP_INCLUDED
#define QUAN_META_DETAIL_GCD_IMPL_HPP_INCLUDED
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
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/integral_constant.hpp>
#endif
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{namespace detail{

   template <typename T, T N, T D>
   struct gcd_impl;

   #define QUAN_META_DETAIL_GCD_TERMINATOR(T) \
   template <T N>\
   struct gcd_impl< T ,N,0> : std::integral_constant<T,N>{}

    QUAN_META_DETAIL_GCD_TERMINATOR(signed char);
    QUAN_META_DETAIL_GCD_TERMINATOR(short);
    QUAN_META_DETAIL_GCD_TERMINATOR(int);
    QUAN_META_DETAIL_GCD_TERMINATOR(long);
#ifdef QUAN_HAS_LONG_LONG
    QUAN_META_DETAIL_GCD_TERMINATOR(long long);
#endif
    QUAN_META_DETAIL_GCD_TERMINATOR(unsigned char);
    QUAN_META_DETAIL_GCD_TERMINATOR(unsigned short);
    QUAN_META_DETAIL_GCD_TERMINATOR(unsigned int);
    QUAN_META_DETAIL_GCD_TERMINATOR(unsigned long);
#ifdef QUAN_HAS_LONG_LONG
    QUAN_META_DETAIL_GCD_TERMINATOR(unsigned long long);
#endif
   #undef QUAN_META_DETAIL_GCD_TERMINATOR

   template <typename T, T N, T D>
   struct gcd_impl : gcd_impl<T,D, (N % D)>{};

}}}//quan::meta::detail

#endif

