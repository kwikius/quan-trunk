#ifndef QUAN_FUN_INNER_PRODUCT_SEQ_HPP_INCLUDED
#define QUAN_FUN_INNER_PRODUCT_SEQ_HPP_INCLUDED
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

#include <quan/fun/fun_seq2.hpp>
#include <quan/fun/make_fun_seq2.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/fold_seq.hpp>
#include <quan/static.hpp>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fun/are_fun_sequences.hpp>
#include <quan/fun/same_size_seq.hpp>
#include <quan/fun/static_monoid.hpp>

namespace quan{namespace fun{

   struct inner_product_seq{

      template <typename SeqL, typename SeqR, typename FF, typename F>
      struct result{
         static_assert( is_fun_sequence<SeqL>::value,"error : SeqL is not a fun_sequence" );
         static_assert( is_fun_sequence<SeqR>::value,"error : SeqR is not a fun_sequence" );
         static_assert( same_size_seq<SeqL,SeqR> ::value,"error");
         typedef typename quan::fun::make_fun_seq2<F,SeqL,SeqR>::type
         muxed_type;

         typedef typename static_monoid<
         FF,typename quan::fun::at_seq<0,muxed_type>::type
         >::type initialiser;

         typedef typename quan::fun::fold_seq::template result<
         muxed_type,initialiser,FF
         >::type type;
      };

      template <typename SeqL,typename SeqR, typename FF, typename F>
      constexpr
      typename result<SeqL,SeqR,FF,F>::type
      operator()(SeqL &&seqL, SeqR && seqR, FF && ff, F && f)const
      {
         typedef quan::fun::fun_seq2<
            F,SeqL,SeqR
         > mux_seq_type;

         typedef quan::fun::fold_seq folder;

         typedef typename static_monoid<
            FF,typename quan::fun::at_seq<0,mux_seq_type>::type
         >::type initialiser;
       
         return folder{}(mux_seq_type{std::forward<SeqL>(seqL),std::forward<SeqR>(seqR)},initialiser{},std::forward<FF>(ff)) ;
      }

      typedef inner_product_seq type;
   };

}}//quan::fun

#endif
