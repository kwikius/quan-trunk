#ifndef QUAN_AREA_HPP_INCLUDED
#define QUAN_AREA_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_area.hpp>

namespace quan{

    template<
        typename Value_type
    >
    struct area_ : meta::components::of_area{
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-48>
                >
            >,
            Value_type
        > ym2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-42>
                >
            >,
            Value_type
        > zm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-36>
                >
            >,
            Value_type
        > am2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-30>
                >
            >,
            Value_type
        > fm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yocto // coherent-exponent -24
            >,
            Value_type
        > pm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > nm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > um2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > mm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-4>
                >
            >,
            Value_type
        > cm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > dm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > m2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > dam2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>
                >
            >,
            Value_type
        > hm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > km2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > Mm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > Gm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yotta // coherent-exponent 24
            >,
            Value_type
        > Tm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<30>
                >
            >,
            Value_type
        > Pm2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<36>
                >
            >,
            Value_type
        > Em2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<42>
                >
            >,
            Value_type
        > Zm2;

        typedef fixed_quantity<
            typename non_si_unit::acre,
            Value_type
        > acre;

        typedef fixed_quantity<
            typename non_si_unit::a,
            Value_type
        > a;

        typedef fixed_quantity<
            typename non_si_unit::b,
            Value_type
        > b;

        typedef fixed_quantity<
            typename non_si_unit::circular_mil,
            Value_type
        > circular_mil;

        typedef fixed_quantity<
            typename non_si_unit::ha,
            Value_type
        > ha;

        typedef fixed_quantity<
            typename non_si_unit::ft2,
            Value_type
        > ft2;

        typedef fixed_quantity<
            typename non_si_unit::in2,
            Value_type
        > in2;

        typedef fixed_quantity<
            typename non_si_unit::mi2,
            Value_type
        > mi2;

        typedef fixed_quantity<
            typename non_si_unit::mi2_us_survey,
            Value_type
        > mi2_us_survey;

        typedef fixed_quantity<
            typename non_si_unit::yd2,
            Value_type
        > yd2;

    };

    struct area : area_<quantity_traits::default_value_type>{};

}//quan

#endif
