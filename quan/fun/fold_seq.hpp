
#ifndef QUAN_FUN_FOLD_SEQ_HPP_INCLUDED
#define QUAN_FUN_FOLD_SEQ_HPP_INCLUDED
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

#include <quan/fun/at_seq.hpp>
#include <quan/fun/auto_at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/meta/strip_cr.hpp>

namespace quan{ namespace fun{

   namespace detail{
   
      template<int I>
      struct fold_fun_seq_n;

      template<>
      struct fold_fun_seq_n<0>{
         template <typename Seq,typename T, typename F>
         struct result{
            typedef T lhs_type;
            typedef typename at_seq<0,Seq>::type rhs_type;
            typedef typename quan::meta::strip_cr<F>::type f_type;
            typedef typename f_type::template result<lhs_type,rhs_type>::type type;
         };

         template <typename Seq, typename T, typename F>
         constexpr 
         typename result<Seq,T,F>::type
         operator()(Seq && seq, T && t, F && f)const
         {
            typedef at_seq<0,Seq,as_value> at_type;
            return f(std::forward<T>(t),at_type{}(std::forward<Seq>(seq)));
         }
         typedef fold_fun_seq_n type;
      };
   
      template< int I>
      struct fold_fun_seq_n{
         template <typename Seq,typename T, typename F>
         struct result{
            typedef typename fold_fun_seq_n<I-1>:: template result<Seq,T,F>::type lhs_type;
            typedef typename at_seq<I,Seq,as_value>::type rhs_type;
            typedef typename quan::meta::strip_cr<F>::type f_type;
            typedef typename f_type::template result<lhs_type,rhs_type>::type type;
         };

         template <typename Seq,typename T, typename F>
         constexpr 
         typename result<Seq,T,F>::type
         operator()(Seq && seq,T && t, F && f)const
         {
             typedef fold_fun_seq_n<I-1> prev_type;
             typedef at_seq<I,Seq,as_value> at_type;
             return f(prev_type{}(std::forward<Seq>(seq),std::forward<T>(t),std::forward<F>(f)),at_type{}(std::forward<Seq>(seq)));
         }
         typedef fold_fun_seq_n type;
      };
   }
   
   struct fold_seq{
   
      template <typename Seq, typename T, typename F>
      struct result{
         static_assert(is_fun_sequence<Seq>::value,"error");
         typedef typename detail::fold_fun_seq_n<
            size_seq<Seq>::value-1
         >::template result<Seq,T,F>::type type;
      };

      template < typename Seq, typename T, typename F>
      // should be a value
      constexpr 
      typename result<Seq,T,F>::type
      operator()(Seq && seq, T&& t, F && f)const
      {
         typedef detail::fold_fun_seq_n<size_seq<Seq>::value -1 > ff;
         return ff{}(std::forward<Seq>(seq),std::forward<T>(t),std::forward<F>(f));
      }

      typedef fold_seq type;
   };
}}

#endif
