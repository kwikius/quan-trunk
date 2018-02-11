#ifndef QUAN_META_ARITHMETIC_PROMOTE_HPP_INCLUDED
#define QUAN_META_ARITHMETIC_PROMOTE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2005 - 2013 Andy Little 

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

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#endif

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
/*
   template <typename T>
   struct arithmetic_promote_impl<T,T,
      typename quan::where_<
         std::is_arithmetic<T> 
      >::type
   > {
      typedef T type;
   };
*/

}}}


namespace quan { namespace meta {

   template <typename T1, typename T2>
   struct arithmetic_promote : impl::arithmetic_promote_impl<
      typename quan::meta::strip_crv<T1>::type,
      typename quan::meta::strip_crv<T2>::type
   > {};

}}//quan::meta

#endif

