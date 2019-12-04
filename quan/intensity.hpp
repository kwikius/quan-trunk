#ifndef QUAN_INTENSITY_HPP_INCLUDED
#define QUAN_INTENSITY_HPP_INCLUDED
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

#include <quan/components/of_intensity.hpp>

namespace quan{

   struct of_intensity{

      struct ycd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct acd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct ncd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct ucd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct ccd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct cd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct dacd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct Mcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct Gcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct Tcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct Pcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct Ecd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct Zcd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct Ycd : quan::meta::unit<
         quan::meta::components::of_intensity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct intensity_ : quan::meta::components::of_intensity{

      typedef quan::fixed_quantity<
         quan::of_intensity::ycd,
         Value_type
      > ycd;

      typedef quan::fixed_quantity<
         quan::of_intensity::zcd,
         Value_type
      > zcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::acd,
         Value_type
      > acd;

      typedef quan::fixed_quantity<
         quan::of_intensity::fcd,
         Value_type
      > fcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::pcd,
         Value_type
      > pcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::ncd,
         Value_type
      > ncd;

      typedef quan::fixed_quantity<
         quan::of_intensity::ucd,
         Value_type
      > ucd;

      typedef quan::fixed_quantity<
         quan::of_intensity::mcd,
         Value_type
      > mcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::ccd,
         Value_type
      > ccd;

      typedef quan::fixed_quantity<
         quan::of_intensity::dcd,
         Value_type
      > dcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::cd,
         Value_type
      > cd;

      typedef quan::fixed_quantity<
         quan::of_intensity::dacd,
         Value_type
      > dacd;

      typedef quan::fixed_quantity<
         quan::of_intensity::hcd,
         Value_type
      > hcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::kcd,
         Value_type
      > kcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::Mcd,
         Value_type
      > Mcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::Gcd,
         Value_type
      > Gcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::Tcd,
         Value_type
      > Tcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::Pcd,
         Value_type
      > Pcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::Ecd,
         Value_type
      > Ecd;

      typedef quan::fixed_quantity<
         quan::of_intensity::Zcd,
         Value_type
      > Zcd;

      typedef quan::fixed_quantity<
         quan::of_intensity::Ycd,
         Value_type
      > Ycd;
    };

    struct intensity : intensity_<quantity_traits::default_value_type>{};

}//quan

#endif
