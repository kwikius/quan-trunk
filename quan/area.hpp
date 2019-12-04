#ifndef QUAN_AREA_HPP_INCLUDED
#define QUAN_AREA_HPP_INCLUDED
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

#include <quan/components/of_area.hpp>

namespace quan{

   struct of_area{
         // coherent_exponent :-27 -> N/A
         // coherent_exponent :-26 -> N/A
         // coherent_exponent :-25 -> N/A
      struct pm2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
         // coherent_exponent :-23 -> N/A
         // coherent_exponent :-22 -> N/A
         // coherent_exponent :-21 -> N/A
         // coherent_exponent :-20 -> N/A
         // coherent_exponent :-19 -> N/A
      struct nm2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent_exponent -18
      >{};
         // coherent_exponent :-17 -> N/A
         // coherent_exponent :-16 -> N/A
         // coherent_exponent :-15 -> N/A
         // coherent_exponent :-14 -> N/A
         // coherent_exponent :-13 -> N/A
      struct um2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
         // coherent_exponent :-11 -> N/A
         // coherent_exponent :-10 -> N/A
         // coherent_exponent :-9 -> N/A
         // coherent_exponent :-8 -> N/A
         // coherent_exponent :-7 -> N/A
      struct mm2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent_exponent -6
      >{};
         // coherent_exponent :-5 -> N/A
         // coherent_exponent :-4 -> N/A
         // coherent_exponent :-3 -> N/A
      struct dm2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent_exponent -2
      >{};
         // coherent_exponent :-1 -> N/A
      struct m2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
         // coherent_exponent :1 -> N/A
      struct dam2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::hecto // coherent_exponent 2
      >{};
         // coherent_exponent :3 -> N/A
         // coherent_exponent :4 -> N/A
         // coherent_exponent :5 -> N/A
      struct km2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent_exponent 6
      >{};
         // coherent_exponent :7 -> N/A
         // coherent_exponent :8 -> N/A
         // coherent_exponent :9 -> N/A
         // coherent_exponent :10 -> N/A
         // coherent_exponent :11 -> N/A
      struct Mm2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
         // coherent_exponent :13 -> N/A
         // coherent_exponent :14 -> N/A
         // coherent_exponent :15 -> N/A
         // coherent_exponent :16 -> N/A
         // coherent_exponent :17 -> N/A
      struct Gm2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent_exponent 18
      >{};
         // coherent_exponent :19 -> N/A
         // coherent_exponent :20 -> N/A
         // coherent_exponent :21 -> N/A
         // coherent_exponent :22 -> N/A
         // coherent_exponent :23 -> N/A
      struct Tm2 :  quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent_exponent 24
      >{};
         // coherent_exponent :25 -> N/A
         // coherent_exponent :26 -> N/A
         // coherent_exponent :27 -> N/A
   };

    template<
        typename Value_type
    >
    struct area_ : meta::components::of_area{

#if 1
      // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::pm2,
         Value_type
      > pm2;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      // coherent_exponent :-21 -> N/A
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::nm2,
         Value_type
      > nm2;
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      // coherent_exponent :-15 -> N/A
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::um2,
         Value_type
      > um2;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      // coherent_exponent :-9 -> N/A
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::mm2,
         Value_type
      > mm2;
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      // coherent_exponent :-3 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::dm2,
         Value_type
      > dm2;
      // coherent_exponent :-1 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::m2,
         Value_type
      > m2;
      // coherent_exponent :1 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::dam2,
         Value_type
      > dam2;
      // coherent_exponent :3 -> N/A
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::km2,
         Value_type
      > km2;
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      // coherent_exponent :9 -> N/A
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::Mm2,
         Value_type
      > Mm2;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      // coherent_exponent :15 -> N/A
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::Gm2,
         Value_type
      > Gm2;
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      // coherent_exponent :21 -> N/A
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area::Tm2,
         Value_type
      > Tm2;
      // coherent_exponent :25 -> N/A
      // coherent_exponent :26 -> N/A
      // coherent_exponent :27 -> N/A

#else
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
#endif

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
