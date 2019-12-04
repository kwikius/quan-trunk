#ifndef QUAN_DENSITY_HPP_INCLUDED
#define QUAN_DENSITY_HPP_INCLUDED
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

#include <quan/components/of_density.hpp>

namespace quan{


   struct of_density{
      // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      struct zg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      struct ag_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent_exponent -21
      >{};
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      struct fg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent_exponent -18
      >{};
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      struct pg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent_exponent -15
      >{};
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      struct ng_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      struct ug_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent_exponent -9
      >{};
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      struct mg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent_exponent -6
      >{};
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      struct g_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent_exponent -3
      >{};
      struct dag_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent_exponent -2
      >{};
      struct hg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent_exponent -1
      >{};
      struct kg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
      // coherent_exponent :1 -> N/A
      // coherent_exponent :2 -> N/A
      struct Mg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent_exponent 3
      >{};
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      struct Gg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent_exponent 6
      >{};
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      struct Tg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent_exponent 9
      >{};
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      struct Pg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      struct Eg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent_exponent 15
      >{};
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      struct Zg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent_exponent 18
      >{};
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      struct Yg_per_m3:  quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
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
    struct density_ : meta::components::of_density{

#if 1
      // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::zg_per_m3,
         Value_type
      > zg_per_m3;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::ag_per_m3,
         Value_type
      > ag_per_m3;
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::fg_per_m3,
         Value_type
      > fg_per_m3;
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::pg_per_m3,
         Value_type
      > pg_per_m3;
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::ng_per_m3,
         Value_type
      > ng_per_m3;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::ug_per_m3,
         Value_type
      > ug_per_m3;
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::mg_per_m3,
         Value_type
      > mg_per_m3;
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::g_per_m3,
         Value_type
      > g_per_m3;
      typedef quan::fixed_quantity<
         quan::of_density::dag_per_m3,
         Value_type
      > dag_per_m3;
      typedef quan::fixed_quantity<
         quan::of_density::hg_per_m3,
         Value_type
      > hg_per_m3;
      typedef quan::fixed_quantity<
         quan::of_density::kg_per_m3,
         Value_type
      > kg_per_m3;
      // coherent_exponent :1 -> N/A
      // coherent_exponent :2 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::Mg_per_m3,
         Value_type
      > Mg_per_m3;
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::Gg_per_m3,
         Value_type
      > Gg_per_m3;
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::Tg_per_m3,
         Value_type
      > Tg_per_m3;
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::Pg_per_m3,
         Value_type
      > Pg_per_m3;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::Eg_per_m3,
         Value_type
      > Eg_per_m3;
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::Zg_per_m3,
         Value_type
      > Zg_per_m3;
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      typedef quan::fixed_quantity<
         quan::of_density::Yg_per_m3,
         Value_type
      > Yg_per_m3;
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      // coherent_exponent :24 -> N/A
      // coherent_exponent :25 -> N/A
      // coherent_exponent :26 -> N/A
      // coherent_exponent :27 -> N/A
#else

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-27>
                >
            >,
            Value_type
        > yg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yocto // coherent-exponent -24
            >,
            Value_type
        > zg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > ag_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > fg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > pg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > ng_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > ug_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > mg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-5>
                >
            >,
            Value_type
        > cg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<-4>
                >
            >,
            Value_type
        > dg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > g_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > dag_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > hg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > kg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > Mg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > Gg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > Tg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > Pg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > Eg_per_m3;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > Zg_per_m3;
#endif

    };

    struct density : density_<quantity_traits::default_value_type>{};

}//quan

#endif
