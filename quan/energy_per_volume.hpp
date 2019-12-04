#ifndef QUAN_ENERGY_PER_VOLUME_HPP_INCLUDED
#define QUAN_ENERGY_PER_VOLUME_HPP_INCLUDED
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

#include <quan/components/of_energy_per_volume.hpp>

namespace quan{
 struct of_energy_per_volume{

      struct yJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct J_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YJ_per_m3 : quan::meta::unit<
         quan::meta::components::of_energy_per_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct energy_per_volume_ : quan::meta::components::of_energy_per_volume{

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::yJ_per_m3,
         Value_type
      > yJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::zJ_per_m3,
         Value_type
      > zJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::aJ_per_m3,
         Value_type
      > aJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::fJ_per_m3,
         Value_type
      > fJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::pJ_per_m3,
         Value_type
      > pJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::nJ_per_m3,
         Value_type
      > nJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::uJ_per_m3,
         Value_type
      > uJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::mJ_per_m3,
         Value_type
      > mJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::cJ_per_m3,
         Value_type
      > cJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::dJ_per_m3,
         Value_type
      > dJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::J_per_m3,
         Value_type
      > J_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::daJ_per_m3,
         Value_type
      > daJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::hJ_per_m3,
         Value_type
      > hJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::kJ_per_m3,
         Value_type
      > kJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::MJ_per_m3,
         Value_type
      > MJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::GJ_per_m3,
         Value_type
      > GJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::TJ_per_m3,
         Value_type
      > TJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::PJ_per_m3,
         Value_type
      > PJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::EJ_per_m3,
         Value_type
      > EJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::ZJ_per_m3,
         Value_type
      > ZJ_per_m3;

      typedef quan::fixed_quantity<
         quan::of_energy_per_volume::YJ_per_m3,
         Value_type
      > YJ_per_m3;

// non SI units...
    };

    struct energy_per_volume : energy_per_volume_<quantity_traits::default_value_type>{};

}//quan

#endif
