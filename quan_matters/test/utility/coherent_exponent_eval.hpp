#ifndef QUAN_DETAIL_COHERENT_EXPONENT_EVAL_INCLUDED
#define QUAN_DETAIL_COHERENT_EXPONENT_EVAL_INCLUDED

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

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
THIS CODE is now redundant except for testing.

    functors to evaluate the value of a coherent-exponent.
    IOW pow(exponent,10), except using constants rather than runtime evaluation if possible.
    Note that only positive exponents are ever used in Quan
    hence there are no specialisations for negative powers.
    Probably should add long double versions too.

    Note: If an int64_t can be returned and the input ResultType is a floating point type
    then the ResultType 'hint' could be ignored, maybe, if it was quicker and could be 
    better optimise away.
*/

#include <quan/meta/pow_c.hpp>
#include <quan/quantity_traits.hpp>
#include <quan/meta/min_type.hpp>
#include <quan/concept_checking.hpp>
#include <quan/detail/pow10_exponent.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/identity.hpp>
#include <quan/static_assert.hpp>

#ifndef __AVR__
#include <cmath>
#include <limits>
#else
#include <math.h>
#include <limits.h>
#endif

namespace quan{ namespace detail{

        // default  instantiated for any non-integer exponent
        // currently set up to return min float of
        // quantity_traits:;default_value_type
        // but maybe should bypass that and return a C++ float if asked
        template <
            typename ResultType,
            int64_t N, 
            int64_t D, 
            bool WantInt
        >
        struct coherent_exponent_eval{

//****************************************************************
//****************************************************************
// If here specialisation of coherent_exponent_eval has failed
            QUAN_STATIC_ASSERT( ((D !=1)||( N <=0)));
// Basically dont want this version called unless necessary
// as it uses std::pow and has limited range
//*****************************************************************
//*****************************************************************

            enum{ required = true};
            typedef float min_result_type;
            typedef typename quan::quantity_traits::min_real<
                min_result_type
            >::type result_type;

#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
            result_type operator()()const 
            {

#ifndef __AVR__
                return std::pow(
#else
                return ::pow(
#endif
                    static_cast<result_type>(10),
                    static_cast<result_type>(N)/D
                );
            }
        };

        // instantiated for very large/small integer powers but not used
        // really requires a mod
        template <typename ResultType,int64_t N, bool WantInt>
        struct coherent_exponent_eval<
            ResultType,N,1, WantInt
        >{
            enum{ required = true};
            typedef ResultType min_result_type;
            typedef ResultType result_type;
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
            result_type operator()()const ;
        };

        //isntantiated for small positive integer exponents
        // fast and integer result
        template<typename ResultType,int64_t N>
        struct coherent_exponent_eval<ResultType,N,1,true>{
            enum{ required = ( N !=0 ) };
            typedef int64_t min_result_type;
            typedef typename meta::arithmetic_promote<
                int64_t,ResultType
            >::type result_type;
 #ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
            result_type operator()()const 
            {
               return static_cast<result_type>(
                    quan::meta::pow_c<
                        int64_t,
                        10,N
                    >::value
                );
            }
        };

        template<typename ResultType,int64_t N>
        struct coherent_exponent_eval<ResultType,N,1,false>{
            enum{ required = ( N !=0 ) };
            typedef ResultType min_result_type;
            typedef typename meta::arithmetic_promote<
                int64_t,ResultType
            >::type result_type;
 
            typedef typename quan::meta::eval_if_c<
					(N>0),
						quan::meta::identity<quan::detail::pow10_integer_exponent<ResultType,N> >,
						quan::meta::identity<quan::detail::pow10_integer_exponent<ResultType,-N> >
              >::type functype;
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
            result_type operator()()const 
            {
                return ( N > 0 ) ? functype ()(): 1/functype()();   
            }
        };


}}//quan::detail

#endif

