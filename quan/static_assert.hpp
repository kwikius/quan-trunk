#ifndef QUAN_STATIC_ASSERT_HPP_INCLUDED
#define QUAN_STATIC_ASSERT_HPP_INCLUDED

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

//#include <type_traits>
#include <quan/config.hpp>

#include <quan/where.hpp>

#include <quan/macro/cat.hpp>

namespace quan{ namespace static_assertion{

   template <int X, typename Where = void> struct passed;

   template <int X>
   struct passed<X, typename quan::where_c<(X !=0)>::type>{};

   template <int X>
   struct tester;

}}
#if (defined _MSC_VER)
#define QUAN_STATIC_ASSERT(Cond) \
   typedef quan::static_assertion::tester<sizeof(quan::static_assertion::passed<Cond>)> \
   QUAN_MACRO_CAT( assertion_failure_ , __COUNTER__ )
#else
#define QUAN_STATIC_ASSERT(Cond) \
   typedef quan::static_assertion::tester<sizeof(quan::static_assertion::passed<Cond>)> \
   QUAN_MACRO_CAT( assertion_failure_ , __LINE__ )
#endif

#if defined QUAN_AVR_NO_CPP_STDLIB
 #define static_assert( cond, text) QUAN_STATIC_ASSERT(( cond ) && text);
#endif

#endif

