#ifndef QUAN_META_IS_LOSSLESS_CALCULATION_HPP_INCLUDED
#define QUAN_META_IS_LOSSLESS_CALCULATION_HPP_INCLUDED


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

#include <quan/meta/is_numeric.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/and.hpp>
//#include <quan/where.hpp>
#include <quan/where.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/integral_constant.hpp>
#endif

namespace quan{ namespace meta{
    
    template <typename TL, typename Op, typename TR, typename Enable = void>
    struct is_lossless_calculation;

    template <typename TL, typename Op, typename TR>
    struct is_lossless_calculation< 
        TL, Op, TR,
        typename quan::where_<
            are_numeric<TL,TR> 
        >::type
    > : std::true_type{};

        
}}//quan::meta

#endif
