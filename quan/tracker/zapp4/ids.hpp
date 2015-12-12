#ifndef QUAN_TRACKER_ZAPP4_IDS_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_IDS_HPP_INCLUDED

#include <cstdint>

namespace quan{ namespace tracker{namespace zapp4{

   struct command_id{
      static constexpr uint16_t   position = 1;
   };

   
   uint32_t get_decoded_packet_size( uint16_t command_id_in)
   {
         switch ( command_id_in){
            case command_id::position:
               return 20;
            default:
               return 0;
         }
   }
      
}}}


#endif // QUAN_TRACKER_ZAPP4_IDS_HPP_INCLUDED
