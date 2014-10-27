#ifndef QUAN_STM32_TX_SERIAL_PORT_HPP_INCLUDED
#define QUAN_STM32_TX_SERIAL_PORT_HPP_INCLUDED
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
 todo specialisations for rx only tx only ports
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

/*
 TODO
 add specialisations or options such that if tx or Rx BufferSize is 0 Then its rxonly or txonly etc
*/

namespace quan{ namespace stm32{

   namespace usart{
      template <typename SerialPort> void tx_irq_handler();
   }

   template <
      typename Usart,
      size_t TxBufSize,  
      typename TxPin
   >
   struct tx_serial_port{

      typedef Usart usart_type;
      typedef char char_type;
      typedef quan::fifo<char_type,TxBufSize,true> tx_fifo_type;
      typedef TxPin tx_pin_type;
  // private:
      friend void quan::stm32::usart::irq_handler<tx_serial_port>();
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

      static void enable_txeie()
      {
//#if QUAN_STM32_HAS_BITBANDING 
//         usart_type::get()->cr1. template bb_setbit<usart_cr1_txeie>();
//#else
         usart_type::get()->cr1. template setbit<usart_cr1_txeie>(); // bit(7)
//#endif
      }

      static void disable_txeie()
      {
//#if  QUAN_STM32_HAS_BITBANDING  
//         usart_type::get()->cr1. template bb_clearbit<usart_cr1_txeie>();
//#else
         usart_type::get()->cr1. template clearbit<usart_cr1_txeie>(); // bit(7)
//#endif
      }

      static bool ll_tx_reg_empty()
      {
#if defined QUAN_STM32F4
         return  usart_type::get()->sr. template getbit<usart_sr_txe>() ; 
#else
#if defined QUAN_STM32F0
         return  usart_type::get()->isr. template getbit<usart_isr_txe>() ; //bit(7)
#else
#error processor undefined 
#endif
#endif
      }

      static bool tx_reg_empty()
      {
        return ( m_tx_fifo.is_empty() && ll_tx_reg_empty());
      }

      static void ll_put( char ch)
      {
#if defined QUAN_STM32F4
         usart_type::get()->dr = ch;
#else
#if defined QUAN_STM32F0
         usart_type::get()->tdr = ch;
#else
#error processor undefined 
#endif
#endif
      }

    static bool ll_txeie_is_enabled()
    {
//#if QUAN_STM32_HAS_BITBANDING
//      return usart_type::get()-> cr1.template bb_getbit<usart_cr1_txeie>();
//#else
      return usart_type::get()->cr1.template getbit<usart_cr1_txeie>(); // bit(7)
//#endif

   }
   public:
     // add priority
     // baudrate etc
      // output style etc.
     // 
      static void init() 
      {
         m_tx_fifo.init(); 

         quan::stm32::module_reset<usart_type>();

         quan::stm32::module_enable<usart_type>();
// add here tx pin open drain no pullup option
         setup_TxPin();
// these settings must be applied with usart disabled
         apply<
            usart_type
            ,usart::asynchronous
            ,usart::transmitter<true>
            ,usart::receiver<false>
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
         enable<usart_type>();
      }

       // To set or clear Over consult data sheet
      // n.b usart must be disabled first
       
      template <uint32_t Baud, bool Over>
      static void set_baudrate()
      {
          bool enabled = tx_serial_port::is_enabled();
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

      static void put( char ch)
      {
         disable_txeie();
         m_tx_fifo.put(ch);
         enable_txeie();
      }

      static void write(const char* str)
      {
         for ( size_t i = 0, len = strlen(str); i < len; ++i) {
            tx_serial_port::put(str[i]);
         }
      }

      static void write(const char* str, size_t len)
      {
         for ( size_t i = 0; i < len; ++i) {
           tx_serial_port::put(str[i]);
         }
      }

   private:

     friend void quan::stm32::usart::irq_handler<tx_serial_port>();
     static tx_fifo_type m_tx_fifo;

     typedef typename quan::stm32::get_alternate_function<
         TxPin,usart_type,quan::stm32::usart::tx_pin
     >::type tx_gpio_af_type;

     static_assert(!std::is_same<tx_gpio_af_type,quan::undefined>::value,"tx pin invalid for alternate function");
     static void setup_TxPin()
      {
         module_enable<typename TxPin::port_type>();

/*
To interface 5V..
".
You should configure the GPIO as open drain and 
disable the internal pull-up (the external one 
only shall be used).

When the FT pin is then output-low, there is 
max allowed current 25mA through the pin.
In output-high guarantees the FT pin circuitry 
zero injection current when the external voltage 
applied to the pin is above VDD (and below VDD+4V)."
*/

         apply<
            TxPin             
            ,tx_gpio_af_type         
            ,gpio::otype::push_pull   // need open_drain amd pullup to 5V option here
            ,gpio::pupd::none         //  this is still corrrect. Use external pullup
            ,gpio::ospeed::slow       
         >();
      }   

      tx_serial_port() = delete;
      tx_serial_port(const tx_serial_port &) = delete;
      tx_serial_port operator = (const tx_serial_port &) = delete;
   };

   template <typename Usart,size_t TxBufSize, typename TxPin>
   typename tx_serial_port<Usart,TxBufSize,TxPin>::tx_fifo_type 
   tx_serial_port<Usart,TxBufSize,TxPin>::m_tx_fifo;

}}

namespace quan{ namespace impl{

   template <typename Usart,size_t TxBufSize, typename TxPin>
   struct is_model_of_impl<
   quan::StaticPort,
      quan::stm32::tx_serial_port<Usart,TxBufSize,TxPin> 
   >: quan::meta::true_{};

}}

#endif // QUAN_STM32_TX_SERIAL_PORT_HPP_INCLUDED
