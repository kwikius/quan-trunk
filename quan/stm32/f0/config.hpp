#ifndef QUAN_STM32_F0_CONFIG_HPP_INCLUDED
#define QUAN_STM32_F0_CONFIG_HPP_INCLUDED
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

#include <cstdint>

#ifndef QUAN_STM32F0
#error dont include directly
#endif

#define QUAN_STM32_HAS_GPIOA 1
#define QUAN_STM32_HAS_GPIOB 1
#define QUAN_STM32_HAS_GPIOC 1
#define QUAN_STM32_HAS_GPIOD 1
#define QUAN_STM32_HAS_GPIOF 1

#define QUAN_STM32_HAS_TIM1  1
#define QUAN_STM32_HAS_TIM2  1
#define QUAN_STM32_HAS_TIM3  1

#define QUAN_STM32_HAS_TIM6  1

#define QUAN_STM32_HAS_TIM14  1
#define QUAN_STM32_HAS_TIM15  1
#define QUAN_STM32_HAS_TIM16  1
#define QUAN_STM32_HAS_TIM17  1

#define QUAN_STM32_HAS_USART1 1
#define QUAN_STM32_HAS_USART2 1

#define QUAN_STM32_HAS_SPI1 1
#define QUAN_STM32_HAS_SPI2 1

#include <quan/stm32/f0/periph_map.hpp>

#define QUAN_STM32_HAS_BITBANDING 0

// TODO others have these periphs too
#if defined QUAN_STM32_SUBFAMILY_05X

#define QUAN_STM32_HAS_DAC    1

#define QUAN_STM32_HAS_I2C1   1
#define QUAN_STM32_HAS_I2C2   1
//#elif defined QUAN_STM32_SUBFAMILY_03X
//  #define QUAN_STM32_HAS_DAC 0
#endif



// defaults for stm32f0 discovery board
// oscillator hsi etc
#ifndef QUAN_STM32_SOURCE_CLOCK_Hz
#define QUAN_STM32_SOURCE_CLOCK_Hz  8000000
#endif

// sysyclk after pll etc
#ifndef QUAN_STM32_SYSCLK_Hz
#define QUAN_STM32_SYSCLK_Hz  48000000
#endif

#ifndef QUAN_STM32_AHB_DIVISOR
#define QUAN_STM32_AHB_DIVISOR 1
#endif

#ifndef QUAN_STM32_APB_DIVISOR
#define QUAN_STM32_APB_DIVISOR 1
#endif

#endif // QUAN_STM32_F0_CONFIG_HPP_INCLUDED
