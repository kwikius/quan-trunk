#ifndef QUAN_FORCE_HPP_INCLUDED
#define QUAN_FORCE_HPP_INCLUDED
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

#include <quan/components/of_force.hpp>

namespace quan{

   struct of_force{

      struct yN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct N : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct EN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YN : quan::meta::unit<
         quan::meta::components::of_force::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct force_ : quan::meta::components::of_force{

      typedef quan::fixed_quantity<
         quan::of_force::yN,
         Value_type
      > yN;

      typedef quan::fixed_quantity<
         quan::of_force::zN,
         Value_type
      > zN;

      typedef quan::fixed_quantity<
         quan::of_force::aN,
         Value_type
      > aN;

      typedef quan::fixed_quantity<
         quan::of_force::fN,
         Value_type
      > fN;

      typedef quan::fixed_quantity<
         quan::of_force::pN,
         Value_type
      > pN;

      typedef quan::fixed_quantity<
         quan::of_force::nN,
         Value_type
      > nN;

      typedef quan::fixed_quantity<
         quan::of_force::uN,
         Value_type
      > uN;

      typedef quan::fixed_quantity<
         quan::of_force::mN,
         Value_type
      > mN;

      typedef quan::fixed_quantity<
         quan::of_force::cN,
         Value_type
      > cN;

      typedef quan::fixed_quantity<
         quan::of_force::dN,
         Value_type
      > dN;

      typedef quan::fixed_quantity<
         quan::of_force::N,
         Value_type
      > N;

      typedef quan::fixed_quantity<
         quan::of_force::daN,
         Value_type
      > daN;

      typedef quan::fixed_quantity<
         quan::of_force::hN,
         Value_type
      > hN;

      typedef quan::fixed_quantity<
         quan::of_force::kN,
         Value_type
      > kN;

      typedef quan::fixed_quantity<
         quan::of_force::MN,
         Value_type
      > MN;

      typedef quan::fixed_quantity<
         quan::of_force::GN,
         Value_type
      > GN;

      typedef quan::fixed_quantity<
         quan::of_force::TN,
         Value_type
      > TN;

      typedef quan::fixed_quantity<
         quan::of_force::PN,
         Value_type
      > PN;

      typedef quan::fixed_quantity<
         quan::of_force::EN,
         Value_type
      > EN;

      typedef quan::fixed_quantity<
         quan::of_force::ZN,
         Value_type
      > ZN;

      typedef quan::fixed_quantity<
         quan::of_force::YN,
         Value_type
      > YN;

        typedef fixed_quantity<
            typename non_si_unit::dyn,
            Value_type
        > dyn;

        typedef fixed_quantity<
            typename non_si_unit::kgf,
            Value_type
        > kgf;

        typedef fixed_quantity<
            typename non_si_unit::kip,
            Value_type
        > kip;

        typedef fixed_quantity<
            typename non_si_unit::ozf,
            Value_type
        > ozf;

        typedef fixed_quantity<
            typename non_si_unit::poundal,
            Value_type
        > poundal;

        typedef fixed_quantity<
            typename non_si_unit::lbf,
            Value_type
        > lbf;

        typedef fixed_quantity<
            typename non_si_unit::ton_force,
            Value_type
        > ton_force;

    };

    struct force : force_<quantity_traits::default_value_type>{};

}//quan

#endif
