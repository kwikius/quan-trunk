#ifndef QUAN_OF_SPECIFIC_ENTROPY_HPP_INCLUDED
#define QUAN_OF_SPECIFIC_ENTROPY_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_specific_entropy{

        static const char* abstract_quantity_name()
        {
            return "specific entropy";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<2>, // length
            meta::rational<-2>, // time
            meta::rational<0>, // mass
            meta::rational<-1>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_specific_entropy
        > abstract_quantity;

        typedef  of_specific_entropy type;

    };

    template<>
    inline
    const char*
    of_specific_entropy::unprefixed_symbol<char>()
    {
        return "J.kg-1.K-1";
    }

    struct non_si_unit_of_specific_entropy{
    };

}}}//quan::meta::components

#endif
