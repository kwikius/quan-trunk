#ifndef QUAN_DETAIL_DIMENSIONED_MULTIPLY1_HPP_INCLUDED
#define QUAN_DETAIL_DIMENSIONED_MULTIPLY1_HPP_INCLUDED
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
dimensioned multiply. Only unit_multipliers are involved at low level (IOW not unit_exponents):

unitless_L = n_L * pow10<exponent_L>() * multiplier_L
unitless_R = n_R * pow10<exponent_R>() * multiplier_R

//unitless_result = unitless_L * unitless_R
unitless_result =  n_L * pow10<exponentL> * pow10<exponent_R> * multiplier_L * multiplier_R;

however the result_type is not unitless but uses pow10<exponent_L + exponent_R> so:

result_pow10<exponent_L + exponent_R> = n_L * n_R * (multiplier_L * multiplier_R);

Therefore only the multipliers are involved in the calc. The result value of the calc
will be used to initialise a quantity (which is always an SI quantity) of the correct exponent

*/
#include <quan/detail/compute_result_type.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/rational.hpp>
#include <quan/quantity_traits.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/eq.hpp>
#include <quan/undefined.hpp>
/*
    Low level calcs for dimensioned multiply of 2 quantities
*/

namespace quan{ namespace detail{

// selected by the  dimensioned_multiply_function below
// where the Multiplier is one
    struct unitary_multiplier_function{
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename quan::meta::binary_op<
                ValueType_L,quan::meta::times,ValueType_R  
            >::type result_type;
QUAN_CONSTEXPR
            result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs)const
            {
                return lhs * rhs;
            }
            typedef eval type;
        };
        typedef unitary_multiplier_function type;
    };
// selected by the  dimensioned_multiply_function below
// where the Multiplier is not equal to 1 but is an integer

    template <typename Multiplier>
    struct non_unitary_integer_multiplier_function{
        typedef int64_t preferred_multiplier_type;
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_multiplier_type 
            >::type  constant_arg_type;   
            typedef typename compute_multiply_result_type<
                ValueType_L,ValueType_R,preferred_multiplier_type  
            >::type result_type;
QUAN_CONSTEXPR
            result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs)const
            {
                return (lhs * rhs) 
                *  static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value);
            }  
            typedef eval type;
        };
        typedef non_unitary_integer_multiplier_function type;
    };

// selected by the  dimensioned_multiply_function below
// where the Multiplier is not equal to 1 and  is not an integer
// but The two rationals have been evaluated to one rational at compile time
    template <typename Multiplier>
    struct non_unitary_float_multiplier_function{
        typedef typename quan::quantity_traits::default_value_type
        preferred_multiplier_type;
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_multiplier_type 
            >::type  constant_arg_type; 
            typedef typename compute_multiply_result_type<
                ValueType_L,ValueType_R,preferred_multiplier_type  
            >::type result_type;
QUAN_CONSTEXPR         
            result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs)const
            {
                return(lhs * rhs )
                * (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
                        / static_cast<int64_t>(quan::meta::denominator<Multiplier>::value));
            } 
            typedef eval type; 
        };
        typedef non_unitary_float_multiplier_function type;
    };

/*
    The default multiplier_function has managed to do a compile time 
    calculation on the two input StaticUnitMultipliers
    and reduced them to one multiplier but it isnt equal to 1.
    If the multiplier is not an integer then the multipliers preferred multiplier result_type is 
    quan::quantity_traits::default_value_type, else int64_t, however the users types may override this.
*/
   template <typename Multiplier>
   struct dimensioned_multiply_function : quan::meta::eval_if<
      quan::meta::eq_one<Multiplier>,
         unitary_multiplier_function,
      quan::meta::is_integer<typename Multiplier::type>,
         non_unitary_integer_multiplier_function<typename Multiplier::type>,
      non_unitary_float_multiplier_function<typename Multiplier::type>
   >::type{};

