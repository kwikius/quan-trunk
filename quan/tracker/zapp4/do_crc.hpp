#ifndef QUAN_TRACKER_ZAPP4_DO_CRC_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_DO_CRC_HPP_INCLUDED

#include <quan/tracker/zapp4/crc.hpp>

namespace quan{ namespace tracker{ namespace zapp4{

   template <typename Packet>
   inline void do_crc(Packet & packet)
   {
      packet.values.crc = Packet::crc_seed;
      uint32_t constexpr n_iters = sizeof(Packet)/4U;
      uint32_t * arr = (uint32_t*) &packet.values.id;
      for ( uint32_t i = 0; i < n_iters; ++i){
         packet.values.crc = quan::tracker::zapp4::crc32(packet.values.crc,arr[i]);
      }
   }

}}} // quan::tracker::zapp4

#endif // QUAN_TRACKER_ZAPP4_DO_CRC_HPP_INCLUDED
