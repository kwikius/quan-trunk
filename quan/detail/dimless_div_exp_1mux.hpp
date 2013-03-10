#ifndef QUAN_DETAIL_DIMLESS_DIVIDE_EXP_1MUX_HPP_INCLUDED
#define QUAN_DETAIL_DIMLESS_DIVIDE_EXP_1MUX_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/**
* @file dimless_div_exp_1mux.hpp
*    In these versions of the dimensionless divide calculation , the Multipliers
*   have been reduced from 2 Multipliers to one multiplier.
*    We also know that the Exponent is non zero, as if it is zero the calculation 
*    is the same as dimensioned_divide.
*    If The multiplier is one then it can be eliminated too.
*    In that case we use the dimensionless divide exponent only functors.
*/

#include <quan/detail/dimless_mul_exp_only.hpp>
#include <quan/detail/united_value/operations/dimensioned_divide.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/digits10.hpp>

namespace quan{namespace detail{
    
    template <typename Exponent, typename Multiplier>
    struct  dimensionless_divide_rt_positive_integer_exp_1mux{
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
                * (pow10()
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                    /(quan::meta::denominator<Multiplier>::value))));
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
                * (pow10()
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                    / (quan::meta::denominator<Multiplier>::value))));
                return result;
            }
            typedef convert type;
        };


        typedef dimensionless_divide_rt_positive_integer_exp_1mux type;
    };
    template <typename Exponent, typename Multiplier>
    struct dimensionless_divide_ct_positive_integer_exp_1mux{
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
                *   (( static_cast<constant_arg_type>(quan::meta::pow_c<
                        int64_t,10,quan::meta::numerator<Exponent>::value
                    >::value))
                *   ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value))
                        / (quan::meta::denominator<Multiplier>::value)));
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
                *   (( static_cast<constant_arg_type>(quan::meta::pow_c<
                        int64_t,10,quan::meta::numerator<Exponent>::value
                    >::value))
                *   ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value))
                        / (quan::meta::denominator<Multiplier>::value)));
                return result;
            }
            typedef convert type;
         };


        typedef dimensionless_divide_ct_positive_integer_exp_1mux type;
    };

    template <typename Exponent, typename Multiplier>
    struct dimensionless_divide_rt_negative_integer_exp_1mux{
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
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                        / (quan::meta::denominator<Multiplier>::value))
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
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                        / (quan::meta::denominator<Multiplier>::value))
                        / pow10());
                return result;
            }
            typedef convert type;
        };

        typedef dimensionless_divide_rt_negative_integer_exp_1mux type;
    };

    template <typename Exponent, typename Multiplier>
    struct dimensionless_divide_ct_negative_integer_exp_1mux{
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
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                        / quan::meta::denominator<Multiplier>::value)
                            / static_cast<constant_arg_type>(quan::meta::pow_c<
                                int64_t,10,-quan::meta::numerator<Exponent>::value
                                >::value ));
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
                * ((static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                    / (quan::meta::denominator<Multiplier>::value))
                    / (static_cast<constant_arg_type>(quan::meta::pow_c<
                        int64_t,10,-quan::meta::numerator<Exponent>::value>::value)) );
                return result;
            }
            typedef convert type;
        };

        typedef dimensionless_divide_ct_negative_integer_exp_1mux type;
    };
            
    // We know that the Exponent is a a rational
    template <typename Exponent, typename Multiplier>
    struct dimensionless_divide_rational_exp_1mux{
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

 #ifndef __AVR__
           using std::pow;
#endif

                result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
                * (pow(static_cast<constant_arg_type>(10),
                    static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                    /quan::meta::denominator<Exponent>::value)
                * (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                        / (quan::meta::denominator<Multiplier>::value)));
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
 #ifndef __AVR__
           using std::pow;
#endif
                result_type result = v 
                * (pow(static_cast<constant_arg_type>(10),
                    static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                    /quan::meta::denominator<Exponent>::value)
                * (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                        / (quan::meta::denominator<Multiplier>::value)));
                return result;
            }
            typedef convert type;
        };

        typedef dimensionless_divide_rational_exp_1mux type;
        
    };

    // If the Multiplier is 1 then use the exponent only calculation.
    // else choose the calcualation to fit the Exponent
    template <typename Exponent, typename Multiplier>
    struct dimensionless_divide_exp_1mux : quan::meta::eval_if<
        quan::meta::eq_one<Multiplier>,
        dimensionless_divide_exp_only<Exponent>,
        quan::meta::eval_if<
            quan::meta::is_integer<Exponent>,
            quan::meta::eval_if<
                quan::meta::gt_zero<quan::meta::numerator<Exponent> >,
                quan::meta::eval_if_c<
                    ((quan::meta::numerator<Exponent>::value) > (quan::meta::digits10<int64_t>::value)),
                    dimensionless_divide_rt_positive_integer_exp_1mux<Exponent,Multiplier>,
                    dimensionless_divide_ct_positive_integer_exp_1mux<Exponent,Multiplier>
                >,
                quan::meta::eval_if_c<
                    ((quan::meta::numerator<Exponent>::value) < (-quan::meta::digits10<int64_t>::value)),
                    dimensionless_divide_rt_negative_integer_exp_1mux<Exponent,Multiplier>,
                    dimensionless_divide_ct_negative_integer_exp_1mux<Exponent,Multiplier>
                >
            >,
            dimensionless_divide_rational_exp_1mux<Exponent,Multiplier>
        >
    >::type {};

}}//quan::detail

#endif

