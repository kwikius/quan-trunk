#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef QUAN_GENERIC_UNARY_OPERATORS_HPP_INCLUDED
#define QUAN_GENERIC_UNARY_OPERATORS_HPP_INCLUDED
//  Copyright (C) Andy Little, White Light Device 2003.
//  Permission to copy, use, modify, sell and distribute this software
//  is granted provided this copyright notice appears in all copies.
//  This software is provided "as is" without express or implied warranty,
//  and with no claim as to its suitability for any purpose.

/*
    unary_operators =- not much used, nor much implemented yet
*/

#include <quan/meta/binary_operator_extra_keys.hpp>
#include <quan/meta/unary_operators.hpp>

namespace quan{

    //// key for reciprocal
    //template <typename T>
    //struct reciprocal;


    template<typename  Op, typename T>
    struct unary_operator{
        
            typedef T result_type;
    };
    template<typename T>
    struct unary_operator<quan::meta::minus,T>{
        
       typedef T result_type;

       result_type operator()( T t)
       {
            return -t;
       }
    };

    template<typename T>
    struct unary_operator<quan::meta::plus,T>{
        
       typedef T result_type;

       result_type operator()( T t)
       {
            return t;
       }
    };
 }//quan

#endif
