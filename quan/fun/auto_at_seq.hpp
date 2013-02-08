#ifndef QUAN_FUN_AUTO_AT_SEQ_HPP_INCLUDED
#define QUAN_FUN_AUTO_AT_SEQ_HPP_INCLUDED

#include <quan/fun/at_seq.hpp>
#include <type_traits>

namespace quan{ namespace fun{

   template<int N, typename Seq>
   struct auto_at_seq {
      typedef typename std::remove_const<
         typename std::remove_reference<Seq>::type
      >::type seq_type;
      typedef at_seq<N,seq_type,as_ref> access_modifier;
      typedef typename access_modifier::type type;
      
         type operator()(Seq & seq)
         {
            return access_modifier()(seq);
         }
      };
   
   template<int N, typename Seq>
   struct auto_at_seq<N,const Seq> {
      typedef typename std::remove_const<
         typename std::remove_reference<Seq>::type
      >::type seq_type;
      typedef at_seq<N,seq_type,as_const_ref> access_modifier;
      typedef typename access_modifier::type type;
      
      type operator()(Seq const & seq)
      {
         return access_modifier()(seq);
      }     
   };
  
   
}}

#endif
