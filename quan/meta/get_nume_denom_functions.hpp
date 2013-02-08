#ifndef QUAN_META_GET_NUME_DENOM_FUNCTIONS_HPP_INCLUDED
#define QUAN_META_GET_NUME_DENOM_FUNCTIONS_HPP_INCLUDED

#include <quan/meta/rational.hpp>

namespace quan{ namespace meta{

   template <QUAN_INT32 N, QUAN_INT32 D>
   inline
   QUAN_INT32 get_numerator(rational<N,D>)
   {
      return numerator<rational<N,D> >::value;
   }
   template <QUAN_INT32 N, QUAN_INT32 D>
   inline
   QUAN_INT32 get_denominator(rational<N,D>)
   {
      return denominator<rational<N,D> >::value;
   }
   
}}//quan::meta

#endif
