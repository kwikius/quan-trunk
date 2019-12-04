#ifndef QUAN_RECIPROCAL_MASS_HPP_INCLUDED
#define QUAN_RECIPROCAL_MASS_HPP_INCLUDED
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

#include <quan/components/of_reciprocal_mass.hpp>

namespace quan{

   struct of_reciprocal_mass{

      struct  per_yg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<27> >
      >{};

      struct  per_zg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

      struct  per_ag : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct  per_fg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct  per_pg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct  per_ng : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct  per_ug : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct  per_mg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct  per_cg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<5> >
      >{};

      struct  per_dg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<4> >
      >{};

      struct  per_g : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct  per_dag : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct  per_hg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct  per_kg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct  per_Mg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct  per_Gg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct  per_Tg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct  per_Pg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct  per_Eg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct  per_Zg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct  per_Yg : quan::meta::unit<
         quan::meta::components::of_reciprocal_mass::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

   };

   template<
      typename Value_type
   >
   struct reciprocal_mass_ : quan::meta::components::of_reciprocal_mass{

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_yg,
         Value_type
      >  per_yg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_zg,
         Value_type
      >  per_zg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_ag,
         Value_type
      >  per_ag;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_fg,
         Value_type
      >  per_fg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_pg,
         Value_type
      >  per_pg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_ng,
         Value_type
      >  per_ng;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_ug,
         Value_type
      >  per_ug;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_mg,
         Value_type
      >  per_mg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_cg,
         Value_type
      >  per_cg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_dg,
         Value_type
      >  per_dg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_g,
         Value_type
      >  per_g;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_dag,
         Value_type
      >  per_dag;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_hg,
         Value_type
      >  per_hg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_kg,
         Value_type
      >  per_kg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_Mg,
         Value_type
      >  per_Mg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_Gg,
         Value_type
      >  per_Gg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_Tg,
         Value_type
      >  per_Tg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_Pg,
         Value_type
      >  per_Pg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_Eg,
         Value_type
      >  per_Eg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_Zg,
         Value_type
      >  per_Zg;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_mass::per_Yg,
         Value_type
      >  per_Yg;

#if 0
    template<
        typename Value_type
    >
    struct reciprocal_mass_ : meta::components::of_reciprocal_mass{
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<27>
                >
            >,
            Value_type
        > per_yg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yotta // coherent-exponent 24
            >,
            Value_type
        > per_zg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > per_ag;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > per_fg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > per_pg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > per_ng;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > per_ug;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > per_mg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<5>
                >
            >,
            Value_type
        > per_cg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                meta::conversion_factor<
                    meta::rational<4>
                >
            >,
            Value_type
        > per_dg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > per_g;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > per_dag;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > per_hg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > per_kg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > per_Mg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > per_Gg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > per_Tg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > per_Pg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > per_Eg;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > per_Zg;
#endif
    };

    struct reciprocal_mass : reciprocal_mass_<quantity_traits::default_value_type>{};

}//quan

#endif
