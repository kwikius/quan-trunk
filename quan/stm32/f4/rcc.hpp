#ifndef QUAN_STM32_F4_RCC_HPP_INCLUDED
#define QUAN_STM32_F4_RCC_HPP_INCLUDED
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

#if !defined QUAN_STM32F4
#error only for stm32f4
#endif

#include <quan/stm32/f4/periph_map.hpp>
#include <quan/stm32/periph_reg.hpp>

namespace quan{ namespace stm32{

   struct rcc {
      typedef uint32_t value_type;
      static constexpr uint32_t address = quan::stm32::periph_map::rcc;
      typedef rcc type;
      quan::stm32::periph_reg<type, 0x0>      cr;
      quan::stm32::periph_reg<type, 0x4>      pllcfgr;
      quan::stm32::periph_reg<type, 0x8>      cfgr;
      quan::stm32::periph_reg<type, 0x0C>     cir;
      quan::stm32::periph_reg<type, 0x10>     ahb1rstr;
      quan::stm32::periph_reg<type, 0x14>     ahb2rstr;
      quan::stm32::periph_reg<type, 0x18>     ahb3rstr;
      uint32_t      reserved0;     /*!< Reserved, 0x1C                                                                    */
      quan::stm32::periph_reg<type, 0x20>     apb1rstr;
      quan::stm32::periph_reg<type, 0x24>     apb2rstr;
      uint32_t      reserved1[2];  /*!< Reserved, 0x28-0x2C                                                               */
      quan::stm32::periph_reg<type, 0x30>     ahb1enr;
      quan::stm32::periph_reg<type, 0x34>     ahb2enr;
      quan::stm32::periph_reg<type, 0x38>     ahb3enr;
      uint32_t      reserved2;     /*!< Reserved, 0x3C                                                                    */
      quan::stm32::periph_reg<type, 0x40>     apb1enr;
      quan::stm32::periph_reg<type, 0x44>     apb2enr;
      uint32_t     reserved3[2];  /*!< Reserved, 0x48-0x4C                                                               */
      quan::stm32::periph_reg<type, 0x50>     ahb1lenr;
      quan::stm32::periph_reg<type, 0x54>     ahb2lenr;
      quan::stm32::periph_reg<type, 0x58>     ahb3lenr;
      uint32_t      reserved4;     /*!< Reserved, 0x5C                                                                    */
      quan::stm32::periph_reg<type, 0x60>     apb1lpenr;
      quan::stm32::periph_reg<type, 0x64>     apb2lpenr;
      uint32_t     reserved5[2];  /*!< Reserved, 0x68-0x6C                                                               */
      quan::stm32::periph_reg<type, 0x70>     bdcr;
      quan::stm32::periph_reg<type, 0x74>     csr;
      uint32_t      reserved6[2];  /*!< Reserved, 0x78-0x7C                                                               */
      quan::stm32::periph_reg<type, 0x80>     sscgr;
      quan::stm32::periph_reg<type, 0x84>     plli2scfgr;

      static constexpr rcc* get(){ return reinterpret_cast<rcc*>(address);}

      private:
         rcc() = delete;
         rcc(rcc const &) = delete;
         rcc& operator = (rcc const & ) = delete;
   };

}} //quan::stm32


#endif	/* QUAN_STM32_F4_RCC_HPP_INCLUDED */

