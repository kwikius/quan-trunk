#ifndef QUAN_STM32_USART_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32_USART_TYPEDEFS_HPP_INCLUDED

#include <quan/stm32/config.hpp>
#include <quan/stm32/usart/module.hpp>
#include <quan/stm32/periph_map.hpp>

namespace quan{ namespace stm32{ 

#if defined QUAN_STM32_HAS_USART1
   typedef quan::stm32::usart::module<quan::stm32::periph_map::usart1> usart1;
#endif
#if defined QUAN_STM32_HAS_USART2
   typedef quan::stm32::usart::module<quan::stm32::periph_map::usart2> usart2;
#endif
#if defined QUAN_STM32_HAS_USART3
   typedef quan::stm32::usart::module<quan::stm32::periph_map::usart3> usart3;
#endif
#if defined QUAN_STM32_HAS_UART4
   typedef quan::stm32::usart::module<quan::stm32::periph_map::uart4>  uart4;
#endif
#if defined QUAN_STM32_HAS_UART5
   typedef quan::stm32::usart::module<quan::stm32::periph_map::uart5>  uart5;
#endif
#if defined QUAN_STM32_HAS_USART6
   typedef quan::stm32::usart::module<quan::stm32::periph_map::usart6> usart6;
#endif

}}// quan::stm32

#endif // QUAN_STM32F4_USART_TYPEDEFS_HPP_INCLUDED
