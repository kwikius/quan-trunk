#ifndef QUAN_TRACKER_ZAPP4_IDS_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_IDS_HPP_INCLUDED

#include <cstdint>

namespace quan{ namespace tracker{namespace zapp4{

   struct command_id{
      static constexpr uint16_t   position = 1;
   };

   // encoded size of packet, includes starting 0
   uint32_t get_encoded_size( uint16_t command_id_in)
   {
         switch ( command_id_in){
            case command_id::position:
               return 22;
            default:
               return 0;
         }
   }
      
}}}


#endif // QUAN_TRACKER_ZAPP4_IDS_HPP_INCLUDED
