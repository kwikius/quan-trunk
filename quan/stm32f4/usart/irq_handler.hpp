#ifndef QUAN_STM32F4_USART_IRQ_HANDLER_HPP_INCLUDED
#define QUAN_STM32F4_USART_IRQ_HANDLER_HPP_INCLUDED
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

#include <quan/stm32f4/serial_port.hpp>

namespace quan{ namespace stm32f4{ namespace usart{

   namespace detail{

      template<typename Usart>
      inline bool ll_tx_reg_empty()
      {
         return  Usart::get()->sr. template bb_getbit<7>() ; // (TXE)
      }

      template<typename Usart>
      inline void ll_serial_port_put( char ch)
      {
          Usart::get()->dr = ch;
      }

      template<typename Usart>
      inline bool ll_rx_reg_full()
      {
        return Usart::get()->sr. template bb_getbit<5>(); //(RXNE)
      }

      template<typename Usart>
      inline char ll_serial_port_get()
      {
        return static_cast<char>(Usart::get()->dr);
      }

   }//detail

   template <typename SerialPort>
   inline void irq_handler()
   {
      typedef typename SerialPort::usart_type usart_type;
      if (usart_type::get()->cr1. template bb_getbit<5>() ) { //(RXNE)
            // received data?
         if(quan::stm32f4::usart::detail::ll_rx_reg_full<usart_type>()){
          
           if ( SerialPort::m_rx_fifo.is_full()){
              // deal with fifo overflow
              // by dumping the oldest data 
               // say rx_stream bad?
               char ch = SerialPort::m_rx_fifo.get();
           }
           // read to rx buffer - clears RXNE flag
           SerialPort::m_rx_fifo.put(quan::stm32f4::usart::detail::ll_serial_port_get<usart_type>() );
         }
      }

      if (usart_type::get()-> cr1. template bb_getbit<7>() ) { // (TXEIE)
         if(! SerialPort::m_tx_fifo.is_empty() ){ 
            if( quan::stm32f4::usart::detail::ll_tx_reg_empty<usart_type>()){
               quan::stm32f4::usart::detail::ll_serial_port_put<usart_type>(SerialPort::m_tx_fifo.get());
            }
         }
         if (SerialPort::m_tx_fifo.is_empty()) {
             usart_type::get()->cr1. template bb_clearbit<7>();// (TXEIE)
         }
      }
   }

}}}

#endif // QUAN_STM32F4_USART_IRQ_HANDLER_HPP_INCLUDED
