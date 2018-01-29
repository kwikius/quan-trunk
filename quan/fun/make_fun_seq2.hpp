#ifndef QUAN_FUN_MAKE_FUN_SEQ2_HPP_INCLUDED1
#define QUAN_FUN_MAKE_FUN_SEQ2_HPP_INCLUDED1
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
#include <quan/meta/type_sequence.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/auto_at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/are_fun_sequences.hpp>

#include <quan/fun/as_vector.hpp>
#include <quan/fun/same_size_seq.hpp>


namespace quan{ namespace fun{

   namespace detail{
      template <int I,typename F,typename SeqL, typename SeqR>
      struct make_fun_seq2_n;

      template <int I,typename F,typename SeqL, typename SeqR>
      struct make_fun_seq2_n{
         
         typedef typename auto_at_seq<I,SeqL>::type lhs_type;
         typedef typename auto_at_seq<I,SeqR>::type rhs_type;
         typedef typename F::template result<lhs_type,rhs_type>::type fun_result_type;
         typedef typename quan::meta::eval_if_c<
            ( I > 0)
            ,make_fun_seq2_n<I-1,F,SeqL,SeqR>
            ,quan::meta::type_sequence<>
         >::type prev_type;
         typedef typename quan::meta::push_back<prev_type,fun_result_type>::type type;
      };
   }//detail
   
   template <typename F,typename SeqL, typename SeqR>
   struct make_fun_seq2{

      static_assert(are_fun_sequences<SeqL,SeqR>::value, "error");
      static_assert(same_size_seq<SeqL,SeqR>::value ,"error");
      
      typedef typename as_vector<
         typename detail::make_fun_seq2_n<
           (size_seq<SeqL>::value -1) , F, SeqL,SeqR
         >::type
       >::type type;
   };
   
}}//quan::fun

#endif
