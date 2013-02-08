#ifndef QUAN_CONCEPT_CHECKING_HPP_INCLUDED
#define QUAN_CONCEPT_CHECKING_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    concept checking classes
*/

#include <type_traits>
#include <quan/meta/to_arithmetic.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/if.hpp>
#if defined __AVR__
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
