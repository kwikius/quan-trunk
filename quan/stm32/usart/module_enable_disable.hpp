#ifndef QUAN_STM32_USART_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_USART_MODULE_ENABLE_DISABLE_HPP_INCLUDED
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

#include <quan/stm32/usart/module.hpp>
#include <quan/stm32/usart/detail/module_enable_disable.hpp>
#include <quan/is_model_of.hpp>

namespace quan{ namespace stm32{

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   module_enable()
   {    
      quan::stm32::usart::detail::module_enable<U>{}();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   module_disable()
   {    
      quan::stm32::usart::detail::module_disable<U>{}();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   module_reset()
   {    
      quan::stm32::usart::detail::module_reset<U>{}();
   }

}}//quan::stm32

#endif // QUAN_STM32_USART_MODULE_ENABLE_DISABLE_HPP_INCLUDED
