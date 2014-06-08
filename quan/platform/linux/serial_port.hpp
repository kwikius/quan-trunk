#ifndef FRSKY_DATA_SERIAL_PORT_HPP_INCLUDED
#define FRSKY_DATA_SERIAL_PORT_HPP_INCLUDED


/*
 Copyright (c) 2012 - 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/


#ifndef __linux 
#error "only for use on linux"
#endif

//#include <asm/termios.h>
#include <cstddef>
#include <cstdint>
#include <string>
#include <quan/concepts/port.hpp>
#include <quan/is_model_of.hpp>

extern "C" struct termios;
namespace quan { 
   struct serial_port{
      typedef  unsigned char data_type;
      serial_port(const char* filename);
      ~serial_port();
      void init();
      ssize_t read( data_type* buf,size_t num);
   
      ssize_t write(const data_type* buf, size_t num) ;
      ssize_t write(const char* buf, size_t num) ;

      template<size_t N>
      ssize_t write(const char(& buf)[N]){
         return write(buf,N);
      }
      
      size_t in_avail();
      bool good() const;
      bool is_deleteable()const;

      int set_baud( uint32_t val);
      
   private:
      std::string m_filename;
      void cleanup();
      int m_fd;
      termios * m_old_termios;
     
      bool m_good_state;
     
      serial_port (serial_port const &) = delete;
      serial_port& operator = (serial_port const &) = delete;
   };
}// quan


namespace quan{ namespace impl{

      template <> struct is_model_of_impl<quan::DynamicPort,quan::serial_port> : quan::meta::true_{};
}}

#endif // FRSKY_DATA_SERIAL_PORT_HPP_INCLUDED
