#ifndef QUAN_FUN_RANGE_SEQ_HPP_INCLUDED
#define QUAN_FUN_RANGE_SEQ_HPP_INCLUDED
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
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/seq_arg_type.hpp>
#include <quan/meta/int32.hpp>
#include <quan/meta/bool.hpp>

namespace quan{namespace fun{

   // get a range of elements in a sequence

   template <typename Seq, int First,int Last>
   struct range_seq{
   
      static_assert(is_fun_sequence<Seq>::value,"error");
      static_assert(quan::meta::bool_< (Last < (size_seq<Seq>::value)) >::value,"error");
      static_assert(quan::meta::bool_< (First >= 0) >::value,"error");   
      static constexpr int size = (Last - First) + 1 ;
      static_assert(quan::meta::bool_< (size > 0) >::value,"error");
      typedef typename seq_arg_type<Seq>::type arg_type;
      
      arg_type m_seq;
      
      range_seq(arg_type seq_in)
      : m_seq(seq_in){}

   };
   
   template <typename Seq,int First,int Last>
   struct is_fun_sequence_impl<range_seq<Seq,First,Last> > : is_fun_sequence<Seq>{};
   
   template <typename Seq,int First,int Last>
   struct size_seq_impl<range_seq<Seq,First,Last> > : quan::meta::int32<
     (range_seq<Seq,First,Last>::size)
   >{};
   
   template <int I,typename Seq, int First, int Last, typename Access>
   struct at_seq_impl<I,range_seq<Seq,First,Last> ,Access>{
       static constexpr int real_pos = I + First;
       static_assert(quan::meta::bool_< (real_pos >= 0) >::value,"error");
       static_assert(quan::meta::bool_< (real_pos < size_seq<Seq>::value) >::value,"error"); 
       typedef typename at_seq<(real_pos),Seq,Access>::type type;
    
       typename at_seq<real_pos,Seq,as_ref>::type
       operator()(range_seq<Seq,First,Last> & seq) const
       {
         at_seq<real_pos,Seq, as_ref> at_seq_var;
         return at_seq_var(seq.m_seq);
       }
       
       type
      operator()(range_seq<const Seq,First,Last> const & seq) const
       {
         at_seq<real_pos,Seq, as_const_ref> at_seq_var;
         return (at_seq_var(seq.m_seq));
       }
   };
   
}}//quan::fun

#endif
