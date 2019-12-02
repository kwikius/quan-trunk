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
#include <quan/meta/is_scalar.hpp>
#include <quan/quantity_traits.hpp>
#include <quan/meta/binary_operator_traits.hpp>
#include <quan/archetypes/meta/static_rational_concept.hpp>
#include <quan/meta/is_runtime_type.hpp>
#include <quan/meta/arithmetic_promote.hpp>
#include <quan/where.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
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

// quan version

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

    namespace impl { 
       
       template <
          typename A,
          typename Op,
          typename B,
          typename Enable = void
       >
       struct binary_op_impl : quan::undefined { };

       template < 
           typename A, 
           typename Op,
           typename B
       >
       struct binary_op_impl<
           A,Op,B,
           typename quan::where_<           
               is_assignment_operator<Op> 
           >::type
       >{
   #ifndef QUAN_AVR_NO_CPP_STDLIB
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
       struct binary_op_impl<
           A,Op,B,
           typename quan::where_<
               and_<
                  is_scalar<A>,
                  is_scalar<B>,
                  or_<
                     quan::meta::is_equality_operator<Op>,
                     quan::meta::is_relational_operator<Op>
                  >,
                  or_<
                     quan::meta::is_runtime_type<A>,
                     quan::meta::is_runtime_type<B>
                  >,
                  or_<
                     quan::meta::is_valid_binary_op<A,minus,B>,
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
      struct binary_op_impl<
         bool, logical_or, bool
      >{
         typedef bool type;
      };
      
      template<>
      struct binary_op_impl<
         bool, logical_and, bool
      >{
         typedef bool type;
      };
      
      template<>
      struct binary_op_impl<
         bool, bit_and, bool
      >{
         typedef bool type;
      };


      template <
       typename A,
       typename B
      >
      struct binary_op_impl<
        A , plus, B , 
        typename quan::where_<
            quan::meta::are_arithmetic<A,B>
        >::type
      > : quan::meta::arithmetic_promote<A,B>{};
//     {
//          typedef typename arithmetic_promote<A,B>::type type;
//      };

      template <
       typename A,
       typename B
      >
      struct binary_op_impl<
        A , minus, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
       > : quan::meta::arithmetic_promote<A,B>{};
//{
//        typedef typename arithmetic_promote<A,B>::type type;
//      };

      template <
       typename A,
       typename B
      >
      struct binary_op_impl<
        A , bit_or, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
      > : quan::meta::arithmetic_promote<A,B>{};
//{
//        typedef typename arithmetic_promote<A,B>::type type;
//      };

      template <
       typename A,
       typename B
      >
      struct binary_op_impl<
        A , bit_and, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
      > : quan::meta::arithmetic_promote<A,B>{};
//{
//        typedef typename arithmetic_promote<A,B>::type type;
//      };

      template <
         typename A,
         typename B
      >
      struct binary_op_impl<
        A , times, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
      > : quan::meta::arithmetic_promote<A,B>{};
//{
//
//        typedef typename quan::meta::arithmetic_promote<A,B>::type type;
//      };

      template <
         typename A,
         typename B
      >
      struct binary_op_impl<
        A , divides, B , 
        typename quan::where_<
            are_arithmetic<A,B>
        >::type
      > : quan::meta::arithmetic_promote<A,B>{};
// {
//          typedef typename quan::meta::arithmetic_promote<A,B>::type type;
//      };

      template <
         typename A,
         typename B
      >
      struct binary_op_impl<
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
      > : quan::meta::arithmetic_promote<
            A,
            quan::quantity_traits::default_value_type
          >{};
//{
//          typedef typename quan::meta::arithmetic_promote<
//            A,
//            quan::quantity_traits::default_value_type
//          >::type type;
//      };

   }//impl
   
}}//quan::meta

#endif
