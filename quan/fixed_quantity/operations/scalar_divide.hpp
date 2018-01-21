#ifndef QUAN_FIXED_QUANTITY_SCALAR_DIVIDE_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_SCALAR_DIVIDE_HPP_INCLUDED
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
    division of ct-quantity by numeric
*/

#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{

    namespace impl{   
        template<
            typename NumericType_1,
            typename StaticUnit,
            typename NumericType
        >
        struct binary_op_impl<
            NumericType_1,
            divides,
            quan ::fixed_quantity<
                StaticUnit,
                NumericType
            >,
            typename quan::where_<
                is_numeric<NumericType_1>
            >::type
            
        >{
            typedef typename unary_operation<
               reciprocal,
               StaticUnit
            >::type def_unit;
            typedef typename eval_if<
              and_<
                  not_<is_named_quantity<def_unit> >,
                  is_si<def_unit>
               >,
               name_anonymous_unit<def_unit>,
               def_unit
            >::type mod_units;
            typedef quan ::fixed_quantity<
                mod_units,
                typename binary_op<
                    NumericType_1,
                    divides,
                    NumericType
                >::type
            > type;
        };   

        template<
            typename StaticUnit,
            typename NumericType,
            typename NumericType_1
        >
        struct binary_op_impl<
            typename quan ::fixed_quantity<
                StaticUnit,
                NumericType
            >,
            divides,
            NumericType_1,
            typename quan::where_<
                is_numeric<NumericType_1>
            >::type
        >{
            typedef quan ::fixed_quantity<
                StaticUnit,
                typename binary_op<
                    NumericType,
                    divides,
                    NumericType_1
                >::type
            > type;
        };

    } // impl
           
}}//quan::meta

namespace quan{

    template<
        typename NumericType_1,
        typename StaticUnit,
        typename NumericType 
    >
    inline 
    QUAN_CONSTEXPR
    typename quan ::meta::binary_op_if<
        quan ::meta::is_numeric<NumericType_1>,
        NumericType_1,
        quan ::meta::divides,
        typename quan ::meta::get_nearest_si<
            quan ::fixed_quantity<
                StaticUnit,
                NumericType
            >
        >::type
    >::type
    operator / (
        NumericType_1 const & v,
        quan ::fixed_quantity<
            StaticUnit,
            NumericType
        >const & pq)
    {   
        typedef typename quan ::meta::get_nearest_si<
            quan ::fixed_quantity<
                StaticUnit,
                NumericType
            >
        >::type coherent_type;

       typedef  typename quan::meta::binary_op<
            NumericType_1,
            quan ::meta::divides,
            coherent_type
        >::type result_type ;
        return result_type{ v / coherent_type{pq}.numeric_value() };
    }

    // PQ / scalar
    template<
        typename StaticUnit,
        typename NumericType,
        typename NumericType_1
    >
    inline 
    QUAN_CONSTEXPR
    typename quan ::meta::binary_op_if<
        quan ::meta::is_numeric<NumericType_1>,
        quan ::fixed_quantity<
            StaticUnit,
            NumericType
        >,
        quan ::meta::divides,
        NumericType_1
    >::type
    operator / (
        quan ::fixed_quantity<
            StaticUnit,
            NumericType
        >const & pq,
        NumericType_1 const& v)
    {
        typedef typename quan ::meta::binary_op<
            quan ::fixed_quantity<
                StaticUnit,
                NumericType
            >,
            quan ::meta::divides,
            NumericType_1
        >::type result_type;

        return result_type{pq.numeric_value() / v};
    }

} //quan

#endif
