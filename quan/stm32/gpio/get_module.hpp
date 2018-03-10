#ifndef QUAN_STM32_GPIO_GET_MODULE_HPP_INCLUDED
#define QUAN_STM32_GPIO_GET_MODULE_HPP_INCLUDED

#include <quan/stm32/module.hpp>
#include <quan/stm32/gpio/pin.hpp>

namespace quan{ namespace stm32{

   template <typename Pin>
   struct get_module<Pin,typename quan::where_<quan::is_model_of<quan::stm32::gpio::Pin, Pin> >::type>
   {
      typedef typename Pin::port_type type;
   };

}}

#endif // QUAN_STM32_GPIO_GET_MODULE_HPP_INCLUDED
