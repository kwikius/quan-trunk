#ifndef QUAN_FIXED_QUANTITY_ADD_SUBTRACT_HPP_INCLUDED111
#define QUAN_FIXED_QUANTITY_ADD_SUBTRACT_HPP_INCLUDED111
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
    addition and subtraction of fixed_quantity
*/
#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/binary_op_if.hpp>
#include <quan/where.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/is_numeric.hpp>

namespace quan{ namespace meta{

   namespace impl{

    template <
        typename StaticUnitL ,
        typename ValueTypeL ,
        typename StaticUnitR ,
        typename ValueTypeR
    > struct binary_op_impl<
        fixed_quantity<
            StaticUnitL ,
            ValueTypeL
        > ,
        plus ,
        fixed_quantity<
            StaticUnitR,
            ValueTypeR
        >,
        typename quan::where_<
            quan::meta::dimensionally_equivalent<
               StaticUnitL,StaticUnitR
            >
        >::type
    >{
        typedef typename binary_op<
            StaticUnitL,
            plus,
            StaticUnitR 
        >::type units;

        typedef typename binary_op<
            ValueTypeL,
            plus, 
            ValueTypeR
        >::type value_type;

        typedef typename fixed_quantity<
            units,
            value_type
        >::type type;
    };

    template <
        typename StaticUnitL ,
        typename ValueTypeL ,
        typename StaticUnitR ,
        typename ValueTypeR
    > struct binary_op_impl<
        fixed_quantity<
            StaticUnitL ,
            ValueTypeL
        > ,
        minus ,
        fixed_quantity<
            StaticUnitR,
            ValueTypeR
        >,
        typename quan::where_<
            quan::meta::dimensionally_equivalent<
               StaticUnitL,StaticUnitR
            >
        >::type
    >{
        typedef typename binary_op<
            StaticUnitL,
            minus,
            StaticUnitR 
        >::type units;

        typedef typename binary_op<
            ValueTypeL,
            minus, 
            ValueTypeR
        >::type value_type;

        typedef typename fixed_quantity<
            units,
            value_type
        >::type type;
    };
  } // impl
} }//quan::meta


namespace quan{

    template < 
        typename StaticUnitL,
        typename ValueTypeL,
        typename StaticUnitR ,
        typename ValueTypeR
    >
    QUAN_CONSTEXPR
    inline
    typename quan::meta::binary_op_if<
        quan::meta::dimensionally_equivalent<
            StaticUnitL,
            StaticUnitR
        >,
        quan::fixed_quantity<
            StaticUnitL ,
            ValueTypeL
        > ,
        quan::meta::plus ,
        quan::fixed_quantity<
            StaticUnitR ,
            ValueTypeR
        >
    >::type
    operator + (
        quan::fixed_quantity<
            StaticUnitL ,
            ValueTypeL
        > const & lhs ,
        quan::fixed_quantity<
            StaticUnitR ,
            ValueTypeR
        > const & rhs
    )
    {
        typedef typename quan::meta::binary_op<
            quan::fixed_quantity<
                StaticUnitL ,
                ValueTypeL
            > ,
            quan::meta::plus ,
            quan::fixed_quantity<
                StaticUnitR ,
                ValueTypeR
            >
        >::type result_type;
       return result_type{result_type{lhs}.numeric_value() + result_type{rhs}.numeric_value()};
    }

    template < 
        typename StaticUnitL,
        typename ValueTypeL,
        typename StaticUnitR ,
        typename ValueTypeR
    >
    QUAN_CONSTEXPR
    inline
    typename quan::meta::binary_op_if<
        quan::meta::dimensionally_equivalent<
            StaticUnitL,
            StaticUnitR
        >,
        quan::fixed_quantity< 
            StaticUnitL ,
            ValueTypeL
        > ,
        quan::meta::minus,
        quan::fixed_quantity<
            StaticUnitR ,
            ValueTypeR
        >
    >::type
    operator -(
        quan::fixed_quantity<
            StaticUnitL ,
            ValueTypeL
        > const & lhs ,
        quan::fixed_quantity<
            StaticUnitR ,
            ValueTypeR
        > const & rhs
    )
    {
        typedef typename quan::meta::binary_op<
            quan::fixed_quantity<
                StaticUnitL ,
                ValueTypeL
            > ,
            quan::meta::minus ,
            quan::fixed_quantity<
                StaticUnitR ,
                ValueTypeR
            >
        >::type result_type;
        return result_type{result_type{lhs}.numeric_value() - result_type{rhs}.numeric_value()};
    }

} //quan


#endif

