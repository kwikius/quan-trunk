/* 
 * File:   bitband.hpp
 * Author: andy
 *
 * Created on 29 April 2012, 11:44
 */

#ifndef QUAN_STM32F$__BITBAND_HPP_INCLUDED
#define QUAN_STM32F$__BITBAND_HPP_INCLUDED

/*
 * File:   bit_banding.hpp
 * Author: andy
 *
 * Created on 27 April 2012, 16:10
 */

#include <stdint.h>
#include <quan/meta/bool.hpp>

/*
 *valid Addresses sources for bit banding each 32 Mb from Cortex-M4 Man sect 3.4
 * ram    0x20000000 to 0x20100000
 * periph 0x40000000 to 0x40100000
 * */
namespace quan{ namespace stm32f4{

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

}}//quan::stm32f4

#endif	/* QUAN_STM32F$__BITBAND_HPP_INCLUDED */

