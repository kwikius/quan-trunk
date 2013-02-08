#ifndef QUAN_META_POW10_RATIONAL_HPP_INCLUDED
#define QUAN_META_POW10_RATIONAL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
#include <quan/detail/united_value/operations/coherent_exponent.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/bool.hpp>
/*
    do 10 to power rational
    pow10::result_type is the minimum for loss of precision and if a float is the
    quantity_traits::default_value_type..
    This is cleaner than passing in the required result_type,
    as required by the coherent_exponent::eval function used 
    in its implementation, but will cause conversions warnings for floats
    if the result_type is a double.
    Its used in the fixed_quantity tests, but not the implementation itself
*/

namespace quan{namespace meta{

    template <typename Rational>
    struct pow10 {
        typedef typename if_<
            or_<
                lt_<
                    Rational,
                    rational<0>
                >,
                gt_<
                    Rational,
                    rational<
                        std::numeric_limits<QUAN_INT32>::digits10
                    >
                >,
                bool_<
                   ( Rational::denominator != 1)
                >
            >,
            typename quan::quantity_traits::default_value_type,
            QUAN_INT32
        >::type result_type;
        typedef typename quan::detail::coherent_exponent<
            Rational::numerator,Rational::denominator
        > coh_exp;   
        typedef typename coh_exp::template eval<result_type> eval;
        
        result_type operator()()
        {
            eval eval_;
            result_type result = eval_();
            return result;
        }
    };
            
}}}

#endif
