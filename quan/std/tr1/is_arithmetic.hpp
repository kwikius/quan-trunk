#ifndef QUAN_STD_TR1_IS_ARITHMETIC_HPP_INCLUDED
#define QUAN_STD_TR1_IS_ARITHMETIC_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2005 - 2013 Andy Little 

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
#ifdef QUAN_USE_QUAN_STD_TR1

#include <quan/std/tr1/impl_detail/is_arithmetic_impl.hpp>

namespace std{

   template <typename T>
   struct is_arithmetic : quan::impl_detail::is_arithmetic_impl<T>{};
}

#else
#include <type_traits>
#endif
#endif
