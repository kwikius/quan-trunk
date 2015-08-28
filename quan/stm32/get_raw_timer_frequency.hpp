#ifndef QUAN_STM32_GET_RAW_TIMER_FREQUENCY_HPP_INCLUDED
#define QUAN_STM32_GET_RAW_TIMER_FREQUENCY_HPP_INCLUDED

#include <quan/stm32/get_module_bus_frequency.hpp>
#include <quan/stm32/tim/module.hpp>
#include <quan/is_model_of.hpp>

//TODO do this properly
// however not to sure re other processors eg f3
// Anyway as it stands raw timer frequency on f4
// is module_bus_freq * 2
#if defined QUAN_STM32F4
namespace quan{ namespace stm32{

   //return frequency in Hz as integer
   template <typename TimerModule>
   inline constexpr uint32_t get_raw_timer_frequency()
   {
      static_assert(quan::is_model_of<quan::stm32::Tim,TimerModule>::value ==true,"only useful for timers");
      return quan::stm32::get_module_bus_frequency<TimerModule>() * 2U;
   }
}}
#else
#error need to check calcs for other processors
#endif

#endif // QUAN_STM32_GET_RAW_TIMER_FREQUENCY_HPP_INCLUDED
