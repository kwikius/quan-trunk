#ifndef QUAN_STM32_F4_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
#define QUAN_STM32_F4_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED

#ifndef QUAN_STM32F4
#error dont include directly
#endif

#include <quan/stm32/f4/config.hpp>
#include <quan/stm32/get_alternate_function.hpp>
#include <quan/stm32/gpio/pin.hpp>
#include <quan/stm32/gpio/typedefs.hpp>
#include <quan/stm32/usart/typedefs.hpp>
#include <quan/stm32/f4/usart/alternate_functions.hpp>

namespace quan{ namespace stm32{ 

   #define QUAN_MAKE_ALTERNATE_FUNCTION( Port, BitVal ,Usart, Fn, Af) \
   template<> \
   struct get_alternate_function< \
         quan::mcu::pin<quan::stm32:: Port , BitVal >,quan::stm32:: Usart ,usart:: Fn \
   > \
   { \
      typedef quan::stm32::gpio::mode:: Af type; \
   };

   QUAN_MAKE_ALTERNATE_FUNCTION(gpioa,0,uart4,tx_pin, af8)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpioa,1,uart4,rx_pin, af8)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpioa,2,usart2,tx_pin, af7)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpioa,3,usart2,rx_pin, af7)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpioa,9,usart1,tx_pin, af7)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpioa,10,usart1,rx_pin, af7)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpiob,6,usart1,tx_pin, af7)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpiob,7,usart1,rx_pin, af7)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpiob,10,usart3,tx_pin, af7)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpiob,11,usart3,rx_pin, af7)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpioc,6,usart6,tx_pin, af8)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpioc,7,usart6,rx_pin, af8)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpioc,10,uart4,tx_pin, af8)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpioc,11,uart4,rx_pin, af8)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpioc,10,usart3,tx_pin, af7)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpioc,11,usart3,rx_pin, af7)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpioc,12,uart5,tx_pin, af8)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpiod, 2,uart5,rx_pin, af8)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpiod,5,usart2,tx_pin, af7)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpiod,6,usart2,rx_pin, af7)
   
   QUAN_MAKE_ALTERNATE_FUNCTION(gpiod,8,usart3,tx_pin, af7)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpiod,9,usart3,rx_pin, af7)

   QUAN_MAKE_ALTERNATE_FUNCTION(gpiog,9,usart6,rx_pin, af8)
   QUAN_MAKE_ALTERNATE_FUNCTION(gpiog,14,usart6,tx_pin, af8)

 #undef QUAN_MAKE_ALTERNATE_FUNCTION

}}

#endif // QUAN_STM32_F4_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
