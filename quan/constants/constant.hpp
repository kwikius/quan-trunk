#ifndef QUAN_MATH_CONSTANT_HPP_INCLUDED
#define QUAN_MATH_CONSTANT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

// See <QUAN_ROOT/quan_matters/index.html> for documentation.

/*
    Constants values provided by Paul Bristow

    struct container for math constants
    note requires compilation/link of <quan_matters/src/constant.cpp>
*/

#include <quan/config.hpp>
#include <quan/quantity_traits.hpp>
namespace quan {

   template<typename ValueType>
   struct constant_{
#if defined ( QUAN_HAS_CONSTEXPR)
        static constexpr ValueType pi = static_cast<ValueType>(3.141592653589793238462643383279502884197);
        static constexpr ValueType e = static_cast<ValueType>(0.5772156649015328606065120900824024310422);
        static constexpr ValueType sqrt2 = static_cast<ValueType>(1.41421356237309504880168872420969807857);

#else
        static ValueType const  pi;
        static ValueType const  e;
        static ValueType const  sqrt2;
#endif
   };

#if defined ( QUAN_HAS_CONSTEXPR)
   template<typename ValueType>
   constexpr ValueType constant_<ValueType>::pi;
   template<typename ValueType>
   constexpr ValueType constant_<ValueType>::e;
   template<typename ValueType>
   constexpr ValueType constant_<ValueType>::sqrt2;
#endif

   struct constant : constant_<quantity_traits::default_value_type>{};



#ifndef QUAN_HAS_CONSTEXPR
#ifdef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS

template<typename T>
T const   constant_<T>::pi
= static_cast<T>(3.141592653589793238462643383279502884197);

template<typename T>
T const  constant_<T>::e
= static_cast<T>(0.5772156649015328606065120900824024310422);

template<typename T>
T const   constant_<T>::sqrt2
= static_cast<T>(1.41421356237309504880168872420969807857);
#endif
#endif

//template<typename T> typename constant_<T>::pi;
} //quan

#endif

