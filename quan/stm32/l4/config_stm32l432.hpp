#ifndef QUAN_STM32_L4_CONFIG_STM32L432_HPP_INCLUDED
#define QUAN_STM32_L4_CONFIG_STM32L432_HPP_INCLUDED

//UFQFPN32 package
// up to 100 Mhz
// up to 256 kB Flas
// up to 64 k Ram
// PORTC has only pins 14,15
// P has only pin 3 which is also boot0
// 

#ifndef QUAN_STM32_SOURCE_CLOCK_Hz
#define QUAN_STM32_SOURCE_CLOCK_Hz  8000000
#endif

#ifndef QUAN_STM32_SYSCLK_Hz
#define QUAN_STM32_SYSCLK_Hz  80000000
#endif

#ifndef QUAN_STM32_AHB1_DIVISOR
#define QUAN_STM32_AHB1_DIVISOR 1
#endif

#ifndef QUAN_STM32_AHB2_DIVISOR
#define QUAN_STM32_AHB2_DIVISOR 1
#endif

// APB2 timer clock is * 2 to the APB2 periph clock
#ifndef QUAN_STM32_APB2_DIVISOR
#define QUAN_STM32_APB2_DIVISOR 1
#endif

// APB1 timer clock is * 2 to the APB1 periph clock
#ifndef QUAN_STM32_APB1_DIVISOR
#define QUAN_STM32_APB1_DIVISOR 1
#endif

#define QUAN_STM32_HAS_BITBANDING 1
#define QUAN_STM32_HAS_DAC 1

#define QUAN_STM32_HAS_GPIOA 1
#define QUAN_STM32_HAS_GPIOB 1
#define QUAN_STM32_HAS_GPIOC 1
#define QUAN_STM32_HAS_GPIOH 1

#define QUAN_STM32_HAS_TIM1  1
#define QUAN_STM32_HAS_TIM2  1
#define QUAN_STM32_HAS_TIM6  1
#define QUAN_STM32_HAS_TIM7  1
#define QUAN_STM32_HAS_TIM15 1
#define QUAN_STM32_HAS_TIM16 1

#define QUAN_STM32_HAS_USART1 1
#define QUAN_STM32_HAS_USART2 1
#define QUAN_STM32_HAS_LPUART 1

#define QUAN_STM32_HAS_I2C1   1
#define QUAN_STM32_HAS_I2C3   1

#define QUAN_STM32_HAS_SPI1 1
#define QUAN_STM32_HAS_SPI3 1

#include <quan/stm32/l4/periph_map.hpp>

#endif // QUAN_STM32_L4_CONFIG_STM32L432_HPP_INCLUDED
