#ifndef QUAN_ACCESS_MODIFIERS_HPP_INCLUDED
#define QUAN_ACCESS_MODIFIERS_HPP_INCLUDED

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
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <type_traits>
#include <quan/meta/strip_cr.hpp>
#include <quan/meta/identity.hpp>

namespace quan{

    struct as_value{
      template <typename T>
      struct apply : quan::meta::strip_cr<T>{};

      template <typename T>
      typename apply<T>::type
      operator()(T in)const
      {
         return in;
      }
      typedef as_value type;
    };

   struct as_cvalue{
      template <typename T>
      struct apply : std::add_const<
         typename quan::meta::strip_cr<T>::type
      >{};

      template <typename T>
      typename apply<T>::type
      operator()(T in)const
      {
         return in;
      }

      typedef as_cvalue type;
    };

    struct as_ref{
      template <typename T>
      struct apply : std::add_reference<
         typename quan::meta::strip_cr<T>::type
      >{};

      template <typename T>
      typename apply<T>::type
      operator()(T & in)const
      {
         return in;
      }


      typedef as_ref type;

      template <typename T>
      struct result;

      template <typename T>
      struct result<as_ref(T)> : apply<T>{};
    };
   

    struct as_cref{
      template <typename T>
      struct apply : std::add_reference<
         typename std::add_const<
            typename std::remove_reference<T>::type
         >::type
      >{};

      template <typename T>
      typename apply<T>::type
      operator()(T const & in)const
      {
         return in;
      }
      typedef as_cref type;
    };

}//quan

#endif

