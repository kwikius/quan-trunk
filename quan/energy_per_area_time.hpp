#ifndef QUAN_ENERGY_PER_AREA_TIME_HPP_INCLUDED
#define QUAN_ENERGY_PER_AREA_TIME_HPP_INCLUDED
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

#include <quan/components/of_energy_per_area_time.hpp>

namespace quan{
 struct of_energy_per_area_time{

      struct yW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct W_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YW_per_m2 : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct energy_per_area_time_ : quan::meta::components::of_energy_per_area_time{

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::yW_per_m2,
         Value_type
      > yW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::zW_per_m2,
         Value_type
      > zW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::aW_per_m2,
         Value_type
      > aW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::fW_per_m2,
         Value_type
      > fW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::pW_per_m2,
         Value_type
      > pW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::nW_per_m2,
         Value_type
      > nW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::uW_per_m2,
         Value_type
      > uW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::mW_per_m2,
         Value_type
      > mW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::cW_per_m2,
         Value_type
      > cW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::dW_per_m2,
         Value_type
      > dW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::W_per_m2,
         Value_type
      > W_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::daW_per_m2,
         Value_type
      > daW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::hW_per_m2,
         Value_type
      > hW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::kW_per_m2,
         Value_type
      > kW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::MW_per_m2,
         Value_type
      > MW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::GW_per_m2,
         Value_type
      > GW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::TW_per_m2,
         Value_type
      > TW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::PW_per_m2,
         Value_type
      > PW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::EW_per_m2,
         Value_type
      > EW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::ZW_per_m2,
         Value_type
      > ZW_per_m2;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time::YW_per_m2,
         Value_type
      > YW_per_m2;

// non SI units...
    };

    struct energy_per_area_time : energy_per_area_time_<quantity_traits::default_value_type>{};

}//quan

#endif
