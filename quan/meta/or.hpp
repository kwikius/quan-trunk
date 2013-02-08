#ifndef QUAN_META_OR_HPP_INCLUDED
#define QUAN_META_OR_HPP_INCLUDED

// Copyright Andrew Little 2006-2007


#include <type_traits>
#include <quan/meta/eval_if.hpp>

namespace quan{namespace meta{

   template <typename Lhs,typename ... Args> struct or_ : eval_if< Lhs, std::true_type, or_<Args...> >::type{};

   template<typename C1, typename C2>
   struct or_<C1,C2>: eval_if<
      C1,
      std::true_type,
      C2
   >::type{};

}}

#endif
