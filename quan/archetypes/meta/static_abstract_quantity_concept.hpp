#ifndef QUAN_META_STATIC_ABSTRACT_QUANTITY_CONCEPT_HPP_INCLUDED
#define QUAN_META_STATIC_ABSTRACT_QUANTITY_CONCEPT_HPP_INCLUDED

// Copyright Andrew Little 2005

// See <QUAN_ROOT/quan_matters/index.html> for documentation.

/*
    associated metafunctions for the StaticAbstractQuantity Concept.
    These are required to be specialised per model.
*/

#include <quan/config.hpp>
#ifndef __AVR__
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#endif
#include <quan/meta/anonymous_quantity_traits.hpp>
#include <quan/meta/if.hpp>

namespace quan { namespace meta{

    template <
        typename Quantity_L,
        typename Quantity_R
    > 
    struct dimensionally_equivalent;

    template <typename StaticAbstractQuantity>
    struct is_dimensionless : if_<
      std::is_arithmetic<StaticAbstractQuantity>,
      std::true_type,
      void
    >{};

    template <
        typename Quantity_L,
        typename Quantity_R
    > 
    struct is_same_quantity;

    template <typename Quantity>
    struct is_named_quantity;

    template <typename Quantity>
    struct make_anonymous;

    template <typename Quantity>
    struct get_named_quantity_traits;

    template <typename Quantity>
    struct get_length_dimension;
    
    template <typename Quantity>
    struct get_time_dimension;
    
    template <typename Quantity>
    struct get_mass_dimension;

    template <typename Quantity>
    struct get_temperature_dimension;

    template <typename Quantity>
    struct get_current_dimension;

    template <typename Quantity>
    struct get_substance_dimension;

    template <typename Quantity>
    struct get_intensity_dimension;

    template <typename Quantity>
    struct name_anonymous_abstract_quantity;
    

} }//quan::meta

#endif

