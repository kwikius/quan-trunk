#ifndef QUAN_STM32_L4_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
#define QUAN_STM32_L4_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
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
//#error todo convert this for L4

#ifndef QUAN_STM32L4
#error dont include directly
#endif

#include <quan/stm32/l4/config.hpp>
#include <quan/stm32/usart/alternate_functions.hpp>
#include <quan/stm32/get_alternate_function.hpp>
#include <quan/stm32/gpio/pin.hpp>
#include <quan/stm32/gpio/typedefs.hpp>
#include <quan/stm32/usart/typedefs.hpp>

namespace quan{ namespace stm32{ 

/* USART1
PA9  AF7  USART1_TX
PA10 AF7  USART1_RX
PB6  AF7  USART1_TX
PB7  AF7  USART1_RX
//TODO
PG9  AF7  USART1_TX
PG10 AF7  USART1_RX
*/

   template<>
   struct get_alternate_function< 
         quan::mcu::pin<quan::stm32::gpioa,9>,quan::stm32::usart1,usart::tx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af7 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,10>,quan::stm32::usart1,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af7 type;
   };

   template<>
   struct get_alternate_function< 
         quan::mcu::pin<quan::stm32::gpiob,6>,quan::stm32::usart1,usart::tx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af7 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpiob,7>,quan::stm32::usart1,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af7 type;
   };

/*
USART2
PA2  AF7  USART2_TX
PA3  AF7  USART2_RX
only on 431 432, 496 not on 4A6
PA15 AF3  USART2_RX

TODO
PD5  AF7  USART2_TX
PD6  AF7  USART2_RX
*/

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,2>,quan::stm32::usart2,usart::tx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af7 type;
   };


   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,3>,quan::stm32::usart2,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af7 type;
   };

//TODO only on 431 432, 496 not on 4A6
   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,15>,quan::stm32::usart2,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af3 type;
   };

// TODO USART3, UART4 etc

}} // quan::stm32

#endif // QUAN_STM32_L4_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
