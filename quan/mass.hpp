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

   struct of_mass{
         // coherent_exponent :-27 -> N/A
         // coherent_exponent :-26 -> N/A
         // coherent_exponent :-25 -> N/A
      struct zg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
         // coherent_exponent :-23 -> N/A
         // coherent_exponent :-22 -> N/A
      struct ag :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent_exponent -21
      >{};
         // coherent_exponent :-20 -> N/A
         // coherent_exponent :-19 -> N/A
      struct fg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent_exponent -18
      >{};
         // coherent_exponent :-17 -> N/A
         // coherent_exponent :-16 -> N/A
      struct pg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent_exponent -15
      >{};
         // coherent_exponent :-14 -> N/A
         // coherent_exponent :-13 -> N/A
      struct ng :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
         // coherent_exponent :-11 -> N/A
         // coherent_exponent :-10 -> N/A
      struct ug :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent_exponent -9
      >{};
         // coherent_exponent :-8 -> N/A
         // coherent_exponent :-7 -> N/A
      struct mg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent_exponent -6
      >{};
         // coherent_exponent :-5 -> N/A
         // coherent_exponent :-4 -> N/A
      struct g :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent_exponent -3
      >{};
      struct dag :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent_exponent -2
      >{};
      struct hg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent_exponent -1
      >{};
      struct kg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
         // coherent_exponent :1 -> N/A
         // coherent_exponent :2 -> N/A
      struct Mg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent_exponent 3
      >{};
         // coherent_exponent :4 -> N/A
         // coherent_exponent :5 -> N/A
      struct Gg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent_exponent 6
      >{};
         // coherent_exponent :7 -> N/A
         // coherent_exponent :8 -> N/A
      struct Tg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent_exponent 9
      >{};
         // coherent_exponent :10 -> N/A
         // coherent_exponent :11 -> N/A
      struct Pg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
         // coherent_exponent :13 -> N/A
         // coherent_exponent :14 -> N/A
      struct Eg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent_exponent 15
      >{};
         // coherent_exponent :16 -> N/A
         // coherent_exponent :17 -> N/A
      struct Zg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent_exponent 18
      >{};
         // coherent_exponent :19 -> N/A
         // coherent_exponent :20 -> N/A
      struct Yg :  quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         typename quan::meta::si_unit::zetta // coherent_exponent 21
      >{};
         // coherent_exponent :22 -> N/A
         // coherent_exponent :23 -> N/A
         // coherent_exponent :24 -> N/A
         // coherent_exponent :25 -> N/A
         // coherent_exponent :26 -> N/A
         // coherent_exponent :27 -> N/A
   };

    template<
        typename Value_type
    >
    struct mass_ : meta::components::of_mass{

      // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::zg,
         Value_type
      > zg;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::ag,
         Value_type
      > ag;
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::fg,
         Value_type
      > fg;
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::pg,
         Value_type
      > pg;
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::ng,
         Value_type
      > ng;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::ug,
         Value_type
      > ug;
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::mg,
         Value_type
      > mg;
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::g,
         Value_type
      > g;
      typedef quan::fixed_quantity<
         quan::of_mass::dag,
         Value_type
      > dag;
      typedef quan::fixed_quantity<
         quan::of_mass::hg,
         Value_type
      > hg;
      typedef quan::fixed_quantity<
         quan::of_mass::kg,
         Value_type
      > kg;
      // coherent_exponent :1 -> N/A
      // coherent_exponent :2 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::Mg,
         Value_type
      > Mg;
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::Gg,
         Value_type
      > Gg;
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::Tg,
         Value_type
      > Tg;
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::Pg,
         Value_type
      > Pg;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::Eg,
         Value_type
      > Eg;
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::Zg,
         Value_type
      > Zg;
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      typedef quan::fixed_quantity<
         quan::of_mass::Yg,
         Value_type
      > Yg;
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      // coherent_exponent :24 -> N/A
      // coherent_exponent :25 -> N/A
      // coherent_exponent :26 -> N/A
      // coherent_exponent :27 -> N/A


// non si

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
