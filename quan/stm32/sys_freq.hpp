#ifndef QUAN_STM32_SYS_FREQ_HPP_INCLUDED
#define QUAN_STM32_SYS_FREQ_HPP_INCLUDED


#if defined QUAN_STM32F4
#include <quan/stm32/f4/sys_freq.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/sys_freq.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/sys_freq.hpp>
#else
#error 
#endif

#endif // QUAN_STM32_SYS_FREQ_HPP_INCLUDED
