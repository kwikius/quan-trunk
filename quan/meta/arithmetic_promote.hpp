#ifndef QUAN_META_ARITHMETIC_PROMOTE_HPP_INCLUDED
#define QUAN_META_ARITHMETIC_PROMOTE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005-2012

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <type_traits>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/strip_cr.hpp>

namespace quan { namespace meta { namespace impl {

   template <typename T1, typename T2, typename Where = void >
   struct arithmetic_promote_impl;

   template <typename T1, typename T2>
   struct arithmetic_promote_impl<T1,T2,
      typename quan::where_<
         quan::meta::and_<std::is_arithmetic<T1>, std::is_arithmetic<T2> >
      >::type
   > {
      typedef decltype(T1{} + T2{}) type;
   };

}}}


namespace quan { namespace meta {

   template <typename T1, typename T2>
   struct arithmetic_promote : impl::arithmetic_promote_impl<
      typename quan::meta::strip_crv<T1>::type,
      typename quan::meta::strip_crv<T2>::type
   > {};

}}//quan::meta

#endif

