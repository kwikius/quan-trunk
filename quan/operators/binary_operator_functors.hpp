#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef QUAN_BINARY_OPERATOR_FUNCTORS_HPP_INCLUDED
#define QUAN_BINARY_OPERATOR_FUNCTORS_HPP_INCLUDED
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
//  Permission to copy, use, modify, sell and distribute this software
//  is granted provided this copyright notice appears in all copies.
//  This software is provided "as is" without express or implied warranty,
//  and with no claim as to its suitability for any purpose.

/*
    functors for replacing original ones in functional
    can be used for udt and combined types e.g
    result_of<operator_plus(int,double) t = operator_plus() (int,double);
*/

#include <quan/operators/binary_operators.hpp>
#include <quan/operators/unary_operators.hpp>
#include <quan/meta/is_valid_binary_op.hpp>
#include <quan/where.hpp>
#include <type_traits>

namespace quan{

    // just a common base class

    template<typename  Op, typename Enable = void>
    struct operator_;
   
    template<typename Op>
    struct operator_<
        Op,
        typename quan::where_not<
            quan::meta::is_assignment_operator<Op>
        >::type
    >{
        
        typedef Op operator_key;
        template< typename L, typename R>
        struct result
        { 
            static_assert(quan::meta::is_valid_binary_op<L,Op,R>::value,"invalid binary op");
            typedef typename binary_operator<
               typename std::remove_cv<
                    typename std::remove_reference<L>::type
               >::type ,
               Op,
               typename std::remove_cv<
                    typename std::remove_reference<R>::type
               >::type
            >::result_type type;
        };

        template< typename L, typename R>
        struct  apply {
           typedef typename result<L,R>::type type;
        };

        template<typename L, typename R>
        constexpr 
        typename result<
           L,R
        >::type 
          operator()(L const&  l, R const & r) const   
        { 
            static_assert(quan::meta::is_valid_binary_op<L,Op,R>::value,"invalid binary op");
            return binary_operator< 
                typename std::remove_cv<
                    typename std::remove_reference<L>::type
               >::type ,
               Op,
               typename std::remove_cv<
                    typename std::remove_reference<R>::type
               >::type
            >()(l,r);
        }
      
    };

    template<typename Op>
    struct operator_<
        Op,
        typename quan::where_<
            quan::meta::is_assignment_operator<Op>
        >::type
    >{
        typedef Op operator_key;
        template< typename L, typename R>
        struct result
        { 
            static_assert(quan::meta::is_valid_binary_op<L,Op,R>::value,"invalid binary op");
            typedef typename binary_operator<
                L,
                Op,
                R
            >::result_type type;
        };

        template< typename L, typename R>
        struct  apply {
           typedef typename result<L,R>::type type;
        };

        template<typename L, typename R>
        constexpr 
        typename result<
           L,R
        >::type 
        
        operator()(L &  lhs, R const & rhs) const   
        { 
            static_assert(quan::meta::is_valid_binary_op<L,Op,R>::value,"invalid binary op");
            return binary_operator<L,Op,R>()(lhs,rhs);
        }
      
    };
        
    struct operator_equals : operator_<quan::meta::equals>{};
    struct operator_plus_equals : operator_<quan::meta::plus_equals>{};
    struct operator_minus_equals : operator_<quan::meta::minus_equals>{};
    struct operator_times_equals : operator_<quan::meta::times_equals>{};
    struct operator_divide_equals : operator_<quan::meta::divide_equals>{};
    struct operator_shift_left_equals : operator_<quan::meta::shift_left_equals>{};
    struct operator_shift_right_equals : operator_<quan::meta::shift_right_equals>{};
    struct operator_or_equals : operator_<quan::meta::or_equals>{};
    struct operator_and_equals : operator_<quan::meta::and_equals>{};
    struct operator_modulus_equals : operator_<quan::meta::modulus_equals>{};
    struct operator_xor_equals : operator_<quan::meta::xor_equals>{};
    /*
      add shift equals etc or_equals
    */
    struct operator_logical_or : operator_<quan::meta::logical_or>{};
    struct operator_logical_and : operator_<quan::meta::logical_and>{};
    struct operator_bit_or : operator_<quan::meta::bit_or>{};
    struct operator_bit_xor : operator_<quan::meta::bit_xor>{};
    struct operator_bit_and : operator_<quan::meta::bit_and>{};
    struct operator_equal_to : operator_<quan::meta::equal_to>{};
    struct operator_not_equal_to : operator_<quan::meta::not_equal_to>{};
    struct operator_greater_equal : operator_<quan::meta::greater_equal>{};
    struct operator_less_equal : operator_<quan::meta::less_equal>{};
    struct operator_greater : operator_<quan::meta::greater>{};
    struct operator_less : operator_<quan::meta::less>{};
    struct operator_minus : operator_<quan::meta::minus>{};
    struct operator_plus : operator_<quan::meta::plus>{};
    struct operator_times : operator_<quan::meta::times>{};
    struct operator_divides : operator_<quan::meta::divides>{};
    struct operator_div : operator_<quan::meta::div>{};
    struct operator_mod : operator_<quan::meta::modulus>{};
    struct operator_shift_left : operator_<quan::meta::shift_left>{};
    struct operator_shift_right : operator_<quan::meta::shift_right>{};

}  //quan

#endif 
