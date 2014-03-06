#ifndef QUAN_UAV_FLETCHER16_HPP_INCLUDED
#define QUAN_UAV_FLETCHER16_HPP_INCLUDED

#include <cstdint>

 // from http://en.wikipedia.org/wiki/Fletcher%27s_checksum

namespace quan{ namespace uav{
//!-!-!start-example
   uint16_t fletcher16( uint8_t const *data, uint32_t bytes )
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
