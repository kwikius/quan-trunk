#ifndef QUAN_META_MAX_HPP_INCLUDED
#define QUAN_META_MAX_HPP_INCLUDED
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
#include <quan/where.hpp>
#include <quan/meta/float_max.hpp>
#include <quan/meta/integer_max.hpp>

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_integral.hpp>
#include <quan/std/tr1/is_float.hpp>
#endif

namespace quan{namespace meta{ 

   namespace detail{

      template <typename T, typename Where = void>
      struct max_;

      template<
         typename T
      > struct max_<T,
         typename quan::where_<std::is_integral<T> >::type
      > : integer_max<T>{};
      
       template<
         typename T
      > struct max_<T,
         typename quan::where_<std::is_floating_point<T> >::type
      > : float_max<T>{};
   }

   template <typename T>
   struct max_ : quan::meta::detail::max_<T>{};
}}

#endif // QUAN_META_MAX_HPP_INCLUDED
