#ifndef QUAN_STM32_SYSCFG_HPP_INCLUDED
#define QUAN_STM32_SYSCFG_HPP_INCLUDED


#if defined QUAN_STM32F4
#include <quan/stm32/f4/syscfg.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/syscfg.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/syscfg.hpp>
#else
#error need to define stm32 processor syscfg.hpp
#endif

#endif // QUAN_STM32_SYSCFG_HPP_INCLUDED
