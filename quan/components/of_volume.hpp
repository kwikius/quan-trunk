#ifndef QUAN_OF_VOLUME_HPP_INCLUDED
#define QUAN_OF_VOLUME_HPP_INCLUDED
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

    struct of_volume{

        static const char* abstract_quantity_name()
        {
            return "volume";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 3,
            prefix_offset = 0
        };

         typedef meta::dimension<
            quan::meta::dim_length<3> 
         > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_volume
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<1233489,1000000>::type,
                    quan::meta::int32<0>
                >
            > acre_foot;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<1589873,1000000>::type,
                    quan::meta::int32<0>
                >
            > bbl;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<2>,
                    meta::rational<3523907,1000000>::type,
                    quan::meta::int32<0>
                >
            > bu;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<906139,250000>::type,
                    quan::meta::int32<0>
                >
            > cord;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-2>,
                    meta::rational<566337,200000>::type,
                    quan::meta::int32<0>
                >
            > ft3;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-5>,
                    meta::rational<819353,500000>::type,
                    quan::meta::int32<0>
                >
            > in3;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<9>,
                    meta::rational<2084091,500000>::type,
                    quan::meta::int32<0>
                >
            > mi3;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<7645549,1000000>::type,
                    quan::meta::int32<0>
                >
            > yd3;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-4>,
                    meta::rational<1182941,500000>::type,
                    quan::meta::int32<0>
                >
            > cup;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-5>,
                    meta::rational<2957353,1000000>::type,
                    quan::meta::int32<0>
                >
            > fl_oz_US;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-3>,
                    meta::rational<454609,100000>::type,
                    quan::meta::int32<0>
                >
            > gal;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-3>,
                    meta::rational<946353,250000>::type,
                    quan::meta::int32<0>
                >
            > gal_US;
        };

        typedef  of_volume type;

    };

    template<>
    inline
    const char*
    of_volume::unprefixed_symbol<char>()
    {
        return "m3";
    }

}}}//quan::meta::components
#endif
