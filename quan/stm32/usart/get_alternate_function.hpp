#ifndef QUAN_STM32_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
#define QUAN_STM32_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
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

#if defined QUAN_STM32F4
#include <quan/stm32/f4/usart/get_alternate_function.hpp>
#elif defined QUAN_STM32L4
#include <quan/stm32/l4/usart/get_alternate_function.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/usart/get_alternate_function.hpp>
#else
#error need to define stm32 processor
#endif

#endif

