#ifndef QUAN_STM32_RX_SERIAL_PORT_HPP_INCLUDED
#define QUAN_STM32_RX_SERIAL_PORT_HPP_INCLUDED
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
/*
 serial port for rx only 
*/

#include <type_traits>

#include <cstdint>
#include <cstring>

#include <quan/meta/if.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/bool.hpp>
#include <quan/concepts/port.hpp>

#include <quan/utility/fifo.hpp>

#include <quan/stm32/config.hpp>
#include <quan/stm32/usart.hpp>
#include <quan/stm32/gpio.hpp>
#include <quan/stm32/usart/detail/get_irq_number.hpp>
#include <quan/stm32/usart/get_alternate_function.hpp>

namespace quan{ namespace stm32{

   namespace usart{
      template <typename SerialPort> void rx_irq_handler();
   }

   template <
      typename Usart,
      size_t RxBufSize, 
      typename RxPin
   >
   struct rx_serial_port{

      typedef Usart usart_type;
      typedef char char_type;
      typedef quan::fifo<char_type,RxBufSize,true> rx_fifo_type;
      typedef RxPin rx_pin_type;
  // private:

     // friend void quan::stm32::usart::rx_irq_handler<serial_port>();
      static constexpr uint8_t usart_cr1_rxneie = 5; //(RXNEIE)
      static constexpr uint8_t usart_cr1_txeie = 7; //(TXEIE)
#if defined QUAN_STM32F4
      static constexpr uint8_t usart_sr_rxne = 5;
      static constexpr uint8_t usart_sr_txe = 7;

#else
   #if defined QUAN_STM32F0
      static constexpr uint8_t usart_isr_rxne = 5;
      static constexpr uint8_t usart_isr_txe = 7;
   #else
      #error processor undefined 
   #endif
#endif

      static bool is_enabled()
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

//   #if QUAN_STM32_HAS_BITBANDING
//         return usart_type::get()->cr1.template bb_getbit<enable_bit>();
//   #else
         return usart_type::get()->cr1.template getbit<enable_bit>();
 //  #endif
      }

      static void enable_rxneie()
      {

//#if (QUAN_STM32_HAS_BITBANDING)  
//         usart_type::get()->cr1. template bb_setbit<usart_cr1_rxneie>();
//#else
         usart_type::get()->cr1. template setbit<usart_cr1_rxneie>(); // bit(5)
//#endif
      }

      static void disable_rxneie()
      {
//#if (QUAN_STM32_HAS_BITBANDING)  

//         usart_type::get()->cr1. template bb_clearbit<usart_cr1_rxneie>();
//#else
         usart_type::get()->cr1. template clearbit<usart_cr1_rxneie>(); // bit(5)
//#endif
      }

      static bool ll_rx_reg_full()
      {
#if defined QUAN_STM32F4
        return usart_type::get()->sr. template getbit<usart_sr_rxne>(); 
#else
#if defined QUAN_STM32F0
        return  usart_type::get()->isr. template getbit<usart_isr_rxne>() ; // bit(5)
#else
#error processor undefined 
#endif
#endif
      }

      static char ll_get()
      {
#if defined QUAN_STM32F4
        return static_cast<char>(usart_type::get()->dr);
#else
#if defined QUAN_STM32F0
        return static_cast<char>(usart_type::get()->rdr);
#else
#error processor undefined 
#endif
#endif
      }

      static bool ll_rxneie_is_enabled()
      {
//#if QUAN_STM32_HAS_BITBANDING
//         return usart_type::get()->cr1.template bb_getbit<usart_cr1_rxneie>();
//#else
         return usart_type::get()->cr1.template getbit<usart_cr1_rxneie>(); // bit(5)
//#endif
      }

   public:
     // add priority
     // baudrate etc
      // output style etc.
     // 
      static void init() 
      {
  
         m_rx_fifo.init();

         quan::stm32::module_reset<usart_type>();

         quan::stm32::module_enable<usart_type>();

         setup_RxPin();
// these settings must be applied with usart disabled
         apply<
            usart_type
            ,usart::asynchronous
            ,usart::transmitter<false>
            ,usart::receiver<true>
            ,usart::baud_rate<9600,false>
            ,usart::parity::none
            ,usart::data_bits<8>
            ,usart::stop_bits<1>
            ,usart::rts<false>
            ,usart::cts<false>
            ,usart::i_en::cts<false>
            ,usart::i_en::lbd<false>
            ,usart::i_en::txe<false>
            ,usart::i_en::tc<false>
            ,usart::i_en::rxne<false>
            ,usart::i_en::idle<false>
            ,usart::i_en::pe<false>
            ,usart::i_en::error<false>
         >();

         NVIC_EnableIRQ(quan::stm32::usart::detail::get_irq_number<usart_type>::value);

   // reset the status reg
#if defined QUAN_STM32F4
         usart_type::get()->sr = 0;
#else
#if defined QUAN_STM32F0
     // do we need to reset?
#endif
#endif
         enable_rxneie();

         enable<usart_type>();
      }

       // To set or clear Over consult data sheet
      // n.b usart must be disabled first
       
      template <uint32_t Baud, bool Over>
      static void set_baudrate()
      {
          bool enabled = rx_serial_port::is_enabled();
          if ( enabled){
            disable<usart_type>();
//######################################################
            // TODO need to wait now till all transfers completed
//########################################################
          }
         quan::stm32::apply<usart_type,usart::baud_rate<Baud,Over> >();
         if (enabled){
            enable<usart_type>();
         }
      }

      static void set_irq_priority(uint32_t priority)
      {
         NVIC_SetPriority(quan::stm32::usart::detail::get_irq_number<usart_type>::value,priority);
      }

      static uint32_t in_avail()
      {

         disable_rxneie();
         size_t result =  m_rx_fifo.num_in_buffer();
         enable_rxneie();

         return result;
      }

      static char get()
      {
         char result = '\0';
         disable_rxneie();
         if (!m_rx_fifo.is_empty()){
            result = m_rx_fifo.get();
         }
         enable_rxneie();
         return result;
      }
    
   private:

     friend void quan::stm32::usart::rx_irq_handler<rx_serial_port>();
     static rx_fifo_type m_rx_fifo;

      typedef typename quan::stm32::get_alternate_function<
         RxPin,usart_type,quan::stm32::usart::rx_pin
     >::type rx_gpio_af_type;

     static_assert(!std::is_same<rx_gpio_af_type,quan::undefined>::value,"rx pin invalid for alternate function");

     static void setup_RxPin()
      {
         module_enable<typename RxPin::port_type>();

         apply<
            RxPin
            ,rx_gpio_af_type
            ,gpio::pupd::pull_up
            ,gpio::ospeed::slow 
         >();
      }

      rx_serial_port() = delete;
      rx_serial_port(const rx_serial_port &) = delete;
      rx_serial_port operator = (const rx_serial_port &) = delete;
   };

   template <typename Usart, size_t RxBufSize, typename RxPin>
   typename rx_serial_port<Usart,RxBufSize,RxPin>::rx_fifo_type 
   rx_serial_port<Usart,RxBufSize,RxPin>::m_rx_fifo;

}}

namespace quan{ namespace impl{

   template <typename Usart,size_t RxBufSize, typename RxPin>
   struct is_model_of_impl<
   quan::StaticPort,
      quan::stm32::rx_serial_port<Usart,RxBufSize,RxPin> 
   >: quan::meta::true_{};

}}

#endif // QUAN_STM32_RX_SERIAL_PORT_HPP_INCLUDED
