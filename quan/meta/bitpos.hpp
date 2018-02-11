
#ifndef QUAN_META_BITPOS_HPP_INCLUDED
#define QUAN_META_BITPOS_HPP_INCLUDED
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

#include <quan/config.hpp>
#include <quan/meta/uint32.hpp>

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cstdint>
#else
#include <stdint.h>
#endif

namespace quan{namespace meta{

        template <uint32_t Value> struct bitpos;
        
        #define QUAN_FUN(N) template<> struct bitpos<(static_cast<uint32_t>(1) << static_cast<uint32_t>(N))> : quan::meta::uint32<N>{};

        QUAN_FUN(0)
        QUAN_FUN(1)
        QUAN_FUN(2)
        QUAN_FUN(3)
        QUAN_FUN(4)
        QUAN_FUN(5)
        QUAN_FUN(6)
        QUAN_FUN(7)
        QUAN_FUN(8)
        QUAN_FUN(9)
        QUAN_FUN(10)
        QUAN_FUN(11)
        QUAN_FUN(12)
        QUAN_FUN(13)
        QUAN_FUN(14)
        QUAN_FUN(15)
        QUAN_FUN(16)
        QUAN_FUN(17)
        QUAN_FUN(18)
        QUAN_FUN(19)
        QUAN_FUN(20)
        QUAN_FUN(21)
        QUAN_FUN(22)
        QUAN_FUN(23)
        QUAN_FUN(24)
        QUAN_FUN(25)
        QUAN_FUN(26)
        QUAN_FUN(27)
        QUAN_FUN(28)
        QUAN_FUN(29)
        QUAN_FUN(30)
        QUAN_FUN(31)

        #undef QUAN_FUN
}}

#endif
