#ifndef QUAN_HEAT_FLOW_DENSITY_HPP_INCLUDED
#define QUAN_HEAT_FLOW_DENSITY_HPP_INCLUDED
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

#include <quan/components/of_heat_flow_density.hpp>

namespace quan{

   struct of_heat_flow_density{

      struct yW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct W_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YW_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_flow_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct heat_flow_density_ : quan::meta::components::of_heat_flow_density{

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::yW_per_m2,
         Value_type
      > yW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::zW_per_m2,
         Value_type
      > zW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::aW_per_m2,
         Value_type
      > aW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::fW_per_m2,
         Value_type
      > fW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::pW_per_m2,
         Value_type
      > pW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::nW_per_m2,
         Value_type
      > nW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::uW_per_m2,
         Value_type
      > uW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::mW_per_m2,
         Value_type
      > mW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::cW_per_m2,
         Value_type
      > cW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::dW_per_m2,
         Value_type
      > dW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::W_per_m2,
         Value_type
      > W_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::daW_per_m2,
         Value_type
      > daW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::hW_per_m2,
         Value_type
      > hW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::kW_per_m2,
         Value_type
      > kW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::MW_per_m2,
         Value_type
      > MW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::GW_per_m2,
         Value_type
      > GW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::TW_per_m2,
         Value_type
      > TW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::PW_per_m2,
         Value_type
      > PW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::EW_per_m2,
         Value_type
      > EW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::ZW_per_m2,
         Value_type
      > ZW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_flow_density::YW_per_m2,
         Value_type
      > YW_per_m2;
// non SI units...
    };

    struct heat_flow_density : heat_flow_density_<quantity_traits::default_value_type>{};

}//quan

#endif
