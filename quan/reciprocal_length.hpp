#ifndef QUAN_RECIPROCAL_LENGTH_HPP_INCLUDED
#define QUAN_RECIPROCAL_LENGTH_HPP_INCLUDED
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

#include <quan/components/of_reciprocal_length.hpp>


namespace quan{

   struct of_reciprocal_length{

      struct  per_ym : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

      struct  per_zm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct  per_am : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct  per_fm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct  per_pm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct  per_nm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct  per_um : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct  per_mm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct  per_cm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct  per_dm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct  per_m : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct  per_dam : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct  per_hm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct  per_km : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct  per_Mm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct  per_Gm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct  per_Tm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct  per_Pm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct  per_Em : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct  per_Zm : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct  per_Ym : quan::meta::unit<
         quan::meta::components::of_reciprocal_length::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct reciprocal_length_ : quan::meta::components::of_reciprocal_length{

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_ym,
         Value_type
      >  per_ym;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_zm,
         Value_type
      >  per_zm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_am,
         Value_type
      >  per_am;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_fm,
         Value_type
      >  per_fm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_pm,
         Value_type
      >  per_pm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_nm,
         Value_type
      >  per_nm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_um,
         Value_type
      >  per_um;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_mm,
         Value_type
      >  per_mm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_cm,
         Value_type
      >  per_cm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_dm,
         Value_type
      >  per_dm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_m,
         Value_type
      >  per_m;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_dam,
         Value_type
      >  per_dam;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_hm,
         Value_type
      >  per_hm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_km,
         Value_type
      >  per_km;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_Mm,
         Value_type
      >  per_Mm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_Gm,
         Value_type
      >  per_Gm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_Tm,
         Value_type
      >  per_Tm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_Pm,
         Value_type
      >  per_Pm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_Em,
         Value_type
      >  per_Em;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_Zm,
         Value_type
      >  per_Zm;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_length::per_Ym,
         Value_type
      >  per_Ym;


#if 0
// SI units...
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yotta // coherent-exponent 24
            >,
            Value_type
        > per_ym;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > per_zm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > per_am;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > per_fm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > per_pm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > per_nm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > per_um;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > per_mm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > per_cm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > per_dm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > per_m;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > per_dam;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > per_hm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > per_km;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > per_Mm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > per_Gm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > per_Tm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > per_Pm;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > per_Em;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > per_Zm;
#endif
// non SI units...
    };

    struct reciprocal_length : reciprocal_length_<quantity_traits::default_value_type>{};

}//quan

#endif
