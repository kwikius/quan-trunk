#ifndef QUAN_OF_TIME_HPP_INCLUDED
#define QUAN_OF_TIME_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

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

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_time{

        static const char* abstract_quantity_name()
        {
            return "time";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

         typedef meta::dimension<
            quan::meta::dim_time<1> 
         > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_time
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>,
                    meta::rational<216,25>::type,
                    quan::meta::int32<0>
                >
            > d;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>,
                    meta::rational<8616409,1000000>::type,
                    quan::meta::int32<0>
                >
            > d_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<18,5>::type,
                    quan::meta::int32<0>
                >
            > h;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<359017,100000>::type,
                    quan::meta::int32<0>
                >
            > h_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<6,1>::type,
                    quan::meta::int32<0>
                >
            > min;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<5983617,1000000>::type,
                    quan::meta::int32<0>
                >
            > min_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<1246587,125000>::type,
                    quan::meta::int32<0>
                >
            > s_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<5>,
                    meta::rational<756,125>::type,
                    quan::meta::int32<0>
                >
            > wk;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<7>,
                    meta::rational<1971,625>::type,
                    quan::meta::int32<0>
                >
            > yr;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<7>,
                    meta::rational<631163,200000>::type,
                    quan::meta::int32<0>
                >
            > yr_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<7>,
                    meta::rational<3155693,1000000>::type,
                    quan::meta::int32<0>
                >
            > yr_trop;
        };

        typedef  of_time type;

    };

    template<>
    inline
    const char*
    of_time::unprefixed_symbol<char>()
    {
        return "s";
    }

}}}//quan::meta::components
#endif
