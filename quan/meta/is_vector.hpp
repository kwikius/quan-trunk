#ifndef QUAN_META_IS_VECTOR_HPP_INCLUDED
#define QUAN_META_IS_VECTOR_HPP_INCLUDED

// Copyright Andrew Little 20011

#include <quan/config.hpp>
#include <quan/meta/bool/false.hpp>

namespace quan{ namespace meta{

    template <typename T>
    struct is_vector : quan::meta::false_{};

}}//quan::meta

#endif
