
#ifndef QUAN_META_IS_ANGLE_VALUE_TYPE_HPP_INCLUDED
#define QUAN_META_IS_ANGLE_VALUE_TYPE_HPP_INCLUDED

// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.
/*
    used to identify if a type is a valid angle value_type
*/

#include <quan/config.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/meta/is_angle.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/and.hpp>

namespace quan{ namespace meta{

    template <typename T>
    struct is_angle_value_type : and_<
        is_numeric<T>,
        not_<is_angle<T> >
    >{};

}}//quan::meta

#endif
