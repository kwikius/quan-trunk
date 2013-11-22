#ifndef QUAN_STM32_F0_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
#define QUAN_STM32_F0_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED

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
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,3>,quan::stm32::usart1,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af1 type;
   };

   template<>
   struct get_alternate_function< quan::mcu::pin<quan::stm32::gpioa,15>,quan::stm32::usart1,usart::rx_pin
   >
   {
      typedef quan::stm32::gpio::mode::af1 type;
   };

}}

#endif // QUAN_STM32_F0_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
