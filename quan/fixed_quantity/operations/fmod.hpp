#ifndef QUAN_FIXED_QUANTITY_FMOD_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_FMOD_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
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
//  Permission to copy, use, modify, sell and distribute this software
//  is granted provided this copyright notice appears in all copies.
//  This software is provided "as is" without express or implied warranty,
//  and with no claim as to its suitability for any purpose.

/*
    fmod for fixed_quantity
*/

#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/binary_op_if.hpp>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cmath>
#include <ctgmath>
#else
#include <math.h>
#endif

namespace quan {

   inline
   QUAN_CONSTEXPR
   QUAN_FLOAT_TYPE fmod(QUAN_FLOAT_TYPE const & lhs, QUAN_FLOAT_TYPE const & rhs)
   {
   #ifndef QUAN_AVR_NO_CPP_STDLIB
       using std::fmod;
   #else
       using ::fmod;
   #endif
       return fmod(lhs, rhs);
   }

   template <
      typename StaticUnitL,
      typename ValueTypeL,
      typename StaticUnitR,
      typename ValueTypeR
   >
   inline 
#if ! defined QUAN_STM32L4
   constexpr
#endif
   typename quan::meta::binary_op_if<
        quan::meta::dimensionally_equivalent<
            StaticUnitL,
            StaticUnitR
        >,
        quan::fixed_quantity<
            StaticUnitL ,
            ValueTypeL
        > ,
        quan::meta::plus ,
        quan::fixed_quantity<
            StaticUnitR ,
            ValueTypeR
        >
    >::type
   fmod(
     quan::fixed_quantity<
            StaticUnitL ,
            ValueTypeL
        > const & numerator ,
        quan::fixed_quantity<
            StaticUnitR ,
            ValueTypeR
        > const & denominator
    )
    {
        typedef typename quan::meta::binary_op<
            quan::fixed_quantity<
                StaticUnitL ,
                ValueTypeL
            > ,
            quan::meta::plus ,
            quan::fixed_quantity<
                StaticUnitR ,
                ValueTypeR
            >
        >::type result_type;
       return result_type{std::fmod(result_type{numerator}.numeric_value() ,result_type{denominator}.numeric_value())};
    }
   
} //quan

#endif
