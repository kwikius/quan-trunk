#ifndef QUAN_META_GCD_HPP_INCLUDED
#define QUAN_META_GCD_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005. All rights reserved.


#include <quan/config.hpp>
#include <quan/meta/detail/gcd_impl.hpp>

namespace quan{ namespace meta{

   template <typename T, T N, T D>
   struct gcd : detail::gcd_impl<T,D, (N % D)>::type {};

}}//quan::meta

#endif

