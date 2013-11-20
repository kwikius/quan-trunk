#ifndef QUAN_STM32_GPIO_PIN_HPP_INCLUDED
#define QUAN_STM32_GPIO_PIN_HPP_INCLUDED

#include <quan/mcu/pin.hpp>

namespace quan{ namespace stm32{ 
   
   struct Gpio;

   namespace gpio{

      struct Pin;

   }

}}

namespace quan{ namespace impl{

  template <typename P, typename P::value_type Pos>
  struct is_model_of_impl<
      quan::stm32::gpio::Pin,quan::mcu::pin<P,Pos>,
      typename quan::where_<
         quan::is_model_of<quan::stm32::Gpio,P> 
      >::type 
   > : quan::meta::true_{};

}}

#endif // QUAN_STM32_GPIO_PIN_HPP_INCLUDED
