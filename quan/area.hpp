#ifndef QUAN_AREA_HPP_INCLUDED
#define QUAN_AREA_HPP_INCLUDED
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

#include <quan/components/of_area.hpp>

namespace quan{


   struct of_area{

      struct ym2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-48> >
      >{};

      struct zm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-42> >
      >{};

      struct am2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-36> >
      >{};

      struct fm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-30> >
      >{};

      struct pm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct nm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct um2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct mm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct cm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-4> >
      >{};

      struct dm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct m2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct hm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<4> >
      >{};

      struct km2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Mm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Gm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Tm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

      struct Pm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<30> >
      >{};

      struct Em2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<36> >
      >{};

      struct Zm2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<42> >
      >{};

      struct Ym2 : quan::meta::unit<
         quan::meta::components::of_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<48> >
      >{};

   };

   template<
      typename Value_type
   >
   struct area_ : quan::meta::components::of_area{

      typedef quan::fixed_quantity<
         quan::of_area::ym2,
         Value_type
      > ym2;

      typedef quan::fixed_quantity<
         quan::of_area::zm2,
         Value_type
      > zm2;

      typedef quan::fixed_quantity<
         quan::of_area::am2,
         Value_type
      > am2;

      typedef quan::fixed_quantity<
         quan::of_area::fm2,
         Value_type
      > fm2;

      typedef quan::fixed_quantity<
         quan::of_area::pm2,
         Value_type
      > pm2;

      typedef quan::fixed_quantity<
         quan::of_area::nm2,
         Value_type
      > nm2;

      typedef quan::fixed_quantity<
         quan::of_area::um2,
         Value_type
      > um2;

      typedef quan::fixed_quantity<
         quan::of_area::mm2,
         Value_type
      > mm2;

      typedef quan::fixed_quantity<
         quan::of_area::cm2,
         Value_type
      > cm2;

      typedef quan::fixed_quantity<
         quan::of_area::dm2,
         Value_type
      > dm2;

      typedef quan::fixed_quantity<
         quan::of_area::m2,
         Value_type
      > m2;

      typedef quan::fixed_quantity<
         quan::of_area::dam2,
         Value_type
      > dam2;

      typedef quan::fixed_quantity<
         quan::of_area::hm2,
         Value_type
      > hm2;

      typedef quan::fixed_quantity<
         quan::of_area::km2,
         Value_type
      > km2;

      typedef quan::fixed_quantity<
         quan::of_area::Mm2,
         Value_type
      > Mm2;

      typedef quan::fixed_quantity<
         quan::of_area::Gm2,
         Value_type
      > Gm2;

      typedef quan::fixed_quantity<
         quan::of_area::Tm2,
         Value_type
      > Tm2;

      typedef quan::fixed_quantity<
         quan::of_area::Pm2,
         Value_type
      > Pm2;

      typedef quan::fixed_quantity<
         quan::of_area::Em2,
         Value_type
      > Em2;

      typedef quan::fixed_quantity<
         quan::of_area::Zm2,
         Value_type
      > Zm2;

      typedef quan::fixed_quantity<
         quan::of_area::Ym2,
         Value_type
      > Ym2;



        typedef fixed_quantity<
            typename non_si_unit::acre,
            Value_type
        > acre;

        typedef fixed_quantity<
            typename non_si_unit::a,
            Value_type
        > a;

        typedef fixed_quantity<
            typename non_si_unit::b,
            Value_type
        > b;

        typedef fixed_quantity<
            typename non_si_unit::circular_mil,
            Value_type
        > circular_mil;

        typedef fixed_quantity<
            typename non_si_unit::ha,
            Value_type
        > ha;

        typedef fixed_quantity<
            typename non_si_unit::ft2,
            Value_type
        > ft2;

        typedef fixed_quantity<
            typename non_si_unit::in2,
            Value_type
        > in2;

        typedef fixed_quantity<
            typename non_si_unit::mi2,
            Value_type
        > mi2;

        typedef fixed_quantity<
            typename non_si_unit::mi2_us_survey,
            Value_type
        > mi2_us_survey;

        typedef fixed_quantity<
            typename non_si_unit::yd2,
            Value_type
        > yd2;

    };

    struct area : area_<quantity_traits::default_value_type>{};

}//quan

#endif
