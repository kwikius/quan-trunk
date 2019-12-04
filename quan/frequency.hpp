#ifndef QUAN_FREQUENCY_HPP_INCLUDED
#define QUAN_FREQUENCY_HPP_INCLUDED
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

#include <quan/components/of_frequency.hpp>

namespace quan{

   struct of_frequency{

      struct yHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct Hz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct THz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YHz : quan::meta::unit<
         quan::meta::components::of_frequency::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct frequency_ : quan::meta::components::of_frequency{

      typedef quan::fixed_quantity<
         quan::of_frequency::yHz,
         Value_type
      > yHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::zHz,
         Value_type
      > zHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::aHz,
         Value_type
      > aHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::fHz,
         Value_type
      > fHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::pHz,
         Value_type
      > pHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::nHz,
         Value_type
      > nHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::uHz,
         Value_type
      > uHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::mHz,
         Value_type
      > mHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::cHz,
         Value_type
      > cHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::dHz,
         Value_type
      > dHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::Hz,
         Value_type
      > Hz;

      typedef quan::fixed_quantity<
         quan::of_frequency::daHz,
         Value_type
      > daHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::hHz,
         Value_type
      > hHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::kHz,
         Value_type
      > kHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::MHz,
         Value_type
      > MHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::GHz,
         Value_type
      > GHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::THz,
         Value_type
      > THz;

      typedef quan::fixed_quantity<
         quan::of_frequency::PHz,
         Value_type
      > PHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::EHz,
         Value_type
      > EHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::ZHz,
         Value_type
      > ZHz;

      typedef quan::fixed_quantity<
         quan::of_frequency::YHz,
         Value_type
      > YHz;


    };

    struct frequency : frequency_<quantity_traits::default_value_type>{};

}//quan

#endif
