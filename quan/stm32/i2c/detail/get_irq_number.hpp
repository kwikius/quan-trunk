#ifndef QUAN_STM32_I2C_DETAIL_GET_IRQ_NUMBER_HPP_INCLUDED
#define QUAN_STM32_I2C_DETAIL_GET_IRQ_NUMBER_HPP_INCLUDED

#include <quan/stm32/config.hpp>

#if defined QUAN_STM32F4
#include <stm32f4xx.h>
#elif defined QUAN_STM32F3
#include <stm32f3xx.h>
#elif defined QUAN_STM32F0
#include <stm32f0xx.h>
#else
#error need to define stm32 processor
#endif
#include <type_traits>
#include <quan/stm32/i2c/typedefs.hpp>

namespace quan{ namespace stm32{ namespace i2c{ namespace detail{

   template < typename I2C>
   struct get_event_irq_number;
   template < typename I2C>
   struct get_error_irq_number;
#if defined QUAN_STM32_HAS_I2C1
   template <> struct get_event_irq_number<quan::stm32::i2c1> : std::integral_constant<IRQn_Type,I2C1_EV_IRQn>{};
   template <> struct get_error_irq_number<quan::stm32::i2c1> : std::integral_constant<IRQn_Type,I2C1_ER_IRQn>{};
#endif
#if defined QUAN_STM32_HAS_I2C2
   template <> struct get_event_irq_number<quan::stm32::i2c2> : std::integral_constant<IRQn_Type,I2C2_EV_IRQn>{};
   template <> struct get_error_irq_number<quan::stm32::i2c2> : std::integral_constant<IRQn_Type,I2C2_ER_IRQn>{};
#endif
#if defined QUAN_STM32_HAS_I2C3
   template <> struct get_event_irq_number<quan::stm32::i2c3> : std::integral_constant<IRQn_Type,I2C3_EV_IRQn>{};
   template <> struct get_error_irq_number<quan::stm32::i2c3> : std::integral_constant<IRQn_Type,I2C3_ER_IRQn>{};
#endif

}}}} // quan::stm32::i2c::detail

#endif // QUAN_STM32_I2C_DETAIL_GET_IRQ_NUMBER_HPP_INCLUDED
