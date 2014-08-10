#ifndef QUAN_FUN_ACCESS_TYPE_SEQ_HPP_INCLUDED
#define QUAN_FUN_ACCESS_TYPE_SEQ_HPP_INCLUDED

#include <quan/meta/strip_cr.hpp>

namespace quan{ namespace fun{

   template <typename Seq>
   struct access_type_seq_impl {
      typedef  typename Seq::access_type type;
   };
   
   template <typename Seq>
   struct access_type_seq : access_type_seq_impl<
      typename quan::meta::strip_cr<Seq>::type
      >::type
   >{};
}}
#endif
