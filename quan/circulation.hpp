#ifndef QUAN_CIRCULATION_HPP_INCLUDED
#define QUAN_CIRCULATION_HPP_INCLUDED
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
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_circulation.hpp>

namespace quan{

   struct of_circulation{
         // coherent_exponent :-27 -> N/A
         // coherent_exponent :-26 -> N/A
         // coherent_exponent :-25 -> N/A
      struct ym2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
         // coherent_exponent :-23 -> N/A
         // coherent_exponent :-22 -> N/A
      struct zm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent_exponent -21
      >{};
         // coherent_exponent :-20 -> N/A
         // coherent_exponent :-19 -> N/A
      struct am2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent_exponent -18
      >{};
         // coherent_exponent :-17 -> N/A
         // coherent_exponent :-16 -> N/A
      struct fm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent_exponent -15
      >{};
         // coherent_exponent :-14 -> N/A
         // coherent_exponent :-13 -> N/A
      struct pm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
         // coherent_exponent :-11 -> N/A
         // coherent_exponent :-10 -> N/A
      struct nm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent_exponent -9
      >{};
         // coherent_exponent :-8 -> N/A
         // coherent_exponent :-7 -> N/A
      struct um2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent_exponent -6
      >{};
         // coherent_exponent :-5 -> N/A
         // coherent_exponent :-4 -> N/A
      struct mm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent_exponent -3
      >{};
      struct cm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent_exponent -2
      >{};
      struct dm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent_exponent -1
      >{};
      struct m2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
      struct dam2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::deka // coherent_exponent 1
      >{};
      struct hm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::hecto // coherent_exponent 2
      >{};
      struct km2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent_exponent 3
      >{};
         // coherent_exponent :4 -> N/A
         // coherent_exponent :5 -> N/A
      struct Mm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent_exponent 6
      >{};
         // coherent_exponent :7 -> N/A
         // coherent_exponent :8 -> N/A
      struct Gm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent_exponent 9
      >{};
         // coherent_exponent :10 -> N/A
         // coherent_exponent :11 -> N/A
      struct Tm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
         // coherent_exponent :13 -> N/A
         // coherent_exponent :14 -> N/A
      struct Pm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent_exponent 15
      >{};
         // coherent_exponent :16 -> N/A
         // coherent_exponent :17 -> N/A
      struct Em2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent_exponent 18
      >{};
         // coherent_exponent :19 -> N/A
         // coherent_exponent :20 -> N/A
      struct Zm2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::zetta // coherent_exponent 21
      >{};
         // coherent_exponent :22 -> N/A
         // coherent_exponent :23 -> N/A
      struct Ym2_per_s :  quan::meta::unit<
         quan::meta::components::of_circulation::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent_exponent 24
      >{};
         // coherent_exponent :25 -> N/A
         // coherent_exponent :26 -> N/A
         // coherent_exponent :27 -> N/A
   };

    template<
        typename Value_type
    >
    struct circulation_ : meta::components::of_circulation{

#if 1

      // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::ym2_per_s,
         Value_type
      > ym2_per_s;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::zm2_per_s,
         Value_type
      > zm2_per_s;
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::am2_per_s,
         Value_type
      > am2_per_s;
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::fm2_per_s,
         Value_type
      > fm2_per_s;
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::pm2_per_s,
         Value_type
      > pm2_per_s;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::nm2_per_s,
         Value_type
      > nm2_per_s;
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::um2_per_s,
         Value_type
      > um2_per_s;
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::mm2_per_s,
         Value_type
      > mm2_per_s;
      typedef quan::fixed_quantity<
         quan::of_circulation::cm2_per_s,
         Value_type
      > cm2_per_s;
      typedef quan::fixed_quantity<
         quan::of_circulation::dm2_per_s,
         Value_type
      > dm2_per_s;
      typedef quan::fixed_quantity<
         quan::of_circulation::m2_per_s,
         Value_type
      > m2_per_s;
      typedef quan::fixed_quantity<
         quan::of_circulation::dam2_per_s,
         Value_type
      > dam2_per_s;
      typedef quan::fixed_quantity<
         quan::of_circulation::hm2_per_s,
         Value_type
      > hm2_per_s;
      typedef quan::fixed_quantity<
         quan::of_circulation::km2_per_s,
         Value_type
      > km2_per_s;
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::Mm2_per_s,
         Value_type
      > Mm2_per_s;
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::Gm2_per_s,
         Value_type
      > Gm2_per_s;
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::Tm2_per_s,
         Value_type
      > Tm2_per_s;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::Pm2_per_s,
         Value_type
      > Pm2_per_s;
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::Em2_per_s,
         Value_type
      > Em2_per_s;
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::Zm2_per_s,
         Value_type
      > Zm2_per_s;
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      typedef quan::fixed_quantity<
         quan::of_circulation::Ym2_per_s,
         Value_type
      > Ym2_per_s;
      // coherent_exponent :25 -> N/A
      // coherent_exponent :26 -> N/A
      // coherent_exponent :27 -> N/A
#else
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yocto // coherent-exponent -24
            >,
            Value_type
        > ym2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > zm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > am2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > fm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > pm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > nm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > um2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > mm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > cm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > dm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > m2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > dam2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > hm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > km2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > Mm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > Gm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > Tm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > Pm2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > Em2_per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > Zm2_per_s;
#endif
    };

    struct circulation : circulation_<quantity_traits::default_value_type>{};

}//quan

#endif
