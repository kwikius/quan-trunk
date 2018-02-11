#ifndef QUAN_DETAIL_DIMLESS_MULTIPLY_EXP_ONLY_HPP_INCLUDED
#define QUAN_DETAIL_DIMLESS_MULTIPLY_EXP_ONLY_HPP_INCLUDED
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
    In these versions of the dimensionless multiply calculation,
    only the Exponent is used. The Multipliers have been eliminated,
    as they evaluate to 1
    We also know that the Exponent is non zero.
    ( If The exponent is 0 then the calculation is the same as  for a dimensioned multiply)
*/

#include <quan/detail/united_value/operations/dimensioned_multiply.hpp>
#include <quan/meta/pow_c.hpp>
#include <quan/detail/pow10_exponent.hpp>
#include <quan/meta/digits10.hpp>

namespace quan{ namespace detail{

    //Exponent is a rational.Use std::pow
    template <typename Exponent>
    struct dimensionless_multiply_exp_only_rational_rt{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;

        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type;   
            
            result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
 #ifndef QUAN_AVR_NO_CPP_STDLIB
           using std::pow;
#endif
                result_type result = lhs * rhs
                *   pow(
                        static_cast<constant_arg_type>(10),
                        (static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                            /quan::meta::denominator<Exponent>::value)
                    );
                return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_exp_only_rational_rt type;
    };

    // Exponent is a negative integer <= -10
    // use pow10_integer_exponent functor
    template <typename Exponent>
    struct dimensionless_multiply_exp_only_negative_integer_rt{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type; 
            QUAN_CONSTEXPR result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
                typedef pow10_integer_exponent<
                    constant_arg_type,-(quan::meta::numerator<Exponent>::value)
                > pow10;
            //    result_type result = (lhs * rhs) / pow10{}();
              //  return result;
               return (lhs * rhs) / pow10{}();
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_exp_only_negative_integer_rt type;
    };

    // Exponent is a positive integer >= 10
    // use pow10_integer_exponent functor
    template <typename Exponent>
    struct dimensionless_multiply_exp_only_positive_integer_rt{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;

        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type; 
            QUAN_CONSTEXPR result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
                typedef pow10_integer_exponent<constant_arg_type,quan::meta::numerator<Exponent>::value> pow10;
//                result_type result = (lhs * rhs) * pow10();
//                return result;
               return  (lhs * rhs) * pow10{}();
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_exp_only_positive_integer_rt type;
    };

    // run time evaluate Exponent 
    // decide whether Exponent is a Rational or Integer
    // and if integer + or -.
    template <typename Exponent>
    struct dimensionless_multiply_exp_only_rt : quan::meta::eval_if<
        quan::meta::is_integer<Exponent>,
        quan::meta::eval_if_c<
            (quan::meta::numerator<Exponent>::value > 0),  
            dimensionless_multiply_exp_only_positive_integer_rt<Exponent>,
            dimensionless_multiply_exp_only_negative_integer_rt<Exponent>
        >,
        dimensionless_multiply_exp_only_rational_rt<Exponent>
    >::type{};

    // Exponent is a positive integer <= 9 so can be compile tiem evaluated
    // Use compile time pow_c
    template <typename Exponent>
    struct dimensionless_multiply_exp_only_positive_ct{
        typedef int32_t preferred_result_type;
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type; 
            // ideally warn if the value_types are 32 bit integers
            // as overflow is very likeley then.
            // OTOH provide a check option
            QUAN_CONSTEXPR result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
                return  (lhs * rhs) *
                    static_cast<constant_arg_type>(
                        quan::meta::pow_c<
                            int32_t,10,quan::meta::numerator<Exponent>::value
                        >::value
                    );
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_exp_only_positive_ct type;
    };

    // In this version the Exponent is a negative integer >= -9.
    // If negated, it can be compile time evaluated
    // Use compile time pow_c function on the negated exponent
    // and divide by it rather than multiply
    // Result type must be a float though
    template <typename Exponent>
    struct dimensionless_multiply_exp_only_negative_ct{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type;
            QUAN_CONSTEXPR result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
                return  (lhs * rhs) /
                    static_cast<constant_arg_type>(
                        quan::meta::pow_c<
                            int32_t,10, -quan::meta::numerator<Exponent>::value
                        >::value
                    );

            }
            typedef eval type;
        };
        typedef dimensionless_multiply_exp_only_negative_ct type;
    };

    // Integer exponent, not zero, small enough to compile time evaluate
    // is it positive or negative?
    template <typename Exponent>
    struct  dimensionless_multiply_exp_only_ct : quan::meta::eval_if<
            quan::meta::gt_zero<quan::meta::numerator<Exponent> >,
            dimensionless_multiply_exp_only_positive_ct<Exponent>,
            dimensionless_multiply_exp_only_negative_ct<Exponent>
    >::type {};

    // The actual calculation used  is dependent on whether
    // -9 <= exponent <= 9
    // note probably should change so that
    // only integer non integer checked here
    template <typename Exponent>
    struct dimensionless_multiply_exp_only : quan::meta::eval_if_c<
        (quan::meta::is_integer<Exponent>::value 
        && quan::meta::numerator<Exponent>::value >= quan::meta::digits10<int32_t>::value
        && quan::meta::numerator<Exponent>::value <= quan::meta::digits10<int32_t>::value),
        dimensionless_multiply_exp_only_ct<Exponent>,
        dimensionless_multiply_exp_only_rt<Exponent>
    >::type {};
    
}}//quan::detail

#endif
