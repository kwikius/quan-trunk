#ifndef QUAN_DETAIL_DIMLESS_DIVIDE_EXP_2MUX_HPP_INCLUDED
#define QUAN_DETAIL_DIMLESS_DIVIDE_EXP_2MUX_HPP_INCLUDED
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

#include <quan/meta/pow_c.hpp>
#include <quan/detail/pow10_exponent.hpp>
#include <quan/detail/united_value/operations/dimensioned_divide.hpp>
#include <quan/meta/digits10.hpp>

namespace quan{namespace detail{

    /*
            2 Multipliers
            Positive Exponent- runtime evaluated
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_divide_rt_positive_integer_exp_2mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs) const
            {
                pow10_integer_exponent<constant_arg_type,quan::meta::numerator<Exponent>::value>
                pow10;
                 result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
                * ( pow10()
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                    /(quan::meta::denominator<Multiplier_L>::value)
                * (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                    / (quan::meta::numerator<Multiplier_R>::value)))));
                return result;
            }
            typedef eval type;
        };

        template <typename ValueType>
        struct convert{
            typedef typename compute_divide_constant_arg_type<
                ValueType,ValueType,preferred_result_type
            >::type constant_arg_type;
            typedef typename quan::meta::binary_op<
                ValueType,
                quan::meta::times,
                constant_arg_type
            >::type result_type;
            result_type operator()(ValueType const & v) const
            {
                pow10_integer_exponent<constant_arg_type,quan::meta::numerator<Exponent>::value>
                pow10;
                 result_type result = v
                * ( pow10()
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                    / (quan::meta::denominator<Multiplier_L>::value)
                * (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                    / (quan::meta::numerator<Multiplier_R>::value)))));
                return result;
            }
            typedef convert type;
        };
    
        typedef dimensionless_divide_rt_positive_integer_exp_2mux type;
    };

    /*
            2 Multipliers
            Negative Exponent- runtime evaluated
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_divide_rt_negative_integer_exp_2mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{

            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;

            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs) const
            {
                pow10_integer_exponent<constant_arg_type,-quan::meta::numerator<Exponent>::value>
                pow10;
                result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
                *   (((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                        / (quan::meta::denominator<Multiplier_L>::value)
                *   (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                        / (quan::meta::numerator<Multiplier_R>::value))))
                    / pow10());
                return result;
            }
            typedef eval type;
        };

        template <typename ValueType>
        struct convert{
            typedef typename compute_divide_constant_arg_type<
                ValueType,ValueType,preferred_result_type
            >::type constant_arg_type;
            typedef typename quan::meta::binary_op<
                ValueType,
                quan::meta::times,
                constant_arg_type
            >::type result_type;

            result_type operator()(ValueType const & v) const
            {
                pow10_integer_exponent<constant_arg_type,-quan::meta::numerator<Exponent>::value>
                pow10;
                result_type result = v
                *   (((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                        /(quan::meta::denominator<Multiplier_L>::value)
                *   (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                        /(quan::meta::numerator<Multiplier_R>::value))))
                    / pow10());
                return result;
            }
            typedef convert type;
        };
        typedef dimensionless_divide_rt_negative_integer_exp_2mux type;
    };

    /*
            2 Multipliers
            Positive Exponent- compiletime evaluated
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_divide_ct_positive_integer_exp_2mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;

           
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs)const
            {
                result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
                *   ( static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,quan::meta::numerator<Exponent>::value
                    >::value)
                *   ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                        / (quan::meta::denominator<Multiplier_L>::value)
                * (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                        / (quan::meta::numerator<Multiplier_R>::value)))));
                return result;
            }
            typedef eval type;
         };

        template <typename ValueType>
        struct convert{

            typedef typename compute_divide_constant_arg_type<
                ValueType,ValueType,preferred_result_type
            >::type constant_arg_type;
            typedef typename quan::meta::binary_op<
                ValueType,
                quan::meta::times,
                constant_arg_type
            >::type result_type;

            result_type operator()(ValueType const & v)const
            {
                result_type result = v
                *   ( static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,quan::meta::numerator<Exponent>::value
                    >::value)
                *   ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                        / (quan::meta::denominator<Multiplier_L>::value)
                * (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                        /(quan::meta::numerator<Multiplier_R>::value)))));
                return result;
            }
            typedef convert type;
         };

        typedef dimensionless_divide_ct_positive_integer_exp_2mux type;
    };

    /*
            2 Multipliers
            Negative Exponent- compiletime evaluated
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_divide_ct_negative_integer_exp_2mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs)const
            {
                result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
                * (((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                    /(quan::meta::denominator<Multiplier_L>::value)
                * (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                    / (quan::meta::numerator<Multiplier_R>::value))))
                /  static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,-quan::meta::numerator<Exponent>::value>::value));
                return result;
            }
            typedef eval type;
        };

        template <typename ValueType>
        struct convert{
            typedef typename compute_divide_constant_arg_type<
                ValueType,ValueType,preferred_result_type
            >::type constant_arg_type;
            typedef typename quan::meta::binary_op<
                ValueType,
                quan::meta::times,
                constant_arg_type
            >::type result_type;
            result_type operator()(ValueType const & v)const
            {
                result_type result = v
                * (((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                    / (quan::meta::denominator<Multiplier_L>::value)
                * (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                    / (quan::meta::numerator<Multiplier_R>::value))))
                /  static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,-quan::meta::numerator<Exponent>::value>::value));
                return result;
            }
            typedef convert type;
        };

        typedef dimensionless_divide_ct_negative_integer_exp_2mux type;
    };
   
    /*
            2 Multipliers
            Rational Exponent- use std::pow
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_divide_rational_exp_2mux{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L, typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;
            result_type operator()(ValueType_L const & lhs, ValueType_R const & rhs)const
            {
 #ifndef QUAN_AVR_NO_CPP_STDLIB
           using std::pow;
#endif
                    result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
                    * (pow(static_cast<constant_arg_type>(10),
                        static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                        /quan::meta::denominator<Exponent>::value)
                    * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                         / (quan::meta::denominator<Multiplier_L>::value)
                    * (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                         / (quan::meta::numerator<Multiplier_R>::value)))));
                    return result;
            }
            typedef eval type;
        };

        template <typename ValueType>
        struct convert{
            typedef typename compute_divide_constant_arg_type<
                ValueType,ValueType,preferred_result_type
            >::type constant_arg_type;
            typedef typename quan::meta::binary_op<
                ValueType,
                quan::meta::times,
                constant_arg_type
            >::type result_type;
            result_type operator()(ValueType const & v)const
            {
 #ifndef QUAN_AVR_NO_CPP_STDLIB
           using std::pow;
#endif
                    result_type result = v
                    * (pow(static_cast<constant_arg_type>(10),
                        static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                        /quan::meta::denominator<Exponent>::value)
                    * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                         / (quan::meta::denominator<Multiplier_L>::value)
                    * (static_cast<constant_arg_type>(quan::meta::denominator<Multiplier_R>::value)
                         / (quan::meta::numerator<Multiplier_R>::value)))));
                    return result;
            }
            typedef convert type;
        };

        typedef dimensionless_divide_rational_exp_2mux type;
    };
    // if here we couldnt reduce the two Multipliers so
    // they must be be evaluated at runtime
    // we know the exponent is not zero too.
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_divide_exp_2mux : quan::meta::eval_if<
        quan::meta::is_integer<Exponent>,
        // add Exp ==0
        quan::meta::eval_if_c<
            (quan::meta::numerator<Exponent>::value > 0),
            quan::meta::eval_if_c<
                ((quan::meta::numerator<Exponent>::value) > (quan::meta::digits10<int32_t>::value)),
                dimensionless_divide_rt_positive_integer_exp_2mux<Exponent,Multiplier_L,Multiplier_R>,
                dimensionless_divide_ct_positive_integer_exp_2mux<Exponent,Multiplier_L,Multiplier_R>
            >,
            quan::meta::eval_if_c<
                ((quan::meta::numerator<Exponent>::value) < (-quan::meta::digits10<int32_t>::value)),
                dimensionless_divide_rt_negative_integer_exp_2mux<Exponent,Multiplier_L,Multiplier_R>,
                dimensionless_divide_ct_negative_integer_exp_2mux<Exponent,Multiplier_L,Multiplier_R>
            >
        >,
        dimensionless_divide_rational_exp_2mux<Exponent,Multiplier_L,Multiplier_R>
    >::type{};

}}//quan::detail

#endif
