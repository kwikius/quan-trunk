#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef QUAN_GENERIC_UNARY_OPERATORS_HPP_INCLUDED
#define QUAN_GENERIC_UNARY_OPERATORS_HPP_INCLUDED
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
