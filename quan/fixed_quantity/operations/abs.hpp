#ifndef QUAN_FIXED_QUANTITY_ABS_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_ABS_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    abs fixed_quantity
*/
#include <quan/fixed_quantity/fixed_quantity.hpp>

#ifndef __AVR__
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
#ifndef __AVR__
   using std::abs;
#endif
      return  fixed_quantity<
         StaticUnit,
         NumericType
      >{abs(in.numeric_value())};
   }  
}//quan

#endif
