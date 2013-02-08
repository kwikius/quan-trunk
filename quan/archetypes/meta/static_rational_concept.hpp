#ifndef QUAN_META_RATIONAL_CONCEPT_HPP_INCLUDED
#define QUAN_META_RATIONAL_CONCEPT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    StaticRational extends StaticNumeric
*/

#include <quan/archetypes/meta/static_numeric_concept.hpp>
#include <quan/meta/numerator.hpp>
#include <quan/meta/denominator.hpp>

namespace quan{namespace meta{

    template < typename StaticRational>
    struct eval;

    template <typename StaticRational>
    struct is_integer;
    
}}

#endif
