#ifndef QUAN_STM32_F4_CONFIG_HPP_INCLUDED
#define QUAN_STM32_F4_CONFIG_HPP_INCLUDED

/*
 Copyright (c) 2013 Andy Little 

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

#ifndef QUAN_STM32F4
#error dont include directly
#endif

#define QUAN_STM32_HAS_BITBANDING 1
#define QUAN_STM32_HAS_DAC 1

#define QUAN_STM32_HAS_GPIOA 1
#define QUAN_STM32_HAS_GPIOB 1
#define QUAN_STM32_HAS_GPIOC 1
#define QUAN_STM32_HAS_GPIOD 1
#define QUAN_STM32_HAS_GPIOE 1
#define QUAN_STM32_HAS_GPIOF 1
#define QUAN_STM32_HAS_GPIOG 1
#define QUAN_STM32_HAS_GPIOH 1
#define QUAN_STM32_HAS_GPIOI 1

#define QUAN_STM32_HAS_TIM1  1
#define QUAN_STM32_HAS_TIM2  1
#define QUAN_STM32_HAS_TIM3  1
#define QUAN_STM32_HAS_TIM4  1
#define QUAN_STM32_HAS_TIM5  1
#define QUAN_STM32_HAS_TIM6  1
#define QUAN_STM32_HAS_TIM7  1
#define QUAN_STM32_HAS_TIM8  1
#define QUAN_STM32_HAS_TIM9  1
#define QUAN_STM32_HAS_TIM10 1
#define QUAN_STM32_HAS_TIM11 1
#define QUAN_STM32_HAS_TIM12 1
#define QUAN_STM32_HAS_TIM13 1
#define QUAN_STM32_HAS_TIM14  1

#define QUAN_STM32_HAS_USART1 1
#define QUAN_STM32_HAS_USART2 1
#define QUAN_STM32_HAS_USART3 1
#define QUAN_STM32_HAS_UART4 1
#define QUAN_STM32_HAS_UART5 1
#define QUAN_STM32_HAS_USART6 1

#define QUAN_STM32_HAS_I2C1   1
#define QUAN_STM32_HAS_I2C2   1
#define QUAN_STM32_HAS_I2C3   1

#define QUAN_STM32_HAS_SPI1 1
#define QUAN_STM32_HAS_SPI2 1
#define QUAN_STM32_HAS_SPI3 1

#include <quan/stm32/f4/periph_map.hpp>

// oscillator hsi etc
#ifndef QUAN_STM32_SOURCE_CLOCK_Hz
#define QUAN_STM32_SOURCE_CLOCK_Hz  8000000
#endif

// sysclk after pll etc
#ifndef QUAN_STM32_SYSCLK_Hz
#define QUAN_STM32_SYSCLK_Hz  168000000
#endif

// set in in rcc.cfgr.hpre
#ifndef QUAN_STM32_AHB_DIVISOR
#define QUAN_STM32_AHB_DIVISOR 1
#endif

#ifndef QUAN_STM32_APB2_DIVISOR
#define QUAN_STM32_APB2_DIVISOR 2
#endif

#ifndef QUAN_STM32_APB1_DIVISOR
#define QUAN_STM32_APB1_DIVISOR 4
#endif

#endif // QUAN_STM32_F4_CONFIG_HPP_INCLUDED
