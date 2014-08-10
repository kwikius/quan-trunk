#ifndef QUAN_FUN_ARE_FUN_SEQUENCES_HPP_INCLUDED
#define QUAN_FUN_ARE_FUN_SEQUENCES_HPP_INCLUDED

#include <quan/fun/is_fun_sequence.hpp>
#include <quan/meta/and.hpp>

namespace quan{ namespace fun{

   template <typename TL,typename TR>
   struct are_fun_sequences : quan::meta::and_<
      is_fun_sequence<TL>,
      is_fun_sequence<TR>
   >{};

}}//quan::fun

#endif
