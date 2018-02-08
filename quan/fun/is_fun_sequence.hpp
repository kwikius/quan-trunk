#ifndef QUAN_FUN_IS_FUN_SEQUENCE_HPP_INCLUDED
#define QUAN_FUN_IS_FUN_SEQUENCE_HPP_INCLUDED
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
#include <tuple>
/*
 to make a model of fun::Sequence

 // sequence requirements are
   num_elements and at?
 
*/
namespace quan{ namespace fun{

   template <typename T>
   struct is_fun_sequence_impl : std::false_type{};

   template <typename T>
   struct is_fun_sequence : is_fun_sequence_impl<
      typename std::remove_const<
         typename std::remove_reference<T>::type
      >::type
   >{};

   template <int N, typename T>
   struct is_fun_sequence_impl<T[N]> : std::true_type{};

   
   template<typename... Elements> 
   struct is_fun_sequence_impl<std::tuple<Elements...> > : std::true_type{};
}}//quan::fun

#endif
