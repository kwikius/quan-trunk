#ifndef QUAN_STM32_RCC_HPP_INCLUDED
#define QUAN_STM32_RCC_HPP_INCLUDED


#if defined QUAN_STM32F4
#include <quan/stm32/f4/rcc.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/rcc.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/rcc.hpp>
#else
#error need to define stm32 rcc
#endif

#endif // QUAN_STM32_RCC_HPP_INCLUDED
