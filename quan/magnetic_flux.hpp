#ifndef QUAN_MAGNETIC_FLUX_HPP_INCLUDED
#define QUAN_MAGNETIC_FLUX_HPP_INCLUDED
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

#include <quan/components/of_magnetic_flux.hpp>

namespace quan{

   struct of_magnetic_flux{

      struct yWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct Wb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YWb : quan::meta::unit<
         quan::meta::components::of_magnetic_flux::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct magnetic_flux_ : quan::meta::components::of_magnetic_flux{

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::yWb,
         Value_type
      > yWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::zWb,
         Value_type
      > zWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::aWb,
         Value_type
      > aWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::fWb,
         Value_type
      > fWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::pWb,
         Value_type
      > pWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::nWb,
         Value_type
      > nWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::uWb,
         Value_type
      > uWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::mWb,
         Value_type
      > mWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::cWb,
         Value_type
      > cWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::dWb,
         Value_type
      > dWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::Wb,
         Value_type
      > Wb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::daWb,
         Value_type
      > daWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::hWb,
         Value_type
      > hWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::kWb,
         Value_type
      > kWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::MWb,
         Value_type
      > MWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::GWb,
         Value_type
      > GWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::TWb,
         Value_type
      > TWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::PWb,
         Value_type
      > PWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::EWb,
         Value_type
      > EWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::ZWb,
         Value_type
      > ZWb;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux::YWb,
         Value_type
      > YWb;

    };

    struct magnetic_flux : magnetic_flux_<quantity_traits::default_value_type>{};

}//quan

#endif
