#ifndef QUAN_TRACKER_ZAPP4_CRC_IS_GOOD_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_CRC_IS_GOOD_HPP_INCLUDED

#include <quan/tracker/zapp4/do_crc.hpp>

namespace quan{ namespace tracker{ namespace zapp4{

   template <typename Packet>
   inline
   bool crc_is_good(Packet & packet)
   {
      uint32_t const crc_read = packet.values.crc;
      do_crc(packet);
      return packet.values.crc == crc_read;
   }

}}} // quan::tracker::zapp4

#endif // QUAN_TRACKER_ZAPP4_CRC_IS_GOOD_HPP_INCLUDED
