#ifndef QUAN_META_IS_RUNTIME_TYPE_HPP_INCLUDED
#define QUAN_META_IS_RUNTIME_TYPE_HPP_INCLUDED

 /*
 Copyright (c) 2006 - 2013 Andy Little 

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
 
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/remove_const.hpp>
#include <quan/std/tr1/remove_reference.hpp>
#endif

namespace quan{ namespace meta{

   namespace impl{
        template <typename T>
        struct is_runtime_type_impl : std::true_type{}; 
   }

   template <typename T>
   struct is_runtime_type : impl::is_runtime_type_impl<
      typename std::remove_const<
         typename std::remove_reference<T>::type
      >::type 
   >{};
      
}}

#endif
