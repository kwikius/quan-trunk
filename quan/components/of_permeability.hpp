#ifndef QUAN_OF_PERMEABILITY_HPP_INCLUDED
#define QUAN_OF_PERMEABILITY_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_permeability{

        static const char* abstract_quantity_name()
        {
            return "permeability";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 3
        };

        typedef meta::dimension<
            meta::rational<-1>, // length
            meta::rational<1>, // time
            meta::rational<0>, // mass
            meta::rational<0>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_permeability
        > abstract_quantity;

        typedef  of_permeability type;

    };

    template<>
    inline
    const char*
    of_permeability::unprefixed_symbol<char>()
    {
        return "g.Pa-1.s-1.m-2";
    }

    struct non_si_unit_of_permeability{
    };

}}}//quan::meta::components

#endif
