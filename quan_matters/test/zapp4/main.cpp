
#include <quan/tracker/zapp4/position.hpp>
#include <quan/out/angle.hpp>
#include <quan/out/length.hpp>
#include <iostream>

   struct packet_parser{
      enum class parser_state_t : uint8_t { not_synced, in_sync, in_packet};
      packet_parser(uint16_t max_encoded_packet_length_in)
      : m_encoded_packet_buffer{new uint8_t [max_encoded_packet_length_in]}
      , m_decoded_packet_buffer{new uint8_t [max_encoded_packet_length_in-1]}
      , m_max_encoded_packet_length{max_encoded_packet_length_in}
      , m_packet_idx{0}
      , m_current_packet_mode{parser_state_t::not_synced}
      { }

      ~packet_parser()
      {
         delete [] m_encoded_packet_buffer;
         delete [] m_encoded_packet_buffer;
      }

      uint8_t const * get_decoded_packet()const 
      {
         return m_decoded_packet_buffer;
      }

      uint16_t parse(uint8_t ch)
      {
         switch (m_current_packet_mode){
            case parser_state_t::in_packet:{
               if ( ch == 0){ // new packet
                  if (quan::uav::cobs::decode(m_encoded_packet_buffer,m_packet_idx,m_decoded_packet_buffer)){
                     m_current_packet_mode = parser_state_t::in_sync;
                     return m_packet_idx -1;
                  }else{
                    // std::cout << "pkt crrpt\n";
                     m_current_packet_mode = parser_state_t::not_synced;  
                     return 0;
                  }
               }else{ // more input to packet
                  if ( m_packet_idx < m_max_encoded_packet_length){
                     m_encoded_packet_buffer[m_packet_idx] = ch;
                     ++m_packet_idx;
                      return 0;  
                  }else{
                    // std::cout << "pkt ovrrn\n";
                     m_current_packet_mode = parser_state_t::not_synced;
                     return 0;  
                  }
               }
            }

            case parser_state_t::in_sync:{ // can have as many zeros as like between frames
               if ( ch != 0){
                  m_encoded_packet_buffer[0] = ch;
                  m_packet_idx = 1;
                  m_current_packet_mode = parser_state_t::in_packet;
               }
               return 0;
            }

            case parser_state_t::not_synced: {
               if ( ch == 0){
                  m_current_packet_mode = parser_state_t::in_sync;
               }
               return 0;
            }

            default:{ // shouldnt get here
               std::cout << "bad error\n";
               return 0;
            }
         }
      }
      private:
      uint8_t * m_encoded_packet_buffer;
      uint8_t * m_decoded_packet_buffer;
      uint16_t const m_max_encoded_packet_length;
      uint16_t m_packet_idx;
      parser_state_t  m_current_packet_mode; //  = not_synced;
   };

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

   auto * parser = new packet_parser{25};

   // parse the stream, decode any packets found
   for (uint16_t i = 0; i < 100; ++i){
      uint16_t const packet_length = parser->parse(array2[i]);
      if ( packet_length > 0 ){
         std::cout << "success\n";
         // result is in decoded_packet
         uint8_t const * decoded_packet_buffer = parser->get_decoded_packet();
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
