#ifndef QUAN_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
#define QUAN_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
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


#include <quan/components/of_area_moment_of_inertia.hpp>

namespace quan{

    template<
        typename Value_type
    >
    struct area_moment_of_inertia_ : meta::components::of_area_moment_of_inertia{
       
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > m4;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -3 * 4 = -12
            >,
            Value_type
        > mm4;
    };

    struct area_moment_of_inertia 
    : area_moment_of_inertia_<quantity_traits::default_value_type>{};

}//quan

#endif
