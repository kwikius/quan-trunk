#ifndef QUAN_FUN_DOT_PRODUCT_SEQ_HPP_INCLUDED
#define QUAN_FUN_DOT_PRODUCT_SEQ_HPP_INCLUDED

#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fun/inner_product_seq.hpp>

namespace quan{namespace fun{

   struct dot_product_seq{

      template <typename SeqL, typename SeqR>
      struct result : inner_product_seq:: template result<
         SeqL,SeqR,quan::operator_plus, quan::operator_times
      >{};

      template <typename SeqL,typename SeqR>
      typename result<SeqL,SeqR>::type
      operator()(SeqL const &seqL, SeqR const & seqR)const
      {
         return inner_product_seq()(seqL,seqR,quan::operator_plus(),quan::operator_times());
      }
      typedef dot_product_seq type;
   };

}}//quan::fun

#endif
