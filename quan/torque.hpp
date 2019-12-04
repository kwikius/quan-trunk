#ifndef QUAN_TORQUE_HPP_INCLUDED
#define QUAN_TORQUE_HPP_INCLUDED
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

#include <quan/components/of_torque.hpp>

namespace quan{

   struct of_torque{

      struct yN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct N_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YN_m : quan::meta::unit<
         quan::meta::components::of_torque::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct torque_ : quan::meta::components::of_torque{

      typedef quan::fixed_quantity<
         quan::of_torque::yN_m,
         Value_type
      > yN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::zN_m,
         Value_type
      > zN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::aN_m,
         Value_type
      > aN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::fN_m,
         Value_type
      > fN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::pN_m,
         Value_type
      > pN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::nN_m,
         Value_type
      > nN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::uN_m,
         Value_type
      > uN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::mN_m,
         Value_type
      > mN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::cN_m,
         Value_type
      > cN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::dN_m,
         Value_type
      > dN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::N_m,
         Value_type
      > N_m;

      typedef quan::fixed_quantity<
         quan::of_torque::daN_m,
         Value_type
      > daN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::hN_m,
         Value_type
      > hN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::kN_m,
         Value_type
      > kN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::MN_m,
         Value_type
      > MN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::GN_m,
         Value_type
      > GN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::TN_m,
         Value_type
      > TN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::PN_m,
         Value_type
      > PN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::EN_m,
         Value_type
      > EN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::ZN_m,
         Value_type
      > ZN_m;

      typedef quan::fixed_quantity<
         quan::of_torque::YN_m,
         Value_type
      > YN_m;

    };

    struct torque : torque_<quantity_traits::default_value_type>{};

}//quan

#endif
