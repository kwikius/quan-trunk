#ifndef QUAN_TRACKER_ZAPP4_CRC_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_CRC_HPP_INCLUDED

#include <cstdint>

namespace quan{ namespace tracker{ namespace zapp4{

// naive crc32 Ethernet algorithm
// todo verify against the stm32 hardware
   inline uint32_t crc32(uint32_t crc, uint32_t data)
   {
      crc = crc ^ data;
      for ( uint32_t i = 0U; i < 32U; ++i){
         if (crc & (1 << 31)){
            crc =  (crc << 1) ^ 0x4c11db7;
         }else{
            crc <<= 1;
         }
      }
      return crc;
   }

}}} // quan::tracker::zapp4

#endif // QUAN_TRACKER_ZAPP4_CRC_HPP_INCLUDED
