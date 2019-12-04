#ifndef QUAN_VOLUME_PER_ENERGY_HPP_INCLUDED
#define QUAN_VOLUME_PER_ENERGY_HPP_INCLUDED
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

#include <quan/components/of_volume_per_energy.hpp>

namespace quan{

 struct of_volume_per_energy{

      struct ym3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct am3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct um3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct m3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct km3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Mm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Gm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Tm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Pm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Em3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Zm3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct Ym3_per_J : quan::meta::unit<
         quan::meta::components::of_volume_per_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct volume_per_energy_ : quan::meta::components::of_volume_per_energy{

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::ym3_per_J,
         Value_type
      > ym3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::zm3_per_J,
         Value_type
      > zm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::am3_per_J,
         Value_type
      > am3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::fm3_per_J,
         Value_type
      > fm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::pm3_per_J,
         Value_type
      > pm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::nm3_per_J,
         Value_type
      > nm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::um3_per_J,
         Value_type
      > um3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::mm3_per_J,
         Value_type
      > mm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::cm3_per_J,
         Value_type
      > cm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::dm3_per_J,
         Value_type
      > dm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::m3_per_J,
         Value_type
      > m3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::dam3_per_J,
         Value_type
      > dam3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::hm3_per_J,
         Value_type
      > hm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::km3_per_J,
         Value_type
      > km3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::Mm3_per_J,
         Value_type
      > Mm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::Gm3_per_J,
         Value_type
      > Gm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::Tm3_per_J,
         Value_type
      > Tm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::Pm3_per_J,
         Value_type
      > Pm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::Em3_per_J,
         Value_type
      > Em3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::Zm3_per_J,
         Value_type
      > Zm3_per_J;

      typedef quan::fixed_quantity<
         quan::of_volume_per_energy::Ym3_per_J,
         Value_type
      > Ym3_per_J;


// non SI units...
    };

    struct volume_per_energy : volume_per_energy_<quantity_traits::default_value_type>{};

}//quan

#endif
