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
      // Fails here if N is not a power of 2 e.g 2,4,6,8 etc
      static_assert( (N > 1) && ((N % 2) == 0),"invalid input for quan::meta::log_2");
   //##################################################################
      static constexpr uint32_t value = quan::meta::log2<N/2>::value + 1;
   };

}}

#endif // QUAN_META_LOG2_HPP_INCLUDED
