#ifndef QUAN_META_TO_ARITHMETIC_HPP_INCLUDED
#define QUAN_META_TO_ARITHMETIC_HPP_INCLUDED

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
    to get at the arithmetic type of a type.
    Used by fixed_quantity value_type
*/

#include <quan/config.hpp>

#include <quan/where.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#endif


namespace quan{namespace meta{

    template <typename T, typename Where = void>
    struct to_arithmetic {};

    template <typename T>
    struct to_arithmetic<
        T, 
        typename quan::where_<
            std::is_arithmetic<T>
        >::type
    >{ 
        typedef T type;
    
        QUAN_CONSTEXPR type operator()(T const & in)const
        {
            return in;
        }
    };

}}//quan::meta

#endif
