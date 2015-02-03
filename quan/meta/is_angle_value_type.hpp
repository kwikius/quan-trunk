
#ifndef QUAN_META_IS_ANGLE_VALUE_TYPE_HPP_INCLUDED
#define QUAN_META_IS_ANGLE_VALUE_TYPE_HPP_INCLUDED

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
