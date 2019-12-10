#ifndef QUAN_DETAIL_DIMENSIONED_DIVIDE1_HPP_INCLUDED
#define QUAN_DETAIL_DIMENSIONED_DIVIDE1_HPP_INCLUDED
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
dimensioned divide. Only unit_multipliers are involved at low level:

unitless_L = n_L * pow10<exponent_L>() * multiplier_L
unitless_R = n_R * pow10<exponent_R>() * multiplier_R

//unitless_result = unitless_L / unitless_R
unitless_result =  (n_L * pow10<exponentL>* multiplier_L) 
    / (n_R * pow10<exponent_R>  * multiplier_R);

however the result_type is not unitless but uses pow10<exponent_L - exponent_R> so:

result_pow10<exponent_L - exponent_R> = (n_L * multiplier_L) / (n_R * multiplier_R);
result_pow10<exponent_L - exponent_R> = (n_L/n_R) * (multiplier_L / multiplier_R);

Therefore only the multipliers are involved in the calculation. 
The result value of the calculation will be used to initialise a quantity 
(which is always an SI quantity) of the correct exponent.
however at that point it may have another conversion.
*/

#include <quan/detail/compute_result_type.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/rational.hpp>
#include <quan/quantity_traits.hpp>

#include <quan/meta/bool.hpp>
#include <quan/meta/eq.hpp>
#include <quan/undefined.hpp>

namespace quan{namespace detail{

// selected by the dimensioned_divide_function below
// where the Multiplier is one
struct unitary_divide_function{
    typedef quan::quantity_traits::default_value_type
    preferred_result_type;
    template <typename ValueType_L,typename ValueType_R>
    struct eval{
        typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
        typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
        typedef typename quan::meta::binary_op<
            value_type_L,
            quan::meta::divides,
            value_type_R
        >::type result_type;
       QUAN_CONSTEXPR
        result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs)const
        {
            return static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs) ;
        }
        typedef eval type;
    };

    template <typename ValueType>
    struct convert{
        typedef ValueType result_type;
QUAN_CONSTEXPR
        typename std::remove_const<
            result_type
        >::type  operator()(ValueType const & v)const
        {
            return v;
        }
        typedef convert type;
    };
    typedef unitary_divide_function type;
};
// selected by the  dimensioned_divide_function below
// where the Multiplier is not equal to 1 but is an integer

template <typename Multiplier>
struct non_unitary_integer_divide_function{
    typedef typename quan::quantity_traits::default_value_type
    preferred_result_type;
    template <typename ValueType_L,typename ValueType_R>
    struct eval{
       
        typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
        typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
        typedef typename compute_divide_constant_arg_type<
            ValueType_L,ValueType_R,preferred_result_type
        >::type constant_arg_type;
        typedef typename compute_divide_result_type<
            ValueType_L, ValueType_R,preferred_result_type
        >::type result_type;
        result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs)const
        {
            return (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs) )
             * static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value);
        }  
        typedef eval type;
    };

    template <typename ValueType>
    struct convert{
       /* typedef typename compute_divide_result_type<
           ValueType,ValueType,preferred_result_type  
        >::type result_type;*/
        typedef typename quan::meta::binary_op<
            ValueType,
            quan::meta::times,
            int64_t
        >::type result_type;

QUAN_CONSTEXPR
        result_type operator()(ValueType const & v)const
        {
            return v * static_cast<int64_t>(quan::meta::numerator<Multiplier>::value);
        }  
        typedef convert type;
    };
    typedef non_unitary_integer_divide_function type;
};

// selected by the  dimensioned_divide_function below
// where the Multiplier is not equal to 1 and  is not an integer
template <typename Multiplier>
struct non_unitary_float_divide_function{
    typedef typename quan::quantity_traits::default_value_type
    preferred_result_type;

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
QUAN_CONSTEXPR
        result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs)const
        {
            return (static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs) )
                *  
                (static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
              /  (quan::meta::denominator<Multiplier>::value));
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
QUAN_CONSTEXPR
        result_type operator()(ValueType const & v)const
        {
            return v * ( static_cast<constant_arg_type>(quan::meta::numerator<Multiplier>::value)
              /  (quan::meta::denominator<Multiplier>::value));
        }  
        typedef convert type;
    };

    typedef non_unitary_float_divide_function type;
};

/*
    The default divide_function has managed to do a compile time 
    calculation on the two input StaticUnitMultipliers
    and reduced them to one multiplier but it isnt equal to 1.
    If the multiplier is not an integer then the multipliers preferred multiplier result_type is 
    quan::quantity_traits::default_value_type, else int64_t
*/
   template <typename Multiplier>
   struct dimensioned_divide_function : quan::meta::eval_if<
      quan::meta::eq_one<Multiplier>,
         unitary_divide_function,
      quan::meta::is_integer<Multiplier>,
         non_unitary_integer_divide_function<Multiplier>,
      non_unitary_float_divide_function<Multiplier>
   >::type{};

