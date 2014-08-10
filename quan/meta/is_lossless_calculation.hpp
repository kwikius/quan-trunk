#ifndef QUAN_META_IS_LOSSLESS_CALCULATION_HPP_INCLUDED
#define QUAN_META_IS_LOSSLESS_CALCULATION_HPP_INCLUDED


// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/is_numeric.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/and.hpp>
//#include <quan/where.hpp>
#include <quan/where.hpp>
#ifndef __AVR__
#include <type_traits>
#else
#include <quan/std/tr1/integral_constant.hpp>
#endif

namespace quan{ namespace meta{
    
    template <typename TL, typename Op, typename TR, typename Enable = void>
    struct is_lossless_calculation;

    template <typename TL, typename Op, typename TR>
    struct is_lossless_calculation< 
        TL, Op, TR,
        typename quan::where_<
            are_numeric<TL,TR> 
        >::type
    > : std::true_type{};

        
}}//quan::meta

#endif
