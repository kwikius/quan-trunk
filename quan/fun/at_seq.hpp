#ifndef QUAN_FUN_AT_HPP_INCLUDED
#define QUAN_FUN_AT_HPP_INCLUDED
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

#include <quan/fun/access_modifiers.hpp>
#include <type_traits>
#include <tuple>

namespace quan{ namespace fun{

    template<int I, typename Seq, typename Access>
    struct at_seq_impl;

    template<int I, typename Seq, typename Access = as_value>
    struct at_seq : at_seq_impl<
      I,
      typename std::remove_const<
         typename std::remove_reference<Seq>::type
      >::type,
      Access
    >{};

    template <int I, int N, typename T, typename Access>
    struct at_seq_impl<I, T[N], Access>{
        
        typedef typename Access:: template result<T>::type type;

        constexpr type operator() ( T(&in)[N])
        {  static_assert( I < N, "array index out of range");
           return in[I];
        }

    };

    template <int I, int N, typename T, typename Access>
    struct at_seq_impl<I, T const[N], Access>{
        typedef T const & type;
        constexpr T const & operator() ( T const(&in)[N])
        {  static_assert( I < N, "array index out of range");
           return in[I];
        }

    };

    template<int I, typename ...Elements , typename Access>
    struct at_seq_impl<I,std::tuple<Elements...>, Access>{

        typedef typename std::tuple_element<I, std::tuple<Elements...> >::type tuple_element_type;
         
        typedef typename Access:: template result<tuple_element_type>::type type;

        constexpr type operator() ( std::tuple<Elements...> & in)
        {
           return std::get<I>(in);
        }

        typedef typename as_const_ref:: template result<tuple_element_type>::type const_type;
        constexpr const_type operator() ( std::tuple<Elements...> const & in)
        {
           return std::get<I>(in);
        }
        
    };

}}//quan::fun

#endif
