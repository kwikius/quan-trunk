#ifndef QUAN_STM32F4_TIM_GET_BUS_HPP_INCLUDED
#define QUAN_STM32F4_TIM_GET_BUS_HPP_INCLUDED

#include <quan/stm32f4/detail/get_bus.hpp>
#include <quan/stm32f4/tim_typedefs.hpp>

namespace quan { namespace stm32f4{ namespace detail{

#define QUAN_STM32F4_GET_TIM_BUS(Tim,Bus) template <> struct get_bus<quan::stm32f4::Tim> { typedef quan::stm32f4::detail:: Bus type;};

      QUAN_STM32F4_GET_TIM_BUS(tim1,apb2)
      QUAN_STM32F4_GET_TIM_BUS(tim2,apb1) 
      QUAN_STM32F4_GET_TIM_BUS(tim3,apb1)
      QUAN_STM32F4_GET_TIM_BUS(tim4,apb1)
      QUAN_STM32F4_GET_TIM_BUS(tim5,apb1)
      QUAN_STM32F4_GET_TIM_BUS(tim6,apb1) 
      QUAN_STM32F4_GET_TIM_BUS(tim7,apb1)
      QUAN_STM32F4_GET_TIM_BUS(tim8,apb2)
      QUAN_STM32F4_GET_TIM_BUS(tim9,apb2)
      QUAN_STM32F4_GET_TIM_BUS(tim10,apb2) 
      QUAN_STM32F4_GET_TIM_BUS(tim11,apb2)
      QUAN_STM32F4_GET_TIM_BUS(tim12,apb1)
      QUAN_STM32F4_GET_TIM_BUS(tim13,apb1)
      QUAN_STM32F4_GET_TIM_BUS(tim14,apb1) 

#undef QUAN_STM32F4_GET_TIM_BUS

}}}

#endif // QUAN_STM32F4_TIM_GET_BUS_HPP_INCLUDED
