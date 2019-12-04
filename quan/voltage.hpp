#ifndef QUAN_VOLTAGE_HPP_INCLUDED
#define QUAN_VOLTAGE_HPP_INCLUDED
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

#include <quan/components/of_voltage.hpp>

namespace quan{

  struct of_voltage{

      struct yV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct V : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YV : quan::meta::unit<
         quan::meta::components::of_voltage::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct voltage_ : quan::meta::components::of_voltage{

      typedef quan::fixed_quantity<
         quan::of_voltage::yV,
         Value_type
      > yV;

      typedef quan::fixed_quantity<
         quan::of_voltage::zV,
         Value_type
      > zV;

      typedef quan::fixed_quantity<
         quan::of_voltage::aV,
         Value_type
      > aV;

      typedef quan::fixed_quantity<
         quan::of_voltage::fV,
         Value_type
      > fV;

      typedef quan::fixed_quantity<
         quan::of_voltage::pV,
         Value_type
      > pV;

      typedef quan::fixed_quantity<
         quan::of_voltage::nV,
         Value_type
      > nV;

      typedef quan::fixed_quantity<
         quan::of_voltage::uV,
         Value_type
      > uV;

      typedef quan::fixed_quantity<
         quan::of_voltage::mV,
         Value_type
      > mV;

      typedef quan::fixed_quantity<
         quan::of_voltage::cV,
         Value_type
      > cV;

      typedef quan::fixed_quantity<
         quan::of_voltage::dV,
         Value_type
      > dV;

      typedef quan::fixed_quantity<
         quan::of_voltage::V,
         Value_type
      > V;

      typedef quan::fixed_quantity<
         quan::of_voltage::daV,
         Value_type
      > daV;

      typedef quan::fixed_quantity<
         quan::of_voltage::hV,
         Value_type
      > hV;

      typedef quan::fixed_quantity<
         quan::of_voltage::kV,
         Value_type
      > kV;

      typedef quan::fixed_quantity<
         quan::of_voltage::MV,
         Value_type
      > MV;

      typedef quan::fixed_quantity<
         quan::of_voltage::GV,
         Value_type
      > GV;

      typedef quan::fixed_quantity<
         quan::of_voltage::TV,
         Value_type
      > TV;

      typedef quan::fixed_quantity<
         quan::of_voltage::PV,
         Value_type
      > PV;

      typedef quan::fixed_quantity<
         quan::of_voltage::EV,
         Value_type
      > EV;

      typedef quan::fixed_quantity<
         quan::of_voltage::ZV,
         Value_type
      > ZV;

      typedef quan::fixed_quantity<
         quan::of_voltage::YV,
         Value_type
      > YV;
        typedef fixed_quantity<
            typename non_si_unit::abvolt,
            Value_type
        > abvolt;

    };

    struct voltage : voltage_<quantity_traits::default_value_type>{};

}//quan

#endif
