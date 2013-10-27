#ifndef QUAN_STD_TR1_REMOVE_EXTENT_HPP_INCLUDED
#define QUAN_STD_TR1_REMOVE_EXTENT_HPP_INCLUDED

#include <quan/config.hpp>

#ifdef QUAN_USE_QUAN_STD_TR1

#include <quan/std/tr1/integral_constant.hpp>
#include <stdint.h>

namespace std{

   /// remove_extent
   template<typename T>
   struct remove_extent{ typedef T type; };

   template<typename T, size_t N>
   struct remove_extent<T[N]> { typedef T type; };

   template<typename T>
   struct remove_extent<T[]>{ typedef T type; };
}

#else
#include <type_traits>
#endif


#endif // QUAN_STD_TR1_REMOVE_EXTENT_HPP_INCLUDED
