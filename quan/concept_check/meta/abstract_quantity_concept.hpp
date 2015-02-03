#ifndef QUAN_META_TEST_ABSTRACT_QUANTITY_CONCEPT_HPP_INCLUDED
#define QUAN_META_TEST_ABSTRACT_QUANTITY_CONCEPT_HPP_INCLUDED

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
#include <type_traits>
#include <quan/concept_check/meta/identity_function.hpp>
#include <quan/concept_check/meta/boolean_function.hpp>
#include <quan/concept_check/meta/boolean_constant.hpp>
#include <quan/meta/rational.hpp>

namespace quan{ namespace concept_check {namespace meta{

   template <typename Q>
   inline
   void AbstractQuantityConcept()
   {
       quan::concept_check::meta::function<Q>();
       typedef typename quan::meta::is_dimensionless<Q>::type is_dimensionless_type;
       const static bool is_dimensionless1 = is_dimensionless<Q>::value;
       const static bool is_dimensionless2 = is_dimensionless_type::value;

       typedef typename is_named_quantity<Q>::type is_named_quantity_type;
       const static bool is_named_quantity1 = is_named_quantity<Q>::value;
       const static bool is_named_quantity2 = is_named_quantity_type::value;

       typedef typename make_anonymous<Q>::type anonymous_type;
       static_assert(is_named_quantity<anonymous_type>::value == false, "make anonymous not working");

       // check the traits class is either the anonymous_quantity or void
       typedef typename get_named_quantity_traits<Q>::type anon_q_traits;
       static_assert(std::is_same<
               typename get_named_quantity_traits<anonymous_type>::type,
               anonymous_quantity_traits
       >::value , "named_quantity_traits should be anonymous or void");

       static_assert(is_same_quantity<Q,Q>::value, "is_same_quantity should be identity");
       static_assert(dimensionally_equivalent<Q,Q>::value, "dimenisonally_equivalent<Q,Q> should always be true");

       // check these are rationals
       typedef typename get_length_dimension<Q>::type length_dimension;
       typedef typename get_time_dimension<Q>::type time_dimension;
       typedef typename get_mass_dimension<Q>::type mass_dimension;
       typedef typename get_temperature_dimension<Q>::type temperature_dimension;
       typedef typename get_current_dimension<Q>::type current_dimension;
       typedef typename get_substance_dimension<Q>::type substance_dimension;
       typedef typename get_intensity_dimension<Q>::type intensity_dimension;

       typedef typename binary_op<Q,plus,Q>::type plus_type;
       typedef typename binary_op<Q,minus,Q>::type minus_type;
       typedef typename binary_op<Q,times,Q>::type times_type;
       typedef typename binary_op<Q,divides,Q>::type divides_type;
       typedef typename binary_op<Q,pow,rational<2> >::type sqr_type;
       
       static_assert(std::is_same<Q,plus_type>::value, "type of addition should be same");
       static_assert(std::is_same<Q,minus_type>::value , "type of subtraction should be same");
       static_assert(std::is_same<times_type,sqr_type>::value, "type of Q * Q should be same as Q ^2");
       static_assert(is_dimensionless<divides_type>::value, "type of Q/Q should be dimensionless");

   }

}}}//quan::concept_check::meta

#endif
