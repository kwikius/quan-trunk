#ifndef QUAN_TEMPERATURE_HPP_INCLUDED
#define QUAN_TEMPERATURE_HPP_INCLUDED
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

#include <quan/components/of_temperature.hpp>

namespace quan{

   struct of_temperature{
      struct YK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent-exponent 24
      >{};
      struct ZK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::zetta // coherent-exponent 21
      >{};
      struct EK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::exa // coherent-exponent 18
      >{};
      struct PK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::peta // coherent-exponent 15
      >{};
      struct TK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent-exponent 12
      >{};
      struct GK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::giga // coherent-exponent 9
      >{};
      struct MK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::mega // coherent-exponent 6
      >{};
      struct kK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::kilo // coherent-exponent 3
      >{};
      struct hK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::hecto // coherent-exponent 2
      >{};
      struct daK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::deka // coherent-exponent 1
      >{};
      struct K :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::none // coherent-exponent 0
      >{};
      struct dK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::deci // coherent-exponent -1
      >{};
      struct cK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::centi // coherent-exponent -2
      >{};
      struct mK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::milli // coherent-exponent -3
      >{};
      struct uK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::micro // coherent-exponent -6
      >{};
      struct nK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::nano // coherent-exponent -9
      >{};
      struct pK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent-exponent -12
      >{};
      struct fK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::femto // coherent-exponent -15
      >{};
      struct aK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::atto // coherent-exponent -18
      >{};
      struct zK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::zepto // coherent-exponent -21
      >{};
      struct yK :  quan::meta::unit<
         quan::meta::components::of_temperature::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent-exponent -24
      >{};
   };

    template<
        typename Value_type
    >
    struct temperature_ : meta::components::of_temperature{

      typedef quan::fixed_quantity<
         quan::of_temperature::YK,
         Value_type
      > YK;
      typedef quan::fixed_quantity<
         quan::of_temperature::ZK,
         Value_type
      > ZK;
      typedef quan::fixed_quantity<
         quan::of_temperature::EK,
         Value_type
      > EK;
      typedef quan::fixed_quantity<
         quan::of_temperature::PK,
         Value_type
      > PK;
      typedef quan::fixed_quantity<
         quan::of_temperature::TK,
         Value_type
      > TK;
      typedef quan::fixed_quantity<
         quan::of_temperature::GK,
         Value_type
      > GK;
      typedef quan::fixed_quantity<
         quan::of_temperature::MK,
         Value_type
      > MK;
      typedef quan::fixed_quantity<
         quan::of_temperature::kK,
         Value_type
      > kK;
      typedef quan::fixed_quantity<
         quan::of_temperature::hK,
         Value_type
      > hK;
      typedef quan::fixed_quantity<
         quan::of_temperature::daK,
         Value_type
      > daK;
      typedef quan::fixed_quantity<
         quan::of_temperature::K,
         Value_type
      > K;
      typedef quan::fixed_quantity<
         quan::of_temperature::dK,
         Value_type
      > dK;
      typedef quan::fixed_quantity<
         quan::of_temperature::cK,
         Value_type
      > cK;
      typedef quan::fixed_quantity<
         quan::of_temperature::mK,
         Value_type
      > mK;
      typedef quan::fixed_quantity<
         quan::of_temperature::uK,
         Value_type
      > uK;
      typedef quan::fixed_quantity<
         quan::of_temperature::nK,
         Value_type
      > nK;
      typedef quan::fixed_quantity<
         quan::of_temperature::pK,
         Value_type
      > pK;
      typedef quan::fixed_quantity<
         quan::of_temperature::fK,
         Value_type
      > fK;
      typedef quan::fixed_quantity<
         quan::of_temperature::aK,
         Value_type
      > aK;
      typedef quan::fixed_quantity<
         quan::of_temperature::zK,
         Value_type
      > zK;
      typedef quan::fixed_quantity<
         quan::of_temperature::yK,
         Value_type
      > yK;
    };

    struct temperature : temperature_<quantity_traits::default_value_type>{};

}//quan

#endif
