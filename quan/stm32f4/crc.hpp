/* 
 * File:   crc.hpp
 * Author: andy
 *
 * Created on 07 May 2012, 09:06
 */

#ifndef QUAN_STM32_CRC_HPP_INCLUDED
#define	QUAN_STM32_CRC_HPP_INCLUDED

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

