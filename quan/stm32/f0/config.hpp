#ifndef QUAN_STM32_F0_CONFIG_HPP_INCLUDED
#define QUAN_STM32_F0_CONFIG_HPP_INCLUDED

#include <cstdint>

#ifndef QUAN_STM32F0
#error dont include directly
#endif

#define QUAN_STM32_HAS_GPIOA 1
#define QUAN_STM32_HAS_GPIOB 1
#define QUAN_STM32_HAS_GPIOC 1
#define QUAN_STM32_HAS_GPIOD 1
#define QUAN_STM32_HAS_GPIOF 1

#define QUAN_STM32_HAS_USART1 1
#define QUAN_STM32_HAS_USART2 1

#include <quan/stm32/f0/periph_map.hpp>

#define QUAN_STM32_HAS_BITBANDING 0

#if defined QUAN_STM32_SUBFAMILY_05X
#define QUAN_STM32_HAS_DAC 1
#elif defined QUAN_STM32_SUBFAMILY_03X
  #define QUAN_STM32_HAS_DAC 0
#endif

// defaults for stm32f0 discovery board
#ifndef QUAN_STM32_SOURCE_CLOCK_Hz
#define QUAN_STM32_SOURCE_CLOCK_Hz  8000000
#endif

#ifndef QUAN_STM32_SYSCLK_Hz
#define QUAN_STM32_SYSCLK_Hz  48000000
#endif

#ifndef QUAN_STM32_AHB1_DIVISOR
#define QUAN_STM32_AHB1_DIVISOR 1
#endif

#ifndef QUAN_STM32_AHB2_DIVISOR
#define QUAN_STM32_AHB2_DIVISOR 1
#endif

#ifndef QUAN_STM32_APB_DIVISOR
#define QUAN_STM32_APB_DIVISOR 1
#endif

#endif // QUAN_STM32_F0_CONFIG_HPP_INCLUDED
