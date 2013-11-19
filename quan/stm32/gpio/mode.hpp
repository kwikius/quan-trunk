#ifndef QUAN_STM32_GPIO_MODE_HPP_INCLUDED
#define QUAN_STM32_GPIO_MODE_HPP_INCLUDED
/*
 Copyright (c) 2012-2013 Andy Little 

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

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/stm32/gpio/setting.hpp>

namespace quan{ namespace stm32{ namespace gpio{

   struct Mode; // Archetype

   template <uint32_t V>
   struct mode_value{

         static constexpr uint32_t value = V;
         static constexpr uint32_t numbits = 2;
   };

   struct AlternateFunction; // Concept

   template <uint32_t N>
   struct alternate_function{

     static constexpr uint32_t value = N;
     static constexpr uint32_t numbits = 4;
     
   };

   struct mode{
     
      typedef mode_value<0b00> input;
      typedef mode_value<0b01> output;
      typedef mode_value<0b10> alternate_function;
      typedef mode_value<0b11> analog;
      
      typedef quan::stm32::gpio::alternate_function<0> af0;
      typedef quan::stm32::gpio::alternate_function<1> af1;
      typedef quan::stm32::gpio::alternate_function<2> af2;
      typedef quan::stm32::gpio::alternate_function<3> af3;
      typedef quan::stm32::gpio::alternate_function<4> af4;
      typedef quan::stm32::gpio::alternate_function<5> af5;
      typedef quan::stm32::gpio::alternate_function<6> af6;
      typedef quan::stm32::gpio::alternate_function<7> af7;
      typedef quan::stm32::gpio::alternate_function<8> af8;
      typedef quan::stm32::gpio::alternate_function<9> af9;
      typedef quan::stm32::gpio::alternate_function<10> a10;
      typedef quan::stm32::gpio::alternate_function<11> af11;
      typedef quan::stm32::gpio::alternate_function<12> af12;
      typedef quan::stm32::gpio::alternate_function<13> af13;
      typedef quan::stm32::gpio::alternate_function<14> af14;
      typedef quan::stm32::gpio::alternate_function<15> af15;

   };

}}} // quan::stm32::gpio

namespace quan{ namespace impl{

    // make port a model of Port
   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32::gpio::Mode,
			quan::stm32::gpio::mode_value<V> 
	> : quan::meta::true_{};

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32::gpio::Setting,
			quan::stm32::gpio::mode_value<V> 
	> : quan::meta::true_{};

   template <uint32_t N>
   struct is_model_of_impl<
			quan::stm32::gpio::AlternateFunction,
			quan::stm32::gpio::alternate_function<N> 
	> : quan::meta::true_{};

   template <uint32_t N>
   struct is_model_of_impl<
			quan::stm32::gpio::Setting,
			quan::stm32::gpio::alternate_function<N> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32_GPIO_MODE_HPP_INCLUDED
