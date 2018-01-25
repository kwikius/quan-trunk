#ifndef QUAN_FUN_ACCESS_MODIFIERS_HPP_INCLUDED
#define QUAN_FUN_ACCESS_MODIFIERS_HPP_INCLUDED

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

namespace quan{namespace fun{

   struct as_value{

      template <typename T>
      struct result{
         typedef typename std::remove_const< 
            typename std::remove_reference<T>::type
         >::type type;
      };

      template <typename T>
      constexpr 
      typename result<T>::type
      operator()(T in)const
      {
         return in;
      }

      typedef as_value type;
   };

   struct as_const_value{

      template <typename T>
      struct result{
         typedef typename std::add_const<T>::type type;
      };

      template <typename T>
      constexpr
      typename result<T>::type
      operator()(T const in)const
      {
         return in;
      }

      typedef as_const_value type;
   };

   struct as_const_ref{

      template <typename T>
      struct result{
         typedef typename std::add_lvalue_reference<
            typename std::add_const<T>::type
         >::type type;
      };

      template <typename T>
      constexpr
      typename result<T>::type
      operator()(T const & in)const
      {
         return in;
      }

      typedef as_const_ref type;
   };

   struct as_ref{

      template <typename T>
      struct result{
         typedef typename std::add_lvalue_reference<
            typename std::remove_const<T>::type
         >::type type;
      };

      template <typename T>
      constexpr
      typename result<T>::type
      operator()(T & in)const
      {
         return in;
      }

      typedef as_ref type;
   };

   template <typename AcessF>
   struct add_const_to_ref;

   template<>
   struct add_const_to_ref<as_ref> : as_const_ref {};

   template<>
   struct add_const_to_ref<as_const_ref> : as_const_ref{};

   template<>
   struct add_const_to_ref<as_value> : as_value{};

   struct as_pointer{

      template <typename T>
      struct result{
         typedef typename std::remove_const<T>::type * type;
      };

      template <typename T>
      constexpr
      typename result<T>::type
      operator()(T & in)const
      {
         return &in;
      }

      typedef as_pointer type;
   };

}}//quan::fun

#endif
