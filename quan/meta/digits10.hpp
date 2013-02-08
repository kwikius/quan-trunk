#ifndef QUAN_META_DIGITS_10_HPP_INCLUDED
#define QUAN_META_DIGITS_10_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005


#include <quan/config.hpp>
#include <quan/meta/numdigits.hpp>
#include <type_traits>
#include <quan/where.hpp>
#ifndef __AVR__
#include <cfloat>
#else
#include <float.h>
#endif
namespace quan{ namespace meta{

 template <typename I, typename Where = void> struct digits10{};

 template<typename I> struct digits10
   <I,typename quan::where_<std::is_integral<I> >::type>{

   static const int value = (static_cast<QUAN_INT32>(quan::meta::numdigits<I>::value) * 643 )/ 2136; 
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
