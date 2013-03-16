#ifndef QUAN_STM32F4_GPIO_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_TYPEDEFS_HPP_INCLUDED
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

#include <quan/stm32f4/periph_map.hpp>
#include <quan/stm32f4/gpio/module.hpp>

namespace quan{ namespace stm32f4 {

   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpioa> gpioa;
   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpiob> gpiob;
   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpioc> gpioc;
   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpiod> gpiod;
   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpioe> gpioe;
   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpiof> gpiof;
   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpiog> gpiog;
   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpioh> gpioh;
   typedef quan::stm32f4::gpio::module<quan::stm32f4::periph_map::gpioi> gpioi;

}}

#endif // QUAN_STM32F4_GPIO_TYPEDEFS_HPP_INCLUDED
