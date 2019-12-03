#ifndef QUAN_MATTERS_TEST_CONCEPTS_STATIC_UNIT_HPP_INCLUDED
#define QUAN_MATTERS_TEST_CONCEPTS_STATIC_UNIT_HPP_INCLUDED

// Copyright Andrew Little 2005
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
/*
    Static Unit Concept check
    Check that a type fulfills the StaticUnit requirements
*/

#include <quan/config.hpp>
#include <quan/meta/static_unit_concept.hpp>
//#include <boost/type_traits/is_same.hpp>
#include <quan_matters/test/concepts/unary_metafunction.hpp>
#include <quan/meta/rational.hpp>
//#include <boost/mpl/assert.hpp>

QUAN_NS_OPEN namespace meta{

template <typename StaticUnit>
inline
void StaticUnitConcept()
{
    UnaryMetaFunctionConcept<StaticUnit>();
    typedef typename is_dimensionless<StaticUnit>::type is_dimensionless_type;
    const static bool is_dimensionless1 = is_dimensionless<StaticUnit>::value;
    const static bool is_dimensionless2 = is_dimensionless_type::value;

    typedef typename is_named_quantity<StaticUnit>::type is_named_quantity_type;
    const static bool is_named_quantity1 = is_named_quantity<StaticUnit>::value;
    const static bool is_named_quantity2 = is_named_quantity_type::value;

    typedef typename make_anonymous<StaticUnit>::type anonymous_type;
    BOOST_MPL_ASSERT_NOT((is_named_quantity<anonymous_type>));
 
    typedef get_named_quantity_traits<StaticUnit>::type named_quantity_traits;

   /* if( boost::is_same<
        named_quantity_traits,
        anonymous_quantity_traits
       >::value == false){*/
    if (is_named_quantity<StaticUnit>::value){
        //pass named_quantity_traits to a NamedQuantityTraitsConcept function
    }
            
   /* BOOST_MPL_ASSERT(( boost::is_same<
        typename get_named_quantity_traits<anonymous_type>::type,
        anonymous_quantity_traits
    >));*/
   // if its a quantity in the si_system
    if (boost::is_same<
            typename get_quantity_system<StaticUnit>::type,
            si_unit_system
        >::value){
        typedef is_si<StaticUnit>::type si_type;
        typedef get_nearest_si<StaticUnit>::type nearest_si_type;
        BOOST_MPL_ASSERT((is_si<nearest_si_type>));

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
    }

    BOOST_MPL_ASSERT((is_same_quantity<StaticUnit,StaticUnit>));
    BOOST_MPL_ASSERT((dimensionally_equivalent<StaticUnit,StaticUnit>));

    // conversion_factor
    //pass to a ConversionFactorConcept
    typedef typename get_conversion_factor<StaticUnit>::type unit_conversion_factor;
    typedef typename get_exponent<unit_conversion_factor>::type exponent;
    typedef typename get_multiplier<unit_conversion_factor>::type multiplier;

    typedef typename binary_operation<StaticUnit,plus,StaticUnit>::type plus_type;
    typedef typename binary_operation<StaticUnit,minus,StaticUnit>::type minus_type;
    typedef typename binary_operation<StaticUnit,times,StaticUnit>::type times_type;
    typedef typename binary_operation<StaticUnit,divides,StaticUnit>::type divides_type;
    typedef typename binary_operation<StaticUnit,pow,rational<2> >::type sqr_type;
    
    BOOST_MPL_ASSERT((boost::is_same<StaticUnit,plus_type>));
    BOOST_MPL_ASSERT((boost::is_same<StaticUnit,minus_type>));
    BOOST_MPL_ASSERT((boost::is_same<times_type,sqr_type>));
    BOOST_MPL_ASSERT((is_dimensionless<divides_type>));

    //unary ops reciprocal
    typedef typename unary_operation<reciprocal,StaticUnit>::type reciprocal_unit;
    BOOST_MPL_ASSERT((is_dimensionless<
        typename quan::meta::binary_operation<
            StaticUnit,
            times,
            reciprocal_unit
        >::type>));

}

QUAN_NS_CLOSE }//quan::meta

#endif

