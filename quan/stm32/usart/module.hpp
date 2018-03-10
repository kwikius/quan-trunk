#ifndef QUAN_STM32_USART_MODULE_HPP_INCLUDED
#define QUAN_STM32_USART_MODULE_HPP_INCLUDED
/*
 Copyright (c) 2003-2018 Andy Little.

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
#include <quan/stm32/module.hpp>

#if defined QUAN_STM32F4
#include <quan/stm32/f4/usart/module.hpp>
#elif (defined(QUAN_STM32F0) || defined(QUAN_STM32L4))
#include <quan/stm32/f0/usart/module.hpp>
#else
#error need to define stm32 processor usart module
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

#endif // QUAN_STM32_USART_MODULE_HPP_INCLUDED
