#ifndef QUAN_HEAT_DENSITY_HPP_INCLUDED
#define QUAN_HEAT_DENSITY_HPP_INCLUDED
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

#include <quan/components/of_heat_density.hpp>

namespace quan{

   struct of_heat_density{

      struct yJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct J_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YJ_per_m2 : quan::meta::unit<
         quan::meta::components::of_heat_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct heat_density_ : quan::meta::components::of_heat_density{

      typedef quan::fixed_quantity<
         quan::of_heat_density::yJ_per_m2,
         Value_type
      > yJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::zJ_per_m2,
         Value_type
      > zJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::aJ_per_m2,
         Value_type
      > aJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::fJ_per_m2,
         Value_type
      > fJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::pJ_per_m2,
         Value_type
      > pJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::nJ_per_m2,
         Value_type
      > nJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::uJ_per_m2,
         Value_type
      > uJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::mJ_per_m2,
         Value_type
      > mJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::cJ_per_m2,
         Value_type
      > cJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::dJ_per_m2,
         Value_type
      > dJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::J_per_m2,
         Value_type
      > J_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::daJ_per_m2,
         Value_type
      > daJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::hJ_per_m2,
         Value_type
      > hJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::kJ_per_m2,
         Value_type
      > kJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::MJ_per_m2,
         Value_type
      > MJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::GJ_per_m2,
         Value_type
      > GJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::TJ_per_m2,
         Value_type
      > TJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::PJ_per_m2,
         Value_type
      > PJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::EJ_per_m2,
         Value_type
      > EJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::ZJ_per_m2,
         Value_type
      > ZJ_per_m2;

      typedef quan::fixed_quantity<
         quan::of_heat_density::YJ_per_m2,
         Value_type
      > YJ_per_m2;


// non SI units...
    };

    struct heat_density : heat_density_<quantity_traits::default_value_type>{};

}//quan

#endif
