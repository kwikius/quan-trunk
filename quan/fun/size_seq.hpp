#ifndef  QUAN_FUN_SIZE_SEQ_HPP_INCLUDED
#define  QUAN_FUN_SIZE_SEQ_HPP_INCLUDED
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

namespace quan{ namespace fun{

   template <typename T>
   struct size_seq_impl {}; 

   template <typename T>
   struct size_seq : size_seq_impl<
      typename std::remove_const<
         typename std::remove_reference<T>::type
      >::type
   >{};

    template <int N, typename T>
    struct size_seq_impl<T[N]> : std::integral_constant<std::size_t, N>{};

    template<typename ...Elements >
    struct size_seq_impl<std::tuple<Elements...> > : std::tuple_size<std::tuple<Elements...> >{};
         
}}//quan::fun
#endif
