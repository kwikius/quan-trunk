#ifndef FRSKY_TWO_WAY_SYSTEM_PROTOCOL_HPP_INCLUDED
#define FRSKY_TWO_WAY_SYSTEM_PROTOCOL_HPP_INCLUDED


#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/concepts/port.hpp>
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

      struct basic_protocol{
          bool get_frame(unsigned char(& destbuf)[9]);
          virtual uint32_t in_avail()const =0;
          virtual bool good()const=0;
      protected:
          virtual ~basic_protocol(){}
          basic_protocol();
          virtual void get()=0;
          virtual void raw_get()=0;;
          bool m_synced;
          unsigned char m_buffer[11];
          int m_buffer_index;
      };

      template < typename Port, typename Where = void>
      struct protocol;
    
      template <typename Port>
      struct protocol<Port, typename quan::where_<quan::is_model_of<quan::DynamicPort,Port> >::type >
      :basic_protocol{
          protocol( Port* port);
          ~protocol();
          bool good()const;
          uint32_t in_avail()const;
      private:
          void get();
          void raw_get();
          Port * m_port;
          protocol(protocol const &) = delete;
          protocol operator = (protocol const &) = delete;
      };

      template <typename Port>
      struct protocol<Port, typename quan::where_<quan::is_model_of<quan::StaticPort,Port> >::type >
      : basic_protocol{
         protocol( );
         ~protocol();
         bool good()const;
         uint32_t in_avail()const;
       private:
         void get();
         void raw_get();

        // bool m_synced;
        // unsigned char m_buffer[11];
       //  int m_buffer_index;
         protocol(protocol const &) = delete;
         protocol operator = (protocol const &) = delete;
      };
}

#endif // FRSKY_TWO_WAY_SYSTEM_PROTOCOL_HPP_INCLUDED
