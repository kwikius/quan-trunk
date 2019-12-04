#ifndef QUAN_CURRENT_HPP_INCLUDED
#define QUAN_CURRENT_HPP_INCLUDED
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

#include <quan/components/of_current.hpp>

namespace quan{

   struct of_current{
         // coherent_exponent :-27 -> N/A
         // coherent_exponent :-26 -> N/A
         // coherent_exponent :-25 -> N/A
      struct yA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
         // coherent_exponent :-23 -> N/A
         // coherent_exponent :-22 -> N/A
      struct zA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent_exponent -21
      >{};
         // coherent_exponent :-20 -> N/A
         // coherent_exponent :-19 -> N/A
      struct aA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent_exponent -18
      >{};
         // coherent_exponent :-17 -> N/A
         // coherent_exponent :-16 -> N/A
      struct fA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent_exponent -15
      >{};
         // coherent_exponent :-14 -> N/A
         // coherent_exponent :-13 -> N/A
      struct pA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
         // coherent_exponent :-11 -> N/A
         // coherent_exponent :-10 -> N/A
      struct nA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent_exponent -9
      >{};
         // coherent_exponent :-8 -> N/A
         // coherent_exponent :-7 -> N/A
      struct uA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent_exponent -6
      >{};
         // coherent_exponent :-5 -> N/A
         // coherent_exponent :-4 -> N/A
      struct mA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent_exponent -3
      >{};
      struct cA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent_exponent -2
      >{};
      struct dA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent_exponent -1
      >{};
      struct A :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
      struct daA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::deka // coherent_exponent 1
      >{};
      struct hA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::hecto // coherent_exponent 2
      >{};
      struct kA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent_exponent 3
      >{};
         // coherent_exponent :4 -> N/A
         // coherent_exponent :5 -> N/A
      struct MA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent_exponent 6
      >{};
         // coherent_exponent :7 -> N/A
         // coherent_exponent :8 -> N/A
      struct GA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent_exponent 9
      >{};
         // coherent_exponent :10 -> N/A
         // coherent_exponent :11 -> N/A
      struct TA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
         // coherent_exponent :13 -> N/A
         // coherent_exponent :14 -> N/A
      struct PA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent_exponent 15
      >{};
         // coherent_exponent :16 -> N/A
         // coherent_exponent :17 -> N/A
      struct EA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent_exponent 18
      >{};
         // coherent_exponent :19 -> N/A
         // coherent_exponent :20 -> N/A
      struct ZA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::zetta // coherent_exponent 21
      >{};
         // coherent_exponent :22 -> N/A
         // coherent_exponent :23 -> N/A
      struct YA :  quan::meta::unit<
         quan::meta::components::of_current::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent_exponent 24
      >{};
         // coherent_exponent :25 -> N/A
         // coherent_exponent :26 -> N/A
         // coherent_exponent :27 -> N/A
   };

    template<
        typename Value_type
    >
    struct current_ : meta::components::of_current{

#if 1
      // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::yA,
         Value_type
      > yA;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::zA,
         Value_type
      > zA;
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::aA,
         Value_type
      > aA;
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::fA,
         Value_type
      > fA;
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::pA,
         Value_type
      > pA;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::nA,
         Value_type
      > nA;
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::uA,
         Value_type
      > uA;
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::mA,
         Value_type
      > mA;
      typedef quan::fixed_quantity<
         quan::of_current::cA,
         Value_type
      > cA;
      typedef quan::fixed_quantity<
         quan::of_current::dA,
         Value_type
      > dA;
      typedef quan::fixed_quantity<
         quan::of_current::A,
         Value_type
      > A;
      typedef quan::fixed_quantity<
         quan::of_current::daA,
         Value_type
      > daA;
      typedef quan::fixed_quantity<
         quan::of_current::hA,
         Value_type
      > hA;
      typedef quan::fixed_quantity<
         quan::of_current::kA,
         Value_type
      > kA;
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::MA,
         Value_type
      > MA;
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::GA,
         Value_type
      > GA;
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::TA,
         Value_type
      > TA;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::PA,
         Value_type
      > PA;
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::EA,
         Value_type
      > EA;
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::ZA,
         Value_type
      > ZA;
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      typedef quan::fixed_quantity<
         quan::of_current::YA,
         Value_type
      > YA;
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
        > yA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > zA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > aA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > fA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > pA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > nA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > uA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > mA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > cA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > dA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > A;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > daA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > hA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > kA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > MA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > GA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > TA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > PA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > EA;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > ZA;
#endif
        typedef fixed_quantity<
            typename non_si_unit::abampere,
            Value_type
        > abampere;

    };

    struct current : current_<quantity_traits::default_value_type>{};

}//quan

#endif
