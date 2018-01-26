#ifndef QUAN_FUN_FUN_SEQ1_HPP_INCLUDED
#define QUAN_FUN_FUN_SEQ1_HPP_INCLUDED
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
#include <quan/fun/access_modifiers.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/seq_arg_type.hpp>
#include <quan/meta/int32.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/bool.hpp>
#include <type_traits>

namespace quan{namespace fun{

   // combine a seq with a function to apply to each
   // element, use to init make_fun_seq1<F,Seq>::type
   // as result
   template <typename F,typename Seq>
   struct fun_seq1{
   
      static_assert(is_fun_sequence<Seq>::value,"error");
      static constexpr int size = size_seq<Seq>::value;
      
      static_assert(size > 0,"error");
      F const & f;
      typedef typename seq_arg_type<Seq>::type arg_type;

      arg_type m_seq;

      typedef typename quan::meta::if_<
         std::is_const<Seq>,
         as_const_ref,
         as_ref
      >::type access_type;

      fun_seq1(F const & f_in, arg_type seq_in)
      : f(f_in),m_seq(seq_in){}

      fun_seq1(arg_type seq_in)
      : f(F()),m_seq(seq_in){}
   };
   
   template <typename F,typename Seq>
   struct is_fun_sequence_impl<fun_seq1<F,Seq> > : quan::meta::bool_<true>{};
   
   template <typename F,typename Seq>
   struct size_seq_impl<fun_seq1<F,Seq> > : quan::meta::int32<
     (fun_seq1<F,Seq>::size)
   >{};
   
   template <int I,typename F,typename Seq, typename Access>
   struct at_seq_impl<I,fun_seq1<F,Seq> ,Access>{
   
       typedef typename at_seq<I,Seq,as_value>::type at_seq_type;
       
       typedef typename F::template result<at_seq_type>::type type;
      
     // typename at_seq<I,Seq,as_const_ref>::type
      type
      operator()(fun_seq1<F,Seq> const & seq) const
       {

         at_seq<I,Seq, as_const_ref> at_seq_var;
         return seq.f(at_seq_var(seq.m_seq));
       }

       typename at_seq<I,Seq,as_ref>::type
       operator()(fun_seq1<F,Seq> & seq) const
       {
         at_seq<I,Seq, as_ref> at_seq_var;
         return seq.f(at_seq_var(seq.m_seq));
       }
   };
   
}}//quan::fun

#endif
