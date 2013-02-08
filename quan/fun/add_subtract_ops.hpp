#ifndef QUAN_FUN_ADD_SUBTRACT_OPS_HPP_INCLUDED
#define QUAN_FUN_ADD_SUBTRACT_OPS_HPP_INCLUDED

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

   template <typename SeqL, typename SeqR>
   struct binary_op<
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
   struct binary_op<
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
