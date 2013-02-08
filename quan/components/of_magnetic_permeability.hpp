#ifndef QUAN_OF_MAGNETIC_PERMEABILITY_HPP_INCLUDED
#define QUAN_OF_MAGNETIC_PERMEABILITY_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_magnetic_permeability{

        static const char* abstract_quantity_name()
        {
            return "magnetic permeability";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<1>, // length
            meta::rational<-2>, // time
            meta::rational<1>, // mass
            meta::rational<0>, // temperature
            meta::rational<-2>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_magnetic_permeability
        > abstract_quantity;

        struct non_si_unit{
        };

        typedef  of_magnetic_permeability type;

    };

    template<>
    inline
    const char*
    of_magnetic_permeability::unprefixed_symbol<char>()
    {
        return "H.m-1";
    }

}}}//quan::meta::components
#endif
