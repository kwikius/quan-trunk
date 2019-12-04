#ifndef QUAN_MAGNETIC_PERMEABILITY_HPP_INCLUDED
#define QUAN_MAGNETIC_PERMEABILITY_HPP_INCLUDED
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

#include <quan/components/of_magnetic_permeability.hpp>

namespace quan{

   struct of_magnetic_permeability{

      struct yH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct H_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YH_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct magnetic_permeability_ : quan::meta::components::of_magnetic_permeability{

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::yH_per_m,
         Value_type
      > yH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::zH_per_m,
         Value_type
      > zH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::aH_per_m,
         Value_type
      > aH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::fH_per_m,
         Value_type
      > fH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::pH_per_m,
         Value_type
      > pH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::nH_per_m,
         Value_type
      > nH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::uH_per_m,
         Value_type
      > uH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::mH_per_m,
         Value_type
      > mH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::cH_per_m,
         Value_type
      > cH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::dH_per_m,
         Value_type
      > dH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::H_per_m,
         Value_type
      > H_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::daH_per_m,
         Value_type
      > daH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::hH_per_m,
         Value_type
      > hH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::kH_per_m,
         Value_type
      > kH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::MH_per_m,
         Value_type
      > MH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::GH_per_m,
         Value_type
      > GH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::TH_per_m,
         Value_type
      > TH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::PH_per_m,
         Value_type
      > PH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::EH_per_m,
         Value_type
      > EH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::ZH_per_m,
         Value_type
      > ZH_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_permeability::YH_per_m,
         Value_type
      > YH_per_m;
    };

    struct magnetic_permeability : magnetic_permeability_<quantity_traits::default_value_type>{};

}//quan

#endif
