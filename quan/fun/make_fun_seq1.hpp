#ifndef QUAN_FUN_MAKE_FUN_SEQ1_HPP_INCLUDED1
#define QUAN_FUN_MAKE_FUN_SEQ1_HPP_INCLUDED1

#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/push_back_seq.hpp>
#include <quan/fun/as_vector.hpp>
>

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
