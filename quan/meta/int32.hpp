#ifndef QUAN_META_INT32_HPP_INCLUDED
#define QUAN_META_INT32_HPP_INCLUDED

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <type_traits>
#if defined __AVR__
   #include <stdint.h>
#else
#include <cstdint>
#endif

namespace quan{namespace meta{

   template <int32_t N>
   struct int32 : std::integral_constant<int32_t,N>{};
}}

#endif
