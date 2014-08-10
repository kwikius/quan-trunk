#ifndef QUAN_FUN_PUSH_BACK_SEQ_HPP_INCLUDED
#define QUAN_FUN_PUSH_BACK_SEQ_HPP_INCLUDED

#include <quan/fun/cons.hpp>

namespace quan{namespace fun{

 template <typename T, typename Seq>
   struct push_back_seq;

   template <typename T>
   struct push_back_seq<T,nil>{
      typedef cons<T> type;
   };

   template <typename T, typename TL, typename TR>
   struct push_back_seq<T,cons<TL,TR> >{
      typedef cons<T,cons<TL,TR> > type;
   };

}}

#endif
