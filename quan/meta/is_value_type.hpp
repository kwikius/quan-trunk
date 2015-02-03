#ifndef QUAN_META_VALUE_TYPE_HPP_INCLUDED1
#define QUAN_META_VALUE_TYPE_HPP_INCLUDED1
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

#include <type_traits>
#include <quan/meta/and.hpp>
namespace quan{ namespace meta{

    template <typename ValueType>
    struct is_value_type : std::is_arithmetic<ValueType>{};

    template <typename A, typename B>
    struct are_value_type2 : and_<
        is_value_type<A>,
        is_value_type<B>
    >::type{};
                
}}//quan::meta

#endif

