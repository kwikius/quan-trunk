#ifndef QUAN_UAV_DO_CHECKSUM_HPP_INCLUDED
#define QUAN_UAV_DO_CHECKSUM_HPP_INCLUDED

#include <cstdint>

namespace quan{ namespace uav{
/*
do checksum. All bytes except last which is used to hold checksum if creating
 and not read if checking
*/
   template< uint32_t len>
   inline
   uint8_t do_checksum(uint8_t (&ar)[len])
   {
      uint8_t sum = ar[0];
      for ( uint32_t i = 1; i < (len-1);++i)
     {
        uint16_t sum1 = static_cast<uint16_t>(sum )  + static_cast<uint16_t>( ar[i]);
        sum += sum1 + (sum1 >> 8);
     }
     return sum;
   }
}}



#endif // QUAN_UAV_DO_CHECKSUM_HPP_INCLUDED
