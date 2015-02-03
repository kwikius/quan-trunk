#ifndef QUAN_STM32F4_TIM_GET_BUS_HPP_INCLUDED
#define QUAN_STM32F4_TIM_GET_BUS_HPP_INCLUDED
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
