#ifndef QUAN_DETAIL_DIMLESS_DIVIDE_EXP_ONLY_HPP_INCLUDED
#define QUAN_DETAIL_DIMLESS_DIVIDE_EXP_ONLY_HPP_INCLUDED
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

/** @file dimless_div_only.hpp
    @brief low level dimensionless division.
 *  In these versions of the dimensionless divide calculation,
 *  only the Exponent is used. The Multipliers have been eliminated,
 *  as they evaluate to 1. We also know that the Exponent is non zero.
 *  ( If the Exponent is 0 then the calculation is the same as for a dimensioned divide)
*/

#include <quan/detail/united_value/operations/dimensioned_divide.hpp>
#include <quan/meta/pow_c.hpp>
#include <quan/detail/pow10_exponent.hpp>
#include <quan/meta/digits10.hpp>

namespace quan{ namespace detail{

    /**
    * Exponent is a rational. Uses std::pow.
    */
    template <typename Exponent>
    struct dimensionless_divide_exp_only_rational_rt{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;
            constexpr result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
#ifndef QUAN_AVR_NO_CPP_STDLIB
                  using std::pow;
#endif
                return (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
                *   pow(
                        static_cast<constant_arg_type>(10),
                        static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                            /quan::meta::denominator<Exponent>::value
                    );
               
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
            constexpr result_type operator()(ValueType const & v) const
            {

#ifndef QUAN_AVR_NO_CPP_STDLIB
                  using std::pow;
#endif

                return v * pow(
                        static_cast<constant_arg_type>(10),
                        static_cast<constant_arg_type>(quan::meta::numerator<Exponent>::value)
                            /quan::meta::denominator<Exponent>::value
                    );
            }
            typedef convert type;
        };
        typedef dimensionless_divide_exp_only_rational_rt type;
    };

