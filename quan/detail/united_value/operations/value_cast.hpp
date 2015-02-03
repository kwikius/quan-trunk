#ifndef QUAN_OPERATIONS_VALUE_CAST_HPP_INCLUDED
#define QUAN_OPERATIONS_VALUE_CAST_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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
    compute result value in scaling two ct-quantities
*/

#include <quan/config.hpp>
#include <quan/quantity_traits.hpp>
#include <quan/meta/to_arithmetic.hpp>
#include <quan/detail/united_value/operations/dimensionless_divide.hpp>
#include <quan/detail/united_value/united_value_fwd.hpp>

namespace quan{ namespace detail{

    template <
        typename TargetUnitedValue,
        typename SrcConversionFactor,
        typename SrcValueType
    > 
    inline QUAN_CONSTEXPR
    typename TargetUnitedValue::value_type     
    united_value_cast(
        united_value<
            SrcConversionFactor,
            SrcValueType
        >const & source_uv
    )
    {   
        typedef typename convert_units1<
            typename TargetUnitedValue::conversion_factor,SrcConversionFactor
        > ::type:: template convert<
             SrcValueType
        > units_converter_type;

      //  units_converter_type units_converter;
        typedef typename quantity_traits::value_type_converter<
            typename TargetUnitedValue::value_type,
            typename units_converter_type::result_type
        > convert_type;

//        typename TargetUnitedValue::value_type result(
//            convert(units_converter(source_uv.raw_value() ))
//        );
//        return result;

        return typename TargetUnitedValue::value_type{convert_type{}(units_converter_type{}(source_uv.raw_value()))};
    }

} }//quan::detail

#endif
