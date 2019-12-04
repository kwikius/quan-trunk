#ifndef QUAN_FORCE_PER_LENGTH_HPP_INCLUDED
#define QUAN_FORCE_PER_LENGTH_HPP_INCLUDED
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

#include <quan/components/of_force_per_length.hpp>

namespace quan{

    struct of_force_per_length{

      struct yN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct N_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YN_per_m : quan::meta::unit<
         quan::meta::components::of_force_per_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct force_per_length_ : quan::meta::components::of_force_per_length{

      typedef quan::fixed_quantity<
         quan::of_force_per_length::yN_per_m,
         Value_type
      > yN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::zN_per_m,
         Value_type
      > zN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::aN_per_m,
         Value_type
      > aN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::fN_per_m,
         Value_type
      > fN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::pN_per_m,
         Value_type
      > pN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::nN_per_m,
         Value_type
      > nN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::uN_per_m,
         Value_type
      > uN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::mN_per_m,
         Value_type
      > mN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::cN_per_m,
         Value_type
      > cN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::dN_per_m,
         Value_type
      > dN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::N_per_m,
         Value_type
      > N_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::daN_per_m,
         Value_type
      > daN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::hN_per_m,
         Value_type
      > hN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::kN_per_m,
         Value_type
      > kN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::MN_per_m,
         Value_type
      > MN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::GN_per_m,
         Value_type
      > GN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::TN_per_m,
         Value_type
      > TN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::PN_per_m,
         Value_type
      > PN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::EN_per_m,
         Value_type
      > EN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::ZN_per_m,
         Value_type
      > ZN_per_m;

      typedef quan::fixed_quantity<
         quan::of_force_per_length::YN_per_m,
         Value_type
      > YN_per_m;

    };

    struct force_per_length : force_per_length_<quantity_traits::default_value_type>{};

}//quan

#endif
