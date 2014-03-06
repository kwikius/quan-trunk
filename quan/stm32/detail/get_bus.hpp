#ifndef QUAN_STM32_DETAIL_GET_BUS_HPP_INCLUDED
#define QUAN_STM32_DETAIL_GET_BUS_HPP_INCLUDED

#if defined QUAN_STM32F4
#include <quan/stm32/f4/detail/get_bus.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/detail/get_bus.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/detail/get_bus.hpp>
#else
#error need to define stm32 processor
#endif

#endif // QUAN_STM32_GET_BUS_HPP_INCLUDED
