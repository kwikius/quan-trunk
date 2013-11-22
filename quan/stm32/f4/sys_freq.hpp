#ifndef QUAN_STM32_F4_SYS_FREQ_HPP_INCLUDED
#define QUAN_STM32_F4_SYS_FREQ_HPP_INCLUDED

#ifndef QUAN_STM32F4
#error dont include directly
#endif

#include <quan/stm32/f4/config.hpp>
#include <quan/stm32/f4/detail/buses.hpp>

namespace quan { namespace stm32{

    inline constexpr 
    uint32_t get_sysclk_frequency(){ return QUAN_STM32_SYSCLK_Hz; }

   namespace detail{

      template <typename Bus> struct get_bus_frequency_impl;

      template<> struct get_bus_frequency_impl<quan::stm32::detail::apb1>{
         constexpr uint32_t operator()(){ return quan::stm32::get_sysclk_frequency() / QUAN_STM32F4_APB1_DIVISOR;}
      };

      template<> struct get_bus_frequency_impl<quan::stm32::detail::apb2>{
         constexpr uint32_t operator()(){ return quan::stm32::get_sysclk_frequency() / QUAN_STM32F4_APB2_DIVISOR;}
      };

      template<> struct get_bus_frequency_impl<quan::stm32::detail::ahb1>{
         constexpr uint32_t operator()(){ return quan::stm32::get_sysclk_frequency() / QUAN_STM32F4_AHB_DIVISOR;}
      };

      template<> struct get_bus_frequency_impl<quan::stm32::detail::ahb2>{
         constexpr uint32_t operator()(){ return quan::stm32::get_sysclk_frequency() / QUAN_STM32F4_AHB_DIVISOR;}
      };
      
      template<> struct get_bus_frequency_impl<quan::stm32::detail::ahb3>{
         constexpr uint32_t operator()(){ return quan::stm32::get_sysclk_frequency() / QUAN_STM32F4_AHB_DIVISOR;}
      };
   }

    template <typename Bus>
    inline constexpr 
    uint32_t 
    get_bus_frequency(){ return quan::stm32::detail::get_bus_frequency_impl<Bus>{}();};
  
}}

#endif // QUAN_STM32_F4_SYS_FREQ_HPP_INCLUDED
