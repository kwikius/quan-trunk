#ifndef QUAN_VOLUME_HPP_INCLUDED
#define QUAN_VOLUME_HPP_INCLUDED
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

#include <quan/components/of_volume.hpp>

namespace quan{

   struct of_volume{

      struct ym3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-72> >
      >{};

      struct zm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-63> >
      >{};

      struct am3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-54> >
      >{};

      struct fm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-45> >
      >{};

      struct pm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-36> >
      >{};

      struct nm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-27> >
      >{};

      struct um3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct mm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct cm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct dm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct m3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dam3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct hm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct km3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Mm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Gm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<27> >
      >{};

      struct Tm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<36> >
      >{};

      struct Pm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<45> >
      >{};

      struct Em3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<54> >
      >{};

      struct Zm3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<63> >
      >{};

      struct Ym3 : quan::meta::unit<
         quan::meta::components::of_volume::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<72> >
      >{};

   };

   template<
      typename Value_type
   >
   struct volume_ : quan::meta::components::of_volume{

      typedef quan::fixed_quantity<
         quan::of_volume::ym3,
         Value_type
      > ym3;

      typedef quan::fixed_quantity<
         quan::of_volume::zm3,
         Value_type
      > zm3;

      typedef quan::fixed_quantity<
         quan::of_volume::am3,
         Value_type
      > am3;

      typedef quan::fixed_quantity<
         quan::of_volume::fm3,
         Value_type
      > fm3;

      typedef quan::fixed_quantity<
         quan::of_volume::pm3,
         Value_type
      > pm3;

      typedef quan::fixed_quantity<
         quan::of_volume::nm3,
         Value_type
      > nm3;

      typedef quan::fixed_quantity<
         quan::of_volume::um3,
         Value_type
      > um3;

      typedef quan::fixed_quantity<
         quan::of_volume::mm3,
         Value_type
      > mm3;

      typedef quan::fixed_quantity<
         quan::of_volume::cm3,
         Value_type
      > cm3;

      typedef quan::fixed_quantity<
         quan::of_volume::dm3,
         Value_type
      > dm3;

      typedef quan::fixed_quantity<
         quan::of_volume::m3,
         Value_type
      > m3;

      typedef quan::fixed_quantity<
         quan::of_volume::dam3,
         Value_type
      > dam3;

      typedef quan::fixed_quantity<
         quan::of_volume::hm3,
         Value_type
      > hm3;

      typedef quan::fixed_quantity<
         quan::of_volume::km3,
         Value_type
      > km3;

      typedef quan::fixed_quantity<
         quan::of_volume::Mm3,
         Value_type
      > Mm3;

      typedef quan::fixed_quantity<
         quan::of_volume::Gm3,
         Value_type
      > Gm3;

      typedef quan::fixed_quantity<
         quan::of_volume::Tm3,
         Value_type
      > Tm3;

      typedef quan::fixed_quantity<
         quan::of_volume::Pm3,
         Value_type
      > Pm3;

      typedef quan::fixed_quantity<
         quan::of_volume::Em3,
         Value_type
      > Em3;

      typedef quan::fixed_quantity<
         quan::of_volume::Zm3,
         Value_type
      > Zm3;

      typedef quan::fixed_quantity<
         quan::of_volume::Ym3,
         Value_type
      > Ym3;


        typedef fixed_quantity<
            typename non_si_unit::acre_foot,
            Value_type
        > acre_foot;

        typedef fixed_quantity<
            typename non_si_unit::bbl,
            Value_type
        > bbl;

        typedef fixed_quantity<
            typename non_si_unit::bu,
            Value_type
        > bu;

        typedef fixed_quantity<
            typename non_si_unit::cord,
            Value_type
        > cord;

        typedef fixed_quantity<
            typename non_si_unit::ft3,
            Value_type
        > ft3;

        typedef fixed_quantity<
            typename non_si_unit::in3,
            Value_type
        > in3;

        typedef fixed_quantity<
            typename non_si_unit::mi3,
            Value_type
        > mi3;

        typedef fixed_quantity<
            typename non_si_unit::yd3,
            Value_type
        > yd3;

        typedef fixed_quantity<
            typename non_si_unit::cup,
            Value_type
        > cup;

        typedef fixed_quantity<
            typename non_si_unit::fl_oz_US,
            Value_type
        > fl_oz_US;

        typedef fixed_quantity<
            typename non_si_unit::gal,
            Value_type
        > gal;

        typedef fixed_quantity<
            typename non_si_unit::gal_US,
            Value_type
        > gal_US;

    };

    struct volume : volume_<quantity_traits::default_value_type>{};

}//quan

#endif
