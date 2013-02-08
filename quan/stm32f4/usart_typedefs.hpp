#ifndef QUAN_STM32F4_USART_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32F4_USART_TYPEDEFS_HPP_INCLUDED

#include <quan/stm32f4/usart/module.hpp>
#include <quan/stm32f4/periph_map.hpp>

namespace quan{ namespace stm32f4{ 

   typedef quan::stm32f4::usart::module<quan::stm32f4::periph_map::usart1> usart1;
   typedef quan::stm32f4::usart::module<quan::stm32f4::periph_map::usart2> usart2;
   typedef quan::stm32f4::usart::module<quan::stm32f4::periph_map::usart3> usart3;
   typedef quan::stm32f4::usart::module<quan::stm32f4::periph_map::uart4>  uart4;
   typedef quan::stm32f4::usart::module<quan::stm32f4::periph_map::uart5>  uart5;
   typedef quan::stm32f4::usart::module<quan::stm32f4::periph_map::usart6> usart6;

}}// quan::stm32f4

#endif // QUAN_STM32F4_USART_TYPEDEFS_HPP_INCLUDED
