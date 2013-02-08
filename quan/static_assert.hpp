#ifndef QUAN_STATIC_ASSERT_HPP_INCLUDED
#define QUAN_STATIC_ASSERT_HPP_INCLUDED

// Copyright Andrew Little 2005-2007

#include <type_traits>
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

#if defined __AVR__
 #define static_assert( cond, text) QUAN_STATIC_ASSERT(( cond ) && text);
#endif

#endif

