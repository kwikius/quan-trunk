#ifndef QUAN_STM32_GPIO_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32_GPIO_TYPEDEFS_HPP_INCLUDED
/*
 Copyright (c) 2012 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/


#include <quan/stm32/gpio/module.hpp>

namespace quan{ namespace stm32 {
#if defined QUAN_STM32_HAS_GPIOA
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpioa> gpioa;
#endif
#if defined QUAN_STM32_HAS_GPIOB
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpiob> gpiob;
#endif
#if defined QUAN_STM32_HAS_GPIOC
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpioc> gpioc;
#endif
#if defined QUAN_STM32_HAS_GPIOD
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpiod> gpiod;
#endif
#if defined QUAN_STM32_HAS_GPIOE
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpioe> gpioe;
#endif
#if defined QUAN_STM32_HAS_GPIOF
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpiof> gpiof;
#endif
#if defined QUAN_STM32_HAS_GPIOG
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpiog> gpiog;
#endif
#if defined QUAN_STM32_HAS_GPIOH
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpioh> gpioh;
#endif
#if defined QUAN_STM32_HAS_GPIOI
   typedef quan::stm32::gpio::module<quan::stm32::periph_map::gpioi> gpioi;
#endif

}}

#endif // QUAN_STM32F4_GPIO_TYPEDEFS_HPP_INCLUDED
