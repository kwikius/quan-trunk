#ifndef QUAN_STM32_SPI_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32_SPI_TYPEDEFS_HPP_INCLUDED

#include <quan/stm32/spi/module.hpp>
#include <quan/stm32/periph_map.hpp>

namespace quan{ namespace stm32{

#if defined( QUAN_STM32_HAS_SPI1 )
   #if ((defined QUAN_STM32F4) || ( defined QUAN_STM32L4))
      typedef quan::stm32::spi::module<quan::stm32::periph_map::spi1> spi1;
   #elif defined QUAN_STM32F0
      typedef quan::stm32::spi::module<quan::stm32::periph_map::spi1_i2s1> spi1; 
   #else
      #error need to define spi1 for stm32 processor
   #endif
#endif  // defined SPI1

#if defined( QUAN_STM32_HAS_SPI2 )
   #if defined QUAN_STM32F4
      typedef quan::stm32::spi::module<quan::stm32::periph_map::spi2_i2s2> spi2;
   #elif ( (defined QUAN_STM32F0)  || (defined QUAN_STM32L4))
      typedef quan::stm32::spi::module<quan::stm32::periph_map::spi2> spi2;
   #else
      #error need to define spi2 for stm32 processor
   #endif
#endif

#if defined( QUAN_STM32_HAS_SPI3 )
   #if defined QUAN_STM32F4
      typedef quan::stm32::spi::module<quan::stm32::periph_map::spi3_i2s3> spi3;
   #elif defined QUAN_STM32L4
      typedef quan::stm32::spi::module<quan::stm32::periph_map::spi3> spi3;
   #else
      #error need to define spi3 for stm32 processor
   #endif
#endif

}}

#endif // QUAN_STM32_SPI_TYPEDEFS_HPP_INCLUDED
