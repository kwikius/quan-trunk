#ifndef QUAN_MAGNETOMOTIVE_FORCE_HPP_INCLUDED
#define QUAN_MAGNETOMOTIVE_FORCE_HPP_INCLUDED
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

#include <quan/components/of_magnetomotive_force.hpp>

namespace quan{

   struct of_magnetomotive_force{

      struct yA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct A : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YA : quan::meta::unit<
         quan::meta::components::of_magnetomotive_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct magnetomotive_force_ : quan::meta::components::of_magnetomotive_force{

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::yA,
         Value_type
      > yA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::zA,
         Value_type
      > zA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::aA,
         Value_type
      > aA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::fA,
         Value_type
      > fA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::pA,
         Value_type
      > pA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::nA,
         Value_type
      > nA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::uA,
         Value_type
      > uA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::mA,
         Value_type
      > mA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::cA,
         Value_type
      > cA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::dA,
         Value_type
      > dA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::A,
         Value_type
      > A;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::daA,
         Value_type
      > daA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::hA,
         Value_type
      > hA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::kA,
         Value_type
      > kA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::MA,
         Value_type
      > MA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::GA,
         Value_type
      > GA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::TA,
         Value_type
      > TA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::PA,
         Value_type
      > PA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::EA,
         Value_type
      > EA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::ZA,
         Value_type
      > ZA;

      typedef quan::fixed_quantity<
         quan::of_magnetomotive_force::YA,
         Value_type
      > YA;
    };

    struct magnetomotive_force : magnetomotive_force_<quantity_traits::default_value_type>{};

}//quan

#endif
