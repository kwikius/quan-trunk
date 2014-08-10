#ifndef QUAN_META_BINARY_OPERATION_IF_HPP_INCLUDED
#define QUAN_META_BINARY_OPERATION_IF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    binary_operation with encapsulated_enable_if
    for use in function return types
*/
#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>

namespace quan { namespace meta{

    template <
        bool Condition,
        typename Left,
        typename Op,
        typename Right
    >
    struct binary_op_if_c;

    template <
        typename Left,
        typename Op,
        typename Right
    >
    struct binary_op_if_c<
        true,
        Left,
        Op,
        Right
    > {
        typedef  typename quan ::meta::binary_op<
            Left,Op,Right
        >::type type;
    };
    

    template <
        typename Left,
        typename Op,
        typename Right
    >
    struct binary_op_if_c<
        false,
        Left,
        Op,
        Right
    >{};

    template <
        typename Condition,
        typename Left,
        typename Op,
        typename Right
    >
    struct binary_op_if : binary_op_if_c<
        (static_cast<bool>(Condition::value)),
        Left, Op, Right
     >{};
            
} }//quan::meta

#endif
