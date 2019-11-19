#ifndef QUAN_STM32_SPI_MODULE_HPP_INCLUDED
#define QUAN_STM32_SPI_MODULE_HPP_INCLUDED

#include <quan/stm32/config.hpp>
#include <quan/stm32/module.hpp>

#if defined QUAN_STM32F4
#include <quan/stm32/f4/spi/module.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/spi/module.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/spi/module.hpp>
#elif defined QUAN_STM32L4
#include <quan/stm32/l4/spi/module.hpp>
#else
#error unknown processor for spi module
#endif

namespace quan{ namespace impl{

   // make port a model of Spi
   template <uint32_t Address>
   struct is_model_of_impl<
			quan::stm32::Spi,
			quan::stm32::spi::module<Address> 
	> : quan::meta::true_{};

   // make a model of Module
   template <uint32_t Address>
   struct is_model_of_impl<
			quan::stm32::Module,
			quan::stm32::spi::module<Address> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32_MODULE_HPP_INCLUDED
