#ifndef QUAN_ABSTRACT_QUANTITY_FWD_HPP_INCLUDED
#define QUAN_ABSTRACT_QUANTITY_FWD_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace meta{

    template< 
        typename Dimension, 
        typename NamedQuantityTraits
    >
    struct abstract_quantity;

}}//quan::meta

#endif
