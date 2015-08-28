#ifndef QUAN_STM32_GET_MODULE_BUS_FREQUENCY_HPP_INCLUDED
#define QUAN_STM32_GET_MODULE_BUS_FREQUENCY_HPP_INCLUDED

#include <quan/stm32/sys_freq.hpp>
#include <quan/stm32/detail/get_bus.hpp>

/*
   Note here where it's in fact x2
   // or have timers on apb when are in fact on ahb?
   tim4 is x2
   tim9 is x2
 I'm guessing al timing is x2
  // APB2 runs at system clk
  // and APB1 at half system clk
*/

namespace quan{ namespace stm32{

   template <typename Module>
   inline constexpr uint32_t get_module_bus_frequency()
   {
      typedef typename quan::stm32::detail::get_bus<Module>::type bus_type;
      return quan::stm32::get_bus_frequency<bus_type>();
   }
}}


#endif // QUAN_STM32_GET_MODULE_BUS_FREQUENCY_HPP_INCLUDED
