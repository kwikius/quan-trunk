#ifndef QUAN_DETAIL_COMPUTE_RESULT_TYPE_HPP_INCLUDED
#define QUAN_DETAIL_COMPUTE_RESULT_TYPE_HPP_INCLUDED

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
    In a multiply/divide on fixed_quantities there are 3 ValueTypes involved.
    The 2 user ValueTypes of the quantities , and the minimum
    ValueType of the Multiplier calculation for preserving precision.
    
    Where the Multiplier ValueType and User resultType of a multiply/divide on 
    the user input types are both floats or integers
    then the user type is preferred even if "smaller".
    Otherwise the result_type of a theoretical multiply of all three is used
    quan::quantity_traits::default_float_type (usually a double) will be used
    for the multipliers float and int64_t for an int
    
    The idea is that the user doesnt want a conversion to double,
    if the input types are floats or an unnecessary conversion to long, 
    if the input types are ints and an integer multiplier will preserve precision.
    
    The compute_multiply_result_type and compute_divide_result_type
    metafunction computes this type.

*/
#include <quan/meta/eval_if.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_same.hpp>
#include <quan/std/tr1/is_integral.hpp>
#include <quan/std/tr1/is_float.hpp>
#endif
#include <quan/meta/binary_op.hpp>
#include <quan/meta/identity.hpp>

namespace quan{ namespace detail{

    // to preserve precision in a UDT or inbuilt
    // the constant multiplier often needs promoting
    // in division of the constant
    // do binary op multiply by * 'some float',
    // but not promoting actual floats, dependent on args
    // this should *hopefully* promote the constant value_type
    // without getting a double promotuion
    // for float types
    template <
        typename ArgType_L, typename ArgType_R, typename DefaultFloat
    >
    struct compute_multiply_constant_arg_type{
        typedef typename quan::meta::binary_op<
            ArgType_L,
            quan::meta::times,
            ArgType_R
        >::type promoted_arg_type;
        typedef  typename quan::meta::if_<
            std::is_same<promoted_arg_type,float>,
            float,
            typename quan::meta::binary_op<
                int64_t,
                quan::meta::times,
                DefaultFloat
            >::type
        >::type type;
    };

    template <
        typename UserValueType_L,
        typename UserValueType_R, 
        typename DefaultFloat
    >
    struct compute_multiply_result_type{
        typedef typename quan::meta::binary_op<
            UserValueType_L,
            quan::meta::times,
            UserValueType_R
        >::type preferred_user_result_type;
        
        typedef typename quan::meta::binary_op<
            preferred_user_result_type,
            quan::meta::times,
            typename compute_multiply_constant_arg_type<
                UserValueType_L,UserValueType_R, DefaultFloat
            >::type
        >::type type;
    };

    // to preserve precision in a UDT or inbuilt
    // the constant multiplier often needs promoting
    // in division of the constant
    // do binary op multiply by * 'some float',
    // but not promoting actual floats, dependent on args

    template <typename T>
    struct min_float_or_udt{
        typedef typename quan::meta::eval_if<
            std::is_integral<T>,
            quan::meta::arithmetic_promote<
                quan::quantity_traits::default_value_type,T
            >,  
            quan::meta::identity<T>
        >::type type;
    };

    template <
        typename ArgType_L, typename ArgType_R, typename Default
    >
    struct compute_divide_constant_arg_type{
        typedef typename quan::meta::binary_op<
            typename min_float_or_udt<ArgType_L>::type,
            quan::meta::divides,
            typename min_float_or_udt<ArgType_R>::type
        >::type promoted_arg_type;

        typedef typename quan::meta::if_<
            std::is_floating_point<promoted_arg_type>,
            promoted_arg_type,
            Default
        >::type type;
    };
    
    template <
        typename UserValueType_L,
        typename UserValueType_R, 
        typename DefaultFloat
    >
    struct compute_divide_result_type{
        typedef typename quan::meta::binary_op<
            typename min_float_or_udt<UserValueType_L>::type,
            quan::meta::divides,
            typename min_float_or_udt<UserValueType_R>::type
        >::type preferred_user_result_type;
        typedef typename quan::meta::binary_op<
            preferred_user_result_type,
            quan::meta::times,
            typename compute_divide_constant_arg_type<
                UserValueType_L,UserValueType_R, DefaultFloat
            >::type
        >::type type;
    };

}}//quan::detail

#endif
