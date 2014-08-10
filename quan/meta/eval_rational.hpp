#ifndef QUAN_META_RATIONAL_EVAL_HPP_INCLUDED1
#define QUAN_META_RATIONAL_EVAL_HPP_INCLUDED1
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    evaluate a quan::meta::rational to "minimum " type 
    e.g int or double
    Only used by testing
*/
#ifndef __AVR__
#include <cstdint>
#else
#include <stdint.h>
#endif
#include <quan/config.hpp>
#include <quan/meta/rational.hpp>

namespace quan{namespace meta{

    namespace detail{
        template<
            int64_t N,
            int64_t D
        >
        struct rational_impl_eval 
        {
            typedef typename rational_impl<N,D>::type rat_type;
            typedef double result_type;

QUAN_CONSTEXPR result_type operator()() const 
            {
                return static_cast<result_type>(static_cast<int64_t>(rat_type::numerator))
                / static_cast<int64_t>(rat_type::denominator);
            }
        };

        template<
            int64_t N
        >
        struct rational_impl_eval<N,1>{
            typedef int64_t result_type;
 QUAN_CONSTEXPR           result_type operator()() const
            {
                return N;
            }
        };

    }//detail

    template <typename Rational>
    struct eval_rational : detail::rational_impl_eval<
                Rational::numerator, Rational::denominator
     >{};

}}//quan::meta

#endif
