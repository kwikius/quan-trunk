#ifndef QUAN_STM32_SPI_MODULE_HPP_INCLUDED
#define QUAN_STM32_SPI_MODULE_HPP_INCLUDED

#if defined QUAN_STM32F4
#include <quan/stm32/f4/spi/module.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/spi/module.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/spi/module.hpp>
#else
#error 
#endif
#endif // QUAN_STM32_MODULE_HPP_INCLUDED
