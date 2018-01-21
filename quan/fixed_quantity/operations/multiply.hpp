#ifndef QUAN_FIXED_QUANTITY_MULTIPLY_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_MULTIPLY_HPP_INCLUDED
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

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    multiply two fixed_quantities
*/
#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/name_anonymous_unit.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/detail/united_value/operations/dimensioned_multiply.hpp>
#include <quan/detail/united_value/operations/dimensionless_multiply.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>

namespace quan{ namespace meta{
    
   namespace impl{

        template <
            typename StaticUnit_L ,
            typename ValueType_L ,
            typename StaticUnit_R ,
            typename ValueType_R
        > struct binary_op_impl<
            fixed_quantity<StaticUnit_L ,ValueType_L> ,
            times ,
            fixed_quantity<StaticUnit_R ,ValueType_R >
        >{
            typedef typename binary_op<
                StaticUnit_L ,
                times ,
                StaticUnit_R 
            >::type def_unit;
            typedef typename eval_if<
               and_<
                  not_<is_named_quantity<def_unit> >,
                  is_si<def_unit>
               >,
               name_anonymous_unit<def_unit>,
               def_unit
            >::type mod_units;
            typedef typename binary_op<
                ValueType_L ,
                times, 
                ValueType_R
            >::type value_type;

            typedef typename fixed_quantity<
                mod_units ,
                value_type
            >::type type;
        };
    } // impl
} }//quan::meta
    
#if !(defined QUAN_SUPPRESS_VC8_ADL_BUG)
namespace quan{ 
#endif

    // multiply
    template< 
        typename StaticUnit_L,typename ValueType_L,
        typename StaticUnit_R,typename ValueType_R
    >
    QUAN_CONSTEXPR
    inline
    typename quan::meta::binary_op< 
        quan::fixed_quantity<
            StaticUnit_L,ValueType_L
        >,
        quan::meta::times,
        quan::fixed_quantity<
            StaticUnit_R,ValueType_R
        >
    >::type
    operator * ( 
        quan::fixed_quantity<
            StaticUnit_L,ValueType_L
        > const & lhs ,
        quan::fixed_quantity<
            StaticUnit_R,ValueType_R
        > const & rhs )
        {
            typedef typename quan::meta::binary_op<
                quan::fixed_quantity<
                    StaticUnit_L,ValueType_L
                >,
                quan::meta::times,
                quan::fixed_quantity<
                    StaticUnit_R,ValueType_R
                >
            >::type result_type;
        //typename meta::get_conversion_factor
            // could check its an si quantity here
            typedef typename quan::meta::get_conversion_factor<
                StaticUnit_L
            >::type conv_factor_L;
            typedef typename quan::meta::get_conversion_factor<
                StaticUnit_R
            >::type conv_factor_R;
            typedef typename quan:: meta::eval_if<
                quan::meta::is_dimensionless<
                    typename quan::meta::binary_op<
                        StaticUnit_L,
                        quan::meta::times,
                        StaticUnit_R
                    >::type
                >,
                quan::detail::dimensionless_multiply1<
                    conv_factor_L, conv_factor_R
                >,
                quan::detail::dimensioned_multiply1< 
                    typename quan::meta::get_multiplier<
                        conv_factor_L
                    >::type,
                    typename quan::meta::get_multiplier<
                        conv_factor_R
                    >::type
                >
            >::type calc_type;
            typedef typename calc_type::template eval<ValueType_L,ValueType_R> func;
    
            return result_type{ func{}( lhs.numeric_value(),rhs.numeric_value())};
        }

#if !(defined QUAN_SUPPRESS_VC8_ADL_BUG)
} //quan
#endif
#endif
