#ifndef QUAN_ENERGY_PER_MASS_HPP_INCLUDED
#define QUAN_ENERGY_PER_MASS_HPP_INCLUDED
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

#include <quan/components/of_energy_per_mass.hpp>

namespace quan{

 struct of_energy_per_mass{

      struct yJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct J_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YJ_per_kg : quan::meta::unit<
         quan::meta::components::of_energy_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct energy_per_mass_ : quan::meta::components::of_energy_per_mass{

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::yJ_per_kg,
         Value_type
      > yJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::zJ_per_kg,
         Value_type
      > zJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::aJ_per_kg,
         Value_type
      > aJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::fJ_per_kg,
         Value_type
      > fJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::pJ_per_kg,
         Value_type
      > pJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::nJ_per_kg,
         Value_type
      > nJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::uJ_per_kg,
         Value_type
      > uJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::mJ_per_kg,
         Value_type
      > mJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::cJ_per_kg,
         Value_type
      > cJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::dJ_per_kg,
         Value_type
      > dJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::J_per_kg,
         Value_type
      > J_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::daJ_per_kg,
         Value_type
      > daJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::hJ_per_kg,
         Value_type
      > hJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::kJ_per_kg,
         Value_type
      > kJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::MJ_per_kg,
         Value_type
      > MJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::GJ_per_kg,
         Value_type
      > GJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::TJ_per_kg,
         Value_type
      > TJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::PJ_per_kg,
         Value_type
      > PJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::EJ_per_kg,
         Value_type
      > EJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::ZJ_per_kg,
         Value_type
      > ZJ_per_kg;

      typedef quan::fixed_quantity<
         quan::of_energy_per_mass::YJ_per_kg,
         Value_type
      > YJ_per_kg;
// non SI units...
    };

    struct energy_per_mass : energy_per_mass_<quantity_traits::default_value_type>{};

}//quan

#endif
