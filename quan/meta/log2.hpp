#ifndef QUAN_META_LOG2_HPP_INCLUDED
#define QUAN_META_LOG2_HPP_INCLUDED

#include <cstdint>

 namespace quan { namespace meta{

   template <uint32_t N> struct log2;

   template <> struct log2<1> {
      static constexpr uint32_t value = 0;
   };

   template <uint32_t N > struct log2 {
   //#############################################################
      static_assert((N != 0) , "log2(N) is not defined for N = 0");
      static_assert((N % 2) == 0,"quan::meta::log_2(N) : N must be an integer power of 2");
   //##################################################################
      static constexpr uint32_t value = quan::meta::log2<N/2>::value + 1;
   };

}}

#endif // QUAN_META_LOG2_HPP_INCLUDED
