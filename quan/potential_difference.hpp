#ifndef QUAN_POTENTIAL_DIFFERENCE_HPP_INCLUDED
#define QUAN_POTENTIAL_DIFFERENCE_HPP_INCLUDED
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

#include <quan/components/of_potential_difference.hpp>

namespace quan{

   struct of_potential_difference{

      struct yV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct V : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YV : quan::meta::unit<
         quan::meta::components::of_potential_difference::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct potential_difference_ : quan::meta::components::of_potential_difference{

      typedef quan::fixed_quantity<
         quan::of_potential_difference::yV,
         Value_type
      > yV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::zV,
         Value_type
      > zV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::aV,
         Value_type
      > aV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::fV,
         Value_type
      > fV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::pV,
         Value_type
      > pV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::nV,
         Value_type
      > nV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::uV,
         Value_type
      > uV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::mV,
         Value_type
      > mV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::cV,
         Value_type
      > cV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::dV,
         Value_type
      > dV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::V,
         Value_type
      > V;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::daV,
         Value_type
      > daV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::hV,
         Value_type
      > hV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::kV,
         Value_type
      > kV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::MV,
         Value_type
      > MV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::GV,
         Value_type
      > GV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::TV,
         Value_type
      > TV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::PV,
         Value_type
      > PV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::EV,
         Value_type
      > EV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::ZV,
         Value_type
      > ZV;

      typedef quan::fixed_quantity<
         quan::of_potential_difference::YV,
         Value_type
      > YV;

    };

    struct potential_difference : potential_difference_<quantity_traits::default_value_type>{};

}//quan

#endif
