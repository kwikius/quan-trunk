#ifndef QUAN_STM32_G4_PERIPH_MAP_HPP_INCLUDED
#define QUAN_STM32_G4_PERIPH_MAP_HPP_INCLUDED

#if !defined QUAN_STM32G4
#error only for stm32g4
#endif
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

#include <cstdint>

/*
 periph_map for stm32g4
*/

namespace quan{ namespace stm32{

   struct periph_map{

      static constexpr uint32_t quadspi         = 0xA0001000;
      static constexpr uint32_t fsmc            = 0xA0000000;

      //----------------------- AHB2 -----------------------
      static constexpr uint32_t rng             = 0x50060800;
      static constexpr uint32_t aes             = 0x50060000;
      static constexpr uint32_t dac4            = 0x50001400;
      static constexpr uint32_t dac3            = 0x50001000;
      static constexpr uint32_t dac2            = 0x50000C00;
      static constexpr uint32_t dac1            = 0x50000800;
      static constexpr uint32_t adc3_4_5        = 0x50000400;
      static constexpr uint32_t adc1_2          = 0x50000000;
      static constexpr uint32_t gpiog           = 0x48001800;
      static constexpr uint32_t gpiof           = 0x48001400;
      static constexpr uint32_t gpioe           = 0x48001000;
      static constexpr uint32_t gpiod           = 0x48000C00;
      static constexpr uint32_t gpioc           = 0x48000800;
      static constexpr uint32_t gpiob           = 0x40800400;
      static constexpr uint32_t gpioa           = 0x48000000;
      //---------------------- ~AHB2 -----------------------
      //- --------------------- AHB1 -----------------------
      static constexpr uint32_t crc             = 0x40023000;
      static constexpr uint32_t flashir         = 0x40022000;
      static constexpr uint32_t fmac            = 0x40021400;
      static constexpr uint32_t rcc             = 0x40021000;
      static constexpr uint32_t cordic          = 0x40020C00;
      static constexpr uint32_t dmamux          = 0x40020800;
      static constexpr uint32_t dma2            = 0x40020400;
      static constexpr uint32_t dma1            = 0x40020000;
      //- -------------------- ~AHB1 -----------------------
      //- --------------------- APB2 -----------------------
      static constexpr uint32_t hrtim           = 0x40016800;
      static constexpr uint32_t sai1            = 0x40015400;
      static constexpr uint32_t tim20           = 0x40015000;
      static constexpr uint32_t tim17           = 0x40014800;
      static constexpr uint32_t tim16           = 0x40014400;
      static constexpr uint32_t tim15           = 0x40014000;
      static constexpr uint32_t spi4            = 0x40013C00;
      static constexpr uint32_t usart1          = 0x40013800;
      static constexpr uint32_t tim8            = 0x40013400;
      static constexpr uint32_t spi1            = 0x40013000;
      static constexpr uint32_t tim1            = 0x40012C00;
      static constexpr uint32_t exti            = 0x40010400;
      static constexpr uint32_t opamp           = 0x40010300;
      static constexpr uint32_t comp            = 0x40010200;
      static constexpr uint32_t vrefbuf         = 0x40010030;
      static constexpr uint32_t syscfg          = 0x40010000;
      //- -------------------- ~APB2 -----------------------
      //- --------------------- APB1 -----------------------
      static constexpr uint32_t fdcan_ram       = 0x4000A400;
      static constexpr uint32_t ucpd1           = 0x4000A000;
      static constexpr uint32_t i2c4            = 0x40008400;
      static constexpr uint32_t lpuart1         = 0x40008000;
      static constexpr uint32_t lptim1          = 0x40007C00;
      static constexpr uint32_t i2c3            = 0x40007800;
      static constexpr uint32_t pwr             = 0x40007000;
      static constexpr uint32_t fdcan3          = 0x40006C00;
      static constexpr uint32_t fdcan2          = 0x40006800;
      static constexpr uint32_t fdcan1          = 0x40006400;
      static constexpr uint32_t usb_sram        = 0x40006000;
      static constexpr uint32_t usb_fs          = 0x40005C00;
      static constexpr uint32_t i2c2            = 0x40005800;
      static constexpr uint32_t i2c1            = 0x40005400;
      static constexpr uint32_t uart5           = 0x40005000;
      static constexpr uint32_t uart4           = 0x40004C00;
      static constexpr uint32_t usart3          = 0x40004800;
      static constexpr uint32_t usart2          = 0x40004400;
      static constexpr uint32_t spi3_i2s3       = 0x40003C00;
      static constexpr uint32_t spi2_i2s2       = 0x40003800;
      static constexpr uint32_t iwdg            = 0x40003000;
      static constexpr uint32_t wwdg            = 0x40002C00;
      static constexpr uint32_t rtc_bkp         = 0x40002800;
      static constexpr uint32_t tamp            = 0x40002400;
      static constexpr uint32_t crs             = 0x40002000;
      static constexpr uint32_t tim7            = 0x40001400;
      static constexpr uint32_t tim6            = 0x40001000;
      static constexpr uint32_t tim5            = 0x40000C00;
      static constexpr uint32_t tim4            = 0x40000800;
      static constexpr uint32_t tim3            = 0x40000400;
      static constexpr uint32_t tim2            = 0x40000000;
      //- --------------------- ~APB1 -----------------------
   };
}}

#endif	/* QUAN_STM32_F4_PERIPH_MAP_HPP_INCLUDED */
