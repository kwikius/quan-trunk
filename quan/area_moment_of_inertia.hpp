#ifndef QUAN_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
#define QUAN_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005


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
