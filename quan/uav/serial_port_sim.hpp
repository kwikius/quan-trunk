#ifndef PC_SERIAL_PORT_HPP_INCLUDED
#define PC_SERIAL_PORT_HPP_INCLUDED
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
#include <iostream>
#include <quan/utility/fifo.hpp>
#include <quan/concepts/port.hpp>
#include <quan/meta/if.hpp>
#include <quan/where.hpp>
#include <type_traits>
#include <cstring>
#include <quan/is_model_of.hpp>

/* for sim to work

 to simulate a serial port "wire"
  the wire has two ends so there are two ports
  each with a fifo for transmit and receive
  
 create two tags one representing each end of the wire
  size memeber is size of the fifo buffer
  struct pc_sp{ static constexpr size_t size = 1000;};
  struct tx_sp{static constexpr size_t size = 1000;};

// Create the sim using the tags
  typedef serial_port_wire<pc_sp,tx_sp> sp_sim;

// create two ports using the tags
// the second has the tags reversed with respect to the other
  typedef serial_port_terminal<sp_sim,pc_sp,tx_sp> server_port;
  typedef serial_port_terminal<sp_sim,tx_sp,pc_sp> client_port;

   Now if you write data to one port , it appears at the other
*/

namespace quan { namespace uav {

   template <typename Atag,typename Btag>
   struct serial_port_wire{

      static quan::fifo<uint8_t, Atag::size> fifo_a;
      static quan::fifo<uint8_t, Btag::size> fifo_b;

      struct get_fifo_a
      {
        typedef quan::fifo<uint8_t, Atag::size> type;
        type & operator() ()
        {return fifo_a;}
      };

      struct get_fifo_b
      {
        typedef quan::fifo<uint8_t, Btag::size> type;
        type & operator() ()
        { return fifo_b;}
      };

      template <typename Tag> 
      struct get_fifo{

         typedef typename quan::meta::if_<
            std::is_same<Tag,Atag>,
               get_fifo_a,
               typename quan::meta::if_<
                  std::is_same<Tag,Btag>,
                  get_fifo_b,
                  int
               >::type
        >::type fun_type;

        typename fun_type::type & operator()()
        { 
         return fun_type{}();
        }
               
      };

      template <typename Tag>
      static size_t in_avail()
      {
        return get_fifo<Tag>{}().num_in_buffer();
      }

      template <typename Tag>
      static void put( uint8_t ch)
      { 
         get_fifo<Tag>{}().put(ch);
      }

      template <typename Tag>
      static uint8_t get ()
      { 
         uint8_t ch;
         get_fifo<Tag>{}().get(ch);
         return ch;
      }
   };

   template <typename Atag,typename Btag>
   quan::fifo<uint8_t, Atag::size> serial_port_wire<Atag,Btag>::fifo_a;

   template <typename Atag,typename Btag>
   quan::fifo<uint8_t, Btag::size> serial_port_wire<Atag,Btag>::fifo_b;

   template <typename Sim, typename Tag1, typename Tag2>
   struct serial_port_terminal{

     static void put (uint8_t ch)
     {
         Sim:: template put<Tag1>(ch);
     }

     static uint8_t get ()
     {
         return Sim:: template get<Tag2>();
     }

     static void write( const char * str)
     {
         for (size_t i = 0, len =strlen(str); i < len;++i)
         {
           put(str[i]);
         }
     }

     static size_t in_avail()
     {
        return Sim::template in_avail<Tag2>();
     }
   };

}}//quan::uav   

namespace quan{ namespace impl{

   template <typename Atag, typename Btag>
   struct is_model_of_impl<quan::StaticPort,quan::uav::serial_port_wire<Atag,Btag> > : quan::meta::true_{};

}}//quan::impl

#endif // PC_SERIAL_PORT_HPP_INCLUDED
