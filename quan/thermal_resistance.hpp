#ifndef QUAN_THERMAL_RESISTANCE_HPP_INCLUDED
#define QUAN_THERMAL_RESISTANCE_HPP_INCLUDED
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

#include <quan/components/of_thermal_resistance.hpp>

namespace quan{

     struct of_thermal_resistance{

      struct yK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YK_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct thermal_resistance_ : quan::meta::components::of_thermal_resistance{

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::yK_per_W,
         Value_type
      > yK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::zK_per_W,
         Value_type
      > zK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::aK_per_W,
         Value_type
      > aK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::fK_per_W,
         Value_type
      > fK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::pK_per_W,
         Value_type
      > pK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::nK_per_W,
         Value_type
      > nK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::uK_per_W,
         Value_type
      > uK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::mK_per_W,
         Value_type
      > mK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::cK_per_W,
         Value_type
      > cK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::dK_per_W,
         Value_type
      > dK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::K_per_W,
         Value_type
      > K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::daK_per_W,
         Value_type
      > daK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::hK_per_W,
         Value_type
      > hK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::kK_per_W,
         Value_type
      > kK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::MK_per_W,
         Value_type
      > MK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::GK_per_W,
         Value_type
      > GK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::TK_per_W,
         Value_type
      > TK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::PK_per_W,
         Value_type
      > PK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::EK_per_W,
         Value_type
      > EK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::ZK_per_W,
         Value_type
      > ZK_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistance::YK_per_W,
         Value_type
      > YK_per_W;
// non SI units...
    };

    struct thermal_resistance : thermal_resistance_<quantity_traits::default_value_type>{};

}//quan

#endif
