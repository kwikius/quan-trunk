#ifndef QUAN_HEAT_TRANSFER_COEFFICIENT_HPP_INCLUDED
#define QUAN_HEAT_TRANSFER_COEFFICIENT_HPP_INCLUDED
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

#include <quan/components/of_heat_transfer_coefficient.hpp>

namespace quan{

   struct of_heat_transfer_coefficient{

      struct yW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct W_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YW_per_m2_K : quan::meta::unit<
         quan::meta::components::of_heat_transfer_coefficient::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct heat_transfer_coefficient_ : quan::meta::components::of_heat_transfer_coefficient{

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::yW_per_m2_K,
         Value_type
      > yW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::zW_per_m2_K,
         Value_type
      > zW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::aW_per_m2_K,
         Value_type
      > aW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::fW_per_m2_K,
         Value_type
      > fW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::pW_per_m2_K,
         Value_type
      > pW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::nW_per_m2_K,
         Value_type
      > nW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::uW_per_m2_K,
         Value_type
      > uW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::mW_per_m2_K,
         Value_type
      > mW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::cW_per_m2_K,
         Value_type
      > cW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::dW_per_m2_K,
         Value_type
      > dW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::W_per_m2_K,
         Value_type
      > W_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::daW_per_m2_K,
         Value_type
      > daW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::hW_per_m2_K,
         Value_type
      > hW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::kW_per_m2_K,
         Value_type
      > kW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::MW_per_m2_K,
         Value_type
      > MW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::GW_per_m2_K,
         Value_type
      > GW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::TW_per_m2_K,
         Value_type
      > TW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::PW_per_m2_K,
         Value_type
      > PW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::EW_per_m2_K,
         Value_type
      > EW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::ZW_per_m2_K,
         Value_type
      > ZW_per_m2_K;

      typedef quan::fixed_quantity<
         quan::of_heat_transfer_coefficient::YW_per_m2_K,
         Value_type
      > YW_per_m2_K;

// non SI units...
    };

    struct heat_transfer_coefficient : heat_transfer_coefficient_<quantity_traits::default_value_type>{};

}//quan

#endif
