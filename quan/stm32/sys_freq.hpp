#ifndef QUAN_STM32_SYS_FREQ_HPP_INCLUDED
#define QUAN_STM32_SYS_FREQ_HPP_INCLUDED
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

#if ! (defined(QUAN_STM32F4) || defined(QUAN_STM32F0) || defined(QUAN_STM32L4))
#error  need to define stm32 processor sys freq
#endif

#include <quan/stm32/config.hpp>
#include <quan/stm32/detail/buses.hpp>

namespace quan { namespace stm32{

    inline constexpr 
    uint32_t get_sysclk_frequency(){ return QUAN_STM32_SYSCLK_Hz; }

    inline constexpr 
    uint32_t get_hclk_frequency(){ return QUAN_STM32_SYSCLK_Hz / QUAN_STM32_AHB_DIVISOR; }

    namespace detail{

      template <typename Bus> struct get_bus_frequency_impl;

#if defined(QUAN_STM32F0)
      template<> struct get_bus_frequency_impl<quan::stm32::detail::apb>{
         constexpr uint32_t operator()()const { return quan::stm32::get_hclk_frequency() / QUAN_STM32_APB_DIVISOR;}
      };
#endif

#if (defined(QUAN_STM32F4) || defined(QUAN_STM32L4) )
      template<> struct get_bus_frequency_impl<quan::stm32::detail::apb1>{
         constexpr uint32_t operator()()const { return quan::stm32::get_hclk_frequency() / QUAN_STM32_APB1_DIVISOR;}
      };

      template<> struct get_bus_frequency_impl<quan::stm32::detail::apb2>{
         constexpr uint32_t operator()()const { return quan::stm32::get_hclk_frequency() / QUAN_STM32_APB2_DIVISOR;}
      };
#endif
      // same as hclk_frequency
      template<> struct get_bus_frequency_impl<quan::stm32::detail::ahb1>{
         constexpr uint32_t operator()()const { return quan::stm32::get_sysclk_frequency() / QUAN_STM32_AHB_DIVISOR;}
      };

      template<> struct get_bus_frequency_impl<quan::stm32::detail::ahb2>{
         constexpr uint32_t operator()()const { return quan::stm32::get_sysclk_frequency() / QUAN_STM32_AHB_DIVISOR;}
      };
      
#if defined(QUAN_STM32F4)
      template<> struct get_bus_frequency_impl<quan::stm32::detail::ahb3>{
         constexpr uint32_t operator()()const { return quan::stm32::get_sysclk_frequency() / QUAN_STM32_AHB_DIVISOR;}
      };
#endif
   }

    template <typename Bus>
    inline constexpr 
    uint32_t 
    get_bus_frequency(){ return quan::stm32::detail::get_bus_frequency_impl<Bus>{}();}

}}

#endif // QUAN_STM32_SYS_FREQ_HPP_INCLUDED
