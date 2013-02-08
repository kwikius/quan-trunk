#ifndef QUAN_META_IS_VALID_BINARY_OPERATION_HPP_INCLUDED
#define QUAN_META_IS_VALID_BINARY_OPERATION_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
  value is true if binary_operation is defined on the two type

*/

#include <quan/meta/binary_op.hpp>
#include <type_traits>


namespace quan{ namespace meta{

    template <
        typename Left, 
        typename Op, 
        typename Right
    >
    struct is_valid_binary_op {

         typedef typename std::remove_cv<
               typename std::remove_reference<
                  Left
               >::type
         >::type lhs;
          typedef typename std::remove_cv<
               typename std::remove_reference<
                  Right
               >::type
         >::type rhs;
         typedef  typename quan::meta::binary_op<
            lhs, Op, rhs
         >::type result_type;
        enum{
            value = (std::is_same<result_type,quan::undefined>::value == 0)
        };
        typedef is_valid_binary_op type;
    };

}}//quan::meta

#endif
