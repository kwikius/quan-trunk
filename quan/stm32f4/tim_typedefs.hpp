#ifndef QUAN_STM32F4_TIM_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32F4_TIM_TYPEDEFS_HPP_INCLUDED

#include <quan/stm32f4/periph_map.hpp>

namespace quan { namespace stm32f4{

  namespace tim{

       template <uint32_t Address>
       struct module;
  }

typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim1> tim1;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim2> tim2;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim3> tim3;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim4> tim4;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim5> tim5;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim6> tim6;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim7> tim7;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim8> tim8;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim9> tim9;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim10> tim10;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim11> tim11;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim12> tim12;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim13> tim13;
typedef quan::stm32f4::tim::module<quan::stm32f4::periph_map::tim14> tim14;

}}

#endif // QUAN_STM32F4_TIM_TYPEDEFS_HPP_INCLUDED
