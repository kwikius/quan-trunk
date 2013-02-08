#ifndef QUAN_FIXED_QUANTITY_TO_ARITHMETIC_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_TO_ARITHMETIC_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    to_arithmetic for fixed_quantity
*/
#include <quan/config.hpp>
#include <quan/meta/to_arithmetic.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>

namespace quan { namespace meta{

    template <
        typename StaticAbstractQuantity,
        typename StaticUnit, 
        typename ValueType
    >
    struct to_arithmetic<
        quan::fixed_quantity<
            StaticAbstractQuantity,
            StaticUnit,
            ValueType
        >
    >{
        typedef ValueType type;
        type operator()(  
            quan::fixed_quantity<
                StaticAbstractQuantity,
                StaticUnit,
                ValueType
            > const & in
        )
        {
            return in.numeric_value();
        }
    };

} }//quan::meta

#endif
 