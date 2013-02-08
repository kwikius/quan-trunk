#ifndef QUAN_META_UNARY_OPERATION_HPP_INCLUDED
#define QUAN_META_UNARY_OPERATION_HPP_INCLUDED

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    not all implemented
    negate, reciprocal,square-root,cube-root,square,cube
*/
#include <quan/config.hpp>
#include <quan/meta/unary_operators.hpp>
#include <quan/concept_checking.hpp>
#include <quan/where.hpp>
#include <type_traits>

namespace quan{namespace meta{

    template <
       typename Op,
       typename T ,
       typename Enable = void
    >
    struct unary_operation;

    template<typename T>
    struct unary_operation<
        reciprocal,
        T,
        typename quan::where_<
            std::is_floating_point<T>
        >::type
    >{
         typedef T type;
    };
    template<typename T>
    struct unary_operation<
        reciprocal,
        T,
        typename quan::where_<
            std::is_integral<T>
        >::type
    >{
         typedef QUAN_FLOAT_TYPE type;
    };

}}//quan::meta

#endif
