#ifndef QUAN_DENSITY_HPP_INCLUDED
#define QUAN_DENSITY_HPP_INCLUDED
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

#include <quan/components/of_density.hpp>

namespace quan{


   struct of_density{

      struct yg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-27> >
      >{};

      struct zg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct ag_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct fg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct pg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct ng_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct ug_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct mg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct cg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-5> >
      >{};

      struct dg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-4> >
      >{};

      struct g_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct dag_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct hg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct kg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct Mg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Gg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Tg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Pg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Eg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Zg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Yg_per_m3 : quan::meta::unit<
         quan::meta::components::of_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

   };

   template<
      typename Value_type
   >
   struct density_ : quan::meta::components::of_density{

      typedef quan::fixed_quantity<
         quan::of_density::yg_per_m3,
         Value_type
      > yg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::zg_per_m3,
         Value_type
      > zg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::ag_per_m3,
         Value_type
      > ag_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::fg_per_m3,
         Value_type
      > fg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::pg_per_m3,
         Value_type
      > pg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::ng_per_m3,
         Value_type
      > ng_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::ug_per_m3,
         Value_type
      > ug_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::mg_per_m3,
         Value_type
      > mg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::cg_per_m3,
         Value_type
      > cg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::dg_per_m3,
         Value_type
      > dg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::g_per_m3,
         Value_type
      > g_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::dag_per_m3,
         Value_type
      > dag_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::hg_per_m3,
         Value_type
      > hg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::kg_per_m3,
         Value_type
      > kg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::Mg_per_m3,
         Value_type
      > Mg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::Gg_per_m3,
         Value_type
      > Gg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::Tg_per_m3,
         Value_type
      > Tg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::Pg_per_m3,
         Value_type
      > Pg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::Eg_per_m3,
         Value_type
      > Eg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::Zg_per_m3,
         Value_type
      > Zg_per_m3;

      typedef quan::fixed_quantity<
         quan::of_density::Yg_per_m3,
         Value_type
      > Yg_per_m3;


    };

    struct density : density_<quantity_traits::default_value_type>{};

}//quan

#endif
