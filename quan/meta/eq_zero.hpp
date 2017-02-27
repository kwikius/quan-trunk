#ifndef QUAN_META_EQ_ZERO_HPP_INCLUDED
#define QUAN_META_EQ_ZERO_HPP_INCLUDED

#include <quan/meta/bool.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/fun.hpp>

namespace quan{namespace meta{

    template <typename T>
    struct eq_zero : bool_<((T::value) == 0)>{};

    template<> struct eq_zero<fun> {
         template <typename T> struct apply : eq_zero<T>{};
    };

}} // quan::meta

#endif // QUAN_META_EQ_ZERO_HPP_INCLUDED
