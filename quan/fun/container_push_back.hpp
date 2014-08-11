#ifndef QUAN_FUN_CONTAINER_FUN_PUSH_BACK_HPP_INCLUDED
#define QUAN_FUN_CONTAINER_FUN_PUSH_BACK_HPP_INCLUDED
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

#include <quan/fun/container_fun_adapt1_macro.hpp>

namespace quan{ namespace fun{namespace impl_detail{

      template <typename Container>
      struct push_back_{
      Container & c;
      push_back_(Container & c_in):c(c_in){}

      template <typename T>
      struct result{
         typedef void type;
      };
      template <typename T>
      typename result<T>::type
      operator()(T const & t)const
      {
         return c.push_back(t);
      }
   };

   template <typename Fun, typename Container>
      struct push_back_fun{
      Container & c;
      Fun const & f;
      push_back_fun(Fun const & f_in,Container & c_in):f(f_in),c(c_in){}

      template <typename T>
      struct result{
         typedef void type;
      };
      template <typename T>
      typename result<T>::type
      operator()(T const & t)const
      {
         return c.push_back(f(t));
      }
   };
   
}
// function returns a functor
// this means you dont need parameters
// on the functor as you would when using direct
template <typename Container>
inline
impl_detail::push_back_<Container> push_back(Container & c)
{
   return impl_detail::push_back_<Container>(c);
}

template <typename F,typename Container>
inline
impl_detail::push_back_fun<F,Container> push_back(F const & f,Container & c)
{
   return impl_detail::push_back_fun<F,Container>(f,c);
}
}}

#endif
