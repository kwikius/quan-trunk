#ifndef QUAN_FUN_AS_VECTOR_HPP_INCLUDED
#define QUAN_FUN_AS_VECTOR_HPP_INCLUDED
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


#include <quan/fun/vector.hpp>

namespace quan{ namespace fun{

   template <typename  Seq>
   struct as_vector;

   template <typename ... T>
   struct as_vector<quan::meta::type_sequence<T...> >{
      typedef quan::fun::vector<T...> type;
   };

}}

#endif // QUAN_FUN_AS_VECTOR_HPP_INCLUDED
