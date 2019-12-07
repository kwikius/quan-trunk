#ifndef QUAN_OF_SPECIFIC_ENTROPY_HPP_INCLUDED
#define QUAN_OF_SPECIFIC_ENTROPY_HPP_INCLUDED
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

    struct of_specific_entropy{

        static const char* abstract_quantity_name()
        {
            return "specific entropy";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };
#if defined QUAN_META_CUSTOM_DIMENSION
         typedef meta::dimension<
            quan::meta::dim_length<2> 
            ,quan::meta::dim_time<-2> 
            ,quan::meta::dim_temperature<-1> 
         > dimension;
#else
        typedef meta::dimension<
            meta::rational<2>, // length
            meta::rational<-2>, // time
            meta::rational<0>, // mass
            meta::rational<-1>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;
#endif
        typedef meta::abstract_quantity<
            dimension,
            of_specific_entropy
        > abstract_quantity;

        typedef  of_specific_entropy type;

    };

    template<>
    inline
    const char*
    of_specific_entropy::unprefixed_symbol<char>()
    {
        return "J.kg-1.K-1";
    }

    struct non_si_unit_of_specific_entropy{
    };

}}}//quan::meta::components

#endif
