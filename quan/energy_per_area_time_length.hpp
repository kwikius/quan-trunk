#ifndef QUAN_energy_per_area_time_length_HPP_INCLUDED
#define QUAN_energy_per_area_time_length_HPP_INCLUDED
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

#include <quan/components/of_energy_per_area_time_length.hpp>

namespace quan{

   struct of_energy_per_area_time_length{

      struct yW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct W_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YW_per_m2_per_m : quan::meta::unit<
         quan::meta::components::of_energy_per_area_time_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct energy_per_area_time_length_ : quan::meta::components::of_energy_per_area_time_length{

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::yW_per_m2_per_m,
         Value_type
      > yW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::zW_per_m2_per_m,
         Value_type
      > zW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::aW_per_m2_per_m,
         Value_type
      > aW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::fW_per_m2_per_m,
         Value_type
      > fW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::pW_per_m2_per_m,
         Value_type
      > pW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::nW_per_m2_per_m,
         Value_type
      > nW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::uW_per_m2_per_m,
         Value_type
      > uW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::mW_per_m2_per_m,
         Value_type
      > mW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::cW_per_m2_per_m,
         Value_type
      > cW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::dW_per_m2_per_m,
         Value_type
      > dW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::W_per_m2_per_m,
         Value_type
      > W_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::daW_per_m2_per_m,
         Value_type
      > daW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::hW_per_m2_per_m,
         Value_type
      > hW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::kW_per_m2_per_m,
         Value_type
      > kW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::MW_per_m2_per_m,
         Value_type
      > MW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::GW_per_m2_per_m,
         Value_type
      > GW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::TW_per_m2_per_m,
         Value_type
      > TW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::PW_per_m2_per_m,
         Value_type
      > PW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::EW_per_m2_per_m,
         Value_type
      > EW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::ZW_per_m2_per_m,
         Value_type
      > ZW_per_m2_per_m;

      typedef quan::fixed_quantity<
         quan::of_energy_per_area_time_length::YW_per_m2_per_m,
         Value_type
      > YW_per_m2_per_m;


// non SI units...
    };

    struct energy_per_area_time_length : energy_per_area_time_length_<quantity_traits::default_value_type>{};

}//quan

#endif
