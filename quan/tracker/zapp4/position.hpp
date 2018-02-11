#ifndef QUAN_TRACKER_ZAPP4_POSITION_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_POSITION_HPP_INCLUDED

#include <quan/uav/position.hpp>
#include <quan/tracker/zapp4/ids.hpp>
#include <quan/tracker/zapp4/crc.hpp>
#include <quan/tracker/detail/normalise_angle.hpp>
#include <quan/uav/cobs/protocol.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cstring>
#else
#include <string.h>
#endif

namespace quan{ namespace tracker{ namespace zapp4{

    //  1 input frame 0
    //  1 id
    //  12 bytes data
    //  4 bytes crc
    //  1 encode
    inline void encode_position(     
      quan::uav::position<
         quan::angle_<int32_t>::deg10e7,
         quan::length_<int32_t>::mm  // N.B changed to mm from old protocol
      > const & pos,
      uint8_t (&encoded) [19])
     {
        union{
            struct {
               uint8_t packing[3]; // packing for alignment
               uint8_t id; // id is first byte
               int32_t lat;
               int32_t lon;   
               int32_t alt;
               uint32_t crc;
            }__attribute__((__packed__)) vals;
            uint8_t ar[20];
        } u;
        static_assert (sizeof(u) == 20,"invalid size");
        u.vals.id = quan::tracker::zapp4::command_id::position;
        u.vals.lat = quan::tracker::detail::normalise (pos.lat);
        u.vals.lon = quan::tracker::detail::normalise (pos.lon);
        u.vals.alt = pos.alt.numeric_value();
        // calc the crc
        uint32_t crc = 0xffffffff;
        for ( uint32_t i = 0; i < 3; ++i){
            uint32_t * p = ((uint32_t * )&u.vals.lat) + i;
            crc = crc32(crc,*p);
        }
        u.vals.crc = crc;
        // encode starting at the id byte
        quan::uav::cobs::encode (u.ar+3,17,encoded+1);
        encoded[0] = 0U; // framing byte
     }


   inline bool get_position(
      uint8_t const * buffer,
      quan::uav::position<
         quan::angle_<int32_t>::deg10e7,
         quan::length_<int32_t>::mm  // 
      > & pos_out)
   {
      union{
         struct {
            uint8_t packing[3];
            uint8_t id;
            int32_t lat;
            int32_t lon;   
            int32_t alt;
            uint32_t crc;
         }__attribute__((__packed__)) vals;
         uint8_t ar[20];
      } u;
      memcpy(u.ar + 3,buffer,17);
      if ( u.vals.id != quan::tracker::zapp4::command_id::position){
        // std::cout << "not a position id\n";
         return false;
      }
      uint32_t crc = 0xffffffff;
      for ( uint32_t i = 0; i < 3; ++i){
         uint32_t * p = ((uint32_t * )&u.vals.lat) + i;
         crc = quan::tracker::zapp4::crc32(crc,*p);
      }
      if ( u.vals.crc == crc){
         pos_out.lat = quan::angle_<int32_t>::deg10e7{u.vals.lat};
         pos_out.lon = quan::angle_<int32_t>::deg10e7{u.vals.lon};
         pos_out.alt = quan::length_<int32_t>::mm{u.vals.alt};
         return true;
      }else{
        // std::cout << "ivalid crc\n";
         return false;
     }
   }

}}}//quan::tracker::zapp4



#endif // QUAN_TRACKER_ZAPP4_POSITION_HPP_INCLUDED
