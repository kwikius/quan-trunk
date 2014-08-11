#ifndef QUAN_META_POW10_RATIONAL_HPP_INCLUDED
#define QUAN_META_POW10_RATIONAL_HPP_INCLUDED
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
                        std::numeric_limits<int64_t>::digits10
                    >
                >,
                bool_<
                   ( Rational::denominator != 1)
                >
            >,
            typename quan::quantity_traits::default_value_type,
            int64_t
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
