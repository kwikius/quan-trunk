#ifndef QUAN_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
#define QUAN_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
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


#include <quan/components/of_area_moment_of_inertia.hpp>

namespace quan{

    struct of_area_moment_of_inertia{

      struct ym4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-96> >
      >{};

      struct zm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-84> >
      >{};

      struct am4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-72> >
      >{};

      struct fm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-60> >
      >{};

      struct pm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-48> >
      >{};

      struct nm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-36> >
      >{};

      struct um4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct mm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct cm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-8> >
      >{};

      struct dm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-4> >
      >{};

      struct m4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<4> >
      >{};

      struct hm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<8> >
      >{};

      struct km4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Mm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

      struct Gm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<36> >
      >{};

      struct Tm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<48> >
      >{};

      struct Pm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<60> >
      >{};

      struct Em4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<72> >
      >{};

      struct Zm4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<84> >
      >{};

      struct Ym4 : quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<96> >
      >{};

   };

   template<
      typename Value_type
   >
   struct area_moment_of_inertia_ : quan::meta::components::of_area_moment_of_inertia{

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::ym4,
         Value_type
      > ym4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::zm4,
         Value_type
      > zm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::am4,
         Value_type
      > am4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::fm4,
         Value_type
      > fm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::pm4,
         Value_type
      > pm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::nm4,
         Value_type
      > nm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::um4,
         Value_type
      > um4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::mm4,
         Value_type
      > mm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::cm4,
         Value_type
      > cm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::dm4,
         Value_type
      > dm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::m4,
         Value_type
      > m4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::dam4,
         Value_type
      > dam4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::hm4,
         Value_type
      > hm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::km4,
         Value_type
      > km4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::Mm4,
         Value_type
      > Mm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::Gm4,
         Value_type
      > Gm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::Tm4,
         Value_type
      > Tm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::Pm4,
         Value_type
      > Pm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::Em4,
         Value_type
      > Em4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::Zm4,
         Value_type
      > Zm4;

      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::Ym4,
         Value_type
      > Ym4;


    };

    struct area_moment_of_inertia 
    : area_moment_of_inertia_<quantity_traits::default_value_type>{};

}//quan

#endif
