#ifndef QUAN_CONCEPT_CHECK_META_ABSTRACT_QUANTITY_CONCEPT_HPP_INCLUDED
#define QUAN_CONCEPT_CHECK_META_ABSTRACT_QUANTITY_CONCEPT_HPP_INCLUDED

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
#include <quan/meta/static_abstract_quantity_concept.hpp>
#include <quan/concept_check/meta/identity_function.hpp>
#include <quan/concept_check/meta/boolean_constant.hpp>
#include <quan/concept_check/meta/rational_constant.hpp>
#include <quan/meta/rational.hpp>

namespace quan{ namespace concept_check{

template <typename Q>
inline
void meta_abstract_quantity()
{
   meta_identity_function<Q>();

   meta_boolean_function<quan::meta::is_dimensionless<Q> >();
   meta_boolean_constant<typename quan::meta::is_dimensionless<Q>::type>();

   meta_boolean_function<quan::meta::is_named_quantity<Q> >();
   meta_boolean_constant<typename quan::meta::is_named_quantity<Q>::type>();

   meta_function<quan::meta::make_anonymous<Q> >();

   typedef typename quan::meta::make_anonymous<Q>::type anonymous_type;

   meta_false_function< quan::meta::is_named_quantity<anonymous_type> >();

   meta_function<quan::meta::get_named_quantity_traits<Q> >();
   meta_true_function<
      std::is_same<
         typename quan::meta::get_named_quantity_traits<anonymous_type>::type,
         quan::meta::anonymous_quantity_traits
      >
   >();

   meta_true_function<quan::meta::is_same_quantity<Q,Q> >();

   meta_true_function<quan::meta::dimensionally_equivalent<Q,Q> >();
   meta_true_function<quan::meta::dimensionally_equivalent<Q,anonymous_type> >();

   // check these are rationals
   meta_function<quan::meta::get_length_dimension<Q> >();
   meta_rational_constant<typename quan::meta::get_length_dimension<Q>::type>();
   
   meta_function<quan::meta::get_time_dimension<Q> >();
   meta_rational_constant<typename quan::meta::get_time_dimension<Q>::type>();

   meta_function<quan::meta::get_mass_dimension<Q> >();
   meta_rational_constant<typename quan::meta::get_mass_dimension<Q>::type>();

   meta_function<quan::meta::get_temperature_dimension<Q> >();
   meta_rational_constant< typename quan::meta::get_temperature_dimension<Q>::type >();

   meta_function<quan::meta::get_current_dimension<Q> >();
   meta_rational_constant<typename quan::meta::get_current_dimension<Q>::type >();

   meta_function<quan::meta::get_mass_dimension<Q> >();
   meta_rational_constant< typename quan::meta::get_substance_dimension<Q>::type >();

   meta_function<quan::meta::get_mass_dimension<Q> >();
   meta_rational_constant< typename quan::meta::get_intensity_dimension<Q>::type >();

   meta_true_function< 
      quan::meta::is_valid_binary_op<Q, quan::meta::plus,Q>
   >();
   meta_true_function< 
      quan::meta::is_valid_binary_op<Q, quan::meta::minus,Q>
   >();
   meta_true_function< 
      quan::meta::is_valid_binary_op<Q, quan::meta::times,Q>
   >();
   meta_true_function< 
      quan::meta::is_valid_binary_op<Q, quan::meta::divides,Q>
   >();
   typedef typename quan::meta::binary_op<Q,quan::meta::plus,Q>::type plus_type;
   typedef typename quan::meta::binary_op<Q,quan::meta::minus,Q>::type minus_type;
   typedef typename quan::meta::binary_op<Q,quan::meta::times,Q>::type times_type;
   typedef typename quan::meta::binary_op<Q,quan::meta::divides,Q>::type divides_type;
   typedef typename quan::meta::binary_op<
         Q,quan::meta::pow,quan::meta::rational<2> 
   >::type sqr_type;

   meta_true_function<std::is_same<Q,plus_type> >();
   meta_true_function<std::is_same<Q,minus_type> >();
   meta_true_function<std::is_same<times_type,sqr_type> >();
   meta_true_function<quan::meta::is_dimensionless<divides_type> >();

   meta_function<quan::meta::unary_operation<quan::meta::reciprocal,Q> > ();
   meta_true_function< 
      quan::meta::dimensionally_equivalent<
         Q,
         typename quan::meta::unary_operation<
            typename quan::meta::reciprocal,
               typename quan::meta::unary_operation<quan::meta::reciprocal,Q
            >::type
         >::type
      >
   >(); 
   //meta_function<quan::meta::unary_operation<quan::meta::negate,Q> > ();
}

}}//quan::meta

#endif
