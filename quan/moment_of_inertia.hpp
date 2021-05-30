#ifndef QUAN_MOMENT_OF_INERTIA_HPP_INCLUDED
#define QUAN_MOMENT_OF_INERTIA_HPP_INCLUDED
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

#include <quan/components/of_moment_of_inertia.hpp>

namespace quan{

   struct of_moment_of_inertia{

      struct yg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-27> >
      >{};

      struct zg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct ag_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct fg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct pg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct ng_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct ug_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct mg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct cg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-5> >
      >{};

      struct dg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-4> >
      >{};

      struct g_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct dag_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct hg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct kg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct Mg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Gg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Tg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Pg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Eg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Zg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Yg_m2 : quan::meta::unit<
         quan::meta::components::of_moment_of_inertia::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

   };

   template<
      typename Value_type
   >
   struct moment_of_inertia_ : quan::meta::components::of_moment_of_inertia{

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::yg_m2,
         Value_type
      > yg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::zg_m2,
         Value_type
      > zg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::ag_m2,
         Value_type
      > ag_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::fg_m2,
         Value_type
      > fg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::pg_m2,
         Value_type
      > pg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::ng_m2,
         Value_type
      > ng_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::ug_m2,
         Value_type
      > ug_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::mg_m2,
         Value_type
      > mg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::cg_m2,
         Value_type
      > cg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::dg_m2,
         Value_type
      > dg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::g_m2,
         Value_type
      > g_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::dag_m2,
         Value_type
      > dag_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::hg_m2,
         Value_type
      > hg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::kg_m2,
         Value_type
      > kg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::Mg_m2,
         Value_type
      > Mg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::Gg_m2,
         Value_type
      > Gg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::Tg_m2,
         Value_type
      > Tg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::Pg_m2,
         Value_type
      > Pg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::Eg_m2,
         Value_type
      > Eg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::Zg_m2,
         Value_type
      > Zg_m2;

      typedef quan::fixed_quantity<
         quan::of_moment_of_inertia::Yg_m2,
         Value_type
      > Yg_m2;

      typedef fixed_quantity<
         typename non_si_unit::slug_ft2,
          Value_type
       > slug_ft2;

    };

    struct moment_of_inertia : moment_of_inertia_<quantity_traits::default_value_type>{};

}//quan

#endif
