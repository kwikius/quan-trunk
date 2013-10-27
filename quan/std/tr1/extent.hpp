#ifndef QUAN_STD_TR1_EXTENT_HPP_INCLUDED
#define QUAN_STD_TR1_EXTENT_HPP_INCLUDED

#include <quan/config.hpp>

#ifdef QUAN_USE_QUAN_STD_TR1
#include <quan/std/tr1/integral_constant.hpp>
#include <stdint.h>

namespace std{ 

   /// extent
   template<typename T , unsigned int U = 0>
   struct extent : integral_constant<size_t, 0> { };

   template<typename T, unsigned U, size_t N>
   struct extent<T[N], U> : std::integral_constant<size_t, U == 0 ? N : extent<T,U - 1>::value>{};

   template<typename T, unsigned  U>
   struct extent<T[], U>  : integral_constant<size_t, U == 0 ? 0 : extent<T,  U - 1>::value>{};

}

#else
#include <type_traits>
#endif

#endif // QUAN_STD_TR1_EXTENT_HPP_INCLUDED
