#ifndef QUAN_STM32_L4_RCC_HPP_INCLUDED
#define QUAN_STM32_L4_RCC_HPP_INCLUDED
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

#if !defined QUAN_STM32L4
#error only for stm32l4
#endif
#include <quan/stm32/config.hpp>
#include <quan/stm32/l4/periph_map.hpp>
#include <quan/stm32/periph_reg.hpp>

namespace quan{ namespace stm32{

   struct rcc {
      typedef uint32_t value_type;
      static constexpr uint32_t address = quan::stm32::periph_map::rcc;
      typedef rcc type;
      quan::stm32::periph_reg<type, 0x0>      cr;
      quan::stm32::periph_reg<type, 0x4>      icscr;
      quan::stm32::periph_reg<type, 0x8>      cfgr;
      quan::stm32::periph_reg<type, 0x0C>     pll_cfgr;
      quan::stm32::periph_reg<type, 0x10>     pllsai1_cfgr;
      uint32_t      reserved0;   /*!< Reserved, 0x14  */
      quan::stm32::periph_reg<type, 0x18>     cier;
      quan::stm32::periph_reg<type, 0x1C>     cifr;                                         
      quan::stm32::periph_reg<type, 0x20>     cicr;
      uint32_t      reserved1;  /*!< Reserved, 0x24  */
      quan::stm32::periph_reg<type, 0x28>     ahb1rstr;
      quan::stm32::periph_reg<type, 0x2C>     ahb2rstr;                                                        
      quan::stm32::periph_reg<type, 0x30>     ahb3rstr;
      uint32_t reserved3;    /*!< Reserved 0x34 */
      quan::stm32::periph_reg<type, 0x38>     apb1rstr1;
      quan::stm32::periph_reg<type, 0x3C>     apb1rstr2;                                                           
      quan::stm32::periph_reg<type, 0x40>     apb2rstr;
      uint32_t     reserved4;  /*!< Reserved 0x44 */
      quan::stm32::periph_reg<type, 0x48>     ahb1enr;
      quan::stm32::periph_reg<type, 0x4C>     ahb2enr;
      quan::stm32::periph_reg<type, 0x50>     ahb3enr;
      uint32_t      reserved5;     /*!< Reserved, 0x54 */
      quan::stm32::periph_reg<type, 0x58>     apb1enr1;
      quan::stm32::periph_reg<type, 0x5C>     apb1enr2;    
      quan::stm32::periph_reg<type, 0x60>     apb2enr;
      uint32_t      reserved6;  /*!< Reserved, 0x64 */  
      quan::stm32::periph_reg<type, 0x68>     ahb1smenr; 
      quan::stm32::periph_reg<type, 0x6C>     ahb2smenr;
      quan::stm32::periph_reg<type, 0x70>     ahb3smenr;
      uint32_t      reserved7;  /*!< Reserved, 0x74 */ 
      quan::stm32::periph_reg<type, 0x78>     apb1smenr1;
      quan::stm32::periph_reg<type, 0x7C>     apb1smenr2;
      quan::stm32::periph_reg<type, 0x80>     apb2smenr;
      uint32_t      reserved8;  /*!< Reserved, 0x84 */ 
      quan::stm32::periph_reg<type, 0x88>     ccipr;
      uint32_t      reserved9;  /*!< Reserved, 0x8C */ 
      quan::stm32::periph_reg<type, 0x90>     bdcr;
      quan::stm32::periph_reg<type, 0x94>     csr;
      quan::stm32::periph_reg<type, 0x98>     crrcr;

      static constexpr rcc* get(){ return reinterpret_cast<rcc*>(address);}

      private:
         rcc() = delete;
         rcc(rcc const &) = delete;
         rcc& operator = (rcc const & ) = delete;
   };

}} //quan::stm32


#endif	/* QUAN_STM32_F4_RCC_HPP_INCLUDED */

