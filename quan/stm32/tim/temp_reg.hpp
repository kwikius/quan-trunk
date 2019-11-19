#ifndef QUAN_STM32_TIM_TEMP_REG_HPP_INCLUDED
#define QUAN_STM32_TIM_TEMP_REG_HPP_INCLUDED

#if defined QUAN_STM32F4
#include <quan/stm32/f4/tim/temp_reg.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/tim/temp_reg.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/tim/temp_reg.hpp>
#elif defined QUAN_STM32L4
#include <quan/stm32/l4/tim/temp_reg.hpp>
#else
#error need to define stm32 processor
#endif

#endif // QUAN_STM32_TIM_TEMP_REG_HPP_INCLUDED
