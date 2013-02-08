#ifndef QUAN_FIXED_QUANTITY_FWD_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_FWD_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
   forward declaration of quan::fixed_quantity
*/
#include <quan/config.hpp>
#include <quan/meta/is_scalar_quantity.hpp>
#include <quan/meta/bool/true.hpp>


namespace quan {

    template<
        typename StaticUnit,
        typename ValueType
    >
    class fixed_quantity;

    namespace meta{

       template<
            typename StaticUnit,
            typename ValueType
        >
        struct is_scalar_quantity<
            fixed_quantity<
                StaticUnit, 
                ValueType
            >
        > : quan::meta::true_{};  
    }

    template <typename StaticUnit>
    struct default_fixed_quantity_unit{};
  
} //quan

#endif
