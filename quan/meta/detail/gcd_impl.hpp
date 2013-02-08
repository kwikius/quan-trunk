#ifndef QUAN_META_DETAIL_GCD_IMPL_HPP_INCLUDED
#define QUAN_META_DETAIL_GCD_IMPL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006. All rights reserved


#include <quan/config.hpp>
#include <type_traits>
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

