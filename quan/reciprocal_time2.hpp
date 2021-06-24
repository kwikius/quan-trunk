#ifndef QUAN_RECIPROCAL_TIME2_HPP_INCLUDED
#define QUAN_RECIPROCAL_TIME2_HPP_INCLUDED
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

#include <quan/components/of_reciprocal_time2.hpp>

namespace quan{

 struct of_reciprocal_time2{

      struct  per_s2 : quan::meta::unit<
         quan::meta::components::of_reciprocal_time2::abstract_quantity,
         quan::meta::conversion_factor<quan::meta::rational<0> >
      >{};

   };

   template<
      typename Value_type
   >
   struct reciprocal_time2_ : quan::meta::components::of_reciprocal_time{

      typedef quan::fixed_quantity<
         quan::of_reciprocal_time2::per_s2,
         Value_type
      >  per_s2;

    };

    struct reciprocal_time2 : reciprocal_time2_<quantity_traits::default_value_type>{};

}//quan

#endif
