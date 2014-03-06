#ifndef QUAN_STM32_I2C_MODULE_HPP_INCLUDED
#define QUAN_STM32_I2C_MODULE_HPP_INCLUDED

#include <quan/stm32/config.hpp>
#include <quan/stm32/module.hpp>

#if defined QUAN_STM32F4
#include <quan/stm32/f4/i2c/module.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/i2c/module.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/i2c/module.hpp>
#else
#error need to define stm32 processor
#endif

namespace quan{ namespace impl{

   // make port a model of I2C
   template <uint32_t Address>
   struct is_model_of_impl<
			quan::stm32::I2C,
			quan::stm32::i2c::module<Address> 
	> : quan::meta::true_{};

   // make port a model of Usart
   template <uint32_t Address>
   struct is_model_of_impl<
			quan::stm32::Module,
			quan::stm32::i2c::module<Address> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32_I2C_MODULE_HPP_INCLUDED
