#ifndef QUAN_MATTERS_TEST_CONCEPTS_STATIC_UNIT_HPP_INCLUDED
#define QUAN_MATTERS_TEST_CONCEPTS_STATIC_UNIT_HPP_INCLUDED

#include <quan/config.hpp>
#include <quan/archetypes/meta/static_unit_concept.hpp>

#include <quan/meta/rational.hpp>

namespace quan{ namespace meta{

   template <typename StaticUnit>
   inline
   void StaticUnitConcept()
   {
 
      // UnaryMetaFunctionConcept<StaticUnit>();

       typedef typename is_dimensionless<StaticUnit>::type is_dimensionless_type;
       const static bool is_dimensionless1 = is_dimensionless<StaticUnit>::value;
       const static bool is_dimensionless2 = is_dimensionless_type::value;

       typedef typename is_named_quantity<StaticUnit>::type is_named_quantity_type;
       const static bool is_named_quantity1 = is_named_quantity<StaticUnit>::value;
       const static bool is_named_quantity2 = is_named_quantity_type::value;

       typedef typename make_anonymous<StaticUnit>::type anonymous_type;
       static_assert(! is_named_quantity<anonymous_type>::value ,"");
    
       typedef typename get_named_quantity_traits<StaticUnit>::type named_quantity_traits;
  
      /* if( std::is_same<
           named_quantity_traits,
           anonymous_quantity_traits
          >::value == false){*/
       if (is_named_quantity<StaticUnit>::value){
           //pass named_quantity_traits to a NamedQuantityTraitsConcept function
       }
               
      /* static_assert(( std::is_same<
           typename get_named_quantity_traits<anonymous_type>::type,
           anonymous_quantity_traits>::value
       >));*/
      // if its a quantity in the si_system
//       if (std::is_same<
//               typename get_quantity_system<StaticUnit>::type,
//               si_unit_system
//           >::value){
           typedef typename is_si<StaticUnit>::type si_type;
           typedef typename get_nearest_si<StaticUnit>::type nearest_si_type;
            static_assert(is_si<nearest_si_type>::value,"");

            // check these are rationals
           // or maybe have numerators and denominators
           // which allows mpl::integral_c etc
           typedef typename get_length_dimension<StaticUnit>::type length_dimension;
           typedef typename get_time_dimension<StaticUnit>::type time_dimension;
           typedef typename get_mass_dimension<StaticUnit>::type mass_dimension;
           typedef typename get_temperature_dimension<StaticUnit>::type temperature_dimension;
           typedef typename get_current_dimension<StaticUnit>::type current_dimension;
           typedef typename get_substance_dimension<StaticUnit>::type substance_dimension;
           typedef typename get_intensity_dimension<StaticUnit>::type intensity_dimension;
       //}

       static_assert(is_same_quantity<StaticUnit,StaticUnit>::value,"");
       static_assert(dimensionally_equivalent<StaticUnit,StaticUnit>::value,"");

       // conversion_factor
       //pass to a ConversionFactorConcept
       typedef typename get_conversion_factor<StaticUnit>::type unit_conversion_factor;
       typedef typename get_exponent<unit_conversion_factor>::type exponent;
       typedef typename get_multiplier<unit_conversion_factor>::type multiplier;

       typedef typename binary_op<StaticUnit,plus,StaticUnit>::type plus_type;
       typedef typename binary_op<StaticUnit,minus,StaticUnit>::type minus_type;
       typedef typename binary_op<StaticUnit,times,StaticUnit>::type times_type;
       typedef typename binary_op<StaticUnit,divides,StaticUnit>::type divides_type;
       typedef typename binary_op<StaticUnit,pow,rational<2> >::type sqr_type;
       
       static_assert(std::is_same<StaticUnit,plus_type>::value,"");
       static_assert(std::is_same<StaticUnit,minus_type>::value,"");
       static_assert(std::is_same<times_type,sqr_type>::value,"");
       static_assert(is_dimensionless<divides_type>::value,"");

       //unary ops reciprocal
       typedef typename unary_operation<reciprocal,StaticUnit>::type reciprocal_unit;
       static_assert(is_dimensionless<
           typename quan::meta::binary_op<
               StaticUnit,
               times,
               reciprocal_unit
           >::type>::value,"");

   }

}}//quan::meta

#endif

