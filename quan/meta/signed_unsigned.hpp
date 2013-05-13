#ifndef QUAN_META_SIGNED_UNSIGNED_HPP_INCLUDED
#define QUAN_META_SIGNED_UNSIGNED_HPP_INCLUDED

// Copyright Andrew Little 2006-2007

#include <quan/undefined.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/eval_if.hpp>
#if defined __AVR__
#include <quan/std/tr1/is_signed.hpp>
#include <quan/std/tr1/is_unsigned.hpp>
#else
#include <type_traits>
#endif
#include <quan/meta/identity.hpp>

namespace quan{ namespace meta{

   template < typename T>
   struct signed_to_unsigned;

   template<> struct signed_to_unsigned<signed char> {typedef unsigned char type;};
   template<> struct signed_to_unsigned<short> {typedef unsigned short type;};
   template<> struct signed_to_unsigned<int> {typedef unsigned int type;};
   template<> struct signed_to_unsigned<long> {typedef unsigned long type;};
#if (defined QUAN_HAS_LONG_LONG)
   template<> struct signed_to_unsigned<long long> {typedef unsigned long long type;};
#endif

   template < typename T>
   struct unsigned_to_signed;

   template<> struct unsigned_to_signed<unsigned char> {typedef signed char type;};
   template<> struct unsigned_to_signed<unsigned short> {typedef short type;};
   template<> struct unsigned_to_signed<unsigned int> {typedef int type;};
   template<> struct unsigned_to_signed<unsigned long> {typedef long type;};
#if (defined QUAN_HAS_LONG_LONG)
   template<> struct unsigned_to_signed<unsigned long long> {typedef long long type;};
#endif

   template <typename I>
   struct to_unsigned : quan::meta::eval_if<
      std::is_signed<I>,
      signed_to_unsigned<I>,
      quan::meta::if_<
         std::is_unsigned<I>,
         I,
         quan::undefined
      >
   >{};

   template <typename I>
   struct to_signed : quan::meta::eval_if<
      std::is_unsigned<I>,
      unsigned_to_signed<I>,
      quan::meta::if_<
         std::is_signed<I>,
         I,
         quan::undefined
      >
   >{};

}}//quan::meta


#endif