/*
    The pair version hasnt been able to reduce the two StaticUnitMultipliers
    so the result must do more run time calculations
    and the result_type must be a real type
*/

template <typename Multiplier_L,typename Multiplier_R>
struct dimensioned_divide_pair_function
{
    typedef Multiplier_L lhs_multiplier;
    typedef Multiplier_R rhs_multiplier;

    // The preferred type must be a float
    typedef typename quan::quantity_traits::default_value_type preferred_result_type;
    template <typename ValueType_L,typename ValueType_R>
    struct eval{
        /*typedef typename compute_divide_result_type<
           ValueType_L,ValueType_R,preferred_result_type  
        >::type result_type;*/
        typedef typename min_float_or_udt<ValueType_L>::type value_type_L;
        typedef typename min_float_or_udt<ValueType_R>::type value_type_R;
        typedef typename compute_divide_constant_arg_type<
            ValueType_L,ValueType_R,preferred_result_type
        >::type constant_arg_type;
        typedef typename compute_divide_result_type<
            ValueType_L,ValueType_R,preferred_result_type
        >::type result_type;
QUAN_CONSTEXPR
        result_type operator()(ValueType_L const & lhs,ValueType_R const & rhs)const
        {
            return( static_cast<value_type_L>(lhs) / static_cast<value_type_R>(rhs) )
             *(( static_cast<constant_arg_type>(quan::meta::numerator<lhs_multiplier>::value)
                    * quan::meta::denominator<rhs_multiplier>::value)
                / ((static_cast<constant_arg_type>(quan::meta::denominator<lhs_multiplier>::value))
                    * (quan::meta::numerator<rhs_multiplier>::value)));
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
    QUAN_CONSTEXPR    
        result_type operator()(ValueType const & v)const
        {
            return v 
             *((static_cast<constant_arg_type>( quan::meta::numerator<lhs_multiplier>::value)
                    * (quan::meta::denominator<rhs_multiplier>::value))
                / (static_cast<constant_arg_type>(quan::meta::denominator<lhs_multiplier>::value)
                    * (quan::meta::numerator<rhs_multiplier>::value)));
        }  
        typedef convert type;
    };

    typedef dimensioned_divide_pair_function type;
};

/*
    range_checking rational
*/
template <typename Rational>
struct elements_in_dividable_range : quan::meta::bool_<
    (
        (-46340 <= quan::meta::numerator<Rational>::value)
        && (46340 >= quan::meta::numerator<Rational>::value)
        &&(-46340 <= quan::meta::denominator<Rational>::value)
        && (46340 >= quan::meta::denominator<Rational>::value)
    )
>{};

/*
    If (The numerators and denominators of  Multiplier_L and Multiplier_R
     are all in range )
    then do the compile time divide
    and use dimensioned_divide_function on the result,
    else if (you can cancel the numerators) do so and
     use dimensioned_divide_function on the result,
    else operate on the pair of multipliers at runtime.

*/

template <
    typename Multiplier_L, 
    typename Multiplier_R
>
struct  dimensioned_divide : quan::meta::eval_if<
        quan::meta::and_<
            elements_in_dividable_range<typename Multiplier_L::type>,
            elements_in_dividable_range<typename Multiplier_R::type>
        >,
           dimensioned_divide_function<
               typename quan::meta::eval_if<
                   quan::meta::and_<
                     elements_in_dividable_range<typename Multiplier_L::type>,
                     elements_in_dividable_range<typename Multiplier_R::type>
                   >,
                   quan::meta::binary_op<
                       typename Multiplier_L::type,
                       quan::meta::divides,
                       typename Multiplier_R::type
                   >,
                   quan::undefined
               >::type
            >,
         quan::meta::eq_<
            quan::meta::numerator<typename Multiplier_L::type>,
            quan::meta::numerator<typename Multiplier_R::type> 
         >,
            dimensioned_divide_function< 
                typename quan::meta::rational<
                   quan::meta::denominator<typename Multiplier_R::type>::value,
                   quan::meta::denominator<typename Multiplier_L::type>::value
                >::type
            >,
         quan::meta::eq_<
            quan::meta::denominator<typename Multiplier_R::type>,
            quan::meta::denominator<typename Multiplier_L::type>
         >,
             dimensioned_divide_function< 
                 typename quan::meta::rational<
                    quan::meta::numerator<typename Multiplier_L::type>::value,
                    quan::meta::numerator<typename Multiplier_R::type>::value
                 >::type
             >,
          dimensioned_divide_pair_function<
             typename Multiplier_L::type, 
             typename Multiplier_R::type
          >
    >::type {};

}}//quan::detail

#endif
