#ifndef QUAN_UAV_FRSKY2WSP_DYNAMIC_PORT_PROTOCOL_HPP_INCLUDED
#define QUAN_UAV_FRSKY2WSP_DYNAMIC_PORT_PROTOCOL_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
