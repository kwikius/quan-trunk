#ifndef QUAN_ENERGY_HPP_INCLUDED
#define QUAN_ENERGY_HPP_INCLUDED
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

#include <quan/components/of_energy.hpp>

namespace quan{

   struct of_energy{

      struct yJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct J : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YJ : quan::meta::unit<
         quan::meta::components::of_energy::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct energy_ : quan::meta::components::of_energy{

      typedef quan::fixed_quantity<
         quan::of_energy::yJ,
         Value_type
      > yJ;

      typedef quan::fixed_quantity<
         quan::of_energy::zJ,
         Value_type
      > zJ;

      typedef quan::fixed_quantity<
         quan::of_energy::aJ,
         Value_type
      > aJ;

      typedef quan::fixed_quantity<
         quan::of_energy::fJ,
         Value_type
      > fJ;

      typedef quan::fixed_quantity<
         quan::of_energy::pJ,
         Value_type
      > pJ;

      typedef quan::fixed_quantity<
         quan::of_energy::nJ,
         Value_type
      > nJ;

      typedef quan::fixed_quantity<
         quan::of_energy::uJ,
         Value_type
      > uJ;

      typedef quan::fixed_quantity<
         quan::of_energy::mJ,
         Value_type
      > mJ;

      typedef quan::fixed_quantity<
         quan::of_energy::cJ,
         Value_type
      > cJ;

      typedef quan::fixed_quantity<
         quan::of_energy::dJ,
         Value_type
      > dJ;

      typedef quan::fixed_quantity<
         quan::of_energy::J,
         Value_type
      > J;

      typedef quan::fixed_quantity<
         quan::of_energy::daJ,
         Value_type
      > daJ;

      typedef quan::fixed_quantity<
         quan::of_energy::hJ,
         Value_type
      > hJ;

      typedef quan::fixed_quantity<
         quan::of_energy::kJ,
         Value_type
      > kJ;

      typedef quan::fixed_quantity<
         quan::of_energy::MJ,
         Value_type
      > MJ;

      typedef quan::fixed_quantity<
         quan::of_energy::GJ,
         Value_type
      > GJ;

      typedef quan::fixed_quantity<
         quan::of_energy::TJ,
         Value_type
      > TJ;

      typedef quan::fixed_quantity<
         quan::of_energy::PJ,
         Value_type
      > PJ;

      typedef quan::fixed_quantity<
         quan::of_energy::EJ,
         Value_type
      > EJ;

      typedef quan::fixed_quantity<
         quan::of_energy::ZJ,
         Value_type
      > ZJ;

      typedef quan::fixed_quantity<
         quan::of_energy::YJ,
         Value_type
      > YJ;

    };

    struct energy : energy_<quantity_traits::default_value_type>{};

}//quan

#endif
