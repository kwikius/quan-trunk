#ifndef QUAN_FUN_ADD_SUBTRACT_OPS_HPP_INCLUDED
#define QUAN_FUN_ADD_SUBTRACT_OPS_HPP_INCLUDED
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

/*add subtract

*/
#include <quan/where.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fun/are_fun_sequences.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/make_fun_seq2.hpp>
#include <quan/fun/fun_seq2.hpp>
#include <quan/fun/partial_binary.hpp>

namespace quan{ namespace meta{

   namespace impl {

      template <typename SeqL, typename SeqR>
      struct binary_op_impl<
         SeqL,
         plus,
         SeqR,
         typename quan::where_<
            and_<
               quan::fun::are_fun_sequences<SeqL,SeqR>,
               quan::fun::same_size_seq<SeqL,SeqR>
            >
         >::type
      >{
         typedef typename quan::fun::make_fun_seq2<
           quan::operator_plus,SeqL,SeqR
         >::type type;
      };

      template <typename SeqL,typename SeqR>
      struct binary_op_impl<
         SeqL,
         minus,
         SeqR,
         typename quan::where_<
            and_<
               quan::fun::are_fun_sequences<SeqL,SeqR>,
               quan::fun::same_size_seq<SeqL,SeqR>
            >
         >::type
      >{
         typedef typename quan::fun::make_fun_seq2<
           quan::operator_minus,SeqL,SeqR
         >::type type;
      };

   }//impl

}}//quan::meta

namespace quan{namespace fun{

   template <typename SeqL, typename SeqR>
   inline
   typename quan::where_<
      quan::meta::and_<
         are_fun_sequences<SeqL,SeqR>,
         same_size_seq<SeqL,SeqR>
      >,
      typename quan::meta::binary_op<
         SeqL,quan::meta::plus,SeqR
      >::type
   >::type
   operator + ( SeqL const & seqL, SeqR const & seqR)
   {
      typedef fun_seq2<
         quan::operator_plus,const SeqL, const SeqR
      > init_type;
      
      return init_type(seqL,seqR);
   }

   template <typename SeqL, typename SeqR>
   inline 
   typename quan::where_<
      quan::meta::and_<
         are_fun_sequences<SeqL,SeqR>,
         same_size_seq<SeqL,SeqR>
      >,
      typename quan::meta::binary_op<
         SeqL,quan::meta::minus,SeqR
      >::type
   >::type
   operator -( SeqL const & seqL, SeqR const & seqR)
   {
      typedef fun_seq2<
         quan::operator_minus,const SeqL, const SeqR
      > init_type;

      return init_type(seqL,seqR);
   }
   
}}//


#endif
