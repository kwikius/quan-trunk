#ifndef QUAN_META_IS_VALID_BINARY_OPERATION_HPP_INCLUDED
#define QUAN_META_IS_VALID_BINARY_OPERATION_HPP_INCLUDED
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
  value is true if binary_operation is defined on the two type

*/

#include <quan/meta/binary_op.hpp>
//#ifndef QUAN_AVR_NO_CPP_STDLIB
//#include <type_traits>
//#else
//#include <quan/std/tr1/remove_reference.hpp>
//#include <quan/std/tr1/is_same.hpp>
//#endif
//
//namespace quan{ namespace meta{
//
////    template <
////        typename Left, 
////        typename Op, 
////        typename Right
////    >
////    struct is_valid_binary_op {
////
////         typedef typename std::remove_cv<
////               typename std::remove_reference<
////                  Left
////               >::type
////         >::type lhs;
////          typedef typename std::remove_cv<
////               typename std::remove_reference<
////                  Right
////               >::type
////         >::type rhs;
////         typedef  typename quan::meta::binary_op<
////            lhs, Op, rhs
////         >::type result_type;
////        enum{
////            value = (std::is_same<result_type,quan::undefined>::value == 0)
////        };
////        typedef is_valid_binary_op type;
////    };
//
//}}//quan::meta

#endif
