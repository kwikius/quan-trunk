#ifndef QUAN_VOLUME_HPP_INCLUDED
#define QUAN_VOLUME_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_volume.hpp>

namespace quan{

    template<
        typename Value_type
    >
    struct volume_ : meta::components::of_volume{
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-54>
                >
            >,
            Value_type
        > am3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-45>
                >
            >,
            Value_type
        > fm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-36>
                >
            >,
            Value_type
        > pm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-27>
                >
            >,
            Value_type
        > nm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > um3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > mm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > cm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > dm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > dam3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > hm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > km3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > Mm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<27>
                >
            >,
            Value_type
        > Gm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<36>
                >
            >,
            Value_type
        > Tm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<45>
                >
            >,
            Value_type
        > Pm3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<54>
                >
            >,
            Value_type
        > Em3;

        typedef fixed_quantity<
            typename non_si_unit::acre_foot,
            Value_type
        > acre_foot;

        typedef fixed_quantity<
            typename non_si_unit::bbl,
            Value_type
        > bbl;

        typedef fixed_quantity<
            typename non_si_unit::bu,
            Value_type
        > bu;

        typedef fixed_quantity<
            typename non_si_unit::cord,
            Value_type
        > cord;

        typedef fixed_quantity<
            typename non_si_unit::ft3,
            Value_type
        > ft3;

        typedef fixed_quantity<
            typename non_si_unit::in3,
            Value_type
        > in3;

        typedef fixed_quantity<
            typename non_si_unit::mi3,
            Value_type
        > mi3;

        typedef fixed_quantity<
            typename non_si_unit::yd3,
            Value_type
        > yd3;

        typedef fixed_quantity<
            typename non_si_unit::cup,
            Value_type
        > cup;

        typedef fixed_quantity<
            typename non_si_unit::fl_oz_US,
            Value_type
        > fl_oz_US;

        typedef fixed_quantity<
            typename non_si_unit::gal,
            Value_type
        > gal;

        typedef fixed_quantity<
            typename non_si_unit::gal_US,
            Value_type
        > gal_US;

    };

    struct volume : volume_<quantity_traits::default_value_type>{};

}//quan

#endif
