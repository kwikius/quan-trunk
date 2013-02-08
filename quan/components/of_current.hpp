#ifndef QUAN_OF_CURRENT_HPP_INCLUDED
#define QUAN_OF_CURRENT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_current{

        static const char* abstract_quantity_name()
        {
            return "current";
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
            meta::rational<0>, // temperature
            meta::rational<1>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_current
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > abampere;
        };

        typedef  of_current type;

    };

    template<>
    inline
    const char*
    of_current::unprefixed_symbol<char>()
    {
        return "A";
    }

}}}//quan::meta::components
#endif
