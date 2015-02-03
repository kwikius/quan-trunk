#ifndef QUAN_CEIL_FLOOR_HPP_INCLUDED
#define QUAN_CEIL_FLOOR_HPP_INCLUDED

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */
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
