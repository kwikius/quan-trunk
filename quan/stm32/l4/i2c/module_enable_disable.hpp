#ifndef QUAN_STM32_L4_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_L4_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
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

#include <quan/stm32/i2c/typedefs.hpp>
#include <quan/stm32/l4/rcc.hpp>
/*
I2C1
I2C3
*/

namespace quan { namespace stm32{

   namespace i2c{ namespace detail{
         
      template <typename I2CP> struct rcc_bit_offset;
#if defined QUAN_STM32_HAS_I2C1
      template <>struct rcc_bit_offset<quan::stm32::i2c1>{
               static const uint32_t value = 21;
      };
#endif
// not on L4
#if defined QUAN_STM32_HAS_I2C2
      template <>struct rcc_bit_offset<quan::stm32::i2c2>{
               static const uint32_t value = 22;
      };
#endif
#if defined QUAN_STM32_HAS_I2C3
      template <>struct rcc_bit_offset<quan::stm32::i2c3>{
               static const uint32_t value = 23;
      };
#endif
   }} // i2c::detail

    template<typename I2CP> inline
    typename quan::where_<quan::is_model_of<quan::stm32::I2C,I2CP> >::type
    module_enable()
    {
        static constexpr uint32_t bit_offset 
            = quan::stm32::i2c::detail::rcc_bit_offset<I2CP>::value;
        quan::stm32::rcc::get()->apb1enr1. template setbit<bit_offset>();
    }

    template<typename I2CP> inline
    typename quan::where_<quan::is_model_of<quan::stm32::I2C,I2CP> >::type
    module_disable()
    {
        static constexpr uint32_t bit_offset 
            = quan::stm32::i2c::detail::rcc_bit_offset<I2CP>::value;
        quan::stm32::rcc::get()->apb1enr1. template clearbit<bit_offset>();
    }

    template<typename I2CP> inline
    typename quan::where_<quan::is_model_of<quan::stm32::I2C,I2CP> >::type
    module_reset()
    {
        static constexpr uint32_t bit_offset 
            = quan::stm32::i2c::detail::rcc_bit_offset<I2CP>::value;

        quan::stm32::rcc::get()->apb1rstr1. template setbit<bit_offset>();
        quan::stm32::rcc::get()->apb1rstr1. template clearbit<bit_offset>();
    }
}} // quan::stm32

#endif // QUAN_STM32_F4_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
