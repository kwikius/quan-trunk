#ifndef QUAN_STD_TR1_IS_ARRAY_HPP_INCLUDED
#define QUAN_STD_TR1_IS_ARRAY_HPP_INCLUDED

#include <quan/config.hpp>

#ifdef QUAN_USE_QUAN_STD_TR1

#include <quan/std/tr1/integral_constant.hpp>
#include <stdint.h>

namespace std{ 

   template < typename T>
   struct is_array : std::false_type{};

   template<typename T, size_t N>
   struct is_array<T[N]> : std::true_type{};

   template<typename T>
   struct is_array<T[]> : std::true_type{};

}

#else
#include <type_traits>
#endif

#endif // QUAN_STD_TR1_IS_ARRAY_HPP_INCLUDED
