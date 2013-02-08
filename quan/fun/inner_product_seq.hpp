#ifndef QUAN_FUN_INNER_PRODUCT_SEQ_HPP_INCLUDED
#define QUAN_FUN_INNER_PRODUCT_SEQ_HPP_INCLUDED

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
          static_assert( are_fun_sequences<SeqL,SeqR>::value,"error" );
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
      typename result<SeqL,SeqR,FF,F>::type
      operator()(SeqL &seqL, SeqR & seqR, FF const & ff, F const & f)const
      {
         typedef quan::fun::fun_seq2<
            F,SeqL,SeqR
         > mux_seq_type;

         quan::fun::fold_seq folder;

         typedef typename static_monoid<
            FF,typename quan::fun::at_seq<0,mux_seq_type>::type
         >::type initialiser;
       
         return folder(mux_seq_type(seqL,seqR),initialiser(),ff) ;
      }
      typedef inner_product_seq type;
   };

}}//quan::fun

#endif
