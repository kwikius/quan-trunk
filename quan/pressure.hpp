#ifndef QUAN_PRESSURE_HPP_INCLUDED
#define QUAN_PRESSURE_HPP_INCLUDED
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

#include <quan/components/of_pressure.hpp>

namespace quan{

   struct of_pressure{

      struct yPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct Pa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YPa : quan::meta::unit<
         quan::meta::components::of_pressure::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct pressure_ : quan::meta::components::of_pressure{

      typedef quan::fixed_quantity<
         quan::of_pressure::yPa,
         Value_type
      > yPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::zPa,
         Value_type
      > zPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::aPa,
         Value_type
      > aPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::fPa,
         Value_type
      > fPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::pPa,
         Value_type
      > pPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::nPa,
         Value_type
      > nPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::uPa,
         Value_type
      > uPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::mPa,
         Value_type
      > mPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::cPa,
         Value_type
      > cPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::dPa,
         Value_type
      > dPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::Pa,
         Value_type
      > Pa;

      typedef quan::fixed_quantity<
         quan::of_pressure::daPa,
         Value_type
      > daPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::hPa,
         Value_type
      > hPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::kPa,
         Value_type
      > kPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::MPa,
         Value_type
      > MPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::GPa,
         Value_type
      > GPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::TPa,
         Value_type
      > TPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::PPa,
         Value_type
      > PPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::EPa,
         Value_type
      > EPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::ZPa,
         Value_type
      > ZPa;

      typedef quan::fixed_quantity<
         quan::of_pressure::YPa,
         Value_type
      > YPa;


        typedef fixed_quantity<
            typename non_si_unit::atm,
            Value_type
        > atm;

        typedef fixed_quantity<
            typename non_si_unit::at,
            Value_type
        > at;

        typedef fixed_quantity<
            typename non_si_unit::bar,
            Value_type
        > bar;

        typedef fixed_quantity<
            typename non_si_unit::cm_mercury0C,
            Value_type
        > cm_mercury0C;

        typedef fixed_quantity<
            typename non_si_unit::cmHg,
            Value_type
        > cmHg;

        typedef fixed_quantity<
            typename non_si_unit::cm_water4C,
            Value_type
        > cm_water4C;

        typedef fixed_quantity<
            typename non_si_unit::cmH20,
            Value_type
        > cmH20;

        typedef fixed_quantity<
            typename non_si_unit::dyn_per_cm2,
            Value_type
        > dyn_per_cm2;

        typedef fixed_quantity<
            typename non_si_unit::ftHg,
            Value_type
        > ftHg;

        typedef fixed_quantity<
            typename non_si_unit::ft_water39_2F,
            Value_type
        > ft_water39_2F;

        typedef fixed_quantity<
            typename non_si_unit::ftH20,
            Value_type
        > ftH20;

        typedef fixed_quantity<
            typename non_si_unit::gf_per_cm2,
            Value_type
        > gf_per_cm2;

        typedef fixed_quantity<
            typename non_si_unit::in_mercury32F,
            Value_type
        > in_mercury32F;

        typedef fixed_quantity<
            typename non_si_unit::in_mercury60F,
            Value_type
        > in_mercury60F;

        typedef fixed_quantity<
            typename non_si_unit::inHg,
            Value_type
        > inHg;

        typedef fixed_quantity<
            typename non_si_unit::in_water39_2F,
            Value_type
        > in_water39_2F;

        typedef fixed_quantity<
            typename non_si_unit::inH20,
            Value_type
        > inH20;

        typedef fixed_quantity<
            typename non_si_unit::kgf_per_cm2,
            Value_type
        > kgf_per_cm2;

        typedef fixed_quantity<
            typename non_si_unit::kgf_per_m2,
            Value_type
        > kgf_per_m2;

        typedef fixed_quantity<
            typename non_si_unit::kgf_per_mm2,
            Value_type
        > kgf_per_mm2;

        typedef fixed_quantity<
            typename non_si_unit::ksi,
            Value_type
        > ksi;

        typedef fixed_quantity<
            typename non_si_unit::mbar,
            Value_type
        > mbar;

        typedef fixed_quantity<
            typename non_si_unit::mmHg,
            Value_type
        > mmHg;

        typedef fixed_quantity<
            typename non_si_unit::mmH20,
            Value_type
        > mmH20;

        typedef fixed_quantity<
            typename non_si_unit::lbf_per_ft2,
            Value_type
        > lbf_per_ft2;

        typedef fixed_quantity<
            typename non_si_unit::psi,
            Value_type
        > psi;

        typedef fixed_quantity<
            typename non_si_unit::poundal_per_ft2,
            Value_type
        > poundal_per_ft2;

        typedef fixed_quantity<
            typename non_si_unit::torr,
            Value_type
        > torr;

    };

    struct pressure : pressure_<quantity_traits::default_value_type>{};

}//quan

#endif
