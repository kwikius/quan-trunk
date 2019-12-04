#ifndef QUAN_FORCE_PER_MASS_HPP_INCLUDED
#define QUAN_FORCE_PER_MASS_HPP_INCLUDED
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

#include <quan/components/of_force_per_mass.hpp>

namespace quan{

   struct of_force_per_mass{

      struct yN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct N_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YN_per_kg : quan::meta::unit<
         quan::meta::components::of_force_per_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct force_per_mass_ : quan::meta::components::of_force_per_mass{

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::yN_per_kg,
         Value_type
      > yN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::zN_per_kg,
         Value_type
      > zN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::aN_per_kg,
         Value_type
      > aN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::fN_per_kg,
         Value_type
      > fN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::pN_per_kg,
         Value_type
      > pN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::nN_per_kg,
         Value_type
      > nN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::uN_per_kg,
         Value_type
      > uN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::mN_per_kg,
         Value_type
      > mN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::cN_per_kg,
         Value_type
      > cN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::dN_per_kg,
         Value_type
      > dN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::N_per_kg,
         Value_type
      > N_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::daN_per_kg,
         Value_type
      > daN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::hN_per_kg,
         Value_type
      > hN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::kN_per_kg,
         Value_type
      > kN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::MN_per_kg,
         Value_type
      > MN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::GN_per_kg,
         Value_type
      > GN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::TN_per_kg,
         Value_type
      > TN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::PN_per_kg,
         Value_type
      > PN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::EN_per_kg,
         Value_type
      > EN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::ZN_per_kg,
         Value_type
      > ZN_per_kg;

      typedef quan::fixed_quantity<
         quan::of_force_per_mass::YN_per_kg,
         Value_type
      > YN_per_kg;
// non SI units...
    };

    struct force_per_mass : force_per_mass_<quantity_traits::default_value_type>{};

}//quan

#endif
