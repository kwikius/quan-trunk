#ifndef QUAN_MAGNETIC_FIELD_STRENGTH_HPP_INCLUDED
#define QUAN_MAGNETIC_FIELD_STRENGTH_HPP_INCLUDED
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

#include <quan/components/of_magnetic_field_strength.hpp>

namespace quan{

 struct of_magnetic_field_strength{

      struct yA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct A_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YA_per_m : quan::meta::unit<
         quan::meta::components::of_magnetic_field_strength::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct magnetic_field_strength_ : quan::meta::components::of_magnetic_field_strength{

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::yA_per_m,
         Value_type
      > yA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::zA_per_m,
         Value_type
      > zA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::aA_per_m,
         Value_type
      > aA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::fA_per_m,
         Value_type
      > fA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::pA_per_m,
         Value_type
      > pA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::nA_per_m,
         Value_type
      > nA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::uA_per_m,
         Value_type
      > uA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::mA_per_m,
         Value_type
      > mA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::cA_per_m,
         Value_type
      > cA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::dA_per_m,
         Value_type
      > dA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::A_per_m,
         Value_type
      > A_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::daA_per_m,
         Value_type
      > daA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::hA_per_m,
         Value_type
      > hA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::kA_per_m,
         Value_type
      > kA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::MA_per_m,
         Value_type
      > MA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::GA_per_m,
         Value_type
      > GA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::TA_per_m,
         Value_type
      > TA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::PA_per_m,
         Value_type
      > PA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::EA_per_m,
         Value_type
      > EA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::ZA_per_m,
         Value_type
      > ZA_per_m;

      typedef quan::fixed_quantity<
         quan::of_magnetic_field_strength::YA_per_m,
         Value_type
      > YA_per_m;

    };

    struct magnetic_field_strength : magnetic_field_strength_<quantity_traits::default_value_type>{};

}//quan

#endif
