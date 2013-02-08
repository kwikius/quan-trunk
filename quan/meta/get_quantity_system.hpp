#ifndef QUAN_META_GET_QUANTITY_SYSTEM_HPP_INCLUDED
#define QUAN_META_GET_QUANTITY_SYSTEM_HPP_INCLUDED

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    metafunction for querying the quantity system for a quantity
*/
namespace quan{namespace meta{

    template <typename StaticAbstractQuantity>
    struct get_quantity_system;

}}//quan::meta

#endif
