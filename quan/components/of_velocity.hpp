#ifndef QUAN_OF_VELOCITY_HPP_INCLUDED
#define QUAN_OF_VELOCITY_HPP_INCLUDED
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

    struct of_velocity{

        static const char* abstract_quantity_name()
        {
            return "velocity";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

         typedef meta::dimension<
            quan::meta::dim_length<1> 
            ,quan::meta::dim_time<-1> 
         > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_velocity
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-5>,
                    meta::rational<8466667,1000000>::type,
                    quan::meta::int32<0>
                >
            > ft_per_h;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-3>,
                    meta::rational<127,25>::type,
                    quan::meta::int32<0>
                >
            > ft_per_min;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<381,125>::type,
                    quan::meta::int32<0>
                >
            > ft_per_s;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-2>,
                    meta::rational<127,50>::type,
                    quan::meta::int32<0>
                >
            > in_per_s;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<1388889,500000>::type,
                    quan::meta::int32<0>
                >
            > km_per_h;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<1286111,250000>::type,
                    quan::meta::int32<0>
                >
            > knot;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<2794,625>::type,
                    quan::meta::int32<0>
                >
            > mi_per_h;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<8382,3125>::type,
                    quan::meta::int32<0>
                >
            > mi_per_min;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<25146,15625>::type,
                    quan::meta::int32<0>
                >
            > mi_per_s;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-5>,
                    meta::rational<1666667,1000000>::type,
                    quan::meta::int32<0>
                >
            > mm_per_min;
        };

        typedef  of_velocity type;

    };

    template<>
    inline
    const char*
    of_velocity::unprefixed_symbol<char>()
    {
        return "m.s-1";
    }

}}}//quan::meta::components
#endif
