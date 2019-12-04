#ifndef QUAN_PERMEABILITY_HPP_INCLUDED
#define QUAN_PERMEABILITY_HPP_INCLUDED
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

#include <quan/components/of_permeability.hpp>

namespace quan{

   struct of_permeability{

      struct yg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-27> >
      >{};

      struct zg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct ag_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct fg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct pg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct ng_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct ug_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct mg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct cg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-5> >
      >{};

      struct dg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-4> >
      >{};

      struct g_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct dag_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct hg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct kg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct Mg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Gg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Tg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Pg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Eg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Zg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Yg_per_Pa_s_m2 : quan::meta::unit<
         quan::meta::components::of_permeability::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

   };

   template<
      typename Value_type
   >
   struct permeability_ : quan::meta::components::of_permeability{

      typedef quan::fixed_quantity<
         quan::of_permeability::yg_per_Pa_s_m2,
         Value_type
      > yg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::zg_per_Pa_s_m2,
         Value_type
      > zg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::ag_per_Pa_s_m2,
         Value_type
      > ag_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::fg_per_Pa_s_m2,
         Value_type
      > fg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::pg_per_Pa_s_m2,
         Value_type
      > pg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::ng_per_Pa_s_m2,
         Value_type
      > ng_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::ug_per_Pa_s_m2,
         Value_type
      > ug_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::mg_per_Pa_s_m2,
         Value_type
      > mg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::cg_per_Pa_s_m2,
         Value_type
      > cg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::dg_per_Pa_s_m2,
         Value_type
      > dg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::g_per_Pa_s_m2,
         Value_type
      > g_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::dag_per_Pa_s_m2,
         Value_type
      > dag_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::hg_per_Pa_s_m2,
         Value_type
      > hg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::kg_per_Pa_s_m2,
         Value_type
      > kg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::Mg_per_Pa_s_m2,
         Value_type
      > Mg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::Gg_per_Pa_s_m2,
         Value_type
      > Gg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::Tg_per_Pa_s_m2,
         Value_type
      > Tg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::Pg_per_Pa_s_m2,
         Value_type
      > Pg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::Eg_per_Pa_s_m2,
         Value_type
      > Eg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::Zg_per_Pa_s_m2,
         Value_type
      > Zg_per_Pa_s_m2;

      typedef quan::fixed_quantity<
         quan::of_permeability::Yg_per_Pa_s_m2,
         Value_type
      > Yg_per_Pa_s_m2;
// non SI units...
    };

    struct permeability : permeability_<quantity_traits::default_value_type>{};

}//quan

#endif
