#ifndef QUAN_OF_RECIPROCAL_MASS_HPP_INCLUDED
#define QUAN_OF_RECIPROCAL_MASS_HPP_INCLUDED
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

    struct of_reciprocal_mass{

        static const char* abstract_quantity_name()
        {
            return "reciprocal mass";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = -1,
            prefix_offset = 3
        };

         typedef meta::dimension< 
            quan::meta::dim_mass<-1> 
         > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_reciprocal_mass
        > abstract_quantity;

        struct non_si_unit{
        };

        typedef  of_reciprocal_mass type;

    };

    template<>
    inline
    const char*
    of_reciprocal_mass::unprefixed_symbol<char>()
    {
        return "g-1";
    }

}}}//quan::meta::components
#endif
