#ifndef QUAN_META_NEQ_ZERO_HPP_INCLUDED
#define QUAN_META_NEQ_ZERO_HPP_INCLUDED

#include <quan/meta/bool.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/fun.hpp>

#include <quan/meta/eq_zero.hpp>

namespace quan{namespace meta{

    template <typename T>
    struct neq_zero : not_< eq_zero<T> >{};

    template<> struct neq_zero<fun> {
         template <typename T> 
         struct apply : neq_zero<T>{};
    };

}} // quan::meta

#endif // QUAN_META_NEQ_ZERO_HPP_INCLUDED
