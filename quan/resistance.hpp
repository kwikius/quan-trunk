#ifndef QUAN_RESISTANCE_HPP_INCLUDED
#define QUAN_RESISTANCE_HPP_INCLUDED
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

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/components/of_resistance.hpp>

namespace quan{

   struct of_resistance{

      struct yR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct R : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct ER : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YR : quan::meta::unit<
         quan::meta::components::of_resistance::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct resistance_ : quan::meta::components::of_resistance{

      typedef quan::fixed_quantity<
         quan::of_resistance::yR,
         Value_type
      > yR;

      typedef quan::fixed_quantity<
         quan::of_resistance::zR,
         Value_type
      > zR;

      typedef quan::fixed_quantity<
         quan::of_resistance::aR,
         Value_type
      > aR;

      typedef quan::fixed_quantity<
         quan::of_resistance::fR,
         Value_type
      > fR;

      typedef quan::fixed_quantity<
         quan::of_resistance::pR,
         Value_type
      > pR;

      typedef quan::fixed_quantity<
         quan::of_resistance::nR,
         Value_type
      > nR;

      typedef quan::fixed_quantity<
         quan::of_resistance::uR,
         Value_type
      > uR;

      typedef quan::fixed_quantity<
         quan::of_resistance::mR,
         Value_type
      > mR;

      typedef quan::fixed_quantity<
         quan::of_resistance::cR,
         Value_type
      > cR;

      typedef quan::fixed_quantity<
         quan::of_resistance::dR,
         Value_type
      > dR;

      typedef quan::fixed_quantity<
         quan::of_resistance::R,
         Value_type
      > R;

      typedef quan::fixed_quantity<
         quan::of_resistance::daR,
         Value_type
      > daR;

      typedef quan::fixed_quantity<
         quan::of_resistance::hR,
         Value_type
      > hR;

      typedef quan::fixed_quantity<
         quan::of_resistance::kR,
         Value_type
      > kR;

      typedef quan::fixed_quantity<
         quan::of_resistance::MR,
         Value_type
      > MR;

      typedef quan::fixed_quantity<
         quan::of_resistance::GR,
         Value_type
      > GR;

      typedef quan::fixed_quantity<
         quan::of_resistance::TR,
         Value_type
      > TR;

      typedef quan::fixed_quantity<
         quan::of_resistance::PR,
         Value_type
      > PR;

      typedef quan::fixed_quantity<
         quan::of_resistance::ER,
         Value_type
      > ER;

      typedef quan::fixed_quantity<
         quan::of_resistance::ZR,
         Value_type
      > ZR;

      typedef quan::fixed_quantity<
         quan::of_resistance::YR,
         Value_type
      > YR;

        typedef fixed_quantity<
            typename non_si_unit::abohm,
            Value_type
        > abohm;

    };

    struct resistance : resistance_<quantity_traits::default_value_type>{};

}//quan

#endif
