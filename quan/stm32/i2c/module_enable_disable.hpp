#ifndef QUAN_STM32_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
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

#include <quan/stm32/i2c/module.hpp>
//#include <quan/stm32/i2c/detail/module_enable_disable.hpp>
#if defined QUAN_STM32F4
#include <quan/stm32/f4/i2c/module_enable_disable.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/i2c/module_enable_disable.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/i2c/module_enable_disable.hpp>
#else
#error need to define stm32 processor
#endif

#if 0
#include <quan/is_model_of.hpp>

namespace quan{ namespace stm32 {

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::I2C,U> >::type 
   module_enable()
   {    
      quan::stm32::i2c::detail::module_enable<U>{}();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::I2C,U> >::type 
   module_disable()
   {    
      quan::stm32::i2c::detail::module_disable<U>{}();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::I2C,U> >::type 
   module_reset()
   {    
      quan::stm32::i2c::detail::module_reset<U>{}();
   }

}}
#endif
#endif // QUAN_STM32_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
