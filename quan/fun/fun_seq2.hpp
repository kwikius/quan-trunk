#ifndef QUAN_FUN_FUN_SEQ2_HPP_INCLUDED
#define QUAN_FUN_FUN_SEQ2_HPP_INCLUDED
#include <quan/meta/int32.hpp>
#include <quan/fun/make_fun_seq2.hpp>
#include <quan/fun/access_type_seq.hpp>
#include <quan/fun/seq_arg_type.hpp>

namespace quan{namespace fun{

   // combine two seqs with a binary function to apply to each
   // element, use to init make_fun_seq2<F,SeqL, SeqR>::type
   // as result
   // a
   template <typename F,typename SeqL, typename SeqR>
   struct fun_seq2{
      
      typedef as_value access_type;
      // type of resulting sequence
     // typedef typename make_fun_seq2<F,SeqL,SeqR>::type type;
   
      static_assert( are_fun_sequences<SeqL,SeqR>::value,"must be fun_seq" );
      static_assert( same_size_seq<SeqL,SeqR>::value, "must be same size" );
      enum {
         size = (size_seq<SeqL>::value )
      };
      typedef typename seq_arg_type<SeqL>::type lhs_arg_type;
      typedef typename seq_arg_type<SeqR>::type rhs_arg_type;

 /*     SeqL const & seqL;
      SeqR const & seqR;
      
      fun_seq2(SeqL const & seqL_in, SeqR const & seqR_in)
      : seqL(seqL_in),seqR(seqR_in){}*/
      
      lhs_arg_type seqL;
      rhs_arg_type seqR;
      
      fun_seq2(lhs_arg_type seqL_in, rhs_arg_type seqR_in)
      : seqL(seqL_in),seqR(seqR_in){}
      
   };
  
   template <typename F,typename SeqL, typename SeqR>
   struct is_fun_sequence_impl<fun_seq2<F,SeqL,SeqR> > : std::true_type{};
   
   template <typename F,typename SeqL, typename SeqR>
   struct size_seq_impl<fun_seq2<F,SeqL,SeqR> > : quan::meta::int32<
     (fun_seq2<F,SeqL,SeqR>::size)
   >{};
   
   template <int I,typename F,typename SeqL, typename SeqR, typename Access>
   struct at_seq_impl<I,fun_seq2<F,SeqL,SeqR> ,Access>{
   
       typedef typename at_seq<I,SeqL,as_const_ref>::type lhs_type;
       typedef typename at_seq<I,SeqR,as_const_ref>::type rhs_type;       
       typedef typename F::template result<lhs_type,rhs_type>::type type;
       
       type operator()(fun_seq2<F,SeqL,SeqR>  & seq) const
       {
         int x= 1;
         auto_at_seq<I,SeqL> lhs_f;
         auto_at_seq<I,SeqR> rhs_f;
         F f;
         return f(lhs_f(seq.seqL),rhs_f(seq.seqR));
       }

       type operator()(fun_seq2<F,SeqL,SeqR> const & seq) const
       {
         typedef typename quan::meta::if_<
            std::is_same<
               typename access_type_seq<SeqL>::type,
               as_ref
            >,
            as_value,
            as_const_ref
         >::type lhs_access;
         typedef typename quan::meta::if_<
            std::is_same<
               typename access_type_seq<SeqR>::type,
               as_ref
            >,
            as_value,
            as_const_ref
         >::type rhs_access;
         at_seq<I,SeqL,lhs_access> lhs_f;
         at_seq<I,SeqR,rhs_access> rhs_f;
         F f;
         return f(lhs_f(seq.seqL),rhs_f(seq.seqR));
       }
   };
   
}}//quan::fun

#endif
