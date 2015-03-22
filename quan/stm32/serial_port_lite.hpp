#ifndef QUAN_STM32_SERIAL_PORT_LITE_HPP_INCLUDED
#define QUAN_STM32_SERIAL_PORT_LITE_HPP_INCLUDED
/*
 Copyright (c) 2003-2015 Andy Little.

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
#include <quan/stm32/config.hpp>
#include <quan/meta/bool.hpp>
#include <quan/concepts/port.hpp>
#include <quan/stm32/usart.hpp>
#include <quan/stm32/usart/get_alternate_function.hpp>

/*
  ligheweight serial port not using buffers or interrupts
*/

namespace quan{ namespace stm32{

   template <
      typename Usart,
      typename TxPin, 
      typename RxPin
   >
   struct serial_port_lite{

      typedef Usart usart_type;
      typedef char char_type;
      typedef TxPin tx_pin_type;
      typedef RxPin rx_pin_type;

private:
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
public:
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
         return usart_type::get()->cr1.template getbit<enable_bit>();
      }

      static bool tx_reg_empty()
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
private:
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

    public:
      static void init() 
      {
         quan::stm32::module_reset<usart_type>();

         quan::stm32::module_enable<usart_type>();
// add here tx pin open drain no pullup option
         setup_TxPin();
         setup_RxPin();
// these settings must be applied with usart disabled
         apply<
            usart_type
            ,usart::asynchronous
            ,usart::transmitter<true>
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
          bool enabled = serial_port_lite::is_enabled();
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

      //blocking
      static void put( char ch)
      {
         while ( !tx_reg_empty()){;}
         ll_put(ch);
      }

      static void write(const char* str, size_t len)
      {
         if (str){
         for ( size_t i = 0; i < len; ++i) {
           put(str[i]);
         }
         }
      }

      static void write(const char* str)
      {
         if ( str){
           write(str,strlen(str));
         }
      }

      static uint32_t in_avail()
      {
          return (ll_rx_reg_full())?1 : 0;
      }

      // may fail
      static bool get(char & ch)
      {
         if (ll_rx_reg_full()){
            ch = ll_get();
            return true;
         }else{
            return false;
         }
      }
    
   private:

     typedef typename quan::stm32::get_alternate_function<
         TxPin,usart_type,quan::stm32::usart::tx_pin
     >::type tx_gpio_af_type;

     static_assert(!std::is_same<tx_gpio_af_type,quan::undefined>::value,"tx pin invalid for alternate function");
      typedef typename quan::stm32::get_alternate_function<
         RxPin,usart_type,quan::stm32::usart::rx_pin
     >::type rx_gpio_af_type;

     static_assert(!std::is_same<rx_gpio_af_type,quan::undefined>::value,"rx pin invalid for alternate function");

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

      serial_port_lite() = delete;
      serial_port_lite(const serial_port_lite &) = delete;
      serial_port_lite operator = (const serial_port_lite &) = delete;
   };

}}

namespace quan{ namespace impl{

   template <typename Usart,typename TxPin, typename RxPin>
   struct is_model_of_impl<
   quan::StaticPort,
      quan::stm32::serial_port_lite<Usart,TxPin,RxPin> 
   >: quan::meta::true_{};

}}

#endif // QUAN_STM32_SERIAL_PORT_LITE_HPP_INCLUDED
