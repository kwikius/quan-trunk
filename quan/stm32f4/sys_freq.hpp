#ifndef QUAN_STM32F4_SYS_FREQ_HPP_INCLUDED
#define QUAN_STM32F4_SYS_FREQ_HPP_INCLUDED
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

namespace quan { namespace stm32f4{

    inline constexpr 
    uint32_t get_sysclk_frequency(){ return QUAN_STM32F4_SYSCLK_Hz; }

   namespace detail{

      template <typename Bus> struct get_bus_frequency_impl;

      template<> struct get_bus_frequency_impl<quan::stm32f4::detail::apb1>{
         constexpr uint32_t operator()(){ return quan::stm32f4::get_sysclk_frequency() / QUAN_STM32F4_APB1_DIVISOR;}
      };

      template<> struct get_bus_frequency_impl<quan::stm32f4::detail::apb2>{
         constexpr uint32_t operator()(){ return quan::stm32f4::get_sysclk_frequency() / QUAN_STM32F4_APB2_DIVISOR;}
      };

      template<> struct get_bus_frequency_impl<quan::stm32f4::detail::ahb1>{
         constexpr uint32_t operator()(){ return quan::stm32f4::get_sysclk_frequency() / QUAN_STM32F4_AHB_DIVISOR;}
      };

      template<> struct get_bus_frequency_impl<quan::stm32f4::detail::ahb2>{
         constexpr uint32_t operator()(){ return quan::stm32f4::get_sysclk_frequency() / QUAN_STM32F4_AHB_DIVISOR;}
      };
      
   }

    template <typename Bus>
    inline constexpr 
    uint32_t 
    get_bus_frequency(){ return quan::stm32f4::detail::get_bus_frequency_impl<Bus>{}();};
  
}}

#endif // QUAN_STM32F4_SYS_FREQ_HPP_INCLUDED
