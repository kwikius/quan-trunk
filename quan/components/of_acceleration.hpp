#ifndef QUAN_OF_ACCELERATION_HPP_INCLUDED
#define QUAN_OF_ACCELERATION_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

/*
 Copyright (c) 2003-2019 Andy Little.

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

    struct of_acceleration{

        static const char* abstract_quantity_name()
        {
            return "acceleration";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

       typedef meta::dimension<
            quan::meta::dim_length<1>
            ,quan::meta::dim_time<-2>
       > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_acceleration
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<0>
                >
            > g_s;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<381,125>::type,
                    quan::meta::int32<0>
                >
            > ft_per_s2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-2>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > Gal;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-2>,
                    meta::rational<127,50>::type,
                    quan::meta::int32<0>
                >
            > in_per_s2;
        };

        typedef  of_acceleration type;

    };

    template<>
    inline
    const char*
    of_acceleration::unprefixed_symbol<char>()
    {
        return "m.s-2";
    }

}}}//quan::meta::components
#endif
