#ifndef QUAN_PRESSURE_HPP_INCLUDED
#define QUAN_PRESSURE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_pressure.hpp>

namespace quan{

    template<
        typename Value_type
    >
    struct pressure_ : meta::components::of_pressure{
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yocto // coherent-exponent -24
            >,
            Value_type
        > yPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > zPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > aPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > fPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > pPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > nPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > uPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > mPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > cPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > dPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > Pa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > daPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > hPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > kPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > MPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > GPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > TPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > PPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > EPa;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > ZPa;

        typedef fixed_quantity<
            typename non_si_unit::atm,
            Value_type
        > atm;

        typedef fixed_quantity<
            typename non_si_unit::at,
            Value_type
        > at;

        typedef fixed_quantity<
            typename non_si_unit::bar,
            Value_type
        > bar;

        typedef fixed_quantity<
            typename non_si_unit::cm_mercury0C,
            Value_type
        > cm_mercury0C;

        typedef fixed_quantity<
            typename non_si_unit::cmHg,
            Value_type
        > cmHg;

        typedef fixed_quantity<
            typename non_si_unit::cm_water4C,
            Value_type
        > cm_water4C;

        typedef fixed_quantity<
            typename non_si_unit::cmH20,
            Value_type
        > cmH20;

        typedef fixed_quantity<
            typename non_si_unit::dyn_per_cm2,
            Value_type
        > dyn_per_cm2;

        typedef fixed_quantity<
            typename non_si_unit::ftHg,
            Value_type
        > ftHg;

        typedef fixed_quantity<
            typename non_si_unit::ft_water39_2F,
            Value_type
        > ft_water39_2F;

        typedef fixed_quantity<
            typename non_si_unit::ftH20,
            Value_type
        > ftH20;

        typedef fixed_quantity<
            typename non_si_unit::gf_per_cm2,
            Value_type
        > gf_per_cm2;

        typedef fixed_quantity<
            typename non_si_unit::in_mercury32F,
            Value_type
        > in_mercury32F;

        typedef fixed_quantity<
            typename non_si_unit::in_mercury60F,
            Value_type
        > in_mercury60F;

        typedef fixed_quantity<
            typename non_si_unit::inHg,
            Value_type
        > inHg;

        typedef fixed_quantity<
            typename non_si_unit::in_water39_2F,
            Value_type
        > in_water39_2F;

        typedef fixed_quantity<
            typename non_si_unit::inH20,
            Value_type
        > inH20;

        typedef fixed_quantity<
            typename non_si_unit::kgf_per_cm2,
            Value_type
        > kgf_per_cm2;

        typedef fixed_quantity<
            typename non_si_unit::kgf_per_m2,
            Value_type
        > kgf_per_m2;

        typedef fixed_quantity<
            typename non_si_unit::kgf_per_mm2,
            Value_type
        > kgf_per_mm2;

        typedef fixed_quantity<
            typename non_si_unit::ksi,
            Value_type
        > ksi;

        typedef fixed_quantity<
            typename non_si_unit::mbar,
            Value_type
        > mbar;

        typedef fixed_quantity<
            typename non_si_unit::mmHg,
            Value_type
        > mmHg;

        typedef fixed_quantity<
            typename non_si_unit::mmH20,
            Value_type
        > mmH20;

        typedef fixed_quantity<
            typename non_si_unit::lbf_per_ft2,
            Value_type
        > lbf_per_ft2;

        typedef fixed_quantity<
            typename non_si_unit::psi,
            Value_type
        > psi;

        typedef fixed_quantity<
            typename non_si_unit::poundal_per_ft2,
            Value_type
        > poundal_per_ft2;

        typedef fixed_quantity<
            typename non_si_unit::torr,
            Value_type
        > torr;

    };

    struct pressure : pressure_<quantity_traits::default_value_type>{};

}//quan

#endif
