#ifndef QUAN_HEAT_FLOW_HPP_INCLUDED
#define QUAN_HEAT_FLOW_HPP_INCLUDED
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

#include <quan/components/of_heat_flow.hpp>

namespace quan{

 struct of_heat_flow{

      struct yW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct W : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YW : quan::meta::unit<
         quan::meta::components::of_heat_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct heat_flow_ : quan::meta::components::of_heat_flow{

      typedef quan::fixed_quantity<
         quan::of_heat_flow::yW,
         Value_type
      > yW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::zW,
         Value_type
      > zW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::aW,
         Value_type
      > aW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::fW,
         Value_type
      > fW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::pW,
         Value_type
      > pW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::nW,
         Value_type
      > nW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::uW,
         Value_type
      > uW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::mW,
         Value_type
      > mW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::cW,
         Value_type
      > cW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::dW,
         Value_type
      > dW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::W,
         Value_type
      > W;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::daW,
         Value_type
      > daW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::hW,
         Value_type
      > hW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::kW,
         Value_type
      > kW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::MW,
         Value_type
      > MW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::GW,
         Value_type
      > GW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::TW,
         Value_type
      > TW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::PW,
         Value_type
      > PW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::EW,
         Value_type
      > EW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::ZW,
         Value_type
      > ZW;

      typedef quan::fixed_quantity<
         quan::of_heat_flow::YW,
         Value_type
      > YW;
// non SI units...
    };

    struct heat_flow : heat_flow_<quantity_traits::default_value_type>{};

}//quan

#endif
