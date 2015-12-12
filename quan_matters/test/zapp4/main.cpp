
#include <quan/tracker/zapp4/position.hpp>
#include <quan/uav/cobs/packet_parser.hpp>
#include <quan/out/length.hpp>
#include <quan/out/angle.hpp>

#include <iostream>

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
   // inited to 0 to represent delimiters between frames
   uint8_t array2[100];
   for ( auto & v: array2){ v = 0;}

   // put the encoded data in the stream at some random point(s)
   memcpy (array2 +  0, array1,22);
   memcpy (array2 + 25, array1,22);
   memcpy (array2 + 50, array1,22);
   memcpy (array2 + 72, array1,22);

   // a protocol agnostic cobs stream parser
   auto * parser = new quan::uav::cobs::packet_parser{22};

   // position out
   quan::uav::position<
      quan::angle_<int32_t>::deg10e7,
      quan::length_<int32_t>::mm  // 
   > pos_out;

   // parse the stream, decode any packets found
   for (uint16_t i = 0; i < 100; ++i){
      uint16_t const packet_length = parser->parse(array2[i]);
      if ( packet_length > 0 ){
         // got a packet
         uint8_t const * decoded_packet_buffer = parser->get_decoded_packet();
         // check its length matches the command
         uint16_t const command_id = static_cast<uint16_t>(decoded_packet_buffer[0]) + (static_cast<uint16_t>(decoded_packet_buffer[1]) << 8U);
         
         switch(command_id){
            case quan::tracker::zapp4::command_id::position:{
               if (packet_length == quan::tracker::zapp4::get_decoded_packet_size(command_id)){
                  if (quan::tracker::zapp4::get_position(parser->get_decoded_packet(),pos_out)){
                     std::cout << "succeeded\n";
                     std::cout << pos_in.lat << " <> " << pos_out.lat <<'\n';
                     std::cout << pos_in.lon << " <> " << pos_out.lon <<'\n';
                     std::cout << pos_in.alt << " <> " << pos_out.alt <<'\n';
                  }
               }else{
                  std::cout << "invalid lengthof packet\n";
               }
               break;
            }
            default:{
               break;
            }
         }
      }
   }
}
