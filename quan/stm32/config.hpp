#ifndef QUAN_STM32_CONFIG_HPP
#define QUAN_STM32_CONFIG_HPP

/*
 Copyright (c) 2007-2013 Andy Little 

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

/* 
add constants defining supply_voltage?
 #define QUAN_STM32F4_SUPPLY_VOLTAGE 3600
*/
#include <cstdint>
#ifndef QUAN_NO_EXCEPTIONS
#define QUAN_NO_EXCEPTIONS
#endif

#ifndef QUAN_FLOAT_TYPE
#define QUAN_FLOAT_TYPE float
#endif

#if defined QUAN_STM32F4
#include <quan/stm32/f4/config.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/config.hpp>
#elif defined QUAN_STM32L4
#include <quan/stm32/l4/config.hpp>
#else
#error need to define stm32 processor
#endif

// required by CMSIS
extern "C" uint32_t SystemCoreClock;

#endif

