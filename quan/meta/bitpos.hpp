
#ifndef QUAN_META_BITPOS_HPP_INCLUDED
#define QUAN_META_BITPOS_HPP_INCLUDED

#include <quan/config.hpp>
#include <quan/meta/uint32.hpp>
#include <cstdint>

namespace quan{namespace meta{

        template <uint32_t Value> struct bitpos;
        
        #define QUAN_FUN(N) template<> struct bitpos<(1 << N)> : quan::meta::uint32<N>{};

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
