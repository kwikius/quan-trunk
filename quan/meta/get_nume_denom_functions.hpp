#ifndef QUAN_META_GET_NUME_DENOM_FUNCTIONS_HPP_INCLUDED
#define QUAN_META_GET_NUME_DENOM_FUNCTIONS_HPP_INCLUDED

#include <quan/meta/rational.hpp>

namespace quan{ namespace meta{

   template <int64_t N, int64_t D>
   inline
   int64_t get_numerator(rational<N,D>)
   {
      return numerator<rational<N,D> >::value;
   }
   template <int64_t N, int64_t D>
   inline
   int64_t get_denominator(rational<N,D>)
   {
      return denominator<rational<N,D> >::value;
   }
   
}}//quan::meta

#endif
