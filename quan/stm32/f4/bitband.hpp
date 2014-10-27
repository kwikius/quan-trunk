#ifndef QUAN_STM32_F4_BITBAND_HPP_INCLUDED
#define QUAN_STM32_F4_BITBAND_HPP_INCLUDED
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

#include <stdint.h>
#include <quan/meta/bool.hpp>

/*
 *valid Addresses sources for bit banding each 32 Mb from Cortex-M4 Man sect 3.4
 * ram    0x20000000 to 0x20100000
 * periph 0x40000000 to 0x40100000
 * */
namespace quan{ namespace stm32{

   template <uint32_t Address>
   struct is_in_periph_bitband : quan::meta::bool_<( (Address >= 0x40000000) && (Address < 0x40100000) )>{};

   template <uint32_t Address, uint8_t bitpos>
   struct periph_bit_band_address {
       static constexpr uint32_t bitpos_hi = bitpos / 8;
       static constexpr uint32_t address = Address + bitpos_hi;

       static constexpr uint32_t bitpos_lo = bitpos % 8;
       static constexpr uint32_t bitband_ref = 0x40000000;
       static_assert(is_in_periph_bitband<address>::value, "peripheral bit banding address out of range");
       static constexpr uint32_t bitband_base = 0x42000000;

       static constexpr uint32_t value = bitband_base + (address - bitband_ref) * 32 + bitpos_lo * 4;
       typedef periph_bit_band_address type;
   };

//bitband for STM32F405, STM32F405, STM32F415,STM32F415
   template <uint32_t Address>
    struct is_in_sram_bitband : quan::meta::bool_<( (Address >= 0x20000000) && (Address < 0x20100000) )>{};

   template <uint32_t Address, uint8_t bitpos>
   struct sram_bit_band_address {
       static constexpr uint32_t bitpos_hi = bitpos / 8;
       static constexpr uint32_t address = Address + bitpos_hi;
       static constexpr uint32_t bitpos_lo = bitpos % 8;
       static constexpr uint32_t bitband_ref = 0x20000000;
       static_assert(is_in_sram_bitband<address>::value, "sram bit banding address out of range");
       static constexpr uint32_t bitband_base = 0x22000000;
       static constexpr uint32_t value = bitband_base + (address - bitband_ref) * 32 + bitpos_lo * 4;
       typedef sram_bit_band_address type;
   };

   inline uint32_t* get_sram_bitband_address(void* addr_in,uint8_t bitpos)
   {
       uint32_t const addr = (uint32_t) addr_in;
       if( (addr >= 0x20000000) && ( addr < 0x20100000)){
          uint32_t const bitpos_hi = bitpos / 8U;
          uint32_t const addr1 = addr + bitpos_hi;
          uint32_t const bitpos_lo = bitpos % 8;
          static constexpr uint32_t bitband_ref = 0x20000000;
          static constexpr uint32_t bitband_base = 0x22000000;
          return (uint32_t*) (bitband_base + (addr1 - bitband_ref) * 32 + bitpos_lo * 4);
       }else{
         return nullptr;
       }
   }

}}//quan::stm32

#endif	/* QUAN_STM32_F4_BITBAND_HPP_INCLUDED */
