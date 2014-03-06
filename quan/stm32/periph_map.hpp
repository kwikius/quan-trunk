#ifndef QUAN_STM32_PERIPH_MAP_HPP_INCLUDED
#define QUAN_STM32_PERIPH_MAP_HPP_INCLUDED

#if defined QUAN_STM32F4
#include <quan/stm32/f4/periph_map.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/periph_map.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/periph_map.hpp>
#else
#error need to define stm32 processor
#endif

#endif // QUAN_STM32_PERIPH_MAP_HPP_INCLUDED
