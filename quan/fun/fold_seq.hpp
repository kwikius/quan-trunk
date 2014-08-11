
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
            typedef typename F::template result<lhs_type,rhs_type>::type type;
         };

         template <typename Seq, typename T, typename F>
         typename result<Seq,T,F>::type
         operator()(Seq const & seq, T t, F const & f)const
         {
            at_seq<0,Seq,as_const_ref> at;
            return f(t,at(seq));
         }

         template <typename Seq, typename T, typename F>
         typename result<Seq,T,F>::type
         operator()(Seq & seq, T t, F const & f)const
         {
            auto_at_seq<0,Seq> at;
            return f(t,at(seq));
         }
         typedef fold_fun_seq_n type;
      };
   
      template< int I>
      struct fold_fun_seq_n{
         template <typename Seq,typename T, typename F>
         struct result{
            typedef typename fold_fun_seq_n<I-1>:: template result<Seq,T,F>::type lhs_type;
            typedef typename at_seq<I,Seq>::type rhs_type;
            typedef typename F::template result<lhs_type,rhs_type>::type type;
         };

         template <typename Seq,typename T, typename F>
         typename result<Seq,T,F>::type
         operator()(Seq const & seq,T t, F const & f)const
         {
           // fold_fun_seq_n<I-1> prev;
           // typename fold_fun_seq_n<I-1>::template result<Seq,T,F>::type lhs = prev(seq,t,f);
           // auto_at_seq<I,const Seq> at;
           // return f(lhs,at(seq));
            //return f(prev(seq,t,f),at(seq));
             typedef  fold_fun_seq_n<I-1> prev_type;
             typedef auto_at_seq<I,const Seq> at_type;
             return f(prev_type()(seq,t,f),at_type()(seq));
         }

         template <typename Seq,typename T, typename F>
         typename result<Seq,T,F>::type
         operator()(Seq & seq,T t, F const & f)const
         {
            //fold_fun_seq_n<I-1> prev;
            //typename fold_fun_seq_n<I-1>::template result<Seq,T,F>::type lhs = prev(seq,t,f);
            //auto_at_seq<I,Seq> at;
            ////return f(prev(seq,t,f),at(seq));
            //return f(lhs,at(seq));
             typedef  fold_fun_seq_n<I-1> prev_type;
             typedef auto_at_seq<I,Seq> at_type;
             return f(prev_type()(seq,t,f),at_type()(seq));
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
      typename result<Seq,T,F>::type
      operator()(Seq const & seq, T t, F const & f)const
      {
         
         enum {dummy = size_seq<Seq>::value};
         enum {size = dummy - 1};
         detail::fold_fun_seq_n<size> ff;
         return ff(seq,t,f);
      }

      template < typename Seq, typename T, typename F>
      typename result<Seq,T,F>::type
      operator()(Seq & seq, T t, F const & f)const
      {
         
         enum {dummy = size_seq<Seq>::value};
         enum {size = dummy - 1};
         detail::fold_fun_seq_n<size> ff;
         return ff(seq,t,f);
      }
      typedef fold_seq type;
   };
}}

#endif
