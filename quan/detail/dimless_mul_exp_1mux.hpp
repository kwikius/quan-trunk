#ifndef QUAN_DETAIL_DIMLESS_MULTIPLY_EXP_1MUX_HPP_INCLUDED
#define QUAN_DETAIL_DIMLESS_MULTIPLY_EXP_1MUX_HPP_INCLUDED
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
    In these versions of the dimensionless multiply calculation , the Multipliers
    have been reduced from 2 Multipliers to one multiplier.
    We also know that the Exponent is non zero, as if it is zero the calculation 
    is the same as dimensioned_multiply.
    If The multiplier is one then it can be eliminated too.
    In that case we use the dimensionless multiply exponent only functors.
*/

#include <quan/detail/dimless_mul_exp_only.hpp>
#include <quan/meta/digits10.hpp>

namespace quan{namespace detail{
    
    template <typename Exponent, typename Multiplier>
    struct  dimensionless_multiply_rt_positive_integer_exp_1mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type;
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs) const
            {
                pow10_integer_exponent<constant_arg_type,quan::meta::numerator<Exponent>::value>
                pow10;
                 result_type result = (lhs * rhs)
                * (pow10()
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                    / (quan::meta::denominator<Multiplier>::value))));
                return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_rt_positive_integer_exp_1mux type;
    };
    template <typename Exponent, typename Multiplier>
    struct dimensionless_multiply_ct_positive_integer_exp_1mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type;
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs)const
            {
                result_type result = (lhs * rhs)
                *   (( static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,quan::meta::numerator<Exponent>::value
                    >::value))
                *   ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value))
                        / (quan::meta::denominator<Multiplier>::value)));
                return result;
            }
            typedef eval type;
         };
        typedef dimensionless_multiply_ct_positive_integer_exp_1mux type;
    };

    template <typename Exponent, typename Multiplier>
    struct dimensionless_multiply_rt_negative_integer_exp_1mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type;
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs) const
            {
                pow10_integer_exponent<constant_arg_type,-quan::meta::numerator<Exponent>::value>
                pow10;
                result_type result = (lhs * rhs)
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                        / (quan::meta::denominator<Multiplier>::value))
                        / pow10());
                return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_rt_negative_integer_exp_1mux type;
    };

    template <typename Exponent, typename Multiplier>
    struct dimensionless_multiply_ct_negative_integer_exp_1mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type;
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs)const
            {
                result_type result = (lhs * rhs)
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                    / (quan::meta::denominator<Multiplier>::value))
                    / (static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,-quan::meta::numerator<Exponent>::value>::value)) );
                return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_ct_negative_integer_exp_1mux type;
    };
            
    // We know that the Exponent is a a rational
    template <typename Exponent, typename Multiplier>
    struct dimensionless_multiply_rational_exp_1mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type 
            >::type  constant_arg_type;
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs)const
            {
 #ifndef QUAN_AVR_NO_CPP_STDLIB
           using std::pow;
#endif
                result_type result = (lhs * rhs)
                * (pow(static_cast<constant_arg_type>(10),
                    static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                    /quan::meta::denominator<Exponent>::value)
                * (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                        / (quan::meta::denominator<Multiplier>::value)));
                return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_rational_exp_1mux type;
        
    };

    // If the Multiplier is 1 then use the exponent only calculation.
    // else choose the calcualation to fit the Exponent
    template <typename Exponent, typename Multiplier>
    struct dimensionless_multiply_exp_1mux : quan::meta::eval_if_c<
        (((quan::meta::is_integer<Multiplier>::value) != 0 )
            && ((quan::meta::numerator<Multiplier>::value) == 1)),
        dimensionless_multiply_exp_only<Exponent>,
        quan::meta::eval_if<
            quan::meta::is_integer<Exponent>,
            quan::meta::eval_if_c<
                ((quan::meta::numerator<Exponent>::value) > 0),
                quan::meta::eval_if_c<
                    ((quan::meta::numerator<Exponent>::value) > (quan::meta::digits10<int32_t>::value)),
                    dimensionless_multiply_rt_positive_integer_exp_1mux<Exponent,Multiplier>,
                    dimensionless_multiply_ct_positive_integer_exp_1mux<Exponent,Multiplier>
                >,
                quan::meta::eval_if_c<
                    ((quan::meta::numerator<Exponent>::value) < (-quan::meta::digits10<int32_t>::value)),
                    dimensionless_multiply_rt_negative_integer_exp_1mux<Exponent,Multiplier>,
                    dimensionless_multiply_ct_negative_integer_exp_1mux<Exponent,Multiplier>
                >
            >,
            dimensionless_multiply_rational_exp_1mux<Exponent,Multiplier>
        >
    >::type {};

}}//quan::detail

#endif

