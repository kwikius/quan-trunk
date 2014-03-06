#ifndef QUAN_STM32_I2C_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32_I2C_TYPEDEFS_HPP_INCLUDED

#include <quan/stm32/config.hpp>
#include <quan/stm32/i2c/module.hpp>
#include <quan/stm32/periph_map.hpp>

namespace quan{ namespace stm32{ 

#if defined QUAN_STM32_HAS_I2C1
   typedef quan::stm32::i2c::module<quan::stm32::periph_map::i2c1> i2c1;
#endif
#if defined QUAN_STM32_HAS_I2C2
   typedef quan::stm32::i2c::module<quan::stm32::periph_map::i2c2> i2c2;
#endif
#if defined QUAN_STM32_HAS_I2C3
   typedef quan::stm32::i2c::module<quan::stm32::periph_map::i2c3> i2c3;
#endif

}}

#endif // QUAN_STM32_I2C_TYPEDEFS_HPP_INCLUDED
