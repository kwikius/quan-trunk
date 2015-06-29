#ifndef QUAN_STM32_MILLIS_HPP_INCLUDED
#define QUAN_STM32_MILLIS_HPP_INCLUDED

#if defined QUAN_FREERTOS
#include <quan/stm32/freertos/millis.hpp>
#else
#include <quan/stm32/systick.hpp>
#endif

#endif