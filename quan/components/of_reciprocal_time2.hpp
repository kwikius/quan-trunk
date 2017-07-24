#ifndef QUAN_OF_RECIPROCAL_TIME2_HPP_INCLUDED
#define QUAN_OF_RECIPROCAL_TIME2_HPP_INCLUDED
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
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_reciprocal_time2{

        static const char* abstract_quantity_name()
        {
            return "reciprocal time^2";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = -2,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<0>, // length
            meta::rational<-2>, // time
            meta::rational<0>, // mass
            meta::rational<0>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_reciprocal_time2
        > abstract_quantity;

//        struct non_si_unit{
//            typedef meta::unit<
//                abstract_quantity,
//                meta::conversion_factor<
//                    meta::rational<-2>,
//                    meta::rational<5,3>::type,
//                    quan::meta::int32<0>
//                >
//            > per_min;
//            typedef meta::unit<
//                abstract_quantity,
//                meta::conversion_factor<
//                    meta::rational<-4>,
//                    meta::rational<25,9>::type,
//                    quan::meta::int32<0>
//                >
//            > per_hour;
//        };

        typedef  of_reciprocal_time2 type;

    };

    template<>
    inline
    const char*
    of_reciprocal_time2::unprefixed_symbol<char>()
    {
        return "s-2";
    }

}}}//quan::meta::components

#endif