/*
    The pair version hasnt been able to reduce the two StaticUnitMultipliers
    so the result must do more run time calculations
    and the result_type must be a real type
*/

    template <typename Multiplier_L,typename Multiplier_R>
    struct dimensioned_multiply_pair_function{
        typedef typename Multiplier_L::type lhs_multiplier;
        typedef typename Multiplier_R::type rhs_multiplier;
        // The preferred type must be a float of some sort
        typedef typename quan::quantity_traits::default_value_type preferred_multiplier_type;
        template <typename ValueType_L,typename ValueType_R>
        struct eval{
            typedef typename compute_multiply_constant_arg_type<
                ValueType_L,ValueType_R,preferred_multiplier_type 
            >::type  constant_arg_type; 
            typedef typename compute_multiply_result_type<
                ValueType_L,ValueType_R,preferred_multiplier_type  
            >::type result_type; 
QUAN_CONSTEXPR 
            result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs)const
            {
                return (lhs * rhs )
                *(( static_cast<constant_arg_type>(quan::meta::numerator<lhs_multiplier>::value)
                        / static_cast<int64_t>(quan::meta::denominator<lhs_multiplier>::value))
                    * (static_cast<constant_arg_type>(quan::meta::numerator<rhs_multiplier>::value)
                        / static_cast<int64_t>(quan::meta::denominator<rhs_multiplier>::value)));
            }  
            typedef eval type;
        };
        typedef dimensioned_multiply_pair_function type;
    };

/*
    range_checking a rational before compile time multiplication
*/
    template <typename Rational>
    struct elements_in_multipliable_range : quan::meta::bool_<(
        (-46340 <= quan::meta::numerator<typename Rational::type>::value)
        && (46340 >= quan::meta::numerator<typename Rational::type>::value)
        &&(-46340 <= quan::meta::denominator<typename Rational::type>::value)
        && (46340 >= quan::meta::denominator<typename Rational::type>::value)
    )>{};

/*
    If (The numerators and denominators of  Multiplier_L and Multiplier_R
     are all in range )
    then do the compile time multiply
    and use dimensioned_multiply_function on the result,
    else if (you can cancel the numerators/denominators) do so and
     use dimensioned_multiply_function on the result,
    else operate on the pair of multipliers at runtime.

*/
    template <
        typename Multiplier_L, 
        typename Multiplier_R
    >
    struct  dimensioned_multiply1 : quan::meta::eval_if<
        quan::meta::and_<
            elements_in_multipliable_range<typename Multiplier_L::type>,
            elements_in_multipliable_range<typename Multiplier_R::type>
        >,
            dimensioned_multiply_function<
               typename quan::meta::eval_if<
                   quan::meta::and_<
                       elements_in_multipliable_range<typename Multiplier_L::type>,
                       elements_in_multipliable_range<typename Multiplier_R::type>
                   >,
                      quan::meta::binary_op<
                         typename Multiplier_L::type,quan::meta::times,typename Multiplier_R::type
                      >,
                   quan::undefined
                >::type
             >,
         quan::meta::eq_<
            quan::meta::numerator<Multiplier_L>,
            quan::meta::denominator<Multiplier_R>
         >,
            dimensioned_multiply_function< 
                typename quan::meta::rational<
                    quan::meta::numerator<Multiplier_R>::value,
                    quan::meta::denominator<Multiplier_L>::value
                >::type
            >,
         quan::meta::eq_<
            quan::meta::numerator<Multiplier_R>,
            quan::meta::denominator<Multiplier_L>
         >,
            dimensioned_multiply_function< 
               typename quan::meta::rational<
                  quan::meta::numerator<Multiplier_L>::value,
                  quan::meta::denominator<Multiplier_R>::value
               >::type
            >,
         dimensioned_multiply_pair_function<
            typename Multiplier_L::type, 
            typename Multiplier_R::type 
         >
    >::type {}; 

}}//quan::detail

#endif
