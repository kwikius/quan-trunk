#ifndef BOOST_PQS_META_MIN_TYPE_HPP_INCLUDED
#define BOOST_PQS_META_MIN_TYPE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    promotion convenience
    to a minimum type
*/

#include <quan/meta/arithmetic_promote.hpp>
#include <quan/quantity_traits.hpp>
#include <quan/meta/if.hpp>
#include <type_traits>

namespace quan{ namespace meta{

    template<typename T>
    struct int_promote : arithmetic_promote<int,T>{};
    template<typename T>
    struct long_promote : arithmetic_promote<long,T>{};
    template<typename T>
    struct float_promote : arithmetic_promote<float,T>{};
    template<typename T>
    struct double_promote : arithmetic_promote<double,T>{};
    template<typename T>
    struct long_double_promote : arithmetic_promote<long double,T>{};

    template <typename T>
    struct min_default_value_type : arithmetic_promote<
        quan::quantity_traits::default_value_type,T
    >{};

    template <typename T>
    struct convert_integral_to_double
    {
        typedef typename if_<
            std::is_integral<T>,
            double,
            T
        >::type type;
    };
    
   
}}//quan::meta

#endif
