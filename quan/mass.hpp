#ifndef QUAN_MASS_HPP_INCLUDED
#define QUAN_MASS_HPP_INCLUDED
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

#include <quan/components/of_mass.hpp>

namespace quan{

   struct of_mass{

      struct yg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-27> >
      >{};

      struct zg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct ag : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct fg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct pg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct ng : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct ug : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct mg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct cg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-5> >
      >{};

      struct dg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-4> >
      >{};

      struct g : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct dag : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct hg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct kg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct Mg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Gg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Tg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Pg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Eg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Zg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Yg : quan::meta::unit<
         quan::meta::components::of_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

   };

   template<
      typename Value_type
   >
   struct mass_ : quan::meta::components::of_mass{

      typedef quan::fixed_quantity<
         quan::of_mass::yg,
         Value_type
      > yg;

      typedef quan::fixed_quantity<
         quan::of_mass::zg,
         Value_type
      > zg;

      typedef quan::fixed_quantity<
         quan::of_mass::ag,
         Value_type
      > ag;

      typedef quan::fixed_quantity<
         quan::of_mass::fg,
         Value_type
      > fg;

      typedef quan::fixed_quantity<
         quan::of_mass::pg,
         Value_type
      > pg;

      typedef quan::fixed_quantity<
         quan::of_mass::ng,
         Value_type
      > ng;

      typedef quan::fixed_quantity<
         quan::of_mass::ug,
         Value_type
      > ug;

      typedef quan::fixed_quantity<
         quan::of_mass::mg,
         Value_type
      > mg;

      typedef quan::fixed_quantity<
         quan::of_mass::cg,
         Value_type
      > cg;

      typedef quan::fixed_quantity<
         quan::of_mass::dg,
         Value_type
      > dg;

      typedef quan::fixed_quantity<
         quan::of_mass::g,
         Value_type
      > g;

      typedef quan::fixed_quantity<
         quan::of_mass::dag,
         Value_type
      > dag;

      typedef quan::fixed_quantity<
         quan::of_mass::hg,
         Value_type
      > hg;

      typedef quan::fixed_quantity<
         quan::of_mass::kg,
         Value_type
      > kg;

      typedef quan::fixed_quantity<
         quan::of_mass::Mg,
         Value_type
      > Mg;

      typedef quan::fixed_quantity<
         quan::of_mass::Gg,
         Value_type
      > Gg;

      typedef quan::fixed_quantity<
         quan::of_mass::Tg,
         Value_type
      > Tg;

      typedef quan::fixed_quantity<
         quan::of_mass::Pg,
         Value_type
      > Pg;

      typedef quan::fixed_quantity<
         quan::of_mass::Eg,
         Value_type
      > Eg;

      typedef quan::fixed_quantity<
         quan::of_mass::Zg,
         Value_type
      > Zg;

      typedef quan::fixed_quantity<
         quan::of_mass::Yg,
         Value_type
      > Yg;

// non si

        typedef fixed_quantity<
            typename non_si_unit::AT,
            Value_type
        > AT;

        typedef fixed_quantity<
            typename non_si_unit::ton_long,
            Value_type
        > ton_long;

        typedef fixed_quantity<
            typename non_si_unit::t,
            Value_type
        > t;

        typedef fixed_quantity<
            typename non_si_unit::carat,
            Value_type
        > carat;

        typedef fixed_quantity<
            typename non_si_unit::grain,
            Value_type
        > grain;

        typedef fixed_quantity<
            typename non_si_unit::hundredwgt_short,
            Value_type
        > hundredwgt_short;

        typedef fixed_quantity<
            typename non_si_unit::hundredwgt_long,
            Value_type
        > hundredwgt_long;

        typedef fixed_quantity<
            typename non_si_unit::oz,
            Value_type
        > oz;

        typedef fixed_quantity<
            typename non_si_unit::troy_oz,
            Value_type
        > troy_oz;

        typedef fixed_quantity<
            typename non_si_unit::dwt,
            Value_type
        > dwt;

        typedef fixed_quantity<
            typename non_si_unit::lb,
            Value_type
        > lb;

        typedef fixed_quantity<
            typename non_si_unit::troy_lb,
            Value_type
        > troy_lb;

        typedef fixed_quantity<
            typename non_si_unit::slug,
            Value_type
        > slug;

    };

    struct mass : mass_<quantity_traits::default_value_type>{};

}//quan

#endif
