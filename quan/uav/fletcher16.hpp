#ifndef QUAN_UAV_FLETCHER16_HPP_INCLUDED
#define QUAN_UAV_FLETCHER16_HPP_INCLUDED
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

#include <cstdint>

 // from http://en.wikipedia.org/wiki/Fletcher%27s_checksum

namespace quan{ namespace uav{
//!-!-!start-example
   inline uint16_t fletcher16( uint8_t const *data, uint32_t bytes )
   {
      uint16_t sum1 = 0xff, sum2 = 0xff;
      while (bytes) {
         uint8_t tlen = bytes > 20 ? 20 : bytes;
         bytes -= tlen;
         do {
            sum2 += sum1 += *data++;
         } while (--tlen);
         sum1 = (sum1 & 0xff) + (sum1 >> 8);
         sum2 = (sum2 & 0xff) + (sum2 >> 8);
      }
      /* Second reduction step to reduce sums to 8 bits */
      sum1 = (sum1 & 0xff) + (sum1 >> 8);
      sum2 = (sum2 & 0xff) + (sum2 >> 8);
      return sum2 << 8 | sum1;
   }
//!-!-!end-example
}}// quan::uav

#endif // QUAN_UAV_FLETCHER16_HPP_INCLUDED
