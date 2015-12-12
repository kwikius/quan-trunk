#ifndef QUAN_TRACKER_ZAPP4_POSITION_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_POSITION_HPP_INCLUDED

#include <quan/uav/position.hpp>
#include <quan/tracker/zapp4/ids.hpp>
#include <quan/tracker/detail/normalise_angle.hpp>
#include <quan/uav/cobs/protocol.hpp>

namespace quan{ namespace tracker{ namespace zapp4{

// naive crc32 Ethernet algorithm
// todo verify against the stm32 hardware
   uint32_t crc32(uint32_t crc, uint32_t data)
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

    //  1 input frame 0
    //  2 bytes id
    //  2 bytes reserved
    //  12 bytes data
    //  4 bytes crc
    //  1 encode
    inline void encode_position(     
      quan::uav::position<
         quan::angle_<int32_t>::deg10e7,
         quan::length_<int32_t>::mm  // N.B changed to mm from old protocol
      > const & pos,
      uint8_t (&encoded) [22])
     {
        union{
            struct {
               uint16_t id;
               uint16_t flags;
               int32_t lat;
               int32_t lon;   
               int32_t alt;
               uint32_t crc;
            }__attribute__((__packed__)) vals;
            uint8_t ar[20];
        } u;
        static_assert (sizeof(u) == 20,"invalid size");
        u.vals.id = quan::tracker::zapp4::command_id::position;
        u.vals.flags = 0;
        u.vals.lat = quan::tracker::detail::normalise (pos.lat);
        u.vals.lon = quan::tracker::detail::normalise (pos.lon);
        u.vals.alt = pos.alt.numeric_value();
       
        uint32_t crc = 0xffffffff;
        for ( uint32_t i = 0; i < 4; ++i){
            uint32_t * p = ((uint32_t * )&u.vals) + i;
            crc = crc32(crc,*p);
        }
        u.vals.crc = crc;
        quan::uav::cobs::encode (u.ar,20,encoded+1);
        encoded[0] = 0U; // framing byte
     }

     inline bool decode_position(
       uint8_t const( &encoded) [22],
       quan::uav::position<
         quan::angle_<int32_t>::deg10e7,
         quan::length_<int32_t>::mm  // N.B changed to mm from old protocol
      > & pos
   )
   {
      if( encoded[0] != 0){
         return false;
      }

      union{
         struct {
            uint16_t id;
            uint16_t flags;
            int32_t lat;
            int32_t lon;   
            int32_t alt;
            uint32_t crc;
         }__attribute__((__packed__)) vals;
         uint8_t ar[20];
      } u;
      if (!quan::uav::cobs::decode(encoded+1,21,u.ar)){
         return false;
      }
      uint32_t crc = 0xffffffff;
      for ( uint32_t i = 0; i < 4; ++i){
         uint32_t * p = ((uint32_t * )&u.vals) + i;
         crc = crc32(crc,*p);
      }
      if ( u.vals.crc != crc){
         return false;
      }
      pos.lat = quan::angle_<int32_t>::deg10e7{u.vals.lat};
      pos.lon = quan::angle_<int32_t>::deg10e7{u.vals.lon};
      pos.alt = quan::length_<int32_t>::mm{u.vals.alt};
      return true;
   }
      

}}}//quan::tracker::zapp4



#endif // QUAN_TRACKER_ZAPP4_POSITION_HPP_INCLUDED
