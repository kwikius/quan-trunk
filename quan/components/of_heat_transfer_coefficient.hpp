#ifndef QUAN_OF_HEAT_TRANSFER_COEFFICIENT_HPP_INCLUDED
#define QUAN_OF_HEAT_TRANSFER_COEFFICIENT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_heat_transfer_coefficient{

        static const char* abstract_quantity_name()
        {
            return "heat transfer coefficient";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<0>, // length
            meta::rational<-3>, // time
            meta::rational<1>, // mass
            meta::rational<-1>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_heat_transfer_coefficient
        > abstract_quantity;

        typedef  of_heat_transfer_coefficient type;

    };

    template<>
    inline
    const char*
    of_heat_transfer_coefficient::unprefixed_symbol<char>()
    {
        return "W.m-2.K-1";
    }

    struct non_si_unit_of_heat_transfer_coefficient{
    };

}}}//quan::meta::components

#endif
