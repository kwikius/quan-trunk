#ifndef QUAN_CONCEPT_CHECK_META_RATIONAL_CONSTANT_HPP_INCLUDED
#define QUAN_CONCEPT_CHECK_META_RATIONAL_CONSTANT_HPP_INCLUDED
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

#include <quan/config.hpp>
#include <quan/concept_check/meta/identity_function.hpp>
#include <quan/meta/static_rational_concept.hpp>
#include <quan/concept_check/meta/integral_constant.hpp>
#include <quan/concept_check/meta/boolean_constant.hpp>
#include <quan/concept_check/meta/boolean_function.hpp>
#include <quan/concept_check/meta/function.hpp>
#include <quan/meta/is_valid_binary_op.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/eq.hpp>

namespace quan{ namespace concept_check{namespace meta{

// assert that T is a rational
template <typename T>
inline
void rational_constant()
{
   quan::concept_check::meta::function<T>();
   quan::concept_check::meta::identity_function<typename T::type>();
   quan::concept_check::meta::function<quan::meta::numerator<T> >();

   quan::concept_check::meta::integral_constant<typename quan::meta::numerator<T>::type>();
   quan::concept_check::meta::integral_constant<typename quan::meta::denominator<T>::type>();

   quan::concept_check::meta::function<quan::meta::denominator<T> >();
   quan::concept_check::meta::true_function< 
      quan::meta::is_valid_binary_op<T, quan::meta::plus,T>
   >();
   quan::concept_check::meta::true_function< 
      quan::meta::is_valid_binary_op<T, quan::meta::minus,T>
   >();
   quan::concept_check::meta::true_function< 
      quan::meta::is_valid_binary_op<T, quan::meta::times,T>
   >();
   quan::concept_check::meta::true_function< 
      quan::meta::is_valid_binary_op<T, quan::meta::divides,T>
   >();

   quan::concept_check::meta::true_function< 
      quan::meta::is_valid_binary_op<T, quan::meta::equal_to,T>
   >();

   quan::concept_check::meta::true_function< 
      quan::meta::is_valid_binary_op<T, quan::meta::not_equal_to,T>
   >();

   quan::concept_check::meta::boolean_function< 
      quan::meta::is_lossless_calculation<T, quan::meta::plus,T>
   >();
   quan::concept_check::meta::boolean_function< 
      quan::meta::is_lossless_calculation<T, quan::meta::minus,T>
   >();
   quan::concept_check::meta::boolean_function< 
      quan::meta::is_lossless_calculation<T, quan::meta::times,T>
   >();
    quan::concept_check::meta::boolean_function< 
      quan::meta::is_lossless_calculation<T, quan::meta::divides,T>
   >();
   
   quan::concept_check::meta::boolean_function<quan::meta::eq_zero<T> >();
   quan::concept_check::meta::boolean_function<quan::meta::eq_one<T> >();
   quan::concept_check::meta::boolean_function<quan::meta::lt_zero<T> >();
   quan::concept_check::meta::boolean_function<quan::meta::lte_zero<T> >();
   quan::concept_check::meta::boolean_function<quan::meta::gt_zero<T> >();
   quan::concept_check::meta::boolean_function<quan::meta::gte_zero<T> >();
   quan::concept_check::meta::boolean_function<quan::meta::is_integer<T> >();

   // avoid zero denom fail on zero numerator for reciprocal
   typedef typename quan::meta::eval_if<
      quan::meta::eq_zero<T>,
      quan::meta::binary_op<
         T,quan::meta::plus,quan::meta::rational<1>
      >,
      T
   >::type recip_check;
   
   quan::concept_check::meta::function<quan::meta::unary_operation<quan::meta::reciprocal,recip_check> > ();
   quan::concept_check::meta::function<quan::meta::unary_operation<quan::meta::negate,T> > ();

   quan::concept_check::meta::true_function<quan::meta::eq_<T,T> >();
   quan::concept_check::meta::false_function<quan::meta::neq_<T,T> >();
   quan::concept_check::meta::false_function<quan::meta::lt_<T,T> >();
   quan::concept_check::meta::true_function<quan::meta::gte_<T,T> >();
   quan::concept_check::meta::true_function<quan::meta::lte_<T,T> >();

   quan::concept_check::meta::true_function<quan::meta::is_rational<T> >();
}

}}}//quan::concept_check::meta


#endif
 
