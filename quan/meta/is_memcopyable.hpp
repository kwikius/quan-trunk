#ifndef QUAN_META_IS_MEMCOPYABLE_HPP_INCLUDED
#define QUAN_META_IS_MEMCOPYABLE_HPP_INCLUDED
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

#include <quan/meta/bool/false.hpp>
#include <quan/meta/strip_cr.hpp>
#include <type_traits>

namespace quan{ namespace meta{
 
  namespace impl{
     
     template <typename T, typename Enable = void>
     struct is_memcopyable_impl : quan::meta::false{};
     
     template <typename T>
     struct is_memcopyable_impl<T, quan::where_<std::is_pod<T> > : quan::meta::true_{};

  }
  
  template <typename T> 
  struct is_mem_copyable : impl::is_memcopyable_impl<
    typename quan::meta::strip_cr<T>::type 
  >{};

}}


#endif // QUAN_META_IS_MEMCOPYABLE_HPP_INCLUDED
