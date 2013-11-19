#ifndef QUAN_STM32_GPIO_HPP_INCLUDED
#define QUAN_STM32_GPIO_HPP_INCLUDED
/*
 Copyright (c) 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/stm32/config.hpp>

#include <quan/bit.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/identity.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/low_bits_mask.hpp>
#include <quan/meta/count_if.hpp>
#include <quan/meta/is_model_of.hpp>

#include <quan/stm32/gpio/pin.hpp>
#include <quan/stm32/gpio_typedefs.hpp>
#include <quan/stm32/gpio/module_enable.hpp>
#include <quan/stm32/gpio/module_disable.hpp>
#include <quan/stm32/gpio/module_reset.hpp>
#include <quan/stm32/detail/get_gpio_reg.hpp>
#include <quan/stm32/periph_reg_actions/apply.hpp>

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
      return P::port_type::get()-> idr.template bb_getbit<P::pin_value>();
   }

   template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32::gpio::Pin,P>,
       void
   >::type set()
   {
       P::port_type::get()-> odr.template bb_setbit<P::pin_value>();
   }

    template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32::gpio::Pin,P>,
       void
   >::type clear()
   {
       P::port_type::get()-> odr.template bb_clearbit<P::pin_value>();
   }

}}

#endif // QUAN_STM32F$_GPIO_HPP_INCLUDED
