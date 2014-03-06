#ifndef QUAN_STM32_TIM_DETAIL_MODULE_ENABLE_HPP_INCLUDED
#define QUAN_STM32_TIM_DETAIL_MODULE_ENABLE_HPP_INCLUDED

#include <quan/stm32/config.hpp>

#if defined QUAN_STM32F4
#include <quan/stm32/f4/tim/detail/module_enable_disable.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/tim/detail/module_enable_disable.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/tim/detail/module_enable_disable.hpp>
#else
#error need to define stm32 processor
#endif

#endif
