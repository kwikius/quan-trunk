#ifndef QUAN_STM32_BITBAND_HPP_INCLUDED
#define QUAN_STM32_BITBAND_HPP_INCLUDED

#if defined QUAN_STM32F4
#include <quan/stm32/f4/bitband.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/bitband.hpp>
#else
#error need to define stm32 processor bitbanding
#endif

#endif // QUAN_STM32_BITBAND_HPP_INCLUDED
