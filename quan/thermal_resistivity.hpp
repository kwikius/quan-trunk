#ifndef QUAN_THERMAL_RESISTIVITY_HPP_INCLUDED
#define QUAN_THERMAL_RESISTIVITY_HPP_INCLUDED
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

#include <quan/components/of_thermal_resistivity.hpp>

namespace quan{

   struct of_thermal_resistivity{

      struct ym_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct am_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct um_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct m_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct km_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Mm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Gm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Tm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Pm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Em_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Zm_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct Ym_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct thermal_resistivity_ : quan::meta::components::of_thermal_resistivity{

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::ym_K_per_W,
         Value_type
      > ym_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::zm_K_per_W,
         Value_type
      > zm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::am_K_per_W,
         Value_type
      > am_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::fm_K_per_W,
         Value_type
      > fm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::pm_K_per_W,
         Value_type
      > pm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::nm_K_per_W,
         Value_type
      > nm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::um_K_per_W,
         Value_type
      > um_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::mm_K_per_W,
         Value_type
      > mm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::cm_K_per_W,
         Value_type
      > cm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::dm_K_per_W,
         Value_type
      > dm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::m_K_per_W,
         Value_type
      > m_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::dam_K_per_W,
         Value_type
      > dam_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::hm_K_per_W,
         Value_type
      > hm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::km_K_per_W,
         Value_type
      > km_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::Mm_K_per_W,
         Value_type
      > Mm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::Gm_K_per_W,
         Value_type
      > Gm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::Tm_K_per_W,
         Value_type
      > Tm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::Pm_K_per_W,
         Value_type
      > Pm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::Em_K_per_W,
         Value_type
      > Em_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::Zm_K_per_W,
         Value_type
      > Zm_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_resistivity::Ym_K_per_W,
         Value_type
      > Ym_K_per_W;


// non SI units...
    };

    struct thermal_resistivity : thermal_resistivity_<quantity_traits::default_value_type>{};

}//quan

#endif
