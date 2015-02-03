#ifndef QUAN_STM32_GPIO_OTYPE_HPP_INCLUDED
#define QUAN_STM32_GPIO_OTYPE_HPP_INCLUDED
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

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/stm32/gpio/setting.hpp>

namespace quan{ namespace stm32{ namespace gpio{

   struct OType; //Concept

   template <uint32_t V>
   struct otype_value{

      static constexpr uint32_t value = V;
      static constexpr uint32_t numbits = 1;

   };

   struct otype{
  
     typedef otype_value<0b0> push_pull;
     typedef otype_value<0b1> open_drain;
    
   };

}}}

namespace quan{ namespace impl{

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32::gpio::OType,
			quan::stm32::gpio::otype_value<V> 
	> : quan::meta::true_{};

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32::gpio::Setting,
			quan::stm32::gpio::otype_value<V> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32_GPIO_OTYPE_HPP_INCLUDED
