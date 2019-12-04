#ifndef QUAN_MAGNETIC_FLUX_DENSITY_HPP_INCLUDED
#define QUAN_MAGNETIC_FLUX_DENSITY_HPP_INCLUDED
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

#include <quan/components/of_magnetic_flux_density.hpp>

namespace quan{

   struct of_magnetic_flux_density{

      struct yT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct T : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct ET : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YT : quan::meta::unit<
         quan::meta::components::of_magnetic_flux_density::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct magnetic_flux_density_ : quan::meta::components::of_magnetic_flux_density{

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::yT,
         Value_type
      > yT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::zT,
         Value_type
      > zT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::aT,
         Value_type
      > aT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::fT,
         Value_type
      > fT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::pT,
         Value_type
      > pT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::nT,
         Value_type
      > nT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::uT,
         Value_type
      > uT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::mT,
         Value_type
      > mT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::cT,
         Value_type
      > cT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::dT,
         Value_type
      > dT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::T,
         Value_type
      > T;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::daT,
         Value_type
      > daT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::hT,
         Value_type
      > hT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::kT,
         Value_type
      > kT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::MT,
         Value_type
      > MT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::GT,
         Value_type
      > GT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::TT,
         Value_type
      > TT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::PT,
         Value_type
      > PT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::ET,
         Value_type
      > ET;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::ZT,
         Value_type
      > ZT;

      typedef quan::fixed_quantity<
         quan::of_magnetic_flux_density::YT,
         Value_type
      > YT;

       typedef fixed_quantity<
            typename non_si_unit::gauss,
            Value_type
        > gauss;

       typedef fixed_quantity<
            typename non_si_unit::milli_gauss,
            Value_type
       > milli_gauss;

    };

    struct magnetic_flux_density : magnetic_flux_density_<quantity_traits::default_value_type>{};

}//quan

#endif
