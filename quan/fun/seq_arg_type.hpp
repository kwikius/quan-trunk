#ifndef QUAN_FUN_SEQ_ARG_TYPE_HPP_INCLUDED
#define QUAN_FUN_SEQ_ARG_TYPE_HPP_INCLUDED

#include <type_traits>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/size_seq.hpp>


namespace quan{namespace fun{

   template <typename Seq>
   struct seq_arg_type{
    
      typedef typename std::add_reference<
         Seq
      >::type type;
   };

   template <typename Seq>
   struct seq_arg_type<const Seq>{
    
      typedef typename std::add_reference<
         typename std::add_const<Seq>::type
      >::type type;
   };

}}

#endif
