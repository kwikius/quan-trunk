#ifndef QUAN_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
#define QUAN_AREA_MOMENT_OF_INERTIA_HPP_INCLUDED
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


#include <quan/components/of_area_moment_of_inertia.hpp>

namespace quan{

   struct of_area_moment_of_inertia{
         // coherent_exponent :-27 -> N/A
         // coherent_exponent :-26 -> N/A
         // coherent_exponent :-25 -> N/A
      struct um4 :  quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         typename quan::meta::si_unit::yocto // coherent_exponent -24
      >{};
         // coherent_exponent :-23 -> N/A
         // coherent_exponent :-22 -> N/A
         // coherent_exponent :-21 -> N/A
         // coherent_exponent :-20 -> N/A
         // coherent_exponent :-19 -> N/A
         // coherent_exponent :-18 -> N/A
         // coherent_exponent :-17 -> N/A
         // coherent_exponent :-16 -> N/A
         // coherent_exponent :-15 -> N/A
         // coherent_exponent :-14 -> N/A
         // coherent_exponent :-13 -> N/A
      struct mm4 :  quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         typename quan::meta::si_unit::pico // coherent_exponent -12
      >{};
         // coherent_exponent :-11 -> N/A
         // coherent_exponent :-10 -> N/A
         // coherent_exponent :-9 -> N/A
         // coherent_exponent :-8 -> N/A
         // coherent_exponent :-7 -> N/A
         // coherent_exponent :-6 -> N/A
         // coherent_exponent :-5 -> N/A
         // coherent_exponent :-4 -> N/A
         // coherent_exponent :-3 -> N/A
         // coherent_exponent :-2 -> N/A
         // coherent_exponent :-1 -> N/A
      struct m4 :  quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         typename quan::meta::si_unit::none // coherent_exponent 0
      >{};
         // coherent_exponent :1 -> N/A
         // coherent_exponent :2 -> N/A
         // coherent_exponent :3 -> N/A
         // coherent_exponent :4 -> N/A
         // coherent_exponent :5 -> N/A
         // coherent_exponent :6 -> N/A
         // coherent_exponent :7 -> N/A
         // coherent_exponent :8 -> N/A
         // coherent_exponent :9 -> N/A
         // coherent_exponent :10 -> N/A
         // coherent_exponent :11 -> N/A
      struct km4 :  quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         typename quan::meta::si_unit::tera // coherent_exponent 12
      >{};
         // coherent_exponent :13 -> N/A
         // coherent_exponent :14 -> N/A
         // coherent_exponent :15 -> N/A
         // coherent_exponent :16 -> N/A
         // coherent_exponent :17 -> N/A
         // coherent_exponent :18 -> N/A
         // coherent_exponent :19 -> N/A
         // coherent_exponent :20 -> N/A
         // coherent_exponent :21 -> N/A
         // coherent_exponent :22 -> N/A
         // coherent_exponent :23 -> N/A
      struct Mm4 :  quan::meta::unit<
         quan::meta::components::of_area_moment_of_inertia::abstract_quantity,
         typename quan::meta::si_unit::yotta // coherent_exponent 24
      >{};
         // coherent_exponent :25 -> N/A
         // coherent_exponent :26 -> N/A
         // coherent_exponent :27 -> N/A
   };

    template<
        typename Value_type
    >
    struct area_moment_of_inertia_ : meta::components::of_area_moment_of_inertia{
       
#if 1

  // coherent_exponent :-27 -> N/A
      // coherent_exponent :-26 -> N/A
      // coherent_exponent :-25 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::um4,
         Value_type
      > um4;
      // coherent_exponent :-23 -> N/A
      // coherent_exponent :-22 -> N/A
      // coherent_exponent :-21 -> N/A
      // coherent_exponent :-20 -> N/A
      // coherent_exponent :-19 -> N/A
      // coherent_exponent :-18 -> N/A
      // coherent_exponent :-17 -> N/A
      // coherent_exponent :-16 -> N/A
      // coherent_exponent :-15 -> N/A
      // coherent_exponent :-14 -> N/A
      // coherent_exponent :-13 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::mm4,
         Value_type
      > mm4;
      // coherent_exponent :-11 -> N/A
      // coherent_exponent :-10 -> N/A
      // coherent_exponent :-9 -> N/A
      // coherent_exponent :-8 -> N/A
      // coherent_exponent :-7 -> N/A
      // coherent_exponent :-6 -> N/A
      // coherent_exponent :-5 -> N/A
      // coherent_exponent :-4 -> N/A
      // coherent_exponent :-3 -> N/A
      // coherent_exponent :-2 -> N/A
      // coherent_exponent :-1 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::m4,
         Value_type
      > m4;
      // coherent_exponent :1 -> N/A
      // coherent_exponent :2 -> N/A
      // coherent_exponent :3 -> N/A
      // coherent_exponent :4 -> N/A
      // coherent_exponent :5 -> N/A
      // coherent_exponent :6 -> N/A
      // coherent_exponent :7 -> N/A
      // coherent_exponent :8 -> N/A
      // coherent_exponent :9 -> N/A
      // coherent_exponent :10 -> N/A
      // coherent_exponent :11 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::km4,
         Value_type
      > km4;
      // coherent_exponent :13 -> N/A
      // coherent_exponent :14 -> N/A
      // coherent_exponent :15 -> N/A
      // coherent_exponent :16 -> N/A
      // coherent_exponent :17 -> N/A
      // coherent_exponent :18 -> N/A
      // coherent_exponent :19 -> N/A
      // coherent_exponent :20 -> N/A
      // coherent_exponent :21 -> N/A
      // coherent_exponent :22 -> N/A
      // coherent_exponent :23 -> N/A
      typedef quan::fixed_quantity<
         quan::of_area_moment_of_inertia::Mm4,
         Value_type
      > Mm4;
      // coherent_exponent :25 -> N/A
      // coherent_exponent :26 -> N/A
      // coherent_exponent :27 -> N/A

#else

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::none // coherent-exponent 0
            >,
            Value_type
        > m4;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::pico // coherent-exponent -3 * 4 = -12
            >,
            Value_type
        > mm4;
#endif
    };

    struct area_moment_of_inertia 
    : area_moment_of_inertia_<quantity_traits::default_value_type>{};

}//quan

#endif
