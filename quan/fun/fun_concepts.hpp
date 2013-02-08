#ifndef QUAN_FUN_FUN_CONCEPTS_HPP_INCLUDED
#define QUAN_FUN_FUN_CONCEPTS_HPP_INCLUDED

#include <type_traits>

namespace quan{ namespace fun{

   template <typename Fun>
   struct is_fun : std::false_type{};

   template <typename Fun>
   struct num_args;

   template<typename Fun, int N>
   struct arg_mod;

   template <typename Fun>
   struct result_mod;

   template <typename Fun>
   struct returns_result;

}}//quan::fun

#endif
