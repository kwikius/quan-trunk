#ifndef QUAN_OF_ENERGY_PER_AREA_TIME_LENGTH_HPP_INCLUDED
#define QUAN_OF_ENERGY_PER_AREA_TIME_LENGTH_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_energy_per_area_time_length{

        static const char* abstract_quantity_name()
        {
            return "energy divided by area time length";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<-1>, // length
            meta::rational<-3>, // time
            meta::rational<1>, // mass
            meta::rational<0>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_energy_per_area_time_length
        > abstract_quantity;

        typedef  of_energy_per_area_time_length type;

    };

    template<>
    inline
    const char*
    of_energy_per_area_time_length::unprefixed_symbol<char>()
    {
        return "W.m-2.m-1";
    }

    struct non_si_unit_of_energy_per_area_time_length{
    };

}}}//quan::meta::components

#endif
