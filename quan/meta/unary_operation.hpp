#ifndef QUAN_META_UNARY_OPERATION_HPP_INCLUDED
#define QUAN_META_UNARY_OPERATION_HPP_INCLUDED

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
    not all implemented
    negate, reciprocal,square-root,cube-root,square,cube
*/
#include <quan/config.hpp>
#include <quan/meta/unary_operators.hpp>
#include <quan/concept_checking.hpp>
#include <quan/where.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_float.hpp>
#endif

namespace quan{namespace meta{

    template <
       typename Op,
       typename T ,
       typename Enable = void
    >
    struct unary_operation;

    template<typename T>
    struct unary_operation<
        reciprocal,
        T,
        typename quan::where_<
            std::is_floating_point<T>
        >::type
    >{
         typedef T type;
    };
    template<typename T>
    struct unary_operation<
        reciprocal,
        T,
        typename quan::where_<
            std::is_integral<T>
        >::type
    >{
         typedef QUAN_FLOAT_TYPE type;
    };

}}//quan::meta

#endif
