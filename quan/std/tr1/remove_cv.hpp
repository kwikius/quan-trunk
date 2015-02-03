#ifndef QUAN_STD_TR1_REMOVE_CV_HPP_INCLUDED
#define QUAN_STD_TR1_REMOVE_CV_HPP_INCLUDED

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

#include <quan/std/tr1/remove_const.hpp>
#include <quan/std/tr1/remove_volatile.hpp>

namespace std{ 

   template<typename T>
   struct remove_cv : remove_const<
      typename remove_volatile<T>::type
   >{};
}

#else
#include <type_traits>
#endif

#endif

