#ifndef QUAN_MASS_HPP_INCLUDED
#define QUAN_MASS_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_mass.hpp>

namespace quan{

    template<
        typename Value_type
    >
    struct mass_ : meta::components::of_mass{
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-27>
                >
            >,
            Value_type
        > yg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yocto // coherent-exponent -24
            >,
            Value_type
        > zg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > ag;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > fg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > pg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > ng;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > ug;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > mg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-5>
                >
            >,
            Value_type
        > cg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-4>
                >
            >,
            Value_type
        > dg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > g;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > dag;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > hg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > kg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > Mg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > Gg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > Tg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > Pg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > Eg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > Zg;

        typedef fixed_quantity<
            typename non_si_unit::AT,
            Value_type
        > AT;

        typedef fixed_quantity<
            typename non_si_unit::ton_long,
            Value_type
        > ton_long;

        typedef fixed_quantity<
            typename non_si_unit::t,
            Value_type
        > t;

        typedef fixed_quantity<
            typename non_si_unit::carat,
            Value_type
        > carat;

        typedef fixed_quantity<
            typename non_si_unit::grain,
            Value_type
        > grain;

        typedef fixed_quantity<
            typename non_si_unit::hundredwgt_short,
            Value_type
        > hundredwgt_short;

        typedef fixed_quantity<
            typename non_si_unit::hundredwgt_long,
            Value_type
        > hundredwgt_long;

        typedef fixed_quantity<
            typename non_si_unit::oz,
            Value_type
        > oz;

        typedef fixed_quantity<
            typename non_si_unit::troy_oz,
            Value_type
        > troy_oz;

        typedef fixed_quantity<
            typename non_si_unit::dwt,
            Value_type
        > dwt;

        typedef fixed_quantity<
            typename non_si_unit::lb,
            Value_type
        > lb;

        typedef fixed_quantity<
            typename non_si_unit::troy_lb,
            Value_type
        > troy_lb;

        typedef fixed_quantity<
            typename non_si_unit::slug,
            Value_type
        > slug;

    };

    struct mass : mass_<quantity_traits::default_value_type>{};

}//quan

#endif
