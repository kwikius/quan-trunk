#ifndef QUAN_STM32_TIM_DETAIL_HAS_PERIPH_REG_XX_HPP_INCLUDED1
#define QUAN_STM32_TIM_DETAIL_HAS_PERIPH_REG_XX_HPP_INCLUDED1

#include <quan/stm32/config.hpp>

#if defined QUAN_STM32F4
#include <quan/stm32/f4/tim/detail/has_periph_reg_xx.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/tim/detail/has_periph_reg_xx.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/tim/detail/has_periph_reg_xx.hpp>
#else
#error need to define stm32 processor
#endif

#endif

