#ifndef QUAN_STM32_F0_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED
#define QUAN_STM32_F0_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED

#include <type_traits>
#include <quan/stm32/f0/config.hpp>
#include <quan/stm32/f0/detail/get_bus.hpp>

/*
 calcs with acknowledegnment to stm32f0xx_usart.h which is
 COPYRIGHT 2011 STMicroelectronics

 Copyright (c) 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

namespace quan { namespace stm32{ namespace usart{ namespace detail{

   template <typename Usart,uint32_t BaudRate, bool Over8>
   struct get_baud_rate_values{
    
      typedef typename quan::stm32::detail::get_bus<Usart>::type bus_type;
      static_assert(std::is_same<bus_type,quan::stm32::detail::apb>::value,"unexpecetd bus");
      static constexpr uint32_t bus_divisor = QUAN_STM32_APB_DIVISOR;
      static constexpr uint32_t fck = QUAN_STM32_SYSCLK_Hz / bus_divisor;
      static_assert(  (QUAN_STM32_SYSCLK_Hz % bus_divisor)==0,"error in calc");

     static constexpr uint32_t divider = Over8
         ? ((2U * fck) / BaudRate)  +  ((((2U * fck) % BaudRate) > (BaudRate / 2U)) ? 1U:0U)
         : (fck / BaudRate) + ((( fck % BaudRate) > ( BaudRate / 2U) ) ? 1U:0U);

     static constexpr uint32_t value = Over8
      ?  (divider & 0x0000FFF0) | ((divider & 0x0000000F) >> 1U)
      :   divider ;
   };

}}}}


#endif // QUAN_STM32_F0_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED
