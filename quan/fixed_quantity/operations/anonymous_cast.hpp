#ifndef QUAN_FIXED_QUANTITY_OPERATIONS_ANONYMOUS_CAST_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_OPERATIONS_ANONYMOUS_CAST_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
/*
    function to cast a named_quantity
    to an anonymous_quantity
*/

#include <quan/fixed_quantity/fixed_quantity.hpp>

namespace quan{

    template < 
        typename StaticUnit,
        typename NumericType
    >
    inline QUAN_CONSTEXPR
    typename meta::make_anonymous<
       fixed_quantity<
            StaticUnit,
            NumericType
        >     
    >::type
    anonymous_cast(
        fixed_quantity<
            StaticUnit,
            NumericType
        > const& pq_in
    )
    {
        return typename meta::make_anonymous<
            fixed_quantity<
                StaticUnit,
                NumericType
            >     
        >::type{pq_in};
    }
}//quan

#endif
