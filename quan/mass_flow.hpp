#ifndef QUAN_MASS_FLOW_HPP_INCLUDED
#define QUAN_MASS_FLOW_HPP_INCLUDED
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

#include <quan/components/of_mass_flow.hpp>

namespace quan{

    struct of_mass_flow{

      struct yg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-27> >
      >{};

      struct zg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct ag_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct fg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct pg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct ng_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct ug_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct mg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct cg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-5> >
      >{};

      struct dg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-4> >
      >{};

      struct g_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct dag_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct hg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct kg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct Mg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Gg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Tg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Pg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Eg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Zg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Yg_per_s : quan::meta::unit<
         quan::meta::components::of_mass_flow::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

   };

   template<
      typename Value_type
   >
   struct mass_flow_ : quan::meta::components::of_mass_flow{

      typedef quan::fixed_quantity<
         quan::of_mass_flow::yg_per_s,
         Value_type
      > yg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::zg_per_s,
         Value_type
      > zg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::ag_per_s,
         Value_type
      > ag_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::fg_per_s,
         Value_type
      > fg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::pg_per_s,
         Value_type
      > pg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::ng_per_s,
         Value_type
      > ng_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::ug_per_s,
         Value_type
      > ug_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::mg_per_s,
         Value_type
      > mg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::cg_per_s,
         Value_type
      > cg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::dg_per_s,
         Value_type
      > dg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::g_per_s,
         Value_type
      > g_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::dag_per_s,
         Value_type
      > dag_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::hg_per_s,
         Value_type
      > hg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::kg_per_s,
         Value_type
      > kg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::Mg_per_s,
         Value_type
      > Mg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::Gg_per_s,
         Value_type
      > Gg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::Tg_per_s,
         Value_type
      > Tg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::Pg_per_s,
         Value_type
      > Pg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::Eg_per_s,
         Value_type
      > Eg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::Zg_per_s,
         Value_type
      > Zg_per_s;

      typedef quan::fixed_quantity<
         quan::of_mass_flow::Yg_per_s,
         Value_type
      > Yg_per_s;

    };

    struct mass_flow : mass_flow_<quantity_traits::default_value_type>{};

}//quan

#endif
