#ifndef QUAN_ACCELERATION_HPP_INCLUDED
#define QUAN_ACCELERATION_HPP_INCLUDED
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
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <quan/components/of_acceleration.hpp>

namespace quan{

   struct of_acceleration{
         // coherent_exponent :-27 -> N/A
         // coherent_exponent :-26 -> N/A
         // coherent_exponent :-25 -> N/A
      struct ym_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
         // coherent_exponent :-23 -> N/A
         // coherent_exponent :-22 -> N/A
      struct zm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent_exponent -21
      >{};
         // coherent_exponent :-20 -> N/A
         // coherent_exponent :-19 -> N/A
      struct am_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent_exponent -18
      >{};
         // coherent_exponent :-17 -> N/A
         // coherent_exponent :-16 -> N/A
      struct fm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent_exponent -15
      >{};
         // coherent_exponent :-14 -> N/A
         // coherent_exponent :-13 -> N/A
      struct pm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
         // coherent_exponent :-11 -> N/A
         // coherent_exponent :-10 -> N/A
      struct nm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent_exponent -9
      >{};
         // coherent_exponent :-8 -> N/A
         // coherent_exponent :-7 -> N/A
      struct um_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent_exponent -6
      >{};
         // coherent_exponent :-5 -> N/A
         // coherent_exponent :-4 -> N/A
      struct mm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent_exponent -3
      >{};
      struct cm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent_exponent -2
      >{};
      struct dm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent_exponent -1
      >{};
      struct m_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
      struct dam_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::deka // coherent_exponent 1
      >{};
      struct hm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::hecto // coherent_exponent 2
      >{};
      struct km_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent_exponent 3
      >{};
         // coherent_exponent :4 -> N/A
         // coherent_exponent :5 -> N/A
      struct Mm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent_exponent 6
      >{};
         // coherent_exponent :7 -> N/A
         // coherent_exponent :8 -> N/A
      struct Gm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent_exponent 9
      >{};
         // coherent_exponent :10 -> N/A
         // coherent_exponent :11 -> N/A
      struct Tm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
         // coherent_exponent :13 -> N/A
         // coherent_exponent :14 -> N/A
      struct Pm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent_exponent 15
      >{};
         // coherent_exponent :16 -> N/A
         // coherent_exponent :17 -> N/A
      struct Em_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent_exponent 18
      >{};
         // coherent_exponent :19 -> N/A
         // coherent_exponent :20 -> N/A
      struct Zm_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::zetta // coherent_exponent 21
      >{};
         // coherent_exponent :22 -> N/A
         // coherent_exponent :23 -> N/A
      struct Ym_per_s2 :  quan::meta::unit<
         quan::meta::components::of_acceleration::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent_exponent 24
      >{};
         // coherent_exponent :25 -> N/A
         // coherent_exponent :26 -> N/A
         // coherent_exponent :27 -> N/A
   };

    template<
        typename Value_type
    >
    struct acceleration_ : meta::components::of_acceleration{

#if 1

    // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::ym_per_s2,
         Value_type
      > ym_per_s2;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::zm_per_s2,
         Value_type
      > zm_per_s2;
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::am_per_s2,
         Value_type
      > am_per_s2;
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::fm_per_s2,
         Value_type
      > fm_per_s2;
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::pm_per_s2,
         Value_type
      > pm_per_s2;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::nm_per_s2,
         Value_type
      > nm_per_s2;
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::um_per_s2,
         Value_type
      > um_per_s2;
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::mm_per_s2,
         Value_type
      > mm_per_s2;
      typedef quan::fixed_quantity<
         quan::of_acceleration::cm_per_s2,
         Value_type
      > cm_per_s2;
      typedef quan::fixed_quantity<
         quan::of_acceleration::dm_per_s2,
         Value_type
      > dm_per_s2;
      typedef quan::fixed_quantity<
         quan::of_acceleration::m_per_s2,
         Value_type
      > m_per_s2;
      typedef quan::fixed_quantity<
         quan::of_acceleration::dam_per_s2,
         Value_type
      > dam_per_s2;
      typedef quan::fixed_quantity<
         quan::of_acceleration::hm_per_s2,
         Value_type
      > hm_per_s2;
      typedef quan::fixed_quantity<
         quan::of_acceleration::km_per_s2,
         Value_type
      > km_per_s2;
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::Mm_per_s2,
         Value_type
      > Mm_per_s2;
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::Gm_per_s2,
         Value_type
      > Gm_per_s2;
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::Tm_per_s2,
         Value_type
      > Tm_per_s2;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::Pm_per_s2,
         Value_type
      > Pm_per_s2;
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::Em_per_s2,
         Value_type
      > Em_per_s2;
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::Zm_per_s2,
         Value_type
      > Zm_per_s2;
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      typedef quan::fixed_quantity<
         quan::of_acceleration::Ym_per_s2,
         Value_type
      > Ym_per_s2;
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
        > ym_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > zm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > am_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > fm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > pm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > nm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > um_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > mm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > cm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > dm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > m_per_s2;



        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > dam_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > hm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > km_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > Mm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > Gm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > Tm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > Pm_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > Em_per_s2;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > Zm_per_s2;
#endif
        typedef fixed_quantity<
            typename non_si_unit::g_s,
            Value_type
        > g_s;

        typedef fixed_quantity<
            typename non_si_unit::ft_per_s2,
            Value_type
        > ft_per_s2;

        typedef fixed_quantity<
            typename non_si_unit::Gal,
            Value_type
        > Gal;

        typedef fixed_quantity<
            typename non_si_unit::in_per_s2,
            Value_type
        > in_per_s2;

        static constexpr m_per_s2 g{static_cast<Value_type>(9.80665)};

    };

    template<
        typename Value_type
    >
    constexpr typename acceleration_<Value_type>::m_per_s2 acceleration_<Value_type>::g;

    struct acceleration : acceleration_<quantity_traits::default_value_type>{};

}//quan

#endif
