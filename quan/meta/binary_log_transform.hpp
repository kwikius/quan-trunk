#ifndef QUAN_META_BINARY_LOG_TRANSFORM_HPP_INCLUDED
#define QUAN_META_BINARY_LOG_TRANSFORM_HPP_INCLUDED
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

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    transform binary operations for use on powers
*/

#include <quan/meta/binary_op.hpp>
#include <quan/concept_checking.hpp>
#include <quan/meta/eq.hpp>

namespace quan{namespace meta{

    template <typename Lhs ,typename Op, typename Rhs>
    struct binary_log_transform;

    template <
        typename A,
        typename B
    > 
    struct binary_log_transform<A,plus,B> 
    : concept_checking::Assert<
        eq_<A,B>::value 
    >{
        typedef A type;
    };

    template <
        typename A,
        typename B
    > 
    struct binary_log_transform<A,minus,B> 
    : concept_checking::Assert<
        eq_<A,B>::value 
    >{
        typedef A type;
    };

    template <
        typename A,
        typename B
    > 
    struct binary_log_transform<A,times,B> : binary_op<
    typename A::type,plus,typename B::type>{};

    template <
        typename A,
        typename B
    > 
    struct binary_log_transform<A,divides,B>: binary_op<
    typename A::type ,minus,typename B::type>{};

}}//quan::meta

#endif
