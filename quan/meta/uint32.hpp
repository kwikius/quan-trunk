#ifndef QUAN_META_UINT32_HPP_INCLUDED
#define QUAN_META_UINT32_HPP_INCLUDED

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#ifndef __AVR__
#include <type_traits>
#include <cstdint>
#else
#include <stdint.h>
#include <quan/std/tr1/integral_constant.hpp>
#endif

namespace quan{namespace meta{

   template <uint32_t N>
   struct uint32 : std::integral_constant<uint32_t,N>{};

}}

#endif
