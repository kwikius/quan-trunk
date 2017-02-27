#ifndef QUAN_ARCHETYPES_META_STATIC_NUMERIC_HPP_INCLUDED
#define QUAN_ARCHETYPES_META_STATIC_NUMERIC_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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
 
/*
    StaticNumeric concept
*/
#include <quan/meta/bool.hpp>
#include <quan/meta/not.hpp>

#include <quan/meta/eq_zero.hpp>
#include <quan/meta/neq_zero.hpp>

namespace quan{namespace meta{


//    template <typename T>
//    struct neq_zero : not_<eq_zero<T> >{};

    template <typename T>
    struct eq_one : bool_<((T::value) ==1)>{};
    
    template <typename T>
    struct neq_one : not_<eq_one<T> >{};

   template <typename T>
   struct lt_zero : bool_<((T::value) < 0)>{};
   
   template <typename T>
   struct gt_zero : bool_<((T::value) > 0)>{};

   template <typename T>
   struct gte_zero : bool_<((T::value) >= 0)>{};
   
   template <typename T>
   struct lte_zero : bool_<((T::value) <= 0)>{};
    
}}

#endif
