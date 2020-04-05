#ifndef QUAN_STD_TR1_IMPL_DETAIL_IS_ARITHMETIC_IMPL_HPP_INCLUDED
#define QUAN_STD_TR1_IMPL_DETAIL_IS_ARITHMETIC_IMPL_HPP_INCLUDED

/*
 Copyright (c) 2006 - 2020 Andy Little 

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

#include <quan/config.hpp>

#if defined QUAN_USE_QUAN_STD_TR1

#include <quan/std/tr1/is_integral.hpp>
#include <quan/std/tr1/is_float.hpp>

namespace quan{ namespace impl_detail{

    template <typename T>  struct is_arithmetic_impl : std::integral_constant<
         bool,(std::is_floating_point<T>::value || std::is_integral<T>::value)
     >{};
}}

#else

#include <type_traits>

#endif
#endif


