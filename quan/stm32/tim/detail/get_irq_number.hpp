#ifndef QUAN_STM32_TIM_DETAIL_GET_IRQ_NUMBER_HPP_INCLUDED
#define QUAN_STM32_TIM_DETAIL_GET_IRQ_NUMBER_HPP_INCLUDED
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

#include <quan/stm32/config.hpp>
#if defined QUAN_STM32F4
#include <stm32f4xx.h>
#elif defined QUAN_STM32L4
#include <stm32l4xx.h>
#elif defined QUAN_STM32F0
#include <stm32f0xx.h>
#else
#error need to define stm32 processor
#endif

#include <type_traits>
#include <quan/stm32/tim/typedefs.hpp>

namespace quan{ namespace stm32{ namespace tim{ namespace detail{

   template < typename Tim>
   struct get_irq_number;

#if defined QUAN_STM32_HAS_TIM1
   #if defined QUAN_STM32F4
      template <> struct get_irq_number<quan::stm32::tim1> : std::integral_constant<IRQn_Type,TIM1_UP_TIM10_IRQn>{};
   #elif defined QUAN_STM32L4
      template <> struct get_irq_number<quan::stm32::tim1> : std::integral_constant<IRQn_Type,TIM1_UP_TIM16_IRQn>{};
   #else
      // For F0 there are 2 -> TIM1_BRK_UP_TRG_COM_IRQn and TIM1_CC_IRQn
      #error need to define processor
   #endif
#endif

#if defined QUAN_STM32_HAS_TIM2
   template <> struct get_irq_number<quan::stm32::tim2> : std::integral_constant<IRQn_Type,TIM2_IRQn>{};
#endif

#if defined QUAN_STM32_HAS_TIM3
   template <> struct get_irq_number<quan::stm32::tim3> : std::integral_constant<IRQn_Type,TIM3_IRQn>{};
#endif

#if defined QUAN_STM32_HAS_TIM4
   template <> struct get_irq_number<quan::stm32::tim4> : std::integral_constant<IRQn_Type,TIM4_IRQn>{};
#endif

#if defined QUAN_STM32_HAS_TIM5
   template <> struct get_irq_number<quan::stm32::tim5> : std::integral_constant<IRQn_Type,TIM5_IRQn>{};
#endif

#if defined QUAN_STM32_HAS_TIM6
   #if (defined(QUAN_STM32F4) || defined(QUAN_STM32L4) || defined(QUAN_STM32F0))
      template <> struct get_irq_number<quan::stm32::tim6> : std::integral_constant<IRQn_Type,TIM6_DAC_IRQn>{};
   #else
      #error need to define processor
   #endif
#endif

#if defined QUAN_STM32_HAS_TIM7
   template <> struct get_irq_number<quan::stm32::tim7> : std::integral_constant<IRQn_Type,TIM7_IRQn>{};
#endif

#if defined QUAN_STM32_HAS_TIM8
   #if defined QUAN_STM32F4
      template <> struct get_irq_number<quan::stm32::tim8> : std::integral_constant<IRQn_Type,TIM8_UP_TIM13_IRQn>{};
   #else
      #error need to define processor
   #endif
#endif

#if defined QUAN_STM32_HAS_TIM9
   #if defined QUAN_STM32F4
      template <> struct get_irq_number<quan::stm32::tim9> : std::integral_constant<IRQn_Type,TIM1_BRK_TIM9_IRQn>{};
   #else
      #error need to define processor
   #endif
#endif
#if defined QUAN_STM32_HAS_TIM10
   #if defined QUAN_STM32F4
      template <> struct get_irq_number<quan::stm32::tim10> : std::integral_constant<IRQn_Type,TIM1_UP_TIM10_IRQn>{};
   #else
      #error need to define processor
   #endif
#endif
#if defined QUAN_STM32_HAS_TIM11
   template <> struct get_irq_number<quan::stm32::tim11> : std::integral_constant<IRQn_Type,TIM11_IRQn>{};
#endif

#if defined QUAN_STM32_HAS_TIM12
   #if defined QUAN_STM32F4
      template <> struct get_irq_number<quan::stm32::tim12> : std::integral_constant<IRQn_Type,TIM8_BRK_TIM12_IRQn>{};
   #else
      #error need to define processor
   #endif
#endif
#if defined QUAN_STM32_HAS_TIM13
   #if defined QUAN_STM32F4
      template <> struct get_irq_number<quan::stm32::tim13> : std::integral_constant<IRQn_Type,TIM8_UP_TIM13_IRQn>{};
   #else
      #error need to define processor
   #endif
#endif

#if defined QUAN_STM32_HAS_TIM14
   #if defined QUAN_STM32F4 
      template <> struct get_irq_number<quan::stm32::tim14> : std::integral_constant<IRQn_Type,TIM8_TRG_COM_TIM14_IRQn>{};
   #else
      #if defined QUAN_STM32F0
         template <> struct get_irq_number<quan::stm32::tim14> : std::integral_constant<IRQn_Type,TIM14_IRQn>{};
      # else
         #error need to define processor
      #endif
   #endif
#endif

#if defined QUAN_STM32_HAS_TIM15
   #if defined QUAN_STM32L4
   template <> struct get_irq_number<quan::stm32::tim15> : std::integral_constant<IRQn_Type,TIM1_BRK_TIM15_IRQn>{};
   #else
      #if defined QUAN_STM32F0
         template <> struct get_irq_number<quan::stm32::tim15> : std::integral_constant<IRQn_Type,TIM15_IRQn>{};
      #else
         #error need to define processor
      #endif
   #endif
#endif

#if defined QUAN_STM32_HAS_TIM16
   #if defined QUAN_STM32L4
   template <> struct get_irq_number<quan::stm32::tim16> : std::integral_constant<IRQn_Type,TIM1_UP_TIM16_IRQn>{};
   #else
      #if defined QUAN_STM32F0
         template <> struct get_irq_number<quan::stm32::tim16> : std::integral_constant<IRQn_Type,TIM16_IRQn>{};
      #else
         #error need to define processor
      #endif
   #endif
#endif

#if defined QUAN_STM32_HAS_TIM17
   #if defined QUAN_STM32F0
     template <> struct get_irq_number<quan::stm32::tim17> : std::integral_constant<IRQn_Type,TIM1_UP_TIM17_IRQn>{};
   #else
      #error need to define processor
   #endif
#endif


}}}}

#endif // QUAN_STM32_USART_DETAIL_GET_IRQ_NUMBER_HPP_INCLUDED


