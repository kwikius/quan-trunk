#ifndef QUAN_MASS_PER_AREA_HPP_INCLUDED
#define QUAN_MASS_PER_AREA_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_mass_per_area.hpp>

namespace quan{

    template<
        typename Value_type
    >
    struct mass_per_area_ : meta::components::of_mass_per_area{
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-27>
                >
            >,
            Value_type
        > yg;


        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > kg_per_m2;



    };

    struct mass_per_area : mass_per_area_<quantity_traits::default_value_type>{};

}//quan

#endif
