#ifndef QUAN_META_BINARY_OPERATION_HPP_INCLUDED1
#define QUAN_META_BINARY_OPERATION_HPP_INCLUDED1
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2005-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/
/*
    The binary_operation struct has one member 'type' which 
    represents the type of the result of a binary operation.
    such as +, -, *, << ,!= ,== etc. The Op parameter 'token'
    is represented by the Op tokens provided in
    "quan/meta/binary_operator_extra_keys.hpp".
    e.g for the result type of addition of 2 ints the typedef 
    would look like binary_op<int,plus,int>::type.

*/
#include <quan/config.hpp>
#include <quan/undefined.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/quantity_traits.hpp>
#include <quan/meta/binary_operator_traits.hpp>
#include <quan/archetypes/meta/static_rational_concept.hpp>
#include <quan/meta/is_runtime_type.hpp>
#include <quan/meta/arithmetic_promote.hpp>
#include <quan/where.hpp>
#ifndef __AVR__
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#include <quan/std/tr1/is_same.hpp>
#include <quan/std/tr1/add_reference.hpp>
#endif

#include <quan/meta/or.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/neq.hpp>
#include <quan/meta/not.hpp>

namespace quan{  namespace meta{

    template <
        typename Left, 
        typename Op, 
        typename Right
    >
    struct is_valid_binary_op;

    template <typename A, typename B>
     struct are_arithmetic : and_<
        std::is_arithmetic<A>,
        std::is_arithmetic<B>
    >{};
       
    template <
       typename A,
       typename Op,
       typename B,
       typename Enable = void
    >
    struct binary_op{
        typedef quan::undefined type;
    };

    template < 
        typename A, 
        typename Op,
        typename B
    >
    struct binary_op<
        A,Op,B,
        typename quan::where_<           
            is_assignment_operator<Op> 
        >::type
    >{
#ifndef __AVR__
        typedef typename std::add_lvalue_reference<A>::type type;
#else
        typedef typename std::add_reference<A>::type type;
#endif
    };

   template<
      typename A, 
      typename Op,
      typename B
    >
    struct binary_op<
        A,Op,B,
        typename quan::where_<
            and_<
               or_<
                  is_equality_operator<Op>,
                  is_relational_operator<Op>
               >,
               or_<
                  is_runtime_type<A>,
                  is_runtime_type<B>
               >,
               or_<
                  is_valid_binary_op<A,minus,B>,
                  and_<
                     std::is_same<A,bool>,
                     std::is_same<B,bool>
                  >
               >
            >
        >::type
    >{
      typedef bool type;
    };

      template<>
      struct binary_op<
         bool, logical_or, bool
      >{
         typedef bool type;
      };
      
      template<>
      struct binary_op<
         bool, logical_and, bool
      >{
         typedef bool type;
      };
      
      template<>
      struct binary_op<
         bool, bit_and, bool
      >{
         typedef bool type;
      };


    template <
       typename A,
       typename B
    >
    struct binary_op<
        A , plus, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
    > {
      typedef typename arithmetic_promote<A,B>::type type;
    };

    template <
       typename A,
       typename B
    >
    struct binary_op<
        A , minus, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
    > {
        typedef typename arithmetic_promote<A,B>::type type;
    };

     template <
       typename A,
       typename B
    >
    struct binary_op<
        A , bit_or, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
    > {
        typedef typename arithmetic_promote<A,B>::type type;
    };

    template <
       typename A,
       typename B
    >
    struct binary_op<
        A , bit_and, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
    > {
        typedef typename arithmetic_promote<A,B>::type type;
    };

    template <
       typename A,
       typename B
    >
    struct binary_op<
        A , times, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
    > {

        typedef typename arithmetic_promote<A,B>::type type;
    };

    template <
       typename A,
       typename B
    >
    struct binary_op<
        A , divides, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
    > {
        typedef typename arithmetic_promote<A,B>::type type;
    };

    template <
       typename A,
       typename B
    >
    struct binary_op<
        A , pow, B , 
        typename quan::where_<
            and_<
               std::is_arithmetic<A>,
               and_<
                  not_<eq_one<B> >,
                  not_<eq_zero<B> >
               >
            >
        >::type
    > {
        typedef typename arithmetic_promote<
            A,
            quan::quantity_traits::default_value_type
        >::type type;
    };
   
}}//quan::meta

#endif
