#ifndef QUAN_LENGTH_HPP_INCLUDED
#define QUAN_LENGTH_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005


#include <quan/components/of_length.hpp>

namespace quan{

    template<
        typename Value_type
    >
    struct length_ : meta::components::of_length{
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yocto // coherent-exponent -24
            >,
            Value_type
        > ym;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > zm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > am;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > fm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > pm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > nm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > um;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > mm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > cm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > dm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > m;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > dam;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > hm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > km;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > Mm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > Gm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > Tm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > Pm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > Em;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > Zm;

        typedef fixed_quantity<
            typename non_si_unit::fathom_us,
            Value_type
        > fathom_us;

        typedef fixed_quantity<
            typename non_si_unit::AU,
            Value_type
        > AU;

        typedef fixed_quantity<
            typename non_si_unit::ch,
            Value_type
        > ch;

        typedef fixed_quantity<
            typename non_si_unit::fathom,
            Value_type
        > fathom;

        typedef fixed_quantity<
            typename non_si_unit::ft,
            Value_type
        > ft;

        typedef fixed_quantity<
            typename non_si_unit::ft_us,
            Value_type
        > ft_us;

        typedef fixed_quantity<
            typename non_si_unit::in,
            Value_type
        > in;

        typedef fixed_quantity<
            typename non_si_unit::thou,
            Value_type
        > thou;

        typedef fixed_quantity<
            typename non_si_unit::mil,
            Value_type
        > mil;

        typedef fixed_quantity<
            typename non_si_unit::l_y_,
            Value_type
        > l_y_;

        typedef fixed_quantity<
            typename non_si_unit::mi,
            Value_type
        > mi;

        typedef fixed_quantity<
            typename non_si_unit::naut_mile,
            Value_type
        > naut_mile;

        typedef fixed_quantity<
            typename non_si_unit::pc,
            Value_type
        > pc;

        typedef fixed_quantity<
            typename non_si_unit::pica_comp,
            Value_type
        > pica_comp;

        typedef fixed_quantity<
            typename non_si_unit::pica_prn,
            Value_type
        > pica_prn;

        typedef fixed_quantity<
            typename non_si_unit::point_comp,
            Value_type
        > point_comp;

        typedef fixed_quantity<
            typename non_si_unit::point_prn,
            Value_type
        > point_prn;

        typedef fixed_quantity<
            typename non_si_unit::rd,
            Value_type
        > rd;

        typedef fixed_quantity<
            typename non_si_unit::yd,
            Value_type
        > yd;

        typedef fixed_quantity<
            typename non_si_unit::angstrom,
            Value_type
        > angstrom;

    };

    struct length : length_<quantity_traits::default_value_type>{};

}//quan

#endif
