#ifndef QUAN_FUEL_CONSUMPTION_HPP_INCLUDED
#define QUAN_FUEL_CONSUMPTION_HPP_INCLUDED
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

#include <quan/components/of_fuel_consumption.hpp>

namespace quan{

 struct of_fuel_consumption{

      struct ym_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct am_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct um_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct m_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct km_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Mm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Gm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Tm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Pm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Em_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Zm_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct Ym_per_m3 : quan::meta::unit<
         quan::meta::components::of_fuel_consumption::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct fuel_consumption_ : quan::meta::components::of_fuel_consumption{

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::ym_per_m3,
         Value_type
      > ym_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::zm_per_m3,
         Value_type
      > zm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::am_per_m3,
         Value_type
      > am_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::fm_per_m3,
         Value_type
      > fm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::pm_per_m3,
         Value_type
      > pm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::nm_per_m3,
         Value_type
      > nm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::um_per_m3,
         Value_type
      > um_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::mm_per_m3,
         Value_type
      > mm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::cm_per_m3,
         Value_type
      > cm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::dm_per_m3,
         Value_type
      > dm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::m_per_m3,
         Value_type
      > m_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::dam_per_m3,
         Value_type
      > dam_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::hm_per_m3,
         Value_type
      > hm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::km_per_m3,
         Value_type
      > km_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::Mm_per_m3,
         Value_type
      > Mm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::Gm_per_m3,
         Value_type
      > Gm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::Tm_per_m3,
         Value_type
      > Tm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::Pm_per_m3,
         Value_type
      > Pm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::Em_per_m3,
         Value_type
      > Em_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::Zm_per_m3,
         Value_type
      > Zm_per_m3;

      typedef quan::fixed_quantity<
         quan::of_fuel_consumption::Ym_per_m3,
         Value_type
      > Ym_per_m3;

// non SI units...
    };

    struct fuel_consumption : fuel_consumption_<quantity_traits::default_value_type>{};

}//quan

#endif
