#ifndef QUAN_THERMAL_DIFFUSIVITY_HPP_INCLUDED
#define QUAN_THERMAL_DIFFUSIVITY_HPP_INCLUDED
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

#include <quan/components/of_thermal_diffusivity.hpp>

namespace quan{

struct of_thermal_diffusivity{

      struct ym2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct am2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct um2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct m2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct km2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Mm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Gm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Tm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Pm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Em2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Zm2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct Ym2_per_s : quan::meta::unit<
         quan::meta::components::of_thermal_diffusivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct thermal_diffusivity_ : quan::meta::components::of_thermal_diffusivity{

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::ym2_per_s,
         Value_type
      > ym2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::zm2_per_s,
         Value_type
      > zm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::am2_per_s,
         Value_type
      > am2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::fm2_per_s,
         Value_type
      > fm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::pm2_per_s,
         Value_type
      > pm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::nm2_per_s,
         Value_type
      > nm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::um2_per_s,
         Value_type
      > um2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::mm2_per_s,
         Value_type
      > mm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::cm2_per_s,
         Value_type
      > cm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::dm2_per_s,
         Value_type
      > dm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::m2_per_s,
         Value_type
      > m2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::dam2_per_s,
         Value_type
      > dam2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::hm2_per_s,
         Value_type
      > hm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::km2_per_s,
         Value_type
      > km2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::Mm2_per_s,
         Value_type
      > Mm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::Gm2_per_s,
         Value_type
      > Gm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::Tm2_per_s,
         Value_type
      > Tm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::Pm2_per_s,
         Value_type
      > Pm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::Em2_per_s,
         Value_type
      > Em2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::Zm2_per_s,
         Value_type
      > Zm2_per_s;

      typedef quan::fixed_quantity<
         quan::of_thermal_diffusivity::Ym2_per_s,
         Value_type
      > Ym2_per_s;


// non SI units...
    };

    struct thermal_diffusivity : thermal_diffusivity_<quantity_traits::default_value_type>{};

}//quan

#endif
