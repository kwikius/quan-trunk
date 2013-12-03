#ifndef QUAN_STM32_USART_IRQ_HANDLER_HPP_INCLUDED
#define QUAN_STM32_USART_IRQ_HANDLER_HPP_INCLUDED

#include <quan/stm32/serial_port.hpp>

namespace quan{ namespace stm32{ namespace usart{

   template <typename SerialPort>
   inline void irq_handler()
   {
      typedef typename SerialPort::usart_type usart_type;
   
      if(SerialPort::ll_rxneie_is_enabled()){
            // received data
         if(SerialPort::ll_rx_reg_full()){
          
           if ( SerialPort::m_rx_fifo.is_full()){
              // deal with fifo overflow
              // by dumping the oldest data 
               // say rx_stream bad?
               char ch = SerialPort::m_rx_fifo.get();
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

}}}

#endif // QUAN_STM32_USART_IRQ_HANDLER_HPP_INCLUDED
