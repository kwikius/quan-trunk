#ifndef QUAN_UAV_FRSKY2WSP_DYNAMIC_PORT_PROTOCOL_HPP_INCLUDED
#define QUAN_UAV_FRSKY2WSP_DYNAMIC_PORT_PROTOCOL_HPP_INCLUDED

#include <cstdint>

namespace FrSky2WSP{ namespace detail{

      template <typename Port>
      struct dynamic_port_protocol;

      template <typename Port>
      struct dynamic_port_protocol {

       dynamic_port_protocol(Port* port);
       ~dynamic_port_protocol();

       bool get_frame(unsigned char(& destbuf)[9]);
       bool good()const;
   protected:
       void get();
       void raw_get();

       Port * m_port;
       bool m_synced;
       unsigned char m_buffer[11];
       int m_buffer_index;
      
       dynamic_port_protocol(dynamic_port_protocol const &) = delete;
       dynamic_port_protocol operator = (dynamic_port_protocol const &) = delete;
   };

}}

#endif // QUAN_UAV_FRSKY2WSP_DYNAMIC_PORT_PROTOCOL_HPP_INCLUDED
