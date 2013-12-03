#ifndef QUAN_STM32_TIM_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32_TIM_TYPEDEFS_HPP_INCLUDED

#include <quan/stm32/config.hpp>
#include <quan/stm32/periph_map.hpp>

namespace quan { namespace stm32{

  namespace tim{

       template <uint32_t Address>
       struct module;
  }
#if defined QUAN_STM32_HAS_TIM1
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim1> tim1;
#endif
#if defined QUAN_STM32_HAS_TIM2
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim2> tim2;
#endif
#if defined QUAN_STM32_HAS_TIM3
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim3> tim3;
#endif
#if defined QUAN_STM32_HAS_TIM4
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim4> tim4;
#endif
#if defined QUAN_STM32_HAS_TIM5
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim5> tim5;
#endif
#if defined QUAN_STM32_HAS_TIM6
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim6> tim6;
#endif
#if defined QUAN_STM32_HAS_TIM7
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim7> tim7;
#endif
#if defined QUAN_STM32_HAS_TIM8
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim8> tim8;
#endif
#if defined QUAN_STM32_HAS_TIM9
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim9> tim9;
#endif
#if defined QUAN_STM32_HAS_TIM10
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim10> tim10;
#endif
#if defined QUAN_STM32_HAS_TIM11
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim11> tim11;
#endif
#if defined QUAN_STM32_HAS_TIM12
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim12> tim12;
#endif
#if defined QUAN_STM32_HAS_TIM13
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim13> tim13;
#endif
#if defined QUAN_STM32_HAS_TIM14
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim14> tim14;
#endif
#if defined QUAN_STM32_HAS_TIM15
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim15> tim15;
#endif
#if defined QUAN_STM32_HAS_TIM16
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim16> tim16;
#endif
#if defined QUAN_STM32_HAS_TIM17
typedef quan::stm32::tim::module<quan::stm32::periph_map::tim17> tim17;
#endif

}}

#endif // QUAN_STM32_TIM_TYPEDEFS_HPP_INCLUDED
