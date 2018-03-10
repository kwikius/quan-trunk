#ifndef QUAN_STM32_USART_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_USART_ENABLE_DISABLE_HPP_INCLUDED
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
#include <quan/is_model_of.hpp>

namespace quan{ namespace stm32{

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   enable()
   {    
#if defined QUAN_STM32F4
      constexpr uint8_t enable_bit = 13;
#else 
#if (defined (QUAN_STM32F0) || defined(QUAN_STM32L4))
      constexpr uint8_t enable_bit = 0;
#else
#error need to define for processor
#endif
#endif
      U::get()->cr1.template setbit<enable_bit>();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   disable()
   {    
#if defined QUAN_STM32F4
      constexpr uint8_t enable_bit = 13;
#else 
#if (defined (QUAN_STM32F0) || defined(QUAN_STM32L4))
      constexpr uint8_t enable_bit = 0;
#else
#errot need to define for processor
#endif
#endif
      U::get()->cr1.template clearbit<enable_bit>();
   }

}}

#endif // QUAN_STM32_USART_ENABLE_DISABLE_HPP_INCLUDED
