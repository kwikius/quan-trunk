#ifndef QUAN_AVR_PERIPH_MAP_HPP_INCLUDED
#define QUAN_AVR_PERIPH_MAP_HPP_INCLUDED
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

#include <stdint.h>

namespace quan{
    namespace avr{
        struct periph_map{
            // nb offsets of 0 are at pinxx
             static constexpr uint8_t gpiob = 0x03;
             static constexpr uint8_t gpioc = 0x06;
             static constexpr uint8_t gpiod = 0x09;
        };

   }
}
#endif // QUAN_AVR_PERIPH_MAP_HPP_INCLUDED
