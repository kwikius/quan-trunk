#ifndef QUAN_STD_TR1_RANK_HPP_INCLUDED
#define QUAN_STD_TR1_RANK_HPP_INCLUDED

#include <quan/config.hpp>

#ifdef QUAN_USE_QUAN_STD_TR1

#include <quan/std/tr1/integral_constant.hpp>
#include <stdint.h>

namespace std{

   template <typename T>
   struct rank : std::integral_constant<size_t, 0> {};

   template <typename T, size_t N>
   struct rank<T[N]> : std::integral_constant<size_t, 1 + rank<T>::value>{};

   template <typename T>
   struct rank<T[]> : std::integral_constant<size_t, 1 + rank<T>::value>{};
}

#else

#include <type_traits>

#endif

#endif // QUAN_STD_TR1_RANK_HPP_INCLUDED
