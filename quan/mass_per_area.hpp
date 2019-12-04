#ifndef QUAN_MASS_PER_AREA_HPP_INCLUDED
#define QUAN_MASS_PER_AREA_HPP_INCLUDED
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

#include <quan/components/of_mass_per_area.hpp>

namespace quan{

   struct of_mass_per_area{

      struct yg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-27> >
      >{};

      struct zg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct ag_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct fg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct pg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct ng_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct ug_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct mg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct cg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-5> >
      >{};

      struct dg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-4> >
      >{};

      struct g_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct dag_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct hg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct kg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct Mg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Gg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Tg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Pg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Eg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Zg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Yg_per_m2 : quan::meta::unit<
         quan::meta::components::of_mass_per_area::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

   };

   template<
      typename Value_type
   >
   struct mass_per_area_ : quan::meta::components::of_mass_per_area{

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::yg_per_m2,
         Value_type
      > yg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::zg_per_m2,
         Value_type
      > zg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::ag_per_m2,
         Value_type
      > ag_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::fg_per_m2,
         Value_type
      > fg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::pg_per_m2,
         Value_type
      > pg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::ng_per_m2,
         Value_type
      > ng_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::ug_per_m2,
         Value_type
      > ug_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::mg_per_m2,
         Value_type
      > mg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::cg_per_m2,
         Value_type
      > cg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::dg_per_m2,
         Value_type
      > dg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::g_per_m2,
         Value_type
      > g_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::dag_per_m2,
         Value_type
      > dag_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::hg_per_m2,
         Value_type
      > hg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::kg_per_m2,
         Value_type
      > kg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::Mg_per_m2,
         Value_type
      > Mg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::Gg_per_m2,
         Value_type
      > Gg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::Tg_per_m2,
         Value_type
      > Tg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::Pg_per_m2,
         Value_type
      > Pg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::Eg_per_m2,
         Value_type
      > Eg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::Zg_per_m2,
         Value_type
      > Zg_per_m2;

      typedef quan::fixed_quantity<
         quan::of_mass_per_area::Yg_per_m2,
         Value_type
      > Yg_per_m2;

    };

    struct mass_per_area : mass_per_area_<quantity_traits::default_value_type>{};

}//quan

#endif
