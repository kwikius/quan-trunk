#ifndef QUAN_META_CONVERSION_FACTOR_CONCEPT_HPP_INCLUDED
#define QUAN_META_CONVERSION_FACTOR_CONCEPT_HPP_INCLUDED
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

namespace quan{namespace meta{

    template <typename T>
    struct get_nearest_si;

    template <typename T>
    struct is_si;
    
    template<typename TL,typename TR>
    struct get_finest_grained;

    template <typename Unit>
    struct get_exponent;
    
    template <typename Unit>
    struct get_multiplier;
    
    template <typename Unit_L, typename Unit_R>
    struct is_math_same_conversion_factor;

}}//quan::meta

#endif
