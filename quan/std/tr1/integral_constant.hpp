#ifndef QUAN_STD_TR1_INTEGRAL_CONSTANT_HPP_INCLUDED
#define QUAN_STD_TR1_INTEGRAL_CONSTANT_HPP_INCLUDED 

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

namespace std{

   template <class T, T v>
   struct integral_constant{
      static const T value = v;
      typedef T value_type;
      typedef integral_constant<T,v> type;
   };

  /*struct true_type : integral_constant<bool, true>{} ;
  struct false_type : integral_constant<bool, false>{};*/

   typedef integral_constant<bool, true> true_type;
   typedef integral_constant<bool, false> false_type;

}

#else
#include <type_traits>
#endif
#endif



