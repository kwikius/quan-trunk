#ifndef QUAN_STD_TR1_EXTENT_HPP_INCLUDED
#define QUAN_STD_TR1_EXTENT_HPP_INCLUDED
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

#include <quan/config.hpp>

#ifdef QUAN_USE_QUAN_STD_TR1
#include <quan/std/tr1/integral_constant.hpp>
#include <stdint.h>

namespace std{ 

   /// extent
   template<typename T , unsigned int U = 0>
   struct extent : integral_constant<size_t, 0> { };

   template<typename T, unsigned U, size_t N>
   struct extent<T[N], U> : std::integral_constant<size_t, U == 0 ? N : extent<T,U - 1>::value>{};

   template<typename T, unsigned  U>
   struct extent<T[], U>  : integral_constant<size_t, U == 0 ? 0 : extent<T,  U - 1>::value>{};

}

#else
#include <type_traits>
#endif

#endif // QUAN_STD_TR1_EXTENT_HPP_INCLUDED
