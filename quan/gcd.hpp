#ifndef QUAN_GCD_HPP_INCLUDED
#define QUAN_GCD_HPP_INCLUDED

namespace quan {

  template <typename TL, typename Tr> 
   inline typename <quan::meta::binary_op<TL,quan::meta::divides,Tr>::type gcd(TL n, TL m)
   {
      if (n < 0)n = -n;
      if (m < 0)m = -m;

      for(;;) {
         if(m == 0)return n;
         n %= m;
         if(n == 0 )return m;
         m %= n;
      }
   }
}
#endif // QUAN_GCD_HPP_INCLUDED
