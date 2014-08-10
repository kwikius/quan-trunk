#ifndef QUAN_FUN_SAME_SIZE_SEQS_HPP_INCLUDED
#define QUAN_FUN_SAME_SIZE_SEQS_HPP_INCLUDED

#include <quan/meta/eq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/meta/bool.hpp>

namespace quan{ namespace fun{

   template <typename SeqL, typename SeqR>
   struct same_size_seq : quan::meta::bool_<
      ((size_seq<SeqL>::value) == (size_seq<SeqR>::value)) 
   >{};

}}//quan::fun

#endif
