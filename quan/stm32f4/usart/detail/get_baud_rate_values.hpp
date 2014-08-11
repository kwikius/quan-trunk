#ifndef QUAN_STM32F4_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED
#define QUAN_STM32F4_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED
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

#include <quan/stm32f4/config.hpp>
#include <quan/stm32f4/usart_typedefs.hpp>
#include <quan/stm32f4/usart/detail/get_bus.hpp>

namespace quan { namespace stm32f4{ namespace usart{ namespace detail{

   template <typename Usart,uint32_t BaudRate, bool Over8>
   struct get_baud_rate_values{
    
      typedef typename quan::stm32f4::detail::get_bus<Usart>::type bus_type;
      static constexpr uint32_t bus_divisor 
            = std::is_same<bus_type,quan::stm32f4::detail::apb2>::value
            ? QUAN_STM32F4_APB2_DIVISOR
            : QUAN_STM32F4_APB1_DIVISOR;
      static constexpr uint32_t fck = QUAN_STM32F4_SYSCLK_Hz / bus_divisor;
      static_assert(  (QUAN_STM32F4_SYSCLK_Hz % bus_divisor)==0,"error in calc");
      static constexpr uint32_t divisor = ((fck % BaudRate) >= ( BaudRate / 2 ) ) 
         ? (fck / BaudRate) + 1
         : (fck / BaudRate);
      static constexpr uint32_t mantissa_shift = Over8 ? 3 : 4;
      static constexpr uint32_t fract_mask = Over8 ? 0x7 : 0xF;

      static constexpr uint32_t mantissa = divisor >> mantissa_shift;
     // mantissa must be less than 
      static_assert( (mantissa & 0xFFFFF000)==0, "baud_rate mantissa cannot be greater than 12 bits");
   
      static constexpr uint32_t fraction = divisor & fract_mask;
     
   };

}}}}


#endif // QUAN_STM32F4_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED
