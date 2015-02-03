#ifndef QUAN_TUPLE_NUM_ELEMENTS_HPP_INCLUDED
#define QUAN_TUPLE_NUM_ELEMENTS_HPP_INCLUDED
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

#include <quan/concepts/tuple.hpp>
#include <quan/meta/strip_cr.hpp>

namespace quan{ namespace tuple{

   namespace impl{

      template <typename T, typename Where = void>
      struct num_elements_impl{}; 
   }

   template <typename T>
   struct num_elements : impl::num_elements_impl<
      typename quan::meta::strip_cr<T>::type
   >{};

}}//quan::tuple

#endif

