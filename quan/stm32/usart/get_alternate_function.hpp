#ifndef QUAN_STM32_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED
#define QUAN_STM32_USART_GET_ALTERNATE_FUNCTION_HPP_INCLUDED

#if defined QUAN_STM32F4
#include <quan/stm32/f4/usart/get_alternate_function.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/usart/get_alternate_function.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/usart/get_alternate_function.hpp>
#else
#error need to define stm32 processor
#endif

#endif

