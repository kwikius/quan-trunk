#ifndef QUAN_META_UINT32_HPP_INCLUDED
#define QUAN_META_UINT32_HPP_INCLUDED

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

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
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
