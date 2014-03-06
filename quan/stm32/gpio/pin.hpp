#ifndef QUAN_STM32_GPIO_PIN_HPP_INCLUDED
#define QUAN_STM32_GPIO_PIN_HPP_INCLUDED

#include <quan/stm32/config.hpp>
#include <quan/mcu/pin.hpp>
#include <quan/is_model_of.hpp>
#include <quan/stm32/gpio/archetype.hpp>
#include <quan/bit.hpp>

namespace quan{ namespace stm32{ 

   namespace gpio{

      struct Pin;   // Archetype

   }

}}

namespace quan{ namespace impl{

  // an mcu::pin is a model of Pin if its port is a model of Gpio
  template <typename P, typename P::value_type Pos>
  struct is_model_of_impl<
      quan::stm32::gpio::Pin,quan::mcu::pin<P,Pos>,
      typename quan::where_<
         quan::is_model_of<quan::stm32::Gpio,P> 
      >::type 
   > : quan::meta::true_{};

}}

namespace quan{ namespace stm32{

   // f4 yes
   // f0 
   template< typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type  complement()
   {
      P::port_type::get()->odr.template xor_equals<
         quan::bit<typename P::value_type>(P::pin_value)
      >();
   }

   template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32::gpio::Pin,P>,
       bool
   >::type get()
   {
#if QUAN_STM32_HAS_BITBANDING
      return P::port_type::get()-> idr.template bb_getbit<P::pin_value>();
#else
      return P::port_type::get()-> idr.template getbit<P::pin_value>();
#endif
   }

   template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32::gpio::Pin,P>,
       void
   >::type set()
   {
#if QUAN_STM32_HAS_BITBANDING
       P::port_type::get()-> odr.template bb_setbit<P::pin_value>();
#else
       P::port_type::get()-> odr.template setbit<P::pin_value>();
#endif
   }

    template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32::gpio::Pin,P>,
       void
   >::type clear()
   {
#if QUAN_STM32_HAS_BITBANDING
       P::port_type::get()-> odr.template bb_clearbit<P::pin_value>();
#else
       P::port_type::get()-> odr.template clearbit<P::pin_value>();
#endif
   }

}}

#endif // QUAN_STM32_GPIO_PIN_HPP_INCLUDED
