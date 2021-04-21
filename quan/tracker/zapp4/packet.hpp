#ifndef QUAN_TRACKER_ZAPP4_PACKET_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP4_PACKET_HPP_INCLUDED


/*
packet concept

   packet is constructed from the data it contains t the transmitter end
   or from the parser at the receiver end

    my_packet
    union my_packet{
         // seed must be less than            4294967295                                 
         static constexpr uint32_t crc_seed = 3141592654U;
         static constexpr PacketID packet_id = PacketID::MyPacket;

         my_packet_packet(float x, float y): values{x,y}{ do_crc(*this);}
         struct packet{
             packet(float x, float y)
             :id{packet_id},
             reserved{0U},
             position_x{x},
             position_y{y}
             {}

             PacketID id;
             uint16_t reserved;
             float position_x;
             float position_y;
             uint32_t crc;
          } values;
          uint8_t ar[sizeof(values)];

         template <uint16_t MaxEncodedPacketLength>
         my_packet(quan::uav::cobs::static_packet_parser<MaxEncodedPacketLength> const & parser)
         {
            static_assert(MaxEncodedPacketLength > sizeof(ar),"packet_parser buffer too short");
            memcpy(ar,parser.get_decoded_packet(),sizeof(ar));
         }
    };

    static_assert ( sizeof (my_packet) == 16,"unexpected union size");
    static_assert ( (sizeof (my_packet) % 4) == 0,"unexpected union size");
*/
#endif // QUAN_TRACKER_ZAPP4_PACKET_HPP_INCLUDED
