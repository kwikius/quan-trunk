#ifndef QUAN_UNIT_FWD_HPP_INCLUDED
#define QUAN_UNIT_FWD_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    forward declaration of quan defaul StaticUnit implementation
*/

#include <quan/archetypes/meta/static_unit_concept.hpp>

namespace quan{namespace meta{

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct unit;

}}//quan::meta


#endif