    /**
    * Exponent is a negative integer <= -10.
    * use pow10_integer_exponent functor.
    */
    template <typename Exponent>
    struct dimensionless_divide_exp_only_negative_integer_rt{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;

        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;
           constexpr result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
//                pow10_integer_exponent<
//                    constant_arg_type,-(quan::meta::numerator<Exponent>::value)
//                > pow10;
                   
//                result_type result 
//                = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs)) / pow10();
//                return result;
                 typedef  pow10_integer_exponent<
                   constant_arg_type,-(quan::meta::numerator<Exponent>::value)
                > pow10;
                 return (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs)) / pow10{}();
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
                quan::meta::divides,
                constant_arg_type
            >::type result_type;
           constexpr result_type operator()(ValueType const & v)const
            {
                typedef pow10_integer_exponent<
                    constant_arg_type,-(quan::meta::numerator<Exponent>::value)
                > pow10;
                //result_type result = v / pow10();
                return v / pow10{}();
            }
            typedef convert type;
        };
        typedef dimensionless_divide_exp_only_negative_integer_rt type;
    };

    /**
    * Exponent is a positive integer >= 10.
    * use pow10_integer_exponent functor
    */
    template <typename Exponent>
    struct dimensionless_divide_exp_only_positive_integer_rt{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
       
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                    ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;
            constexpr result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
                typedef pow10_integer_exponent<constant_arg_type,quan::meta::numerator<Exponent>::value> pow10;
//                result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
//                * pow10();
              //  return result;
                return  (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs))
                * pow10{}();
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
            constexpr result_type operator()(ValueType const & v) const
            {
                typedef pow10_integer_exponent<constant_arg_type,quan::meta::numerator<Exponent>::value> pow10;
                //result_type result = v * pow10();
                return v * pow10{}();
            }
            typedef convert type;
        };
        typedef dimensionless_divide_exp_only_positive_integer_rt type;
    };

    /** 
    * Run time evaluate Exponent. 
    * Decide whether Exponent is a Rational or Integer
    * and if integer + or -.
    */
    template <typename Exponent>
    struct dimensionless_divide_exp_only_rt : quan::meta::eval_if<
        quan::meta::is_integer<Exponent>,
        quan::meta::eval_if_c<
            (quan::meta::numerator<Exponent>::value > 0),  
            dimensionless_divide_exp_only_positive_integer_rt<Exponent>,
            dimensionless_divide_exp_only_negative_integer_rt<Exponent>
        >,
        dimensionless_divide_exp_only_rational_rt<Exponent>
    >::type{};

    /**
    * Exponent is a positive integer <= 9 so can be compile time evaluated.
    * Use compile time pow_c
    */
    template <typename Exponent>
    struct dimensionless_divide_exp_only_positive_ct{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;
            constexpr result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
//                result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>( rhs)) *
//                    static_cast<constant_arg_type>(quan::meta::pow_c<
//                        int32_t,10,quan::meta::numerator<Exponent>::value
//                    >::value);
//                return result;
                return (static_cast<value_type_L>(lhs) / static_cast<value_type_R>( rhs)) *
                    static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10,quan::meta::numerator<Exponent>::value
                    >::value);
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
        
           /* typedef typename compute_divide_result_type<
                ValueType,ValueType,preferred_result_type
            >::type result_type;*/
            constexpr result_type operator()(ValueType const & v) const
            {
//                result_type result = v *
//                   static_cast<constant_arg_type>( quan::meta::pow_c<
//                        int32_t,10,quan::meta::numerator<Exponent>::value
//                    >::value);
//                return result;
                 return v *
                   static_cast<constant_arg_type>( quan::meta::pow_c<
                        int32_t,10,quan::meta::numerator<Exponent>::value
                    >::value);
            }
            typedef convert type;
        };

        typedef dimensionless_divide_exp_only_positive_ct type;
    };

    /**
    * The Exponent is a negative integer >= -9.
    * If negated, it can be compile time evaluated
    * Use compile time pow_c function on the negated exponent
    * and divide by it rather than divide
    * Result type must be a float.
    */
    template <typename Exponent>
    struct dimensionless_divide_exp_only_negative_ct{
        typedef typename quan::quantity_traits::default_value_type preferred_result_type;
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
            typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
            typedef typename compute_divide_result_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type result_type;
            typedef typename compute_divide_constant_arg_type<
                ValueType_L,ValueType_R,preferred_result_type
            >::type constant_arg_type;
            constexpr result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs) const
            {
//                result_type result = (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs)) /
//                static_cast<constant_arg_type>(
//                    quan::meta::pow_c<
//                        int32_t,10, -quan::meta::numerator<Exponent>::value
//                    >::value);
//                return result;
                  return  (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs)) /
                static_cast<constant_arg_type>(
                    quan::meta::pow_c<
                        int32_t,10, -quan::meta::numerator<Exponent>::value
                    >::value);
              //  return result;
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
            constexpr result_type operator()(ValueType const & v) const
            {
//                result_type result = v / 
//                    static_cast<constant_arg_type>(quan::meta::pow_c<
//                        int32_t,10, -quan::meta::numerator<Exponent>::value
//                    >::value);
//                return result;
                return v / 
                    static_cast<constant_arg_type>(quan::meta::pow_c<
                        int32_t,10, -quan::meta::numerator<Exponent>::value
                    >::value);
  
            }
            typedef convert type;
        };
        typedef dimensionless_divide_exp_only_negative_ct type;
    };

    /**
    * Integer exponent, not zero, small enough to compile time evaluate
    * is it positive or negative?
    */
    template <typename Exponent>
    struct  dimensionless_divide_exp_only_ct : quan::meta::eval_if_c<
            (quan::meta::numerator<Exponent>::value > 0),
            dimensionless_divide_exp_only_positive_ct<Exponent>,
            dimensionless_divide_exp_only_negative_ct<Exponent>
    >::type {};

    /**
    * The actual calculation used  is dependent on whether
    * -9 <= exponent <= 9
    * note probably should change the logic so that
    * only integer/non integer checked here.
    */
    template <typename Exponent>
    struct dimensionless_divide_exp_only : quan::meta::eval_if_c<
        (quan::meta::is_integer<Exponent>::value 
      //  && quan::meta::numerator<Exponent>::value >= -std::numeric_limits<int32_t>::digits10
       // && quan::meta::numerator<Exponent>::value <= std::numeric_limits<int32_t>::digits10),
           && quan::meta::numerator<Exponent>::value >= - quan::meta::digits10<int32_t>::value
        && quan::meta::numerator<Exponent>::value <= quan::meta::digits10<int32_t>::value),
        dimensionless_divide_exp_only_ct<Exponent>,
        dimensionless_divide_exp_only_rt<Exponent>
    >::type {};
    
}}//quan::detail

#endif
