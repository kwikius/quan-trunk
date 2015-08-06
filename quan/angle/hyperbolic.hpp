#ifndef QUAN_ANGLE_HYPERBOLIC_HPP_INCLUDED
#define QUAN_ANGLE_HYPERBOLIC_HPP_INCLUDED

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

/*
 hyberbolic functions
*/

#include <quan/angle/mathematic_angle.hpp>
#include <quan/where.hpp>
#include <quan/meta/min_type.hpp>

namespace quan{

    template <typename ValueType>
    inline
    typename quan::where_<
        quan::meta::is_angle_value_type<ValueType>,
        typename quan::meta::convert_integral_to_double<ValueType>::type
    >::type
    sinh(mathematic_angle<meta::rational<1>, ValueType> const & x)
    {
        typedef typename quan::meta::convert_integral_to_double<
            ValueType
        >::type result_type;
        using std::sinh;
        result_type result = sinh(static_cast<result_type>(x.numeric_value()));
        return  result;
    }

    template <typename ValueType>
    inline
    typename quan::where_<
        quan::meta::is_angle_value_type<ValueType>,
        typename quan::meta::convert_integral_to_double<ValueType>::type
    >::type
    cosh(mathematic_angle<meta::rational<1>, ValueType> const & x)
    {
        typedef typename quan::meta::convert_integral_to_double<
            ValueType
        >::type result_type;
        using std::cosh;
        result_type result = cosh(static_cast<result_type>(x.numeric_value()));
        return  result;
    }

    template <typename ValueType>
    inline
    typename quan::where_<
        quan::meta::is_angle_value_type<ValueType>,
        typename quan::meta::convert_integral_to_double<ValueType>::type
    >::type
    tanh(mathematic_angle<meta::rational<1>, ValueType> const & x)
    {
        typedef typename quan::meta::convert_integral_to_double<
            ValueType
        >::type result_type;
        using std::tanh;
        result_type result = tanh(static_cast<result_type>(x.numeric_value()));
        return  result;
    }

}// quan

#endif
