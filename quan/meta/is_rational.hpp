#ifndef QUAN_META_IS_RATIONAL_HPP_INCLUDED
#define QUAN_META_IS_RATIONAL_HPP_INCLUDED

#ifndef __AVR__
#include <type_traits>
#else
#include <quan/std/tr1/integral_constant.hpp>
#endif

namespace quan{namespace meta{

    template <typename T>
    struct is_rational : std::false_type{}; 

}}

#endif // QUAN_META_IS_RATIONAL_HPP_INCLUDED