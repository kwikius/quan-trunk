#ifndef QUAN_META_EVAL_IF_HPP_INCLUDED
#define QUAN_META_EVAL_IF_HPP_INCLUDED
/*
 Copyright (c) 2006-2013 Andy Little 

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

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

#if 1

#include <quan/meta/type_sequence.hpp>

namespace quan{ namespace meta{

   namespace detail{
      template <typename ... T>
      struct eval_if_list;

      template <typename T>
      struct make_eval_if_list;

      template <typename ...T>
      struct make_eval_if_list< quan::meta::type_sequence<T...> >{
         typedef eval_if_list<T...> type;
      };

   }

     // e,g
   // eval_if_c<bool, Fun1, BoolFun2, Fun2, BooolFun3, Fun3,BoolFun4, Fun4, Fun5>
   template <bool b, typename FT, typename... Rest>
   struct eval_if_c {
      typedef typename FT::type type;
   };

   // e,g
   // eval_if_c<BoolFun1, Fun1, BoolFun2, Fun2, BooolFun3, Fun3,BoolFun4, Fun4, Fun5>
   template <typename C, typename FT, typename... Rest>
   struct eval_if : eval_if_c<C::type::value, FT, Rest...>{};

   template <typename FT, typename FF>
   struct eval_if_c<false,FT,FF> :FF{};

   template <typename FT, typename ... FF>
   struct eval_if_c<true, FT, quan::meta::detail::eval_if_list<FF...> > : FT{};

   template <typename FT, typename ...FF>
   struct eval_if_c<false, FT, quan::meta::detail::eval_if_list<FF...> > : eval_if_c<false,FT, FF...> {};

   template <typename FT, typename... FF>
   struct eval_if_c<false,FT,FF...> {
      typedef quan::meta::type_sequence<FF...> list;
      typedef typename quan::meta::front<list>::type cond;
      typedef typename quan::meta::pop_front<list>::type list1;
      typedef typename quan::meta::front<list1>::type FT1;
      typedef typename quan::meta::pop_front<list1>::type next_list;
      typedef typename detail::make_eval_if_list<next_list>::type eval_list;
      
      typedef typename eval_if<
         cond,
         FT1,
         eval_list
      >::type type;
   };

}} // quan::meta

#else

namespace quan{ namespace meta{
   
   template <bool B, typename TrueFunction, typename FalseFunction>
   struct eval_if_c{
      typedef typename TrueFunction::type type;
   };

   template <typename TrueFunction,typename FalseFunction>
   struct eval_if_c<false,TrueFunction,FalseFunction> {
      typedef typename FalseFunction::type type;
   };

   template<typename C, typename TrueFunction, typename FalseFunction>
   struct eval_if : eval_if_c<((C::type::value)!=0),TrueFunction,FalseFunction>{};
   
}}//quan::meta

#endif

#endif
