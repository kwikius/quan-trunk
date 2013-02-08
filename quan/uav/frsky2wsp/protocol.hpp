#ifndef FRSKY_TWO_WAY_SYSTEM_PROTOCOL_HPP_INCLUDED
#define FRSKY_TWO_WAY_SYSTEM_PROTOCOL_HPP_INCLUDED

#include <cstdint>

/*
 FrSky 2 Way System Protocol
*/
namespace FrSky2WSP{

      struct Frame{
         static constexpr uint8_t header = 0x7E;
         static constexpr uint8_t escape = 0x7D;
      };

      struct CommandID{
         // Remote Voltage & Link Quality
         static constexpr uint8_t RVLQ = 0xFE;
          /*
           after RVLQ command id
           byte1 = receiver analog port 1 analog voltage
           byte2 = receiver analog port 2 analog voltage

           value of 255 =3.3 V for Analog1 and Analog2
           so V  = 3.3 [volts] * x / 255 
           ---------------
           byte3 = RC receiver RSSI
           byte4 = RC Transmitter RSSI

           divide Tx Module RSSI value by 2 to get dB
          */
      
         // user data
         static constexpr uint8_t UserData = 0xFD;
         /*
          After User Data command id
          byte1 = number of user bytes in frame min 1 max 6 bytes
          byte2 = unused
          byte3 = 1st user data byte
          byte 4 = 2nd user byte
          .. etc
         */

       // set get thresholds
         static constexpr uint8_t ThrAn1a = 0xFC;
         static constexpr uint8_t ThrAn1b = 0xFB;
         static constexpr uint8_t ThrAn2b = 0xFA;
         static constexpr uint8_t ThrAn2a = 0xF9;
         static constexpr uint8_t ThrReq  = 0xF8;

      };

// overlay the FrSky2WSP protocol on a port

      template <typename Port>
      struct protocol {

       protocol(Port* port);
       ~protocol();

       bool get_frame(unsigned char(& destbuf)[9]);
       bool good()const;
   private:

       void get();
       void raw_get();

       Port * m_port;
       bool m_synced;
       unsigned char m_buffer[11];
       int m_buffer_index;
      
       protocol(protocol const &) = delete;
       protocol operator = (protocol const &) = delete;
   };
}

#endif // FRSKY_TWO_WAY_SYSTEM_PROTOCOL_HPP_INCLUDED
