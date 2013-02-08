#ifndef QUAN_FUN_AT_HPP_INCLUDED1
#define QUAN_FUN_AT_HPP_INCLUDED1

#include <quan/fun/at_seq.hpp>
#include <quan/fun/access_modifiers.hpp>

namespace quan{ namespace fun{

   template <int I,typename T>
   typename at_seq<I,T>::type
   at(T const & in)
   {
      return at_seq<I,T,as_const_ref>()(in);
   }

   template <int I,typename T>
   typename at_seq<I,T>::type
   at(T & in)
   {
      return at_seq<I,T,as_ref>()(in);
   }

   template <size_t I,typename T, size_t N>
   T at( T (& ar)[N])
   {
      return ar[I];
   }
  
}}//quan::fun

#endif
