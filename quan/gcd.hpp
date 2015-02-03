#ifndef QUAN_GCD_HPP_INCLUDED
#define QUAN_GCD_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
