#ifndef QUAN_META_IS_ANGLE_HPP_INCLUDED
#define QUAN_META_IS_ANGLE_HPP_INCLUDED

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
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/integral_constant.hpp>
#endif

#include <quan/meta/or.hpp>

namespace quan{ namespace meta{

    template <typename T>
    struct is_mathematic_angle : std::false_type{};
    
    template <typename T>
    struct is_fraction_of_revolution : std::false_type{};

    template <typename T>
    struct is_angle : or_<
       is_mathematic_angle<T>,
       is_fraction_of_revolution<T>
    >{}; 
    
}} //quan::meta

#endif

