#ifndef QUAN_STD_TR1_IS_BASE_OF_HPP_INCLUDED
#define QUAN_STD_TR1_IS_BASE_OF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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

#include <quan/config.hpp>
#ifdef QUAN_USE_QUAN_STD_TR1

#include <quan/meta/detail/is_base_of_impl.hpp>
#include <quan/meta/strip_cr.hpp>

namespace std{ 

   template <typename B, typename T>
   struct is_base_of {
      typedef typename quan::meta::detail::is_base_of_impl<
         typename quan::meta::strip_cr<B>::type,
         typename quan::meta::strip_cr<T>::type
      >::type type;
      static const bool value = type::value;
   };

}

#else
#include <type_traits>
#endif
#endif

