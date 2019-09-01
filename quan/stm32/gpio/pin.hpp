#ifndef QUAN_STM32_GPIO_PIN_HPP_INCLUDED
#define QUAN_STM32_GPIO_PIN_HPP_INCLUDED
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
#if (QUAN_STM32_HAS_BITBANDING && ! defined (QUAN_STM32L4))
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
 // could  do P::port_type::get()-> bsrr = 1U << P::pin_value;
#if (QUAN_STM32_HAS_BITBANDING && !defined(QUAN_STM32L4))
       P::port_type::get()-> odr.template bb_setbit<P::pin_value>();
#else
   //  #if defined(QUAN_STM32L4) || defined(QUAN_STM32F0)
       P::port_type::get()-> bsrr = 1U << P::pin_value;
//     #else
//       P::port_type::get()-> odr.template setbit<P::pin_value>();
//     #endif
#endif
   }

    template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32::gpio::Pin,P>,
       void
   >::type clear()
   {
    
#if (QUAN_STM32_HAS_BITBANDING && !defined (QUAN_STM32L4))
     // could  do P::port_type::get()-> bsrr = 0x10000 << P::pin_value;
       P::port_type::get()-> odr.template bb_clearbit<P::pin_value>();
#else
       P::port_type::get()-> brr = 1U << P::pin_value;
#endif
   }

   template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32::gpio::Pin,P>,
       void
   >::type put( bool value)
   {
#if QUAN_STM32_HAS_BITBANDING && ! defined (QUAN_STM32L4)
     // no gain here 
     P::port_type::get()-> odr.template bb_putbit<P::pin_value>(value);
#else
     
    #if defined(QUAN_STM32L4) || defined(QUAN_STM32F0)
      uint32_t const shift = (value)? P::pin_value:(P::pin_value+16U);
      P::port_type::get()-> bsrr = 1U << shift;
    #else
     if ( value) {
        set<P>();
     }else{
        clear<P>();
     }
     #endif
#endif
   }

}}

#endif // QUAN_STM32_GPIO_PIN_HPP_INCLUDED
