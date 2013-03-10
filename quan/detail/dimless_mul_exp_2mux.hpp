#ifndef QUAN_DETAIL_DIMLESS_MULTIPLY_EXP_2MUX_HPP_INCLUDED
#define QUAN_DETAIL_DIMLESS_MULTIPLY_EXP_2MUX_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/pow_c.hpp>
#include <quan/detail/pow10_exponent.hpp>

namespace quan{namespace detail{

    /*
            2 Multipliers
            Positive Exponent- runtime evaluated
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_multiply_rt_positive_integer_exp_2mux{
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
                * ( pow10()
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                    / quan::meta::denominator<Multiplier_L>::value)
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_R>::value)
                    / quan::meta::denominator<Multiplier_R>::value))));
                return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_rt_positive_integer_exp_2mux type;
    };

    /*
            2 Multipliers
            Negative Exponent- runtime evaluated
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_multiply_rt_negative_integer_exp_2mux{
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
                *   (((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                        / (quan::meta::denominator<Multiplier_L>::value)
                *   (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_R>::value)
                        / (quan::meta::denominator<Multiplier_R>::value))))
                    / pow10());
                return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_rt_negative_integer_exp_2mux type;
    };

    /*
            2 Multipliers
            Positive Exponent- compiletime evaluated
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_multiply_ct_positive_integer_exp_2mux{
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
                *   ( static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,quan::meta::numerator<Exponent>::value
                    >::value)
                *   ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                        / (quan::meta::denominator<Multiplier_L>::value)
                * (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_R>::value)
                        / (quan::meta::denominator<Multiplier_R>::value)))));
                return result;
            }
            typedef eval type;
         };
        typedef dimensionless_multiply_ct_positive_integer_exp_2mux type;
    };

    /*
            2 Multipliers
            Negative Exponent- compiletime evaluated
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_multiply_ct_negative_integer_exp_2mux{
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
                * (((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                    / (quan::meta::denominator<Multiplier_L>::value)
                * (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_R>::value)
                    / (quan::meta::denominator<Multiplier_R>::value))))
                /  static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,-quan::meta::numerator<Exponent>::value>::value));
                return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_ct_negative_integer_exp_2mux type;
    };
   
    /*
            2 Multipliers
            Rational Exponent- use std::pow
    */
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_multiply_rational_exp_2mux{
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
 #ifndef __AVR__
           using std::pow;
#endif
                    result_type result = (lhs * rhs)
                    * (pow(static_cast<constant_arg_type>(10),
                        static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                        /quan::meta::denominator<Exponent>::value)
                    * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_L>::value)
                         / (quan::meta::denominator<Multiplier_L>::value)
                    * (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier_R>::value)
                         / (quan::meta::denominator<Multiplier_R>::value)))));
                    return result;
            }
            typedef eval type;
        };
        typedef dimensionless_multiply_rational_exp_2mux type;
    };
    // if here we couldnt reduce the two Multipliers so
    // they must be be evaluated at runtime
    // we know the exponent is not zero too.
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct dimensionless_multiply_exp_2mux : quan::meta::eval_if<
        quan::meta::is_integer<Exponent>,
        quan::meta::eval_if_c<
            (quan::meta::numerator<Exponent>::value > 0),
            quan::meta::eval_if_c<
                ((quan::meta::numerator<Exponent>::value) > (quan::meta::digits10<int32_t>::value)),
                dimensionless_multiply_rt_positive_integer_exp_2mux<Exponent,Multiplier_L,Multiplier_R>,
                dimensionless_multiply_ct_positive_integer_exp_2mux<Exponent,Multiplier_L,Multiplier_R>
            >,
            quan::meta::eval_if_c<
                ((quan::meta::numerator<Exponent>::value) < (-quan::meta::digits10<int32_t>::value)),
                dimensionless_multiply_rt_negative_integer_exp_2mux<Exponent,Multiplier_L,Multiplier_R>,
                dimensionless_multiply_ct_negative_integer_exp_2mux<Exponent,Multiplier_L,Multiplier_R>
            >
        >,
        dimensionless_multiply_rational_exp_2mux<Exponent,Multiplier_L,Multiplier_R>
    >::type{};

}}//quan::detail

#endif
