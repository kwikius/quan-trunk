#ifndef QUAN_STM32_I2C_TYPEDEFS_HPP_INCLUDED
#define QUAN_STM32_I2C_TYPEDEFS_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
