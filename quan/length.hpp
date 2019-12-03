#ifndef QUAN_LENGTH_HPP_INCLUDED
#define QUAN_LENGTH_HPP_INCLUDED
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


#include <quan/components/of_length.hpp>

namespace quan{

    struct of_length{
         struct Ym :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::yotta // coherent-exponent 24
         >{};
         struct Zm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::zetta // coherent-exponent 21
         >{};
         struct Em :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::exa // coherent-exponent 18
         >{};
         struct Pm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::peta // coherent-exponent 15
         >{};
         struct Tm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::tera // coherent-exponent 12
         >{};
         struct Gm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::giga // coherent-exponent 9
         >{};
         struct Mm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::mega // coherent-exponent 6
         >{};
         struct km :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::kilo // coherent-exponent 3
         >{};
         struct hm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::hecto // coherent-exponent 2
         >{};
         struct dam :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::deka // coherent-exponent 1
         >{};
         struct m :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::none // coherent-exponent 0
         >{};
         struct dm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::deci // coherent-exponent -1
         >{};
         struct cm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::centi // coherent-exponent -2
         >{};
         struct mm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::milli // coherent-exponent -3
         >{};
         struct um :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::micro // coherent-exponent -6
         >{};
         struct nm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::nano // coherent-exponent -9
         >{};
         struct pm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::pico // coherent-exponent -12
         >{};
         struct fm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::femto // coherent-exponent -15
         >{};
         struct am :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::atto // coherent-exponent -18
         >{};
         struct zm :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::zepto // coherent-exponent -21
         >{};
         struct ym :  quan::meta::unit<
            quan::meta::components::of_length::abstract_quantity,
            typename quan::meta::si_unit::yocto // coherent-exponent -24
         >{};

    };

    template<
        typename Value_type
    >
    struct length_ : meta::components::of_length{

      typedef quan::fixed_quantity<
         quan::of_length::Ym,
         Value_type
      > Ym;
      typedef quan::fixed_quantity<
         quan::of_length::Zm,
         Value_type
      > Zm;
      typedef quan::fixed_quantity<
         quan::of_length::Em,
         Value_type
      > Em;
      typedef quan::fixed_quantity<
         quan::of_length::Pm,
         Value_type
      > Pm;
      typedef quan::fixed_quantity<
         quan::of_length::Tm,
         Value_type
      > Tm;
      typedef quan::fixed_quantity<
         quan::of_length::Gm,
         Value_type
      > Gm;
      typedef quan::fixed_quantity<
         quan::of_length::Mm,
         Value_type
      > Mm;
      typedef quan::fixed_quantity<
         quan::of_length::km,
         Value_type
      > km;
      typedef quan::fixed_quantity<
         quan::of_length::hm,
         Value_type
      > hm;
      typedef quan::fixed_quantity<
         quan::of_length::dam,
         Value_type
      > dam;
      typedef quan::fixed_quantity<
         quan::of_length::m,
         Value_type
      > m;
      typedef quan::fixed_quantity<
         quan::of_length::dm,
         Value_type
      > dm;
      typedef quan::fixed_quantity<
         quan::of_length::cm,
         Value_type
      > cm;
      typedef quan::fixed_quantity<
         quan::of_length::mm,
         Value_type
      > mm;
      typedef quan::fixed_quantity<
         quan::of_length::um,
         Value_type
      > um;
      typedef quan::fixed_quantity<
         quan::of_length::nm,
         Value_type
      > nm;
      typedef quan::fixed_quantity<
         quan::of_length::pm,
         Value_type
      > pm;
      typedef quan::fixed_quantity<
         quan::of_length::fm,
         Value_type
      > fm;
      typedef quan::fixed_quantity<
         quan::of_length::am,
         Value_type
      > am;
      typedef quan::fixed_quantity<
         quan::of_length::zm,
         Value_type
      > zm;
      typedef quan::fixed_quantity<
         quan::of_length::ym,
         Value_type
      > ym;

//-- non si

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
