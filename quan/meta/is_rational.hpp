#ifndef QUAN_META_IS_RATIONAL_HPP_INCLUDED
#define QUAN_META_IS_RATIONAL_HPP_INCLUDED

#include <quan/config.hpp>
#if ! defined QUAN_USE_QUAN_STD_TR1
#include <type_traits>
#include <ratio>
#else
#include <stdint.h>
#include <quan/std/tr1/integral_constant.hpp>
//#include <quan/std/tr1/ratio.hpp>
#endif

#if defined QUAN_USE_QUAN_STD_TR1

namespace std{
   template <intmax_t N, intmax_t D> struct ratio;
}

#endif

namespace quan{namespace meta{

    template <typename T>
    struct is_rational : std::false_type{}; 

    template <intmax_t N, intmax_t D>
    struct is_rational<std::ratio<N,D> > : std::true_type{};

}}

#endif // QUAN_META_IS_RATIONAL_HPP_INCLUDED
