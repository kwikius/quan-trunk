#ifndef QUAN_GCD_HPP_INCLUDED
#define QUAN_GCD_HPP_INCLUDED

namespace quan {

  template <typename TL, typename TR> 
   inline typename quan::meta::binary_op<TL,quan::meta::divides,TR>::type gcd(TL  n, TR  m)
   {
      if (n < TL{0})n = -n;
      if (m < TR{0})m = -m;

      for(;;) {
         if(m == TL{0})return n;
         n %= m;
         if(n == TR{0} )return m;
         m %= n;
      }
   }
}
#endif // QUAN_GCD_HPP_INCLUDED
