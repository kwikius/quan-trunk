#ifndef QUAN_FUN_MAKE_FUN_SEQ2_HPP_INCLUDED1
#define QUAN_FUN_MAKE_FUN_SEQ2_HPP_INCLUDED1

#include <quan/fun/at_seq.hpp>
#include <quan/fun/auto_at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/are_fun_sequences.hpp>
#include <quan/fun/push_back_seq.hpp>
#include <quan/fun/as_vector.hpp>
#include <quan/fun/same_size_seq.hpp>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace fun{

   namespace detail{
      template <int I,typename F,typename SeqL, typename SeqR>
      struct make_fun_seq2_n;

      //template <typename F,typename SeqL, typename SeqR>
      //struct make_fun_seq2_n<0,F,SeqL,SeqR>{
      //   
      //   typedef typename auto_at_seq<0,SeqL>::type lhs_type;
      //   typedef typename auto_at_seq<0,SeqR>::type rhs_type;
      //   typedef typename F:: template result<lhs_type,rhs_type>::type fun_result_type;
      //   typedef typename push_back_seq<fun_result_type,nil>::type type;
      //};

      template <int I,typename F,typename SeqL, typename SeqR>
      struct make_fun_seq2_n{
         
         typedef typename auto_at_seq<I,SeqL>::type lhs_type;
         typedef typename auto_at_seq<I,SeqR>::type rhs_type;
         typedef typename F::template result<lhs_type,rhs_type>::type fun_result_type;
         typedef typename quan::meta::eval_if_c<
            (I == 0),
            nil,
            make_fun_seq2_n<I-1,F,SeqL,SeqR>
         >::type prev_type;
        // typedef typename make_fun_seq2_n<I-1,F,SeqL,SeqR>::type prev_type;
         typedef typename push_back_seq<fun_result_type,prev_type>::type type;
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
