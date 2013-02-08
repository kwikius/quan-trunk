#ifndef BOOST_PQS_META_VALUE_TYPE_HPP_INCLUDED
#define  BOOST_PQS_META_VALUE_TYPE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

#include <type_traits>
#include <quan/meta/and.hpp>
namespace quan{ namespace meta{

    template <typename ValueType>
    struct is_value_type : std::is_arithmetic<ValueType>{};

    template <typename A, typename B>
    struct are_value_type2 : and_<
        is_value_type<A>,
        is_value_type<B>
    >::type{};
                
}}//quan::meta

#endif

