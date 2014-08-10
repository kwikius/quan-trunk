#ifndef QUAN_OF_CHARGE_HPP_INCLUDED
#define QUAN_OF_CHARGE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_charge{

        static const char* abstract_quantity_name()
        {
            return "charge";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };
//{0,1,0,0,1}
        typedef meta::dimension<
            meta::rational<0>, // length
            meta::rational<1>, // time
            meta::rational<0>, // mass
            meta::rational<0>, // temperature
            meta::rational<1>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_charge
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<18,5>::type,
                    quan::meta::int32<0>
                >
            > A_h;

             typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<18,5>::type,
                    quan::meta::int32<0>
                >
            > mA_h;
            
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > abcoulomb;
        };

        typedef  of_charge type;

    };

    template<>
    inline
    const char*
    of_charge::unprefixed_symbol<char>()
    {
        return "C";
    }

}}}//quan::meta::components
#endif
