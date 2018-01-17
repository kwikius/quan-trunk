#ifndef QUAN_FUN_MAKE_FUN_SEQ1_HPP_INCLUDED1
#define QUAN_FUN_MAKE_FUN_SEQ1_HPP_INCLUDED1
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
#include <quan/fun/push_back_seq.hpp>
#include <quan/fun/as_vector.hpp>

namespace quan{ namespace fun{

   namespace detail{
      template <int I,typename F,typename Seq>
      struct make_fun_seq1_n;

      template <typename F,typename Seq>
      struct make_fun_seq1_n<0,F,Seq>{
         
         typedef typename at_seq<0,Seq>::type at_seq_type;
         typedef typename F:: template result<at_seq_type>::type fun_result_type;
         typedef typename push_back_seq<fun_result_type,nil>::type type;
      };

      template <int I,typename F,typename Seq>
      struct make_fun_seq1_n{
         
         typedef typename at_seq<I,Seq>::type at_seq_type;
         typedef typename F::template result<at_seq_type>::type fun_result_type;
         typedef typename make_fun_seq1_n<I-1,F,Seq>::type prev_type;
         typedef typename push_back_seq<fun_result_type,prev_type>::type type;
      };
   }//detail
   
   template <typename F,typename Seq>
   struct make_fun_seq1{

      static_assert(is_fun_sequence<Seq>::value,"error");
      
      typedef typename as_vector<
         typename detail::make_fun_seq1_n<
           (size_seq<Seq>::value -1) , F, Seq
         >::type
       >::type type;
   };
   
}}//quan::fun

#endif
