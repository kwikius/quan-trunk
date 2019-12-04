#ifndef QUAN_SUBSTANCE_HPP_INCLUDED
#define QUAN_SUBSTANCE_HPP_INCLUDED
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

#include <quan/components/of_substance.hpp>

namespace quan{

     struct of_substance{

      struct ymol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct amol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct umol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct mol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct damol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Mmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Gmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Tmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Pmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Emol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Zmol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct Ymol : quan::meta::unit<
         quan::meta::components::of_substance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct substance_ : quan::meta::components::of_substance{

      typedef quan::fixed_quantity<
         quan::of_substance::ymol,
         Value_type
      > ymol;

      typedef quan::fixed_quantity<
         quan::of_substance::zmol,
         Value_type
      > zmol;

      typedef quan::fixed_quantity<
         quan::of_substance::amol,
         Value_type
      > amol;

      typedef quan::fixed_quantity<
         quan::of_substance::fmol,
         Value_type
      > fmol;

      typedef quan::fixed_quantity<
         quan::of_substance::pmol,
         Value_type
      > pmol;

      typedef quan::fixed_quantity<
         quan::of_substance::nmol,
         Value_type
      > nmol;

      typedef quan::fixed_quantity<
         quan::of_substance::umol,
         Value_type
      > umol;

      typedef quan::fixed_quantity<
         quan::of_substance::mmol,
         Value_type
      > mmol;

      typedef quan::fixed_quantity<
         quan::of_substance::cmol,
         Value_type
      > cmol;

      typedef quan::fixed_quantity<
         quan::of_substance::dmol,
         Value_type
      > dmol;

      typedef quan::fixed_quantity<
         quan::of_substance::mol,
         Value_type
      > mol;

      typedef quan::fixed_quantity<
         quan::of_substance::damol,
         Value_type
      > damol;

      typedef quan::fixed_quantity<
         quan::of_substance::hmol,
         Value_type
      > hmol;

      typedef quan::fixed_quantity<
         quan::of_substance::kmol,
         Value_type
      > kmol;

      typedef quan::fixed_quantity<
         quan::of_substance::Mmol,
         Value_type
      > Mmol;

      typedef quan::fixed_quantity<
         quan::of_substance::Gmol,
         Value_type
      > Gmol;

      typedef quan::fixed_quantity<
         quan::of_substance::Tmol,
         Value_type
      > Tmol;

      typedef quan::fixed_quantity<
         quan::of_substance::Pmol,
         Value_type
      > Pmol;

      typedef quan::fixed_quantity<
         quan::of_substance::Emol,
         Value_type
      > Emol;

      typedef quan::fixed_quantity<
         quan::of_substance::Zmol,
         Value_type
      > Zmol;

      typedef quan::fixed_quantity<
         quan::of_substance::Ymol,
         Value_type
      > Ymol;


    };

    struct substance : substance_<quantity_traits::default_value_type>{};

}//quan

#endif
