#ifndef QUAN_STM32_GET_RAW_TIMER_FREQUENCY_HPP_INCLUDED
#define QUAN_STM32_GET_RAW_TIMER_FREQUENCY_HPP_INCLUDED

#include <quan/stm32/get_module_bus_frequency.hpp>
#include <quan/stm32/get_bus_prescaler_value.hpp>
#include <quan/stm32/tim/module.hpp>
#include <quan/is_model_of.hpp>

//TODO do this properly
// however not to sure re other processors eg f3
// Anyway as it stands raw timer frequency on f4
// is module_bus_freq * 2

namespace quan{ namespace stm32{

#if defined(QUAN_STM32F4) || defined (QUAN_STM32L4) || defined(QUAN_STM32F0)
   
   //return frequency in Hz as integer
   // Refer to Clock configuration in STM32Cube
   // The timer frequency is a slightly complicated relation to the APB1 and APB2 peripheral prescalers
/*
 STM32F4 ref man (RM0090) 5.2 Clocks
The timer clock frequencies are automatically set by hardware. There are two cases:
1. If the APB prescaler is 1, the timer clock frequencies are set to the same frequency as
that of the APB domain to which the timers are connected.
2. Otherwise, they are set to twice (×2) the frequency of the APB domain to which the
timers are connected.

also stm32L412 ref man 6.2.14 timer clock
also stm32f0 ref man 7.2 Clocks  figure 10 Clock Tree 
*/

   template <typename TimerModule>
   inline constexpr uint32_t get_raw_timer_frequency()
   {
      static_assert(quan::is_model_of<quan::stm32::Tim,TimerModule>::value == true,"only useful for timers");
      typedef typename quan::stm32::detail::get_bus<TimerModule>::type bus_type;
    //  static_assert(std::is_same<bus_type,quan::stm32::detail::apb1>::value, "unexpected bus");
    /*  
      c++11 requires everything to be in the return statement
      constexpr uint32_t  bus_prescaler_value = quan::stm32::get_bus_prescaler_value<bus_type>();
     // static_assert(bus_prescaler_value == 1, "unexpected precasler value");
      constexpr uint32_t multiplier = (bus_prescaler_value == 1U)?1U: 2U;

      return quan::stm32::get_module_bus_frequency<TimerModule>() * multiplier;
    */
      return quan::stm32::get_module_bus_frequency<TimerModule>() * (( quan::stm32::get_bus_prescaler_value<bus_type>() == 1)?1U:2U);
   }

//#elif defined QUAN_STM32F0
//   // think freq is same
//   template <typename TimerModule>
//   inline constexpr uint32_t get_raw_timer_frequency()
//   {
//      static_assert(quan::is_model_of<quan::stm32::Tim,TimerModule>::value ==true,"only useful for timers");
//      return quan::stm32::get_module_bus_frequency<TimerModule>();
//   }
#else
#error need to check calcs for other processors
#endif

}}

#endif // QUAN_STM32_GET_RAW_TIMER_FREQUENCY_HPP_INCLUDED
