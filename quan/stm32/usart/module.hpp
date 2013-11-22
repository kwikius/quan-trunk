#ifndef QUAN_STM32F4_USART_MODULE_HPP_INCLUDED
#define QUAN_STM32F4_USART_MODULE_HPP_INCLUDED

#include <quan/stm32/config.hpp>
#include <quan/stm32/module.hpp>

#if defined QUAN_STM32F4
#include <quan/stm32/f4/usart/module.hpp>
#elif defined QUAN_STM32F3
#include <quan/stm32/f3/usart/module.hpp>
#elif defined QUAN_STM32F0
#include <quan/stm32/f0/usart/module.hpp>
#else
#error need to define stm32 processor
#endif

namespace quan{ namespace impl{

   // make port a model of Usart
   template <uint32_t Address>
   struct is_model_of_impl<
			quan::stm32::Usart,
			quan::stm32::usart::module<Address> 
	> : quan::meta::true_{};

   // make port a model of Usart
   template <uint32_t Address>
   struct is_model_of_impl<
			quan::stm32::Module,
			quan::stm32::usart::module<Address> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32F4_USART_MODULE_HPP_INCLUDED
