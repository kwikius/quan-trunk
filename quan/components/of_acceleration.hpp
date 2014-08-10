#ifndef QUAN_OF_ACCELERATION_HPP_INCLUDED
#define QUAN_OF_ACCELERATION_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_acceleration{

        static const char* abstract_quantity_name()
        {
            return "acceleration";
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
            meta::rational<0>, // mass
            meta::rational<0>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_acceleration
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<0>,
                    meta::rational<196133,20000>::type,
                    quan::meta::int32<0>
                >
            > g_s;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<381,125>::type,
                    quan::meta::int32<0>
                >
            > ft_per_s2;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-2>,
                    meta::rational<1,1>::type,
                    quan::meta::int32<1>
                >
            > Gal;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-2>,
                    meta::rational<127,50>::type,
                    quan::meta::int32<0>
                >
            > in_per_s2;
        };

        typedef  of_acceleration type;

    };

    template<>
    inline
    const char*
    of_acceleration::unprefixed_symbol<char>()
    {
        return "m.s-2";
    }

}}}//quan::meta::components
#endif
