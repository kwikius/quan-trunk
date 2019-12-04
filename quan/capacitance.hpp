#ifndef QUAN_CAPACITANCE_HPP_INCLUDED
#define QUAN_CAPACITANCE_HPP_INCLUDED
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

#include <quan/components/of_capacitance.hpp>

namespace quan{

   struct of_capacitance{
         // coherent_exponent :-27 -> N/A
         // coherent_exponent :-26 -> N/A
         // coherent_exponent :-25 -> N/A
      struct yF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
         // coherent_exponent :-23 -> N/A
         // coherent_exponent :-22 -> N/A
      struct zF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent_exponent -21
      >{};
         // coherent_exponent :-20 -> N/A
         // coherent_exponent :-19 -> N/A
      struct aF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent_exponent -18
      >{};
         // coherent_exponent :-17 -> N/A
         // coherent_exponent :-16 -> N/A
      struct fF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent_exponent -15
      >{};
         // coherent_exponent :-14 -> N/A
         // coherent_exponent :-13 -> N/A
      struct pF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
         // coherent_exponent :-11 -> N/A
         // coherent_exponent :-10 -> N/A
      struct nF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent_exponent -9
      >{};
         // coherent_exponent :-8 -> N/A
         // coherent_exponent :-7 -> N/A
      struct uF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent_exponent -6
      >{};
         // coherent_exponent :-5 -> N/A
         // coherent_exponent :-4 -> N/A
      struct mF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent_exponent -3
      >{};
      struct cF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent_exponent -2
      >{};
      struct dF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent_exponent -1
      >{};
      struct F :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
      struct daF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::deka // coherent_exponent 1
      >{};
      struct hF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::hecto // coherent_exponent 2
      >{};
      struct kF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent_exponent 3
      >{};
         // coherent_exponent :4 -> N/A
         // coherent_exponent :5 -> N/A
      struct MF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent_exponent 6
      >{};
         // coherent_exponent :7 -> N/A
         // coherent_exponent :8 -> N/A
      struct GF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent_exponent 9
      >{};
         // coherent_exponent :10 -> N/A
         // coherent_exponent :11 -> N/A
      struct TF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
         // coherent_exponent :13 -> N/A
         // coherent_exponent :14 -> N/A
      struct PF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent_exponent 15
      >{};
         // coherent_exponent :16 -> N/A
         // coherent_exponent :17 -> N/A
      struct EF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent_exponent 18
      >{};
         // coherent_exponent :19 -> N/A
         // coherent_exponent :20 -> N/A
      struct ZF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::zetta // coherent_exponent 21
      >{};
         // coherent_exponent :22 -> N/A
         // coherent_exponent :23 -> N/A
      struct YF :  quan::meta::unit<
         quan::meta::components::of_capacitance::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent_exponent 24
      >{};
         // coherent_exponent :25 -> N/A
         // coherent_exponent :26 -> N/A
         // coherent_exponent :27 -> N/A
   };

    template<
        typename Value_type
    >
    struct capacitance_ : meta::components::of_capacitance{

#if 1
  // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::yF,
         Value_type
      > yF;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::zF,
         Value_type
      > zF;
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::aF,
         Value_type
      > aF;
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::fF,
         Value_type
      > fF;
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::pF,
         Value_type
      > pF;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::nF,
         Value_type
      > nF;
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::uF,
         Value_type
      > uF;
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::mF,
         Value_type
      > mF;
      typedef quan::fixed_quantity<
         quan::of_capacitance::cF,
         Value_type
      > cF;
      typedef quan::fixed_quantity<
         quan::of_capacitance::dF,
         Value_type
      > dF;
      typedef quan::fixed_quantity<
         quan::of_capacitance::F,
         Value_type
      > F;
      typedef quan::fixed_quantity<
         quan::of_capacitance::daF,
         Value_type
      > daF;
      typedef quan::fixed_quantity<
         quan::of_capacitance::hF,
         Value_type
      > hF;
      typedef quan::fixed_quantity<
         quan::of_capacitance::kF,
         Value_type
      > kF;
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::MF,
         Value_type
      > MF;
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::GF,
         Value_type
      > GF;
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::TF,
         Value_type
      > TF;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::PF,
         Value_type
      > PF;
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::EF,
         Value_type
      > EF;
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::ZF,
         Value_type
      > ZF;
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      typedef quan::fixed_quantity<
         quan::of_capacitance::YF,
         Value_type
      > YF;
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
        > yF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > zF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > aF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > fF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > pF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > nF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > uF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > mF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > cF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > dF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > F;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > daF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > hF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > kF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > MF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > GF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > TF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > PF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > EF;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > ZF;
#endif
        typedef fixed_quantity<
            typename non_si_unit::abfarad,
            Value_type
        > abfarad;

    };

    struct capacitance : capacitance_<quantity_traits::default_value_type>{};

}//quan

#endif
