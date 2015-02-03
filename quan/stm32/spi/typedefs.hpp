#ifndef QUAN_STM32_SPI_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32_SPI_TYPEDEFS_HPP_INCLUDED

#include <quan/stm32/spi/module.hpp>
#include <quan/stm32/periph_map.hpp>

namespace quan{ namespace stm32{

#if defined( QUAN_STM32_HAS_SPI1 )
   typedef quan::stm32::spi::module<quan::stm32::periph_map::spi1> spi1;
#endif
#if defined( QUAN_STM32_HAS_SPI2 )
// f4 only?
    typedef quan::stm32::spi::module<quan::stm32::periph_map::spi2_i2s2> spi2;
#endif
#if defined( QUAN_STM32_HAS_SPI3 )
// f4 only?
   typedef quan::stm32::spi::module<quan::stm32::periph_map::spi3_i2s3> spi3;
#endif

}}

#endif // QUAN_STM32_SPI_TYPEDEFS_HPP_INCLUDED
