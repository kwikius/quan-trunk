#ifndef QUAN_META_RATIONAL_EVAL_HPP_INCLUDED1
#define QUAN_META_RATIONAL_EVAL_HPP_INCLUDED1
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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
//

//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    evaluate a quan::meta::rational to "minimum " type 
    e.g int or double
    Only used by testing
*/
#ifndef QUAN_AVR_NO_CPP_STDLIB
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
            typedef int32_t result_type;
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
