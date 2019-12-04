#ifndef QUAN_RECIPROCAL_TIME_HPP_INCLUDED
#define QUAN_RECIPROCAL_TIME_HPP_INCLUDED
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

#include <quan/components/of_reciprocal_time.hpp>

namespace quan{

 struct of_reciprocal_time{

      struct  per_ys : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

      struct  per_zs : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct  per_as : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct  per_fs : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct  per_ps : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct  per_ns : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct  per_us : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct  per_ms : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct  per_cs : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct  per_ds : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct  per_s : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct  per_das : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct  per_hs : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct  per_ks : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct  per_Ms : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct  per_Gs : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct  per_Ts : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct  per_Ps : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct  per_Es : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct  per_Zs : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct  per_Ys : quan::meta::unit<
         quan::meta::components::of_reciprocal_time::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct reciprocal_time_ : quan::meta::components::of_reciprocal_time{

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_ys,
         Value_type
      >  per_ys;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_zs,
         Value_type
      >  per_zs;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_as,
         Value_type
      >  per_as;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_fs,
         Value_type
      >  per_fs;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_ps,
         Value_type
      >  per_ps;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_ns,
         Value_type
      >  per_ns;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_us,
         Value_type
      >  per_us;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_ms,
         Value_type
      >  per_ms;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_cs,
         Value_type
      >  per_cs;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_ds,
         Value_type
      >  per_ds;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_s,
         Value_type
      >  per_s;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_das,
         Value_type
      >  per_das;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_hs,
         Value_type
      >  per_hs;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_ks,
         Value_type
      >  per_ks;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_Ms,
         Value_type
      >  per_Ms;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_Gs,
         Value_type
      >  per_Gs;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_Ts,
         Value_type
      >  per_Ts;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_Ps,
         Value_type
      >  per_Ps;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_Es,
         Value_type
      >  per_Es;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_Zs,
         Value_type
      >  per_Zs;

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time::per_Ys,
         Value_type
      >  per_Ys;




#if 0
    template<
        typename Value_type
    >
    struct reciprocal_time_ : meta::components::of_reciprocal_time{
        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::yotta // coherent-exponent 24
            >,
            Value_type
        > per_ys;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zetta // coherent-exponent 21
            >,
            Value_type
        > per_zs;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::exa // coherent-exponent 18
            >,
            Value_type
        > per_as;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::peta // coherent-exponent 15
            >,
            Value_type
        > per_fs;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::tera // coherent-exponent 12
            >,
            Value_type
        > per_ps;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::giga // coherent-exponent 9
            >,
            Value_type
        > per_ns;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::mega // coherent-exponent 6
            >,
            Value_type
        > per_us;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::kilo // coherent-exponent 3
            >,
            Value_type
        > per_ms;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::hecto // coherent-exponent 2
            >,
            Value_type
        > per_cs;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deka // coherent-exponent 1
            >,
            Value_type
        > per_ds;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > per_s;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::deci // coherent-exponent -1
            >,
            Value_type
        > per_das;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::centi // coherent-exponent -2
            >,
            Value_type
        > per_hs;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::milli // coherent-exponent -3
            >,
            Value_type
        > per_ks;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::micro // coherent-exponent -6
            >,
            Value_type
        > per_Ms;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano // coherent-exponent -9
            >,
            Value_type
        > per_Gs;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -12
            >,
            Value_type
        > per_Ts;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::femto // coherent-exponent -15
            >,
            Value_type
        > per_Ps;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::atto // coherent-exponent -18
            >,
            Value_type
        > per_Es;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::zepto // coherent-exponent -21
            >,
            Value_type
        > per_Zs;

#endif

        typedef fixed_quantity<
            typename non_si_unit::per_min,
            Value_type
        > per_min;

        typedef fixed_quantity<
            typename non_si_unit::per_hour,
            Value_type
        > per_hour;

    };

    struct reciprocal_time : reciprocal_time_<quantity_traits::default_value_type>{};

}//quan

#endif
