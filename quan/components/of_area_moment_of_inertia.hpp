#ifndef QUAN_OF_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
#define QUAN_OF_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
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
#include <quan/meta/name_anonymous_abstract_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_area_moment_of_inertia{

        static const char* abstract_quantity_name()
        {
            return "area_moment_of_inertia";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 4,
            prefix_offset = 0
        };

       typedef meta::dimension<
            quan::meta::dim_length<4> 
       > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_area_moment_of_inertia
        > abstract_quantity;

        typedef  of_area_moment_of_inertia type;
    };
 
    template<>
    inline
    const char*
    of_area_moment_of_inertia::unprefixed_symbol<char>()
    {
        return "m4";
    }

}//components

#ifdef QUAN_ENABLE_SELECTED_HOISTED_QUANTITIES
// enable hoisting of anonymous length
   template<>
   struct name_anonymous_abstract_quantity<
      abstract_quantity<
         quan::meta::components::of_area_moment_of_inertia::dimension,
         quan::meta::anonymous_quantity_traits
      >
   >{
      typedef components::of_area_moment_of_inertia::abstract_quantity type;
   };
#endif

}}//quan::meta

#endif
