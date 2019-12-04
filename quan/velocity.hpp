#ifndef QUAN_VELOCITY_HPP_INCLUDED
#define QUAN_VELOCITY_HPP_INCLUDED
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

#include <quan/components/of_velocity.hpp>

namespace quan{

    struct of_velocity{

      struct ym_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct am_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct um_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct m_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct km_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Mm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Gm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Tm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Pm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Em_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Zm_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct Ym_per_s : quan::meta::unit<
         quan::meta::components::of_velocity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct velocity_ : quan::meta::components::of_velocity{

      typedef quan::fixed_quantity<
         quan::of_velocity::ym_per_s,
         Value_type
      > ym_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::zm_per_s,
         Value_type
      > zm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::am_per_s,
         Value_type
      > am_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::fm_per_s,
         Value_type
      > fm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::pm_per_s,
         Value_type
      > pm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::nm_per_s,
         Value_type
      > nm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::um_per_s,
         Value_type
      > um_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::mm_per_s,
         Value_type
      > mm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::cm_per_s,
         Value_type
      > cm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::dm_per_s,
         Value_type
      > dm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::m_per_s,
         Value_type
      > m_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::dam_per_s,
         Value_type
      > dam_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::hm_per_s,
         Value_type
      > hm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::km_per_s,
         Value_type
      > km_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::Mm_per_s,
         Value_type
      > Mm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::Gm_per_s,
         Value_type
      > Gm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::Tm_per_s,
         Value_type
      > Tm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::Pm_per_s,
         Value_type
      > Pm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::Em_per_s,
         Value_type
      > Em_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::Zm_per_s,
         Value_type
      > Zm_per_s;

      typedef quan::fixed_quantity<
         quan::of_velocity::Ym_per_s,
         Value_type
      > Ym_per_s;


        typedef fixed_quantity<
            typename non_si_unit::ft_per_h,
            Value_type
        > ft_per_h;

        typedef fixed_quantity<
            typename non_si_unit::ft_per_min,
            Value_type
        > ft_per_min;

        typedef fixed_quantity<
            typename non_si_unit::ft_per_s,
            Value_type
        > ft_per_s;

        typedef fixed_quantity<
            typename non_si_unit::in_per_s,
            Value_type
        > in_per_s;

        typedef fixed_quantity<
            typename non_si_unit::km_per_h,
            Value_type
        > km_per_h;

        typedef fixed_quantity<
            typename non_si_unit::knot,
            Value_type
        > knot;

        typedef fixed_quantity<
            typename non_si_unit::mi_per_h,
            Value_type
        > mi_per_h;

        typedef fixed_quantity<
            typename non_si_unit::mi_per_min,
            Value_type
        > mi_per_min;

        typedef fixed_quantity<
            typename non_si_unit::mi_per_s,
            Value_type
        > mi_per_s;

        typedef fixed_quantity<
            typename non_si_unit::mm_per_min,
            Value_type
        > mm_per_min;

    };

    struct velocity : velocity_<quantity_traits::default_value_type>{};

}//quan

#endif
