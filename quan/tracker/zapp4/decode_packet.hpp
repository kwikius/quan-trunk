#ifndef QUAN_TRACKER_ZAPP4_DECODE_PACKET_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_DECODE_PACKET_HPP_INCLUDED

#include <quan/tracker/zapp4/crc_is_good.hpp>

namespace quan{ namespace tracker{ namespace zapp4{

   template <typename Packet,typename Parser >
   inline bool decode_packet( uint16_t const packet_length, Parser const & parser,void (*pfn)( Packet const & packet) )
   {
      if ( packet_length == sizeof(Packet)){
         Packet packet {parser};
         if(crc_is_good(packet)){
            pfn(packet);
            return true;
         }
      }
      return false;
   }

}}} // quan::tracker::zapp4

#endif // QUAN_TRACKER_ZAPP4_DECODE_PACKET_HPP_INCLUDED
