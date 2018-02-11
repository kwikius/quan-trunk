#ifndef QUAN_FIXED_QUANTITY_ABS_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_ABS_HPP_INCLUDED
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
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    abs fixed_quantity
*/
#include <quan/fixed_quantity/fixed_quantity.hpp>

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cmath>
#else
#include <math.h>
#if defined(abs)
#undef abs
#include <type_traits>
#include <quan/where.hpp>
   template<typename T>
   QUAN_CONSTEXPR
   inline
    typename quan::where_<quan::std::is_arithmetic<T> ,T>::type
    abs(T const & in)
    {
       return (in > T(0)) ? in:-in;
    }
#endif
#endif

namespace quan{

    template<
        typename StaticUnit,
        typename NumericType
    >
    QUAN_CONSTEXPR
    inline 
    fixed_quantity<StaticUnit,NumericType>
    abs(
        fixed_quantity<
            StaticUnit,
            NumericType
        >const & in)
    {
#ifndef QUAN_AVR_NO_CPP_STDLIB
   using std::abs;
#endif
      return  fixed_quantity<
         StaticUnit,
         NumericType
      >{abs(in.numeric_value())};
   }  
}//quan

#endif
