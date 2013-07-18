#ifndef QUAN_META_BINARY_OPERATOR_TRAITS_HPP_INCLUDED
#define QUAN_META_BINARY_OPERATOR_TRAITS_HPP_INCLUDED
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
    more refined traits of operators
    should probably be:
    binary_operator_expression_family<op>::value;
    binary_operator_associates_left<op>::value
    note commutivity is naff and will be removed!
    might need to be specialised
*/
#include <quan/config.hpp>
#include <quan/meta/binary_operator_parameters.hpp>
#include <quan/meta/binary_operator_extra_keys.hpp>
#include <quan/meta/or.hpp>

namespace quan{ namespace meta{

    // per operator info
    // may require specialisation for udt
    template<
        typename Op
    >
    struct binary_operator_traits ;

    template<>
    struct binary_operator_traits<equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };
   
    template<>
    struct binary_operator_traits<plus_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    template<>
    struct binary_operator_traits<minus_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    template<>
    struct binary_operator_traits<times_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    template<>
    struct binary_operator_traits<divide_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    template<>
    struct binary_operator_traits<modulus_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    template<>
    struct binary_operator_traits<shift_left_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };
    
    template<>
    struct binary_operator_traits<shift_right_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    template<>
    struct binary_operator_traits<or_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    template<>
    struct binary_operator_traits<xor_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    template<>
    struct binary_operator_traits<and_equals> {
        enum{
            expression_family 
            = binary_operator_parameters::assignment_expression,
            associativity
            = binary_operator_parameters::left_associative
        };
    };

    //logical_or
    template<>
    struct binary_operator_traits<logical_or> {
        enum{
            expression_family 
            = binary_operator_parameters::logical_or_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };
    
    //logical and
    template<>
    struct binary_operator_traits<logical_and> {
        enum{
            expression_family 
            = binary_operator_parameters::logical_and_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };

    //bit or,inclusive or
    template<>
    struct binary_operator_traits<bit_or> {
        enum{
            expression_family 
            = binary_operator_parameters::inclusive_or_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };

     //exclusive or
    template<>
    struct binary_operator_traits<bit_xor> {
        enum{
            expression_family 
            = binary_operator_parameters::exclusive_or_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };

    //bitand, and
    template<>
    struct binary_operator_traits<bit_and> {
        enum{
            expression_family 
            = binary_operator_parameters::and_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };

    // equality_expressions  == !=
    template<>
    struct binary_operator_traits<equal_to> {
        enum{
            expression_family 
            = binary_operator_parameters::equality_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };

    // equality_expressions  == !=
    template<>
    struct binary_operator_traits<not_equal_to> {
        enum{
            expression_family 
            = binary_operator_parameters::equality_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };

    //relational

    template<>
    struct binary_operator_traits<less_equal> {
        enum{
            expression_family 
            = binary_operator_parameters::relational_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };
    template<>
    struct binary_operator_traits<greater_equal> {
        enum{
            expression_family 
            = binary_operator_parameters::relational_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };
    template<>
    struct binary_operator_traits<greater> {
        enum{
            expression_family 
            = binary_operator_parameters::relational_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };
    template<>
    struct binary_operator_traits<less> {
        enum{
            expression_family 
            = binary_operator_parameters::relational_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };
//shift
    template<>
    struct binary_operator_traits<shift_left> {
        enum{
            expression_family 
            = binary_operator_parameters::shift_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };
    template<>
    struct binary_operator_traits<shift_right> {
        enum{
            expression_family 
            = binary_operator_parameters::shift_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };
  
    template<>
    struct binary_operator_traits<plus> {
        enum{
            expression_family 
            = binary_operator_parameters::additive_expression,
            associativity
            = binary_operator_parameters::right_associative
        };
    };

    template<>
    struct binary_operator_traits<minus> {
        enum{
            expression_family 
            = binary_operator_parameters::additive_expression,
            associativity 
            = binary_operator_parameters::right_associative
        };
    };

    template<>
    struct binary_operator_traits<times> {
        enum{
            expression_family 
            = binary_operator_parameters::multiplicative_expression,
            associativity 
            = binary_operator_parameters::right_associative
        };
    };

    template<>
    struct binary_operator_traits<divides> {
        enum{
            expression_family 
            = binary_operator_parameters::multiplicative_expression,
            associativity 
            = binary_operator_parameters::right_associative
        };
    };

   template<>
    struct binary_operator_traits<div> {
        enum{
            expression_family 
            = binary_operator_parameters::multiplicative_expression,
            associativity 
            = binary_operator_parameters::right_associative
        };
    };

    template<>
    struct binary_operator_traits<modulus>  {
        enum{
            expression_family 
            = binary_operator_parameters::multiplicative_expression,
            associativity 
            = binary_operator_parameters::right_associative
        };
    };
    template<>
    struct binary_operator_traits<pow>  {
        enum{
            expression_family 
        // = binary_operator_parameters::multiplicative_expression,
            = binary_operator_parameters::pow_expression,
            associativity 
            = binary_operator_parameters::right_associative
        };
    };


    template< 
        typename Op
    >
    struct is_assignment_operator{
        typedef is_assignment_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::assignment_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_conditional_operator{
        typedef is_conditional_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::conditional_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_logical_or_operator{
        typedef is_logical_or_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::logical_or_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_logical_and_operator{
        typedef is_logical_and_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::logical_and_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_inclusive_or_operator{
        typedef is_inclusive_or_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::inclusive_or_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_exclusive_or_operator{
        typedef is_exclusive_or_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::exclusive_or_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_and_operator{
        typedef is_and_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::and_expression))
        };
    };

     template< 
        typename Op
    >
    struct is_bit_operator 
      : or_< 
            is_and_operator<Op>,
            or_<
             is_inclusive_or_operator<Op>,
             is_exclusive_or_operator<Op>
            >
      >{};

    template< 
        typename Op
    >
    struct is_equality_operator{
        typedef is_equality_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::equality_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_relational_operator{
        typedef is_relational_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::relational_expression))
        };
    };
    
   template< 
        typename Op
    >
    struct is_logical_operator : or_<
      is_logical_and_operator<Op>,
      or_<
         is_logical_or_operator<Op>,
         or_<
            is_relational_operator<Op>,
            is_equality_operator<Op>
         >
      >
    >{};

    template< 
        typename Op
    >
    struct is_shift_operator{
        typedef is_shift_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::shift_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_additive_operator{
        typedef is_additive_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::additive_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_multiplicative_operator{
        typedef is_multiplicative_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::multiplicative_expression))
        };
    };

    template< 
        typename Op
    >
    struct is_pow_operator{
        typedef is_pow_operator type;
        enum{ 
        value =
           (binary_operator_traits<Op>::expression_family
            == static_cast<int>(binary_operator_parameters::pow_expression))
        };
    };
    
}}//quan::meta

#endif
