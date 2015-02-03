#ifndef QUAN_STM32_F0_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
#define QUAN_STM32_F0_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
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

#ifndef QUAN_STM32F0
#error dont include directly
#endif

#include <quan/stm32/f0/config.hpp>
#include <quan/stm32/get_alternate_function.hpp>
#include <quan/stm32/gpio/pin.hpp>
#include <quan/stm32/gpio/typedefs.hpp>
#include <quan/stm32/usart/typedefs.hpp>
#include <quan/stm32/f0/usart/alternate_functions.hpp>

namespace quan{ namespace stm32{ 

   template<>
   struct get_alternate_function< 
         quan::mcu::pin<quan::stm32::gpioa,9>,quan::stm32::usart1,usart::tx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af1 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpiob,6>,quan::stm32::usart1,usart::tx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af0 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,10>,quan::stm32::usart1,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af1 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpiob,7>,quan::stm32::usart1,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af0 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,2>,quan::stm32::usart2,usart::tx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af1 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,14>,quan::stm32::usart2,usart::tx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af1 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,3>,quan::stm32::usart2,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af1 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,15>,quan::stm32::usart2,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af1 type;
   };

}}

#endif // QUAN_STM32_F0_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
