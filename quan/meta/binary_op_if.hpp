#ifndef QUAN_META_BINARY_OPERATION_IF_HPP_INCLUDED
#define QUAN_META_BINARY_OPERATION_IF_HPP_INCLUDED
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
