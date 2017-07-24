#ifndef QUAN_TRACKER_ZAPP4_GPS_STATUS_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_GPS_STATUS_HPP_INCLUDED

#include <quan/tracker/zapp4/ids.hpp>
#include <quan/tracker/zapp4/crc.hpp>

namespace quan{ namespace tracker{ namespace zapp4{
/*
  encode the gps status mainly useful for when initialising or when there is no gps or no fix etc
  Actually could send extra data here e.g dead reckoning info, course and direction
  however that is for another ID
  Actually could mod this to add num sats info/ aircraft uptime etc. For startup this keeps interest.
*/
   enum class gps_status_t: uint8_t{
     no_gps,no_fix,fix_2d,fix_3d,unknown
   };

   //  1 input frame 0
   //  1 id
   //  4 bytes data ( 3 of those are packing)
   //  4 bytes crc
   //  1 encode
   // Total == 11
   inline void encode_gps_status(gps_status_t gps_status_in,uint8_t (&encoded) [11])
   {
      union{
         struct{
             uint8_t packing[3];
             uint8_t id;  // the message id
             uint8_t gps_status;
             char empty[3];
             uint32_t crc;
         }__attribute__((__packed__)) vals;
         uint8_t arr[12]; //
      }u;
      u.vals.id = quan::tracker::zapp4::command_id::gps_status;
      u.vals.gps_status = static_cast<uint8_t>(gps_status_in);
      u.vals.empty[0] = 'G';
      u.vals.empty[1] = 'P';
      u.vals.empty[2] = 'S';
      uint32_t const crc_check = 
       static_cast<uint32_t>(u.vals.gps_status) | 
       (static_cast<uint32_t>(u.vals.empty[0]) << static_cast<uint32_t>(8U)) | 
       (static_cast<uint32_t>(u.vals.empty[1]) << static_cast<uint32_t>(16)) |
       (static_cast<uint32_t>(u.vals.empty[2]) << static_cast<uint32_t>(24));
      u.vals.crc = crc32(0xffffffff,crc_check);
      // encode starting at the id byte
      quan::uav::cobs::encode(u.arr + 3,9,encoded+1);
      encoded[0] = 0U; // framing byte
   }

   inline bool get_gps_status( uint8_t const * buffer,gps_status_t & gps_status_out)
   {
      union{
         struct{
         uint8_t packing[3];
         uint8_t id;  // the message id
         uint8_t gps_status;
         char empty[3];
         uint32_t crc;
         }__attribute__((__packed__)) vals;
         uint8_t arr[12]; //
      }u;
      memcpy(u.arr + 3,buffer,9);
      if ( u.vals.id != quan::tracker::zapp4::command_id::gps_status){
         return false;
      }
      uint32_t const crc_check = static_cast<uint32_t>(u.vals.gps_status) |
      (static_cast<uint32_t>(u.vals.empty[0]) << static_cast<uint32_t>(8U)) |
      (static_cast<uint32_t>(u.vals.empty[1]) << static_cast<uint32_t>(16)) |
      (static_cast<uint32_t>(u.vals.empty[2]) << static_cast<uint32_t>(24));
      uint32_t const crc = quan::tracker::zapp4::crc32(0xffffffff,crc_check);
      if ( u.vals.crc == crc){
         gps_status_out = static_cast<gps_status_t>(u.vals.gps_status);
         return true;
      }else{
         return false;
      }
   }

}}} //quan::tracker::zapp4

#endif // QUAN_TRACKER_ZAPP4_GPS_STATUS_HPP_INCLUDED
