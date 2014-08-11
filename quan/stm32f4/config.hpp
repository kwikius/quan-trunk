#ifndef QUAN_STM32F4_CONFIG_HPP_INCLUDED1
#define QUAN_STM32F4_CONFIG_HPP_INCLUDED1
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

#ifndef QUAN_STM32F4
#define QUAN_STM32F4
#endif

#ifndef QUAN_FLOAT_TYPE
#define QUAN_FLOAT_TYPE float
#endif

/* 
add constants defining supply_voltage
 #define QUAN_STM32F4_SUPPLY_VOLTAGE 3600
*/

// defaults for stm32f4 discovery board
#ifndef QUAN_STM32F4_SOURCE_CLOCK_Hz
#define QUAN_STM32F4_SOURCE_CLOCK_Hz  8000000
#endif

#ifndef QUAN_STM32F4_SYSCLK_Hz
#define QUAN_STM32F4_SYSCLK_Hz  168000000
#endif

#ifndef QUAN_STM32F4_AHB_DIVISOR
#define QUAN_STM32F4_AHB_DIVISOR 1
#endif

#ifndef QUAN_STM32F4_APB1_DIVISOR
  #define QUAN_STM32F4_APB1_DIVISOR 4
#endif

#ifndef QUAN_STM32F4_APB2_DIVISOR
  #define QUAN_STM32F4_APB2_DIVISOR 2
#endif
// required by CMSIS
extern "C" uint32_t SystemCoreClock;

//// QUAN_STM32F4_PLL_VCO_INPUT_Hz can be any value between 1 and 2 MHz though 2 MHz is recommended
//// to avoid jitter. ref man 5.3.2
// if not defined attempt to calculate it internally
//#define QUAN_STM32F4_PLL_VCO_INPUT_Hz 2000000


#endif // QUAN_STM32F4_CONFIG_HPP_INCLUDED
