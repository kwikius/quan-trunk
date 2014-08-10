#ifndef QUAN_OF_TEMPERATURE_HPP_INCLUDED
#define QUAN_OF_TEMPERATURE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_temperature{

        static const char* abstract_quantity_name()
        {
            return "temperature";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<0>, // length
            meta::rational<0>, // time
            meta::rational<0>, // mass
            meta::rational<1>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_temperature
        > abstract_quantity;

        struct non_si_unit{
        };

        typedef  of_temperature type;

    };

    template<>
    inline
    const char*
    of_temperature::unprefixed_symbol<char>()
    {
        return "K";
    }

}}}//quan::meta::components
#endif
