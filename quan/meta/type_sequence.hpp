#ifndef QUAN_META_TYPE_SEQUENCE_HPP_INCLUDED
#define QUAN_META_TYPE_SEQUENCE_HPP_INCLUDED
/*
 Copyright (c) 2003-2017 Andy Little.

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

#include <quan/concepts/meta/type_sequence.hpp>

#include <quan/is_model_of.hpp>
#include <quan/where.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/undefined.hpp>
#include <quan/meta/eval_if_else.hpp>

namespace quan{ namespace meta{

   template <typename ... T> struct type_sequence{
      typedef type_sequence type;
      static const uint32_t length = sizeof...(T);
   };

   template <> struct type_sequence<>{
     typedef type_sequence type;
     static const uint32_t length = 0;
   };

}}

namespace quan{ namespace impl{

   template <typename ...T>
   struct is_model_of_impl<
      quan::meta::TypeSequence_,
      quan::meta::type_sequence<T...> 
   > : quan::meta::true_{};
}}


namespace quan{ namespace meta{

    namespace impl{

       template <typename ... T>
       struct get_num_elements_impl<
            quan::meta::type_sequence<T...>
       > : quan::meta::int32< (sizeof...(T) )>{};
    }

   template <typename T>
   struct push_back<type_sequence<>,T >{
      typedef type_sequence<T> type;
   };

   template <typename ... L, typename T>
   struct push_back<type_sequence<L...>,T >{
      typedef type_sequence<L...,T> type;
   };

   template <typename Front, typename ... List>
   struct pop_front<type_sequence<Front,List...> >
   {
      typedef type_sequence<List...> type;
   };

   template <>
   struct pop_front<type_sequence<> >
   {
      // could just be empty_list?
      typedef quan::undefined type;
   };

   template <typename...L, typename T>
   struct push_front<type_sequence<L...> , T>
   {
       typedef type_sequence<T,L...> type;
   };

   template < typename Front, typename... List> 
   struct front<type_sequence<Front,List...> >
   {
      typedef Front type;
   };

   template < typename Front> 
   struct front<type_sequence<Front> >
   {
      typedef Front type;
   };

   template <>
   struct front<type_sequence<> >
   {
      // could just be empty_list?
      typedef quan::undefined type;
   };

   template < typename Front ,typename... List> 
   struct back< type_sequence<Front,List...> >
   {
      typedef typename back<type_sequence<List...> >::type type;
   };

   template < typename Back> 
   struct back< type_sequence<Back> >
   {
      typedef Back type;
   };

   template <>
   struct back<type_sequence<> >
   {
      // could just be empty_list?
      typedef quan::undefined type;
   };

   namespace detail {

      template <uint32_t N,typename List, typename other_list = type_sequence<> >
      struct type_sequence_get_first_n{
         
         typedef typename front<List>::type first_type;
         typedef typename pop_front<List>::type rest_type;
         typedef typename push_back<other_list,first_type>::type result_list_type;
         typedef typename quan::meta::eval_if_else_c<
            result_list_type::length == N,
            result_list_type,
            type_sequence_get_first_n<N,rest_type,result_list_type>
         >::type type;
      };
   }

   template<typename... List>
   struct pop_back<type_sequence<List...> >{
      typedef type_sequence<List...> list_type;
      typedef typename detail::type_sequence_get_first_n<list_type::length-1,list_type>::type type;
   };

   template< typename Last>
   struct pop_back<type_sequence<Last> >{
       typedef type_sequence<> type;
   };

   template <>
   struct pop_back<type_sequence<> >
   {
      typedef quan::undefined type;
   };

   template <uint32_t N, typename... List>
   struct at<N,type_sequence<List...> >{
       typedef type_sequence<List...> list_type;
       static_assert(N < list_type::length,"index out of range in quan::meta::type_sequence");
       typedef typename quan::meta::eval_if_else_c<
            N==0,
            quan::meta::front<list_type>,
            quan::meta::at<N-1,typename quan::meta::pop_front<list_type>::type>
       >::type type; 
   };

   template <uint32_t N>
   struct at<N,type_sequence<> >{
      typedef quan::undefined type;
   };
   
}}

#endif // QUAN_META_TYPE_SEQUENCE_HPP_INCLUDED
