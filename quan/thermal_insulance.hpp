#ifndef QUAN_THERMAL_INSULANCE_HPP_INCLUDED
#define QUAN_THERMAL_INSULANCE_HPP_INCLUDED
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

#include <quan/components/of_thermal_insulance.hpp>

namespace quan{


 struct of_thermal_insulance{

      struct ym2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct am2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct um2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct m2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct km2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Mm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Gm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Tm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Pm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Em2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Zm2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct Ym2_K_per_W : quan::meta::unit<
         quan::meta::components::of_thermal_insulance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct thermal_insulance_ : quan::meta::components::of_thermal_insulance{

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::ym2_K_per_W,
         Value_type
      > ym2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::zm2_K_per_W,
         Value_type
      > zm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::am2_K_per_W,
         Value_type
      > am2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::fm2_K_per_W,
         Value_type
      > fm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::pm2_K_per_W,
         Value_type
      > pm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::nm2_K_per_W,
         Value_type
      > nm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::um2_K_per_W,
         Value_type
      > um2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::mm2_K_per_W,
         Value_type
      > mm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::cm2_K_per_W,
         Value_type
      > cm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::dm2_K_per_W,
         Value_type
      > dm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::m2_K_per_W,
         Value_type
      > m2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::dam2_K_per_W,
         Value_type
      > dam2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::hm2_K_per_W,
         Value_type
      > hm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::km2_K_per_W,
         Value_type
      > km2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::Mm2_K_per_W,
         Value_type
      > Mm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::Gm2_K_per_W,
         Value_type
      > Gm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::Tm2_K_per_W,
         Value_type
      > Tm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::Pm2_K_per_W,
         Value_type
      > Pm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::Em2_K_per_W,
         Value_type
      > Em2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::Zm2_K_per_W,
         Value_type
      > Zm2_K_per_W;

      typedef quan::fixed_quantity<
         quan::of_thermal_insulance::Ym2_K_per_W,
         Value_type
      > Ym2_K_per_W;


// non SI units...
    };

    struct thermal_insulance : thermal_insulance_<quantity_traits::default_value_type>{};

}//quan

#endif
