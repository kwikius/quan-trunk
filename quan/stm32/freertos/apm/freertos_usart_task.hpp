#ifndef QUAN_STM32_FREERTOS_APM_USART_TASK_HPP_INCLUDED
#define QUAN_STM32_FREERTOS_APM_USART_TASK_HPP_INCLUDED

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
#if defined QUAN_STM32F4
#include <stm32f4xx.h>
#else
#error "need to define processor"
#endif
#include "FreeRTOS.h"
#include <task.h>
#include <queue.h>
#include <semphr.h>
#include <quan/where.hpp>
#include <type_traits>
#include <quan/stm32/config.hpp>
#include <quan/stm32/usart.hpp>
#include <quan/stm32/gpio.hpp>
#include <quan/stm32/get_alternate_function.hpp>
#include <quan/stm32/usart/detail/get_irq_number.hpp>
#include <quan/stm32/usart/get_alternate_function.hpp>
#include <quan/stm32/freertos/apm/detail/set_baud.hpp>

namespace quan{ namespace stm32{namespace freertos{ namespace apm{

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   struct usart_tx_rx_task{
      typedef uint8_t char_type;
      typedef Usart usart_type;

      static void begin(uint32_t Baudrate_in, uint16_t rxBufferSize_in, uint16_t TxBufferSize_in)
      {
         //taskENTER_CRITICAL();
            UBaseType_t const old_prio = uxTaskPriorityGet(NULL);
            vTaskPrioritySet(NULL,configMAX_PRIORITIES - 1 );
            setup_tx_mutex();
            setup_rx_mutex();
 
            uint16_t rx_buf_size = rxBufferSize_in;
            if ( rx_buf_size == 0){
               rx_buf_size  = m_rx_queue_size;
            }

            uint16_t tx_buf_size = TxBufferSize_in;
            if ( tx_buf_size == 0){
               tx_buf_size  =  m_tx_queue_size;
            }
            
            setup_rxi_queue(rx_buf_size);
            setup_txo_queue(tx_buf_size);

            quan::stm32::disable<usart_type>();

            uint32_t baudrate = Baudrate_in;
            if ( baudrate == 0){
               baudrate = m_baudrate;
            }

            setup_usart<9600>(m_interrupt_priority);
            
            if ( !quan::stm32::freertos::apm::detail::set_baud<usart_type>(baudrate)){
                // "Panic"()
            }
            m_baudrate = baudrate;
            
            typedef Usart usart_type;
            constexpr uint8_t usart_cr1_rxneie = 5; 
            usart_type::get()->cr1. template bb_setbit<usart_cr1_rxneie>();
            quan::stm32::enable<usart_type>();
            m_is_initialised = true;
         //taskEXIT_CRITICAL();
            vTaskPrioritySet(NULL,old_prio);
      }
// ND
      static bool is_initialised()
      {
         return m_is_initialised;
      }

      static void end()
      {
         // kill the queues
         // check its released
         quan::stm32::disable<usart_type>();
      }

      static bool is_enabled() // atomic
      {
   #if defined QUAN_STM32F4
         constexpr uint8_t enable_bit = 13;
   #else 
   #if defined QUAN_STM32F0
         constexpr uint8_t enable_bit = 0;
   #else
   #error need to define for processor
   #endif
   #endif
         return usart_type::get()->cr1.template getbit<enable_bit>();
      }
// ND
      static int16_t get()
      {
         char_type ch;
         if ( m_blocking_mode == true){
            xQueueReceive(m_rxi_queue_handle,&ch,portMAX_DELAY);
            return ch;
         }else{
            if ( in_avail()){
               xQueueReceive(m_rxi_queue_handle, &ch,0);
               return ch;
            }else{
               return -1;
            }
         }
      }
//ND
      static bool set_blocking( bool b)
      {
         m_blocking_mode = b;
         return true;
      }
//ND
      static size_t in_avail()
      {
          return uxQueueMessagesWaiting(m_rxi_queue_handle);
      }
//ND
      static size_t out_waiting()
      {
         return uxQueueMessagesWaiting(m_txo_queue_handle);
      }
//ND
      static size_t out_spaces_available()
      {
         return uxQueueSpacesAvailable(m_txo_queue_handle);
      }

      static bool put (char_type ch)
      {
         typedef Usart usart_type;
         constexpr uint8_t usart_cr1_txeie = 7;
         if ( m_blocking_mode == true){
            xQueueSendToBack(m_txo_queue_handle,&ch,portMAX_DELAY);
            usart_type::get()->cr1. template bb_setbit<usart_cr1_txeie>();
            return true;
         }else{
            if ( uxQueueSpacesAvailable(m_txo_queue_handle) > 0){
              xQueueSendToBack(m_txo_queue_handle,&ch,0); 
              usart_type::get()->cr1. template bb_setbit<usart_cr1_txeie>();
              return true;
            }else{
              return false;
            }
         }
      }

      static size_t write(char_type const * str, size_t n)
      {
         for ( size_t i = 0; i < n; ++i){
            if ( ! put(str[i])){
               return i;
            }
         }
         return n;
      }

      static void set_interrupt_priority(uint32_t priority)
      {
          constexpr IRQn_Type irq_num 
            = quan::stm32::usart::detail::get_irq_number<Usart>::value;
          NVIC_SetPriority(irq_num,priority);
      }
      
      static void irq_handler()
      {
         
         constexpr uint8_t usart_sr_rxne = 5;
         // constexpr uint8_t usart_sr_txe = 7;
         constexpr uint8_t usart_cr1_txeie = 7;

         BaseType_t HigherPriorityTaskHasWoken = pdFALSE;

         if ( usart_type::get()->sr. template bb_getbit<usart_sr_rxne>()){
            char_type ch = static_cast<char_type>(usart_type::get()->dr);
            BaseType_t result = xQueueSendToBackFromISR(m_rxi_queue_handle, &ch, &HigherPriorityTaskHasWoken);
            if ( result == errQUEUE_FULL){
            //set some led to indicate fail
              // Panic From ISR
            }
         }else{
         // must be txe
            if ( !xQueueIsQueueEmptyFromISR(m_txo_queue_handle)){
               char_type ch;
               xQueueReceiveFromISR(m_txo_queue_handle,&ch,&HigherPriorityTaskHasWoken);
               usart_type::get()->dr = ch;
            }
            if ( xQueueIsQueueEmptyFromISR(m_txo_queue_handle)){
               usart_type::get()->cr1. template bb_clearbit<usart_cr1_txeie>();
            }
         }
         portEND_SWITCHING_ISR(HigherPriorityTaskHasWoken);
      }

      static void flush()
      {
        //  taskENTER_CRITICAL();
          xQueueReset(m_txo_queue_handle);
          xQueueReset(m_rxi_queue_handle);
          constexpr uint8_t usart_cr1_txeie = 7;
          usart_type::get()->cr1. template bb_clearbit<usart_cr1_txeie>();
         // taskEXIT_CRITICAL();
      }

// ND
      static bool acquire_tx_mutex(TickType_t ticks_to_wait)
      {
    
         if ((m_tx_mutex_handle != nullptr) && 
               (!m_tx_mutex_in_use) && 
               (xSemaphoreTake(m_tx_mutex_handle,ticks_to_wait) == pdTRUE) ){
            m_tx_mutex_in_use = true;
            return true;
         }else{
            return false;
         }
      }
// ND
      static void release_tx_mutex()
      {
         if ((m_tx_mutex_in_use == true) && (xSemaphoreGive(m_tx_mutex_handle) == pdTRUE) ){
            m_tx_mutex_in_use = false;
         }else{
               //PANIC()
         }
      }
//ND
      static bool acquire_rx_mutex(TickType_t ticks_to_wait)
      {
    
         if ((m_rx_mutex_handle != nullptr) && 
               (!m_rx_mutex_in_use) && 
               (xSemaphoreTake(m_rx_mutex_handle,ticks_to_wait) == pdTRUE) ){
            m_rx_mutex_in_use = true;
            return true;
         }else{
            return false;
         }
      }
//ND
      static void release_rx_mutex()
      {
         if ((m_rx_mutex_in_use == true) && (xSemaphoreGive(m_rx_mutex_handle) == pdTRUE) ){
            m_rx_mutex_in_use = false;
         }else{
               //PANIC()
         }
      }

   private:
// ND
      // always called in critical
      static void setup_txo_queue(UBaseType_t queue_size)
      {
        if ( m_txo_queue_handle  !=  nullptr ){
           while ( out_waiting() > 0){
            // taskEXIT_CRITICAL();
              vTaskDelay(1);
             //while (out_waiting()){taskYIELD();}
             
             //taskENTER_CRITICAL();
           }
           if ( queue_size != m_tx_queue_size){
              vQueueDelete(m_txo_queue_handle);
              m_txo_queue_handle = xQueueCreate(queue_size, sizeof(char_type));
           }
        }else{
            m_txo_queue_handle = xQueueCreate(queue_size, sizeof(char_type));
        }
        if (m_txo_queue_handle == nullptr){
            // PANIC();
        }else{
            m_tx_queue_size = queue_size;
        }
      }
//ND
      // in critical
      static void setup_rxi_queue(UBaseType_t queue_size)
      {
        if ( m_rxi_queue_handle != nullptr){  
          if ( queue_size != m_rx_queue_size){
            // kill any input
           vQueueDelete(m_rxi_queue_handle);
           m_rxi_queue_handle = xQueueCreate(queue_size, sizeof(char_type));
          }
        }else{
           m_rxi_queue_handle = xQueueCreate(queue_size, sizeof(char_type));
        }  
        if (m_rxi_queue_handle == 0){
            //PANIC()
        }else{
            m_rx_queue_size = queue_size;
        }
      }
//ND
      static void setup_tx_mutex()
      {
        // todo check already inited
        if ( m_tx_mutex_handle == nullptr){
            m_tx_mutex_handle = xSemaphoreCreateMutex();
        }
        if (m_tx_mutex_handle == nullptr){
             // PANIC()
        }
      }
//ND
      static void setup_rx_mutex()
      {
        // todo check already inited
        if ( m_rx_mutex_handle == nullptr){
            m_rx_mutex_handle = xSemaphoreCreateMutex();
        }
        if (m_rx_mutex_handle == nullptr){
             // PANIC()
        }
      }

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

      static QueueHandle_t          m_rxi_queue_handle;
      static QueueHandle_t          m_txo_queue_handle;
      static UBaseType_t            m_tx_queue_size;
      static UBaseType_t            m_rx_queue_size;
      static UBaseType_t            m_interrupt_priority;
      static SemaphoreHandle_t      m_tx_mutex_handle;
      static bool                   m_tx_mutex_in_use;
      static SemaphoreHandle_t      m_rx_mutex_handle;
      static bool                   m_rx_mutex_in_use;
      static bool                   m_blocking_mode; 
      static uint32_t               m_baudrate;
      static bool                   m_is_initialised;
 
   };

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   QueueHandle_t usart_tx_rx_task<Usart,TxPin,RxPin>::m_rxi_queue_handle = 0;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   QueueHandle_t usart_tx_rx_task< Usart,TxPin,RxPin>::m_txo_queue_handle = 0;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   SemaphoreHandle_t usart_tx_rx_task< Usart,TxPin,RxPin>::m_tx_mutex_handle = 0;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   SemaphoreHandle_t usart_tx_rx_task< Usart,TxPin,RxPin>::m_rx_mutex_handle = 0;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   bool usart_tx_rx_task<Usart,TxPin,RxPin>::m_tx_mutex_in_use = false;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   uint32_t usart_tx_rx_task<Usart,TxPin,RxPin>::m_baudrate = 57600;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   bool usart_tx_rx_task<Usart,TxPin,RxPin>::m_blocking_mode = false;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   bool usart_tx_rx_task<Usart,TxPin,RxPin>::m_rx_mutex_in_use = false;


   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   bool usart_tx_rx_task<Usart,TxPin,RxPin>::m_is_initialised = false;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   UBaseType_t usart_tx_rx_task<Usart,TxPin,RxPin>::m_tx_queue_size = 500;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   UBaseType_t usart_tx_rx_task<Usart,TxPin,RxPin>::m_rx_queue_size = 500;

   template <
      typename Usart
      ,typename TxPin
      ,typename RxPin
   >
   UBaseType_t usart_tx_rx_task<Usart,TxPin,RxPin>::m_interrupt_priority = 14;

}}}} // quan::stm32::freertos::apm

#endif // QUAN_STM32_FREERTOS_APM_USART_TASK_HPP_INCLUDED
