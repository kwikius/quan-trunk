#ifndef QUAN_CONDUCTANCE_HPP_INCLUDED
#define QUAN_CONDUCTANCE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

/*
 Copyright (c) 2003-2019 Andy Little.

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

#include <quan/components/of_conductance.hpp>

namespace quan{

   struct of_conductance{
         // coherent_exponent :-27 -> N/A
         // coherent_exponent :-26 -> N/A
         // coherent_exponent :-25 -> N/A
      struct yS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
         // coherent_exponent :-23 -> N/A
         // coherent_exponent :-22 -> N/A
      struct zS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent_exponent -21
      >{};
         // coherent_exponent :-20 -> N/A
         // coherent_exponent :-19 -> N/A
      struct aS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent_exponent -18
      >{};
         // coherent_exponent :-17 -> N/A
         // coherent_exponent :-16 -> N/A
      struct fS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent_exponent -15
      >{};
         // coherent_exponent :-14 -> N/A
         // coherent_exponent :-13 -> N/A
      struct pS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
         // coherent_exponent :-11 -> N/A
         // coherent_exponent :-10 -> N/A
      struct nS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent_exponent -9
      >{};
         // coherent_exponent :-8 -> N/A
         // coherent_exponent :-7 -> N/A
      struct uS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent_exponent -6
      >{};
         // coherent_exponent :-5 -> N/A
         // coherent_exponent :-4 -> N/A
      struct mS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent_exponent -3
      >{};
      struct cS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent_exponent -2
      >{};
      struct dS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent_exponent -1
      >{};
      struct S :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
      struct daS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::deka // coherent_exponent 1
      >{};
      struct hS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::hecto // coherent_exponent 2
      >{};
      struct kS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent_exponent 3
      >{};
         // coherent_exponent :4 -> N/A
         // coherent_exponent :5 -> N/A
      struct MS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent_exponent 6
      >{};
         // coherent_exponent :7 -> N/A
         // coherent_exponent :8 -> N/A
      struct GS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent_exponent 9
      >{};
         // coherent_exponent :10 -> N/A
         // coherent_exponent :11 -> N/A
      struct TS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
         // coherent_exponent :13 -> N/A
         // coherent_exponent :14 -> N/A
      struct PS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent_exponent 15
      >{};
         // coherent_exponent :16 -> N/A
         // coherent_exponent :17 -> N/A
      struct ES :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent_exponent 18
      >{};
         // coherent_exponent :19 -> N/A
         // coherent_exponent :20 -> N/A
      struct ZS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::zetta // coherent_exponent 21
      >{};
         // coherent_exponent :22 -> N/A
         // coherent_exponent :23 -> N/A
      struct YS :  quan::meta::unit<
         quan::meta::components::of_conductance::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent_exponent 24
      >{};
         // coherent_exponent :25 -> N/A
         // coherent_exponent :26 -> N/A
         // coherent_exponent :27 -> N/A
   };

    template<
        typename Value_type
    >
    struct conductance_ : meta::components::of_conductance{

#if 1
      // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::yS,
         Value_type
      > yS;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::zS,
         Value_type
      > zS;
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::aS,
         Value_type
      > aS;
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::fS,
         Value_type
      > fS;
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::pS,
         Value_type
      > pS;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::nS,
         Value_type
      > nS;
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::uS,
         Value_type
      > uS;
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::mS,
         Value_type
      > mS;
      typedef quan::fixed_quantity<
         quan::of_conductance::cS,
         Value_type
      > cS;
      typedef quan::fixed_quantity<
         quan::of_conductance::dS,
         Value_type
      > dS;
      typedef quan::fixed_quantity<
         quan::of_conductance::S,
         Value_type
      > S;
      typedef quan::fixed_quantity<
         quan::of_conductance::daS,
         Value_type
      > daS;
      typedef quan::fixed_quantity<
         quan::of_conductance::hS,
         Value_type
      > hS;
      typedef quan::fixed_quantity<
         quan::of_conductance::kS,
         Value_type
      > kS;
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::MS,
         Value_type
      > MS;
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::GS,
         Value_type
      > GS;
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::TS,
         Value_type
      > TS;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::PS,
         Value_type
      > PS;
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::ES,
         Value_type
      > ES;
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::ZS,
         Value_type
      > ZS;
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      typedef quan::fixed_quantity<
         quan::of_conductance::YS,
         Value_type
      > YS;
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
        > yS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > zS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > aS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > fS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > pS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > nS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > uS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > mS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > cS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > dS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > S;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > daS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > hS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > kS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > MS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > GS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > TS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > PS;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > ES;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > ZS;
#endif
    };

    struct conductance : conductance_<quantity_traits::default_value_type>{};

}//quan

#endif
