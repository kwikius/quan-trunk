
#include <quan/tracker/zapp4/position.hpp>
#include <quan/out/angle.hpp>
#include <quan/out/length.hpp>
#include <iostream>

namespace {
   // the info for all decoded packets
   static constexpr uint8_t max_encoded_packet_length = 131; // encoded
   static constexpr uint8_t max_decoded_packet_length = max_encoded_packet_length - 1; // encoded 
   static uint8_t packet_idx = 0; // index of next pos in array and count of num in packet
   enum { not_synced, in_sync, in_packet};
   static uint8_t current_packet_mode = not_synced;
   uint8_t encoded_packet_buffer[max_encoded_packet_length];
   uint8_t decoded_packet_buffer[max_decoded_packet_length];

   // parse a cobs encoded packet stream
   int16_t parse_encoded_packet_stream(uint8_t ch);

   bool decode_position_packet(uint8_t * buffer);
   
}

int main()
{
   //position input
   // N.B angle inputs must be < +- 180 deg), else wont compare equal
   quan::uav::position<
      quan::angle_<int32_t>::deg10e7,
      quan::length_<int32_t>::mm  // 
   > pos_in{quan::angle::deg{100.f},quan::angle::deg{150.f},quan::length::mm{ 300.f}};

   // encoded the input to an array
   uint8_t array1[22];
   quan::tracker::zapp4::encode_position(pos_in,array1);

   // an array representing the transmitted data stream.
   // inited to 0 to represent delimiter between frames
   uint8_t array2[100];
   for ( auto & v: array2){ v = 0;}

   // put the encoded data in the stream at some random point(s)
   memcpy (array2 +  0, array1,22);
   memcpy (array2 + 25, array1,22);
   memcpy (array2 + 50, array1,22);
   memcpy (array2 + 72, array1,22);

   // parse the stream, decode any packets found
   for (uint16_t i = 0; i < 100; ++i){
      uint16_t packet_length = parse_encoded_packet_stream(array2[i]);

      if ( packet_length > 0 ){
         std::cout << "success\n";
         // result is in decoded_packet
         if ( decoded_packet_buffer[0] == 1){
            std::cout << "Success 2\n";
            if (packet_length == 20){
               std::cout << "Succes 3\n";
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
               memcpy(u.ar,decoded_packet_buffer,20);
               uint32_t crc = 0xffffffff;
               for ( uint32_t i = 0; i < 4; ++i){
                  uint32_t * p = ((uint32_t * )&u.vals) + i;
                  crc = quan::tracker::zapp4::crc32(crc,*p);
               }
               if ( u.vals.crc == crc){
                  std::cout << "crc matches\n";
               }else{
                  std::cout << "crc didnt match\n";
                  return false;
               }

               std::cout << pos_in.lat << " <> " << u.vals.lat <<'\n';
               std::cout << pos_in.lon << " <> " << u.vals.lon <<'\n';
               std::cout << pos_in.alt << " <> " << u.vals.alt <<'\n';

            }else{
               std::cout << "invalid lengthof packet\n";
            }
         }
      }
   }
}


namespace {

   // input is a stream of cobs encoded packets
   // max length of encoded packet in max_encoded_packet_length
   // return is non zero if have a packet then return is length of packet
   // packet is in decoded_packet_buffer
   int16_t parse_encoded_packet_stream(uint8_t ch)
   {
        switch (current_packet_mode){
         case in_packet:{
            if ( ch == 0){ // new packet
               if (quan::uav::cobs::decode(encoded_packet_buffer,packet_idx,decoded_packet_buffer)){
                  current_packet_mode = in_sync;
                  return packet_idx -1;
               }else{
                   std::cout << "pkt crrpt\n";
                  current_packet_mode = not_synced;  
                  return 0;
               }
            }else{ // more input to packet
               if ( packet_idx < max_encoded_packet_length){
                  encoded_packet_buffer[packet_idx] = ch;
                  ++packet_idx;
               }else{
                 std::cout << "pkt ovrrn\n";
                  current_packet_mode = not_synced;  
               }
               return 0;  
            }
         }
         case in_sync:{ // can have as many zeros as like between frames
            if ( ch != 0){
               encoded_packet_buffer[0] = ch;
               packet_idx = 1;
               current_packet_mode = in_packet;
            }
            return 0;
         }
         case not_synced:
         {
            if ( ch == 0){
               current_packet_mode = in_sync;
            }
            return 0;
         }
         default:{ // shouldnt get here
            std::cout << "bad error\n";
            return 0;
         }
      }
   }

   bool decode_position_packet(uint8_t * buffer)
   {
     return false;

   }

}//namespace



