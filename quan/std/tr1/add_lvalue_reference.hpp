#ifndef QUAN_STD_TR1_ADD_LVALUE_REFERENCE_HPP_INCLUDED
#define QUAN_STD_TR1_ADD_LVALUE_REFERENCE_HPP_INCLUDED
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

#include <quan/where.hpp>
#include <quan/std/tr1/is_reference.hpp>
#include <quan/meta/and.hpp>

namespace quan{namespace detail{

     template < typename T,typename Where = void>
     struct add_l_value_reference;

      template <typename T>
      struct add_l_value_reference<
         T,
         typename quan::meta::and_<
            typename quan::where_not<std::is_reference<T> >::type
             quan::meta::not_<std::is_same<T,void>
      >
      
}}

namespace std{

}

#endif // QUAN_STD_TR1_ADD_LVALUE_REFERENCE_HPP_INCLUDED
