/* 
 * File:   crc.hpp
 * Author: andy
 *
 * Created on 07 May 2012, 09:06
 */

#ifndef QUAN_STM32_CRC_HPP_INCLUDED
#define	QUAN_STM32_CRC_HPP_INCLUDED
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

#include <quan/stm32f4/periph_map.hpp>
#include <quan/stm32f4/periph_reg.hpp>
#include <quan/stm32f4/field.hpp>
#include <quan/bit.hpp>

namespace quan{ namespace stm32f4{

    namespace crc{

        static constexpr uint32_t base_address = periph_map::crc;

        static constexpr volatile uint32_t & DR = *reinterpret_cast<volatile uint32_t*> (base_address + 0x0);
        static constexpr volatile uint32_t & IDR = *reinterpret_cast<volatile uint32_t*> (base_address + 0x04);

        struct CR : periph_reg<uint32_t, base_address + 0x08 >{
            static constexpr auto RESET = field<CR, bit(0)>{};
        };

    }
}}

#endif	/* QUAN_STM32_CRC_HPP_INCLUDED */

