#ifndef QUAN_MINMAXPAIR_HPP_INCLUDED
#define QUAN_MINMAXPAIR_HPP_INCLUDED

#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>

namespace quan{ 

   template <typename Min, typename Max = Min>
   struct minmaxpair{
      minmaxpair(Min const & min_in, Max const & max_in)
      : min(min_in), max(max_in){}
      minmaxpair(){}
      Min min;
      Max max;
   };
   
   template <typename MinL, typename MaxL, typename MinR, typename MaxR>
   inline
   minmaxpair<
      typename quan::meta::binary_op<
         MinL,quan::meta::minus,MinR
      >::type,
       typename quan::meta::binary_op<
         MaxL,quan::meta::minus,MaxR
      >::type
   >
   operator -(minmaxpair<MinL,MaxL> const & lhs, minmaxpair<MinR,MaxR> const & rhs)
   { 
      typedef minmaxpair<
          typename quan::meta::binary_op<MinL,quan::meta::minus,MinR >::type,
          typename quan::meta::binary_op<MaxL,quan::meta::minus,MaxR>::type
      > result_type;
     return result_type(lhs.min - rhs.min,lhs.max- rhs.max);
   };
   
}

#endif
