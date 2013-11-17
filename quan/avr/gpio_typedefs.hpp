#ifndef QUAN_AVR_GPIO_TYPEDEFS_HPP_INCLUDED
#define QUAN_AVR_GPIO_TYPEDEFS_HPP_INCLUDED
/*
 Copyright (c) 2012 Andy Little 

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

#include <quan/avr/periph_map.hpp>
#include <quan/avr/gpio/module.hpp>

namespace quan{ namespace avr {


   typedef quan::avr::gpio::module<quan::avr::periph_map::gpiob> gpiob;
   typedef quan::avr::gpio::module<quan::avr::periph_map::gpioc> gpioc;
   typedef quan::avr::gpio::module<quan::avr::periph_map::gpiod> gpiod;


}}

#endif // QUAN_AVR_GPIO_TYPEDEFS_HPP_INCLUDED
