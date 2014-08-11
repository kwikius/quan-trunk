#ifndef QUAN_AVR_GPIO_MODULE_HPP_INCLUDED
#define QUAN_AVR_GPIO_MODULE_HPP_INCLUDED
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

/*
for avr gcc defines  see http://www.nongnu.org/avr-libc/user-manual/using_tools.html
*/
#include <stdint.h>
#include <quan/avr/periph_reg.hpp>
#include <quan/is_model_of.hpp>
//#include <quan/avr/periph_map.hpp>

namespace quan{ namespace avr{ 

   struct Gpio; // Archetype

   namespace gpio{
   #if defined(__AVR_ATmega328P__)
      template <uint8_t Address> 
      struct module{
         typedef uint8_t value_type;
         static constexpr value_type address = Address;
         typedef module type;
         typedef quan::avr::periph_reg<type,0x0>  pin_type;
         typedef quan::avr::periph_reg<type,0x1>  ddr_type;
         typedef quan::avr::periph_reg<type,0x2>  port_type;
      };
   #else
   #error need to define processor
   #endif 
 }
}}


namespace quan{ namespace impl{

    // make module a model of quan::stm32f4::Gpio
   template <uint8_t Address>
   struct is_model_of_impl<
      quan::avr::Gpio,
      quan::avr::gpio::module<Address> 
	> : quan::meta::true_{};

}}

#endif // QUAN_AVR_GPIO_MODULE_HPP_INCLUDED
