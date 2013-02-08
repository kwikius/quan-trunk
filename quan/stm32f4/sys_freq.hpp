#ifndef QUAN_STM32F4_SYS_FREQ_HPP_INCLUDED
#define QUAN_STM32F4_SYS_FREQ_HPP_INCLUDED

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
