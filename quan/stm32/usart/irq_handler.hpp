#ifndef QUAN_STM32_USART_IRQ_HANDLER_HPP_INCLUDED
#define QUAN_STM32_USART_IRQ_HANDLER_HPP_INCLUDED
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

#include <quan/stm32/serial_port.hpp>

namespace quan{ namespace stm32{ namespace usart{

   template <typename SerialPort>
   inline void irq_handler()
   {
     // typedef typename SerialPort::usart_type usart_type;
   
      if(SerialPort::ll_rxneie_is_enabled()){
            // received data
         if(SerialPort::ll_rx_reg_full()){
          
           if ( SerialPort::m_rx_fifo.is_full()){
              // deal with fifo overflow
              // by dumping the oldest data 
               // say rx_stream bad?
               SerialPort::m_rx_fifo.get();
           }
           // read to rx buffer - clears RXNE flag
           SerialPort::m_rx_fifo.put( SerialPort::ll_get() );
         }
      }

      if (SerialPort::ll_txeie_is_enabled()) { // (TXE)
         if(! SerialPort::m_tx_fifo.is_empty() ){ 
            if( SerialPort::ll_tx_reg_empty()){
               SerialPort::ll_put(SerialPort::m_tx_fifo.get());
            }
         }
         if (SerialPort::m_tx_fifo.is_empty()) {
             SerialPort::disable_txeie();
         }
      }
   }

   template <typename SerialPort>
   inline void tx_irq_handler()
   {
    //  typedef typename SerialPort::usart_type usart_type;

      if (SerialPort::ll_txeie_is_enabled()) { // (TXE)
         if(! SerialPort::m_tx_fifo.is_empty() ){ 
            if( SerialPort::ll_tx_reg_empty()){
               SerialPort::ll_put(SerialPort::m_tx_fifo.get());
            }
         }
         if (SerialPort::m_tx_fifo.is_empty()) {
             SerialPort::disable_txeie();
         }
      }
   }


  template <typename SerialPort>
   inline void rx_irq_handler()
   {
     // typedef typename SerialPort::usart_type usart_type;
   
      if(SerialPort::ll_rxneie_is_enabled()){
            // received data
         if(SerialPort::ll_rx_reg_full()){
          
           if ( SerialPort::m_rx_fifo.is_full()){
              // deal with fifo overflow
              // by dumping the oldest data 
               // say rx_stream bad?
               SerialPort::m_rx_fifo.get();
           }
           // read to rx buffer - clears RXNE flag
           SerialPort::m_rx_fifo.put( SerialPort::ll_get() );
         }
      }
   }

}}}

#endif // QUAN_STM32_USART_IRQ_HANDLER_HPP_INCLUDED
