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

#define QUAN_STM32_HAS_USART1 1
#define QUAN_STM32_HAS_USART2 1
#define QUAN_STM32_HAS_USART3 1
#define QUAN_STM32_HAS_UART4 1
#define QUAN_STM32_HAS_UART5 1
#define QUAN_STM32_HAS_USART6 1

#include <quan/stm32/f4/periph_map.hpp>

#ifndef QUAN_STM32_SOURCE_CLOCK_Hz
#define QUAN_STM32_SOURCE_CLOCK_Hz  8000000
#endif

#ifndef QUAN_STM32_SYSCLK_Hz
#define QUAN_STM32_SYSCLK_Hz  168000000
#endif

#ifndef QUAN_STM32_AHB1_DIVISOR
#define QUAN_STM32_AHB1_DIVISOR 1
#endif

#ifndef QUAN_STM32_AHB2_DIVISOR
#define QUAN_STM32_AHB2_DIVISOR 1
#endif

#ifndef QUAN_STM32_AHB3_DIVISOR
#define QUAN_STM32_AHB3_DIVISOR 1
#endif

#ifndef QUAN_STM32_APB2_DIVISOR
#define QUAN_STM32_APB2_DIVISOR 2
#endif

#ifndef QUAN_STM32_APB1_DIVISOR
#define QUAN_STM32_APB1_DIVISOR 4
#endif

#endif // QUAN_STM32_F4_CONFIG_HPP_INCLUDED
