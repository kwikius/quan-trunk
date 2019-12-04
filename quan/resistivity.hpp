#ifndef QUAN_RESISTIVITY_HPP_INCLUDED
#define QUAN_RESISTIVITY_HPP_INCLUDED
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

#include <quan/components/of_resistivity.hpp>

namespace quan{

      struct of_resistivity{

      struct yR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-24> >
      >{};

      struct zR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-21> >
      >{};

      struct aR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-18> >
      >{};

      struct fR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-15> >
      >{};

      struct pR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-12> >
      >{};

      struct nR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-9> >
      >{};

      struct uR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-6> >
      >{};

      struct mR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-3> >
      >{};

      struct cR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-2> >
      >{};

      struct dR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<-1> >
      >{};

      struct R_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

      struct daR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<1> >
      >{};

      struct hR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<2> >
      >{};

      struct kR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<3> >
      >{};

      struct MR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<6> >
      >{};

      struct GR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<9> >
      >{};

      struct TR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<12> >
      >{};

      struct PR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<15> >
      >{};

      struct ER_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<18> >
      >{};

      struct ZR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<21> >
      >{};

      struct YR_m : quan::meta::unit<
         quan::meta::components::of_resistivity::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<24> >
      >{};

   };

   template<
      typename Value_type
   >
   struct resistivity_ : quan::meta::components::of_resistivity{

      typedef quan::fixed_quantity<
         quan::of_resistivity::yR_m,
         Value_type
      > yR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::zR_m,
         Value_type
      > zR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::aR_m,
         Value_type
      > aR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::fR_m,
         Value_type
      > fR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::pR_m,
         Value_type
      > pR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::nR_m,
         Value_type
      > nR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::uR_m,
         Value_type
      > uR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::mR_m,
         Value_type
      > mR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::cR_m,
         Value_type
      > cR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::dR_m,
         Value_type
      > dR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::R_m,
         Value_type
      > R_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::daR_m,
         Value_type
      > daR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::hR_m,
         Value_type
      > hR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::kR_m,
         Value_type
      > kR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::MR_m,
         Value_type
      > MR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::GR_m,
         Value_type
      > GR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::TR_m,
         Value_type
      > TR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::PR_m,
         Value_type
      > PR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::ER_m,
         Value_type
      > ER_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::ZR_m,
         Value_type
      > ZR_m;

      typedef quan::fixed_quantity<
         quan::of_resistivity::YR_m,
         Value_type
      > YR_m;
      
    };

    struct resistivity : resistivity_<quantity_traits::default_value_type>{};

}//quan

#endif
