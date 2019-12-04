#ifndef QUAN_INDUCTANCE_HPP_INCLUDED
#define QUAN_INDUCTANCE_HPP_INCLUDED
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

#include <quan/components/of_inductance.hpp>

namespace quan{

   struct of_inductance{

      struct yH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct H : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YH : quan::meta::unit<
         quan::meta::components::of_inductance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct inductance_ : quan::meta::components::of_inductance{

      typedef quan::fixed_quantity<
         quan::of_inductance::yH,
         Value_type
      > yH;

      typedef quan::fixed_quantity<
         quan::of_inductance::zH,
         Value_type
      > zH;

      typedef quan::fixed_quantity<
         quan::of_inductance::aH,
         Value_type
      > aH;

      typedef quan::fixed_quantity<
         quan::of_inductance::fH,
         Value_type
      > fH;

      typedef quan::fixed_quantity<
         quan::of_inductance::pH,
         Value_type
      > pH;

      typedef quan::fixed_quantity<
         quan::of_inductance::nH,
         Value_type
      > nH;

      typedef quan::fixed_quantity<
         quan::of_inductance::uH,
         Value_type
      > uH;

      typedef quan::fixed_quantity<
         quan::of_inductance::mH,
         Value_type
      > mH;

      typedef quan::fixed_quantity<
         quan::of_inductance::cH,
         Value_type
      > cH;

      typedef quan::fixed_quantity<
         quan::of_inductance::dH,
         Value_type
      > dH;

      typedef quan::fixed_quantity<
         quan::of_inductance::H,
         Value_type
      > H;

      typedef quan::fixed_quantity<
         quan::of_inductance::daH,
         Value_type
      > daH;

      typedef quan::fixed_quantity<
         quan::of_inductance::hH,
         Value_type
      > hH;

      typedef quan::fixed_quantity<
         quan::of_inductance::kH,
         Value_type
      > kH;

      typedef quan::fixed_quantity<
         quan::of_inductance::MH,
         Value_type
      > MH;

      typedef quan::fixed_quantity<
         quan::of_inductance::GH,
         Value_type
      > GH;

      typedef quan::fixed_quantity<
         quan::of_inductance::TH,
         Value_type
      > TH;

      typedef quan::fixed_quantity<
         quan::of_inductance::PH,
         Value_type
      > PH;

      typedef quan::fixed_quantity<
         quan::of_inductance::EH,
         Value_type
      > EH;

      typedef quan::fixed_quantity<
         quan::of_inductance::ZH,
         Value_type
      > ZH;

      typedef quan::fixed_quantity<
         quan::of_inductance::YH,
         Value_type
      > YH;

        typedef fixed_quantity<
            typename non_si_unit::abhenry,
            Value_type
        > abhenry;

    };

    struct inductance : inductance_<quantity_traits::default_value_type>{};

}//quan

#endif
