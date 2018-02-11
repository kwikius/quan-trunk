#ifndef QUAN_CONCEPT_CHECKING_HPP_INCLUDED
#define QUAN_CONCEPT_CHECKING_HPP_INCLUDED
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
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    concept checking classes
*/
#include <quan/config.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#include <quan/std/tr1/is_integral.hpp>
#endif

#include <quan/meta/to_arithmetic.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/if.hpp>
#if defined QUAN_AVR_NO_CPP_STDLIB
#include <limits.h>
#else
#include <limits>
#endif

namespace quan{ namespace concept_checking{

    template< bool Assertion>struct Assert;

    template<>struct Assert<true>{};

    template<typename ArithmeticType>
    struct AssertIsArithmetic 
    : Assert<std::is_arithmetic<ArithmeticType>::value >{};

    template<typename ArithmeticTypeA, typename ArithmeticTypeB>
    struct AssertAreBothArithmetic 
    : Assert<
      (quan::meta::and_<
         std::is_arithmetic<ArithmeticTypeA>,
         std::is_arithmetic<ArithmeticTypeB>
      >::value)  
     >{};

    template<typename IntegralType>
    struct AssertIsIntegral 
    : Assert<std::is_integral<IntegralType>::value >{};

    template<typename IntegralTypeA, typename IntegralTypeB>
    struct AssertAreBothIntegral 
    : Assert<
      (quan::meta::and_<
         std::is_integral<IntegralTypeA>,
         std::is_integral<IntegralTypeB>
       >::value) 
    >{};

    template<typename FundamentalType>
    struct AssertIsFundamentalType 
    : Assert<std::numeric_limits<FundamentalType>::is_specialized>{};

    template<typename FundamentalTypeA, typename FundamentalTypeB>
    struct AssertAreBothFundamentalTypes 
    : Assert< (std::numeric_limits<FundamentalTypeA>::is_specialized &&
        std::numeric_limits<FundamentalTypeB>::is_specialized) >{};

   
    // assert that the parameter can be converted to an arithmetic type via the 
    // quan::meta::to_arithmetic metafunction
    template<typename ToArithmeticType>
    struct AssertToArithmetic 
    : Assert<
         std::is_arithmetic< 
            typename quan::meta::
                to_arithmetic<ToArithmeticType>::type
        >::value 
    >{};
  
}}//quan::concept_checking

#endif
