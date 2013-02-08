#ifndef QUAN_META_STATIC_UNIT_CONCEPT_HPP_INCLUDED
#define QUAN_META_STATIC_UNIT_CONCEPT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See <QUAN_ROOT/quan_matters/index.html> for documentation.

/*
    associated metafunctions for StaticUnit Concept.
    These are required to be specialised per model
*/

#include <quan/config.hpp>
#include <quan/archetypes/meta/static_abstract_quantity_concept.hpp>
#include <quan/meta/get_quantity_system.hpp>
#include <quan/archetypes/meta/conversion_factor_concept.hpp>

namespace quan { namespace meta{

    template <typename StaticUnit>
    struct get_conversion_factor;

    template <typename StaticUnit>
    struct get_named_quantity_traits;

    template <typename StaticUnit>
    struct allow_implicit_unit_conversions;

    template <typename StaticUnit>
    struct name_anonymous_unit;

} }//quan::meta

#endif
