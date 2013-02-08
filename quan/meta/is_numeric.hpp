#ifndef QUAN_META_IS_NUMERIC_HPP_INCLUDED
#define QUAN_META_IS_NUMERIC_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

/*
    Is T a numeric type
*/

#include <type_traits>
#include <quan/meta/and.hpp>
#include <quan/meta/is_angle.hpp>
#include <quan/meta/or.hpp>

namespace quan{ namespace meta{

    template <typename ValueType>
    struct is_numeric : quan::meta::or_<std::is_arithmetic<ValueType>,quan::meta::is_angle<ValueType> >{};

    template <typename A, typename B>
    struct are_numeric : and_<
        is_numeric<A>,
        is_numeric<B>
    >{};
                
}}//quan::meta

#endif

