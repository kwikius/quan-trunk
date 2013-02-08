#ifndef QUAN_FUN_GET_FUN_SEQ1_HPP_INCLUDED
#define QUAN_FUN_GET_FUN_SEQ1_HPP_INCLUDED

#include <quan/fun/fun_seq1.hpp>
namespace quan{ namespace fun{

   template <typename F, typename Seq>
   inline
   fun_seq1<F,Seq>
   get_fun_seq1(F const & f, Seq & seq)
   {
      return fun_seq1<F,Seq>(f,seq);
   }
   template <typename F, typename Seq>
   inline
   fun_seq1<F,const Seq>
   get_fun_seq1(F const & f, Seq const & seq)
   {
      return fun_seq1<F,const Seq>(f,seq);
   }   
}}

#endif
