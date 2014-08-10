#ifndef QUAN_OF_VOLTAGE_HPP_INCLUDED
#define QUAN_OF_VOLTAGE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_voltage{

        static const char* abstract_quantity_name()
        {
            return "voltage";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<2>, // length
            meta::rational<-3>, // time
            meta::rational<1>, // mass
            meta::rational<0>, // temperature
            meta::rational<-1>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_voltage
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-8>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > abvolt;
        };

        typedef  of_voltage type;

    };

    template<>
    inline
    const char*
    of_voltage::unprefixed_symbol<char>()
    {
        return "V";
    }

}}}//quan::meta::components
#endif
