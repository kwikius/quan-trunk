#ifndef QUAN_STM32F4_USART_GET_HANDLER_HPP_INCLUDED
#define QUAN_STM32F4_USART_GET_HANDLER_HPP_INCLUDED
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

#include <stm32f4xx.h>
#include <quan/stm32f4/usart_typedefs.hpp>
#include  <type_traits>

namespace quan{ namespace stm32f4{ namespace usart{

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
