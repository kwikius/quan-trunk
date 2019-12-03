#ifndef QUAN_TIME_HPP_INCLUDED
#define QUAN_TIME_HPP_INCLUDED
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
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_time.hpp>

namespace quan{

   struct of_time{
      struct Ys :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent-exponent 24
      >{};
      struct Zs :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::zetta // coherent-exponent 21
      >{};
      struct Es :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent-exponent 18
      >{};
      struct Ps :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent-exponent 15
      >{};
      struct Ts :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent-exponent 12
      >{};
      struct Gs :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent-exponent 9
      >{};
      struct Ms :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent-exponent 6
      >{};
      struct ks :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent-exponent 3
      >{};
      struct hs :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::hecto // coherent-exponent 2
      >{};
      struct das :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::deka // coherent-exponent 1
      >{};
      struct s :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::none // coherent-exponent 0
      >{};
      struct ds :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent-exponent -1
      >{};
      struct cs :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent-exponent -2
      >{};
      struct ms :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent-exponent -3
      >{};
      struct us :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent-exponent -6
      >{};
      struct ns :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent-exponent -9
      >{};
      struct ps :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent-exponent -12
      >{};
      struct fs :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent-exponent -15
      >{};
      struct as :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent-exponent -18
      >{};
      struct zs :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent-exponent -21
      >{};
      struct ys :  quan::meta::unit<
         quan::meta::components::of_time::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent-exponent -24
      >{};
   };

    template<
        typename Value_type
    >
    struct time_ : meta::components::of_time{

      typedef quan::fixed_quantity<
         quan::of_time::Ys,
         Value_type
      > Ys;
      typedef quan::fixed_quantity<
         quan::of_time::Zs,
         Value_type
      > Zs;
      typedef quan::fixed_quantity<
         quan::of_time::Es,
         Value_type
      > Es;
      typedef quan::fixed_quantity<
         quan::of_time::Ps,
         Value_type
      > Ps;
      typedef quan::fixed_quantity<
         quan::of_time::Ts,
         Value_type
      > Ts;
      typedef quan::fixed_quantity<
         quan::of_time::Gs,
         Value_type
      > Gs;
      typedef quan::fixed_quantity<
         quan::of_time::Ms,
         Value_type
      > Ms;
      typedef quan::fixed_quantity<
         quan::of_time::ks,
         Value_type
      > ks;
      typedef quan::fixed_quantity<
         quan::of_time::hs,
         Value_type
      > hs;
      typedef quan::fixed_quantity<
         quan::of_time::das,
         Value_type
      > das;
      typedef quan::fixed_quantity<
         quan::of_time::s,
         Value_type
      > s;
      typedef quan::fixed_quantity<
         quan::of_time::ds,
         Value_type
      > ds;
      typedef quan::fixed_quantity<
         quan::of_time::cs,
         Value_type
      > cs;
      typedef quan::fixed_quantity<
         quan::of_time::ms,
         Value_type
      > ms;
      typedef quan::fixed_quantity<
         quan::of_time::us,
         Value_type
      > us;
      typedef quan::fixed_quantity<
         quan::of_time::ns,
         Value_type
      > ns;
      typedef quan::fixed_quantity<
         quan::of_time::ps,
         Value_type
      > ps;
      typedef quan::fixed_quantity<
         quan::of_time::fs,
         Value_type
      > fs;
      typedef quan::fixed_quantity<
         quan::of_time::as,
         Value_type
      > as;
      typedef quan::fixed_quantity<
         quan::of_time::zs,
         Value_type
      > zs;
      typedef quan::fixed_quantity<
         quan::of_time::ys,
         Value_type
      > ys;

// non si
        typedef fixed_quantity<
            typename non_si_unit::d,
            Value_type
        > d;

        typedef fixed_quantity<
            typename non_si_unit::d_sid,
            Value_type
        > d_sid;

        typedef fixed_quantity<
            typename non_si_unit::h,
            Value_type
        > h;

        typedef fixed_quantity<
            typename non_si_unit::h_sid,
            Value_type
        > h_sid;

        typedef fixed_quantity<
            typename non_si_unit::min,
            Value_type
        > min;

        typedef fixed_quantity<
            typename non_si_unit::min_sid,
            Value_type
        > min_sid;

        typedef fixed_quantity<
            typename non_si_unit::s_sid,
            Value_type
        > s_sid;

        typedef fixed_quantity<
            typename non_si_unit::wk,
            Value_type
        > wk;

        typedef fixed_quantity<
            typename non_si_unit::yr,
            Value_type
        > yr;

        typedef fixed_quantity<
            typename non_si_unit::yr_sid,
            Value_type
        > yr_sid;

        typedef fixed_quantity<
            typename non_si_unit::yr_trop,
            Value_type
        > yr_trop;

    };

    struct time : time_<quantity_traits::default_value_type>{};

}//quan

#endif
