#ifndef QUAN_FIXED_QUANTITY_ATAN2_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_ATAN2_HPP_INCLUDED
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
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    atan2 for fixed_quantity
    returns quan::angle::rad
*/

#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/angle.hpp>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>
//#include <quan/static_assert.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cmath>
#else
#include <math.h>
#endif

namespace quan {

   inline
   quan::angle::rad atan2(QUAN_FLOAT_TYPE const & lhs, QUAN_FLOAT_TYPE const & rhs)
   {
   #ifndef QUAN_AVR_NO_CPP_STDLIB
       using std::atan2;
   #else
       using ::atan2;
   #endif
       return quan::angle::rad {atan2(lhs, rhs)};
   }

   template <
      typename StaticUnit_L,
      typename NumericType_L,
      typename StaticUnit_R,
      typename NumericType_R
   >
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::meta::dimensionally_equivalent<StaticUnit_L, StaticUnit_R>,
         quan::meta::or_<
            quan::meta::and_<
               quan::meta::allow_implicit_unit_conversions<StaticUnit_L>,
               quan::meta::allow_implicit_unit_conversions<StaticUnit_R>
            >,
            quan::meta::is_math_same_conversion_factor<
               typename quan::meta::get_conversion_factor<StaticUnit_L>::type,
               typename quan::meta::get_conversion_factor<StaticUnit_R>::type
            >
         >
      >,
      typename quan::angle_<
         typename quan::meta::binary_op<
            fixed_quantity<StaticUnit_L, NumericType_L>,
            quan::meta::divides,
            fixed_quantity<StaticUnit_R, NumericType_R>
         >::type
      >::rad
   >::type
   atan2(fixed_quantity<StaticUnit_L, NumericType_L> const & y,
         fixed_quantity<StaticUnit_R, NumericType_R> const & x)
   {
       typedef fixed_quantity<StaticUnit_L, NumericType_L> arg_type1;
       typedef fixed_quantity<StaticUnit_R, NumericType_R> arg_type2;

       // need to convert both quantities to a common unit
       // which this does, and if necessary promotes value_type
       typedef typename quan::meta::binary_op<
         arg_type1, quan::meta::minus, arg_type2
       >::type finest_grained_type;

       finest_grained_type ty = y;
       finest_grained_type tx = x;

       // 'type' of result of division must be a numeric
       typedef typename quan::meta::binary_op<
          finest_grained_type,
          quan::meta::divides,
          finest_grained_type
       >::type result_value_type;

       // To show this ... check it is a numeric
       static_assert(quan::meta::is_numeric<
                     result_value_type
                     >::value," result not numeric");

       typedef typename quan::angle_<result_value_type>::rad result_type;
   #ifndef QUAN_AVR_NO_CPP_STDLIB
       using std::atan2;
   #else
       using ::atan2;
   #endif
       return result_type {atan2(ty.numeric_value(), tx.numeric_value())};
   }

} //quan

#endif
