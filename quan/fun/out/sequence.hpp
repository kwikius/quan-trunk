#ifndef QUAN_FUN_OUT_SEQUENCE_HPP_INCLUDED
#define QUAN_FUN_OUT_SEQUENCE_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/for_each.hpp>
#include <quan/fun/output.hpp>
#include <iostream>

namespace quan{namespace fun{

   template <typename Seq>
   typename quan::where_<
      is_fun_sequence<Seq>,
      std::ostream &
   >::type
   operator << ( std::ostream & os, Seq const & seq)
   {
      os << '[';for_each_and_last(seq,output(os,','),output(os,']'));
      return os;
   }

   template <typename Seq>
   typename quan::where_<
      is_fun_sequence<Seq>,
      std::ostream &
   >::type
   operator << ( std::ostream & os, Seq & seq)
   {
      os << '['; for_each_and_last(seq,output(os,','),output(os,']'));
      return os;
   }

}}//quan::fun

#endif
