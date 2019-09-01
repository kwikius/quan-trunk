#ifndef QUAN_STM32_FREERTOS_USART_TASK_HPP_INCLUDED
#define QUAN_STM32_FREERTOS_USART_TASK_HPP_INCLUDED

/*
 Copyright (c) 2013 -2015 Andy Little 

 With Grateful Acknowledgements to the prior work of:
   Sami Korhonen(Openpilot.org)
   taulabs ( taulabs.com) 
   brainFPV ( brainfpv.com)
   Thomas Oldbury (super-osd.com)

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

#include <cctype>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#if defined QUAN_STM32F4
#include <stm32f4xx.h>
#else
#error "need to define processor"
#endif
#include "FreeRTOS.h"
#include <task.h>
#include <queue.h>
#include <quan/where.hpp>
#include <type_traits>
#include <quan/stm32/config.hpp>
#include <quan/stm32/usart.hpp>
#include <quan/stm32/gpio.hpp>
#include <quan/stm32/get_alternate_function.hpp>
#include <quan/stm32/usart/detail/get_irq_number.hpp>
#include <quan/stm32/usart/get_alternate_function.hpp>

namespace quan{ namespace stm32{namespace freertos{

   template <
      typename Usart
      ,uint32_t TX_q_size
      ,uint32_t RX_q_size
      ,typename TxPin
      ,typename RxPin
      ,typename CharType = char
   >
   struct usart_tx_rx_task{
      static_assert(sizeof(CharType) == sizeof(char),"invalid char_type");

      static constexpr uint32_t get_tx_queue_size() { return TX_q_size;}
      static constexpr uint32_t get_rx_queue_size() { return RX_q_size;}
      static void enable()
      {
//###############
         typedef Usart usart_type;
         static constexpr uint8_t usart_cr1_rxneie = 5; 
         usart_type::get()->cr1. template bb_setbit<usart_cr1_rxneie>();
         quan::stm32::enable<usart_type>();
      }

      template <uint32_t Baudrate>
      static void setup(uint32_t priority)
      {
         setup_rxi_queue();
         setup_txo_queue();
         setup_usart<Baudrate>(priority);
      }
      // blocking
      static CharType get()
      {
         CharType ch;
         xQueueReceive(m_rxi_queue_handle,&ch,portMAX_DELAY);
         return ch;
      }
      
      static size_t in_avail()
      {
         return uxQueueMessagesWaiting(m_rxi_queue_handle);
      }

      static size_t out_waiting()
      {
         return uxQueueMessagesWaiting(m_txo_queue_handle);
      }

      static size_t out_space_avail()
      {
         return get_tx_queue_size() - out_waiting();
      }

      // blocking ( if q full)
      static void put (CharType ch)
      {
         xQueueSendToBack(m_txo_queue_handle,&ch,portMAX_DELAY);
         typedef Usart usart_type;
         constexpr uint8_t usart_cr1_txeie = 7;
         usart_type::get()->cr1. template bb_setbit<usart_cr1_txeie>();
      }
      // blocking
      static void write(CharType const * str, size_t n)
      {
         for ( size_t i = 0; i < n; ++i){
            put(str[i]);
         }
      }

      // also blocking
      // only for char string
      template <typename T>
      static 
      typename quan::where_<
            quan::meta::and_<
                std::is_same<T,char>
               ,std::is_same<T,CharType>
              >
        >::type
        write ( T const * str){
         write ( str, strlen(str));
      }

      template <uint32_t Buflen>
      static inline int print(char const * const format,  ...)
      {
         char buffer[Buflen];
         va_list args;
         va_start (args, format);
         int n = vsnprintf(buffer, Buflen, format, args);
         if ( n > 0){
            write(buffer,n);
         }
         va_end(args);
         return n;
      }
      
      static void irq_handler()
      {
         typedef Usart usart_type;
         constexpr uint8_t usart_sr_rxne = 5;
         // constexpr uint8_t usart_sr_txe = 7;
         constexpr uint8_t usart_cr1_txeie = 7;

         BaseType_t HigherPriorityTaskHasWoken = pdFALSE;

         if ( usart_type::get()->sr. template bb_getbit<usart_sr_rxne>()){
            char ch = static_cast<char>(usart_type::get()->dr);
            BaseType_t result = xQueueSendToBackFromISR(m_rxi_queue_handle, &ch, &HigherPriorityTaskHasWoken);
            if ( result == errQUEUE_FULL){
            //set some led to indicate fail
            }
         }else{
         // must be txe
            if ( !xQueueIsQueueEmptyFromISR(m_txo_queue_handle)){
               char ch;
               xQueueReceiveFromISR(m_txo_queue_handle,&ch,&HigherPriorityTaskHasWoken);
               usart_type::get()->dr = ch;
            }
            if ( xQueueIsQueueEmptyFromISR(m_txo_queue_handle)){
               usart_type::get()->cr1. template bb_clearbit<usart_cr1_txeie>();
            }
         }
         portEND_SWITCHING_ISR(HigherPriorityTaskHasWoken);
      }

   private:
      static void setup_rxi_queue()
      {
        m_rxi_queue_handle = xQueueCreate(RX_q_size, sizeof(char));
        if (m_rxi_queue_handle == 0){
            //prob out of memory
            //flash_led
            // error loop()
        }
      }
      static void setup_txo_queue()
      {
        // todo check already inited
        m_txo_queue_handle = xQueueCreate(TX_q_size, sizeof(char));
        if (m_txo_queue_handle == 0){
             //prob out of memory
            //flash_led
            // error loop()
        }
      }
      /*
        N.B serial port task must be enabled afte this call before it will work
      */
      template <uint32_t Baudrate>
      static void setup_usart(uint32_t irq_priority)
      {
         quan::stm32::module_enable<Usart>();

         typedef typename quan::stm32::get_alternate_function<
            TxPin,Usart,quan::stm32::usart::tx_pin
         >::type tx_gpio_af_type;
         static_assert(!std::is_same<tx_gpio_af_type,quan::undefined>::value,
            "tx pin invalid for alternate function");

         quan::stm32::module_enable<typename TxPin::port_type>();
         quan::stm32::apply<
            TxPin
            ,tx_gpio_af_type
            ,quan::stm32::gpio::otype::push_pull   // need open_drain amd pullup to 5V option here
            ,quan::stm32::gpio::pupd::none         //  this is still corrrect. Use external pullup
            ,quan::stm32::gpio::ospeed::slow
         >();

         typedef typename quan::stm32::get_alternate_function<
            RxPin,Usart,quan::stm32::usart::rx_pin
         >::type rx_gpio_af_type;
         static_assert(!std::is_same<rx_gpio_af_type,quan::undefined>::value,
            "rx pin invalid for alternate function");

         quan::stm32::module_enable<typename RxPin::port_type>();
         quan::stm32::apply<
            RxPin
            ,rx_gpio_af_type
            ,quan::stm32::gpio::pupd::pull_up
            ,quan::stm32::gpio::ospeed::slow
         >();

      // these settings must be applied with usart disabled
         quan::stm32::apply<
            Usart
            ,quan::stm32::usart::asynchronous
            ,quan::stm32::usart::transmitter<true>
            ,quan::stm32::usart::receiver<true>
            ,quan::stm32::usart::baud_rate<Baudrate,false>
            ,quan::stm32::usart::parity::none
            ,quan::stm32::usart::data_bits<8>
            ,quan::stm32::usart::stop_bits<1>
            ,quan::stm32::usart::rts<false>
            ,quan::stm32::usart::cts<false>
            ,quan::stm32::usart::i_en::cts<false>
            ,quan::stm32::usart::i_en::lbd<false>
            ,quan::stm32::usart::i_en::txe<false>
            ,quan::stm32::usart::i_en::tc<false>
            ,quan::stm32::usart::i_en::rxne<false>
            ,quan::stm32::usart::i_en::idle<false>
            ,quan::stm32::usart::i_en::pe<false>
            ,quan::stm32::usart::i_en::error<false>
         >();

         IRQn_Type irq_num 
            = quan::stm32::usart::detail::get_irq_number<Usart>::value;
         NVIC_SetPriority(irq_num,irq_priority);
         NVIC_EnableIRQ(irq_num);
      }
//data----------
      static QueueHandle_t m_rxi_queue_handle;
      static QueueHandle_t m_txo_queue_handle;
   };

   template <
      typename Usart
      ,uint32_t TX_q_size
      ,uint32_t RX_q_size
      ,typename TxPin
      ,typename RxPin
      ,typename CharType
   >
   QueueHandle_t usart_tx_rx_task<
         Usart,TX_q_size,RX_q_size,TxPin,RxPin,CharType
   >::m_rxi_queue_handle = 0;

   template <
      typename Usart
      ,uint32_t TX_q_size
      ,uint32_t RX_q_size
      ,typename TxPin
      ,typename RxPin
      ,typename CharType
   >
   QueueHandle_t usart_tx_rx_task<
      Usart,TX_q_size,RX_q_size,TxPin,RxPin,CharType
   >::m_txo_queue_handle = 0;
   
}}}

#endif // QUAN_STM32_FREERTOS_USART_TASK_HPP_INCLUDED
