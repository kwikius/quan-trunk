#ifndef QUAN_OF_TIME_HPP_INCLUDED
#define QUAN_OF_TIME_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_named_quantity.hpp>

namespace quan{ namespace meta{ namespace components{

    struct of_time{

        static const char* abstract_quantity_name()
        {
            return "time";
        }

        template<typename CharType>
        static const CharType* unprefixed_symbol();

        enum{
            extent = 1,
            prefix_offset = 0
        };

        typedef meta::dimension<
            meta::rational<0>, // length
            meta::rational<1>, // time
            meta::rational<0>, // mass
            meta::rational<0>, // temperature
            meta::rational<0>, // current
            meta::rational<0>, // substance
            meta::rational<0> // intensity
        > dimension;

        typedef meta::abstract_quantity<
            dimension,
            of_time
        > abstract_quantity;

        struct non_si_unit{
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>,
                    meta::rational<216,25>::type,
                    quan::meta::int32<0>
                >
            > d;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>,
                    meta::rational<8616409,1000000>::type,
                    quan::meta::int32<0>
                >
            > d_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<18,5>::type,
                    quan::meta::int32<0>
                >
            > h;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<3>,
                    meta::rational<359017,100000>::type,
                    quan::meta::int32<0>
                >
            > h_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<6,1>::type,
                    quan::meta::int32<0>
                >
            > min;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<1>,
                    meta::rational<5983617,1000000>::type,
                    quan::meta::int32<0>
                >
            > min_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-1>,
                    meta::rational<1246587,125000>::type,
                    quan::meta::int32<0>
                >
            > s_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<5>,
                    meta::rational<756,125>::type,
                    quan::meta::int32<0>
                >
            > wk;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<7>,
                    meta::rational<1971,625>::type,
                    quan::meta::int32<0>
                >
            > yr;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<7>,
                    meta::rational<631163,200000>::type,
                    quan::meta::int32<0>
                >
            > yr_sid;
            typedef meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<7>,
                    meta::rational<3155693,1000000>::type,
                    quan::meta::int32<0>
                >
            > yr_trop;
        };

        typedef  of_time type;

    };

    template<>
    inline
    const char*
    of_time::unprefixed_symbol<char>()
    {
        return "s";
    }

}}}//quan::meta::components
#endif
