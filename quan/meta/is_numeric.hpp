#ifndef QUAN_META_IS_NUMERIC_HPP_INCLUDED
#define QUAN_META_IS_NUMERIC_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2005-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

/*
    Is T a numeric type
*/
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#endif
#include <quan/meta/and.hpp>
#include <quan/meta/is_angle.hpp>
#include <quan/meta/or.hpp>

namespace quan{ namespace meta{

    template <typename ValueType>
    struct is_numeric : quan::meta::or_<std::is_arithmetic<ValueType>,quan::meta::is_angle<ValueType> >{};

    template <typename A, typename B>
    struct are_numeric : and_<
        is_numeric<A>,
        is_numeric<B>
    >{};
                
}}//quan::meta

#endif

