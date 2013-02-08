#ifndef QUAN_META_AND_HPP_INCLUDED
#define QUAN_META_AND_HPP_INCLUDED

// Copyright Andrew Little 2006-2007

#include <type_traits>
#include <quan/meta/eval_if.hpp>

namespace quan{namespace meta{
   
   template<typename Lhs, typename... Args > struct and_ : eval_if<
      Lhs, and_<Args...>, std::false_type
   >::type {};
     
   template<typename C1, typename C2>
   struct and_<C1,C2>: eval_if<
      C1,C2,
      std::false_type
   >::type{};

}}

#endif
