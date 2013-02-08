#ifndef QUAN_FUN_AT_HPP_INCLUDED
#define QUAN_FUN_AT_HPP_INCLUDED

#include <quan/fun/access_modifiers.hpp>
#include <type_traits>
#include <type_traits>

namespace quan{ namespace fun{

    template<int N, typename Seq, typename Access>
    struct at_seq_impl;

    template<int N, typename Seq, typename Access = as_value>
    struct at_seq : at_seq_impl<
      N,
      typename std::remove_const<
         typename std::remove_reference<Seq>::type
      >::type,
      Access
    >{};
      

}}//quan::fun

#endif
