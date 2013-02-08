#ifndef QUAN_META_BINARY_LOG_TRANSFORM_HPP_INCLUDED
#define QUAN_META_BINARY_LOG_TRANSFORM_HPP_INCLUDED
// Copyright Andrew Little 2005

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
