#ifndef QUAN_STM32_GET_MODULE_BUS_FREQUENCY_HPP_INCLUDED
#define QUAN_STM32_GET_MODULE_BUS_FREQUENCY_HPP_INCLUDED

#include <quan/stm32/sys_freq.hpp>
#include <quan/stm32/detail/get_bus.hpp>

namespace quan{ namespace stm32{

   template <typename Module>
   inline constexpr uint32_t get_module_bus_frequency()
   {
      typedef typename quan::stm32::detail::get_bus<Module>::type bus_type;
      return quan::stm32::get_bus_frequency<bus_type>();
   };
}}


#endif // QUAN_STM32_GET_MODULE_BUS_FREQUENCY_HPP_INCLUDED
