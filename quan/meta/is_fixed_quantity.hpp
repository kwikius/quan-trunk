#ifndef QUAN_META_IS_FIXED_QUANTITY_HPP_INCLUDED
#define QUAN_META_IS_FIXED_QUANTITY_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/fixed_quantity/fixed_quantity_fwd.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/bool/false.hpp>
#include <quan/meta/bool/true.hpp>

namespace quan{namespace meta{

    template <typename T>
    struct is_fixed_quantity : quan::meta::false_{};

    template<
        typename StaticUnit,
        typename ValueType
    >
    struct is_fixed_quantity<
        quan::fixed_quantity<
           StaticUnit,ValueType 
        >
    > : quan::meta::true_{};
}}//quan:meta

#endif
