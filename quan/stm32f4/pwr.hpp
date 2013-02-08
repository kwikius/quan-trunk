/* 
 * File:   pwr.hpp
 * Author: andy
 *
 * Created on 06 May 2012, 22:03
 */

#ifndef QUAN_STM32F4_PWR_HPP_INCLUDED
#define	QUAN_STM32F4_PWR_HPP_INCLUDED

#include <quan/stm32f4/periph_map.hpp>
#include <quan/stm32f4/periph_reg.hpp>
#include <quan/stm32f4/field.hpp>
#include <quan/bit.hpp>

namespace quan{
    namespace stm32f4{
        namespace pwr{

            static constexpr uint32_t base_address = periph_map::pwr;

            struct CR : periph_reg<uint32_t, base_address + 0x0 >{
                 static constexpr auto LPDS = field<CR, bit(0)>{};
                 static constexpr auto PDDS = field<CR, bit(1)>{};
                 static constexpr auto CWUF = field<CR, bit(2)>{};
                 static constexpr auto CSBF = field<CR, bit(3)>{};
                 static constexpr auto PVDE = field<CR, bit(4)>{};
                 static constexpr auto PLS = field_gen<CR, bit(5) | bit(6) | bit(7)>{};
                 static constexpr auto DBP = field<CR, bit(8)>{};
                 static constexpr auto FPDS = field<CR, bit(9)>{};
                 static constexpr auto VOS = field<CR, bit(14)>{};

            };

            struct CSR : periph_reg<uint32_t, base_address + 0x04 > {
                  static constexpr auto WUF = field<CR, bit(0)>{};
                  static constexpr auto SBF = field<CR, bit(1)>{};
                  static constexpr auto PVDO = field<CR, bit(2)>{};
                  static constexpr auto BRR = field<CR, bit(3)>{};

                  static constexpr auto EWUP = field<CR, bit(8)>{};
                  static constexpr auto BRE = field<CR, bit(9)>{};

                  static constexpr auto VOSRDY = field<CR, bit(14)>{};
            };

        }
    }
}


#endif	/*  QUAN_STM32F4__PWR_HPP_INCLUDED */

