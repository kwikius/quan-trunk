#ifndef QUAN_CEIL_FLOOR_HPP_INCLUDED
#define QUAN_CEIL_FLOOR_HPP_INCLUDED

// Copyright Andrew Little 2005-2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
   ceil floor of quantity
*/

#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/min_type.hpp>
#include <cmath>

namespace quan{

    template <typename Unit, typename ValueType>
    inline fixed_quantity<
        Unit,
        ValueType
    >
    floor(fixed_quantity<Unit, ValueType> const & x)
    {
        typedef typename quan::meta::convert_integral_to_double<
            ValueType
        >::type cast_value_type;
        using std::floor;
        return fixed_quantity<
           Unit,
           ValueType
        >(floor(static_cast<cast_value_type>(x.numeric_value())));
    }

    template <typename Unit, typename ValueType>
    inline fixed_quantity<
        Unit,
        ValueType
    >
    ceil(fixed_quantity<Unit, ValueType> const & x)
    {
        typedef typename quan::meta::convert_integral_to_double<
            ValueType
        >::type cast_value_type;
        using std::ceil;
        return fixed_quantity<
           Unit,
           ValueType
        >(ceil(static_cast<cast_value_type>(x.numeric_value())));
    }

}//quan

#endif
