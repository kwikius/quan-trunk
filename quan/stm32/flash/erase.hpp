#ifndef QUAN_STM32_FLASH_ERASE_HPP_INCLUDED
#define QUAN_STM32_FLASH_ERASE_HPP_INCLUDED

#if defined QUAN_STM32F4
#include <quan/stm32/f4/flash/erase.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/flash/erase.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/flash/erase.hpp>
#elif defined QUAN_STM32_SIM
 #include <quan/stm32/sim/flash/erase.hpp> 
#else
#error need to define stm32 processor
#endif

#endif // QUAN_STM32_FLASH_ERASE_HPP_INCLUDED
