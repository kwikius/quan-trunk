#ifndef QUAN_STM32_F4_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED
#define QUAN_STM32_F4_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED

#include <type_traits>
#include <quan/stm32/f4/config.hpp>
#include <quan/stm32/f4/detail/get_bus.hpp>
#include <quan/stm32/get_module_bus_frequency.hpp>
/*
 calcs with acknowledegnment to stm32f4xx_usart.c which is
 COPYRIGHT 2011 STMicroelectronics

 Copyright (c) 2013-2018 Andy Little 

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
#if 1
      typedef typename quan::stm32::detail::get_bus<Usart>::type bus_type;

      static_assert(
         (std::is_same<bus_type,quan::stm32::detail::apb2>::value == true)
         || (std::is_same<bus_type,quan::stm32::detail::apb1>::value == true)
       , "invalide bus in baudrate calc");
      static constexpr uint32_t bus_divisor 
            = std::is_same<bus_type,quan::stm32::detail::apb2>::value
            ? QUAN_STM32_APB2_DIVISOR
            : QUAN_STM32_APB1_DIVISOR;
     static constexpr uint32_t usart_bus_clk = QUAN_STM32_SYSCLK_Hz / bus_divisor;
     static_assert(  (QUAN_STM32_SYSCLK_Hz % bus_divisor)==0,"error in calc");
#else
    // TODO test this
    static constexpr uint32_t usart_bus_clk = quan::stm32::get_module_bus_frequency<Usart>();
#endif
     static constexpr uint32_t integerdivider = Over8
     ? (25 * usart_bus_clk) / (2 * BaudRate)
     : (25 * usart_bus_clk) / (4 * BaudRate); 
     
   static constexpr uint32_t tmpreg = (integerdivider / 100) << 4;
   static constexpr uint32_t fractionaldivider = integerdivider - (100 * (tmpreg >> 4));
   static constexpr uint32_t value = Over8
   ?  tmpreg | ( ((fractionaldivider * 8 + 50) / 100) & static_cast<uint8_t>(0x07) )
   :  tmpreg | ( ((fractionaldivider * 16 + 50) / 100) & static_cast<uint8_t>(0x0F) );
    static_assert((value & 0xFFFF0000) == 0,"baud rate not available");
   };

}}}}

#endif // QUAN_STM32_F4_USART_DETAIL_GET_BAUD_RATE_VALUES_HPP_INCLUDED
