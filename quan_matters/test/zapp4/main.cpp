

#include <iostream>
#include <quan/uav/osd/api.hpp>
#include <quan/tracker/zapp4/position.hpp>
#include <quan/uav/cobs/packet_parser.hpp>
#include <quan/out/length.hpp>
#include <quan/out/angle.hpp>


int main()
{
   //position input
   // N.B angle inputs must be < +- 180 deg), else wont compare equal
   quan::uav::position<
      quan::angle_<int32_t>::deg10e7,
      quan::length_<int32_t>::mm  // 
   > pos_in{quan::angle::deg{-100.f},quan::angle::deg{123.f},quan::length::mm{ 70000.f}};

   // encoded the input to an array
   uint8_t array1[19];
   quan::tracker::zapp4::encode_position(pos_in,array1);

   // an array representing the transmitted data stream.
   // inited to 0 to represent delimiters between frames
   uint8_t array2[100];
   for ( auto & v: array2){ v = 0;}

   // put the encoded data in the stream at some random point(s)
   memcpy (array2 +  0, array1,19);
   memcpy (array2 + 19, array1,19);
   memcpy (array2 + 50, array1,19);
   memcpy (array2 + 72, array1,19);

   // a protocol agnostic cobs stream parser
   // construct with the length of the longest encoded packet
   auto * packet_parser = new quan::uav::cobs::packet_parser{19};

   // position output holder
   quan::uav::position<
      quan::angle_<int32_t>::deg10e7,
      quan::length_<int32_t>::mm  // 
   > pos_out;

   // parse the stream, decode any packets found
   for (uint16_t i = 0; i < 100; ++i){
     // std:: cout << i <<'\n';
      uint8_t ch = array2[i];
      uint16_t const packet_length = packet_parser->parse(ch);
      if ( packet_length > 0 ){
         // got a packet
         uint8_t const * decoded_packet_buffer = packet_parser->get_decoded_packet();
         // check its length matches the command
         uint8_t const command_id = static_cast<uint16_t>(decoded_packet_buffer[0]) ;
         switch(command_id){
            case quan::tracker::zapp4::command_id::position:{
               if (packet_length == quan::tracker::zapp4::get_decoded_packet_size(command_id)){
                  bool result = quan::tracker::zapp4::get_position(packet_parser->get_decoded_packet(),pos_out);
                  if (result){
                   std::cout << "success\n";

                    std::cout << pos_in.lat << " <> " << pos_out.lat <<'\n';
                     std::cout << pos_in.lon << " <> " << pos_out.lon <<'\n';
                     std::cout << pos_in.alt << " <> " << pos_out.alt <<'\n';
                  }else{
                     std::cout << "fail\n";
                  }
               }else{
                  std::cout << "packet invalid length\n";
               }
               break;
            }
            default:{
               std::cout << "invalid packet id\n";
               break;
            }
         }
      }else{
        // std::cout << "pkt[" << i << "]= 0\n";
      }
   }
}
