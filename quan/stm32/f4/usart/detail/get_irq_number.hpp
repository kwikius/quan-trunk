#ifndef QUAN_STM32_F4_USART_DETAIL_GET_HANDLER_HPP_INCLUDED
#define QUAN_STM32_F4_USART_DETAIL_GET_HANDLER_HPP_INCLUDED

#ifndef QUAN_STM32F4
#error dont include directly
#endif

#include <stm32f4xx.h>
#include <type_traits>
#include <quan/stm32/f4/config.hpp>
#include <quan/stm32/usart/typedefs.hpp>

namespace quan{ namespace stm32{ namespace usart{

   template < typename Usart>
   struct get_irq_number;

   template <> struct get_irq_number<quan::stm32f4::usart1> : std::integral_constant< IRQn_Type,USART1_IRQn>{};
   template <> struct get_irq_number<quan::stm32f4::usart2> : std::integral_constant<IRQn_Type,USART2_IRQn>{};
   template <> struct get_irq_number<quan::stm32f4::usart3> : std::integral_constant<IRQn_Type,USART3_IRQn>{};
   template <> struct get_irq_number<quan::stm32f4::uart4> : std::integral_constant<IRQn_Type,UART4_IRQn>{};
   template <> struct get_irq_number<quan::stm32f4::uart5> : std::integral_constant<IRQn_Type,UART5_IRQn>{};
   template <> struct get_irq_number<quan::stm32f4::usart6> : std::integral_constant<IRQn_Type,USART6_IRQn>{};

}}}

#endif // QUAN_STM32F4_USART_GET_HANDLER_HPP_INCLUDED
