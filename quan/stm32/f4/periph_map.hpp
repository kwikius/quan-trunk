#ifndef QUAN_STM32_F4_PERIPH_MAP_HPP_INCLUDED
#define QUAN_STM32_F4_PERIPH_MAP_HPP_INCLUDED

#if !defined QUAN_STM32F4
#error only for stm32f4
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
 periph_map for stm32f4
*/

namespace quan{ namespace stm32{

   struct periph_map{
      //----------------------- AHB3 -----------------------
      static constexpr uint32_t fsmc            = 0xa0000000;
      //---------------------- ~AHB3 -----------------------
      //----------------------- AHB2 -----------------------
      static constexpr uint32_t rng             = 0x50060800;
      static constexpr uint32_t hash            = 0x50060400;
      static constexpr uint32_t cryp            = 0x50060000;
      static constexpr uint32_t dcmi            = 0x50050000;
      static constexpr uint32_t usbotgfs        = 0x50000000;
      //---------------------- ~AHB2 -----------------------
      //- --------------------- AHB1 -----------------------    
      static constexpr uint32_t usbotghs        = 0x40040000;
      static constexpr uint32_t ethernetmac     = 0x40028000;
      static constexpr uint32_t dma2            = 0x40026400;
      static constexpr uint32_t dma1            = 0x40026000;
      static constexpr uint32_t bkpsram         = 0x40024000;
      static constexpr uint32_t flashir         = 0x40023C00;
      static constexpr uint32_t rcc             = 0x40023800;
      static constexpr uint32_t crc             = 0x40023000;
      static constexpr uint32_t gpioi           = 0x40022000;
      static constexpr uint32_t gpioh           = 0x40021C00;
      static constexpr uint32_t gpiog           = 0x40021800;
      static constexpr uint32_t gpiof           = 0x40021400;
      static constexpr uint32_t gpioe           = 0x40021000;
      static constexpr uint32_t gpiod           = 0x40020C00;
      static constexpr uint32_t gpioc           = 0x40020800;
      static constexpr uint32_t gpiob           = 0x40020400;
      static constexpr uint32_t gpioa           = 0x40020000;
      //- -------------------- ~AHB1 -----------------------
      //- --------------------- APB2 -----------------------
      static constexpr uint32_t tim11           = 0x40014800;
      static constexpr uint32_t tim10           = 0x40014400;
      static constexpr uint32_t tim9            = 0x40014000;
      static constexpr uint32_t exti            = 0x40013C00;
      static constexpr uint32_t syscfg          = 0x40013800;
      static constexpr uint32_t spi1            = 0x40013000;
      static constexpr uint32_t sdio            = 0x40012C00;
      static constexpr uint32_t adc             = 0x40012000;
      static constexpr uint32_t usart6          = 0x40011400;
      static constexpr uint32_t usart1          = 0x40011000;
      static constexpr uint32_t tim8            = 0x40010400;
      static constexpr uint32_t tim1            = 0x40010000;
      //- -------------------- ~APB2 -----------------------
      //- --------------------- APB1 -----------------------
      static constexpr uint32_t dac             = 0x40007400;
      static constexpr uint32_t pwr             = 0x40007000;
      static constexpr uint32_t can2            = 0x40006800;
      static constexpr uint32_t can1            = 0x40006400;
      static constexpr uint32_t i2c3            = 0x40005C00;
      static constexpr uint32_t i2c2            = 0x40005800;
      static constexpr uint32_t i2c1            = 0x40005400;
      static constexpr uint32_t uart5            = 0x40005000;
      static constexpr uint32_t uart4            = 0x40004C00;
      static constexpr uint32_t usart3           = 0x40004800;
      static constexpr uint32_t usart2           = 0x40004400;
      static constexpr uint32_t i2s3ext          = 0x40004000;
      static constexpr uint32_t spi3_i2s3        = 0x40003C00;
      static constexpr uint32_t spi2_i2s2        = 0x40003800;
      static constexpr uint32_t i2s2ext          = 0x40003400;
      static constexpr uint32_t iwdg             = 0x40003000;
      static constexpr uint32_t wwdg             = 0x40002C00;
      static constexpr uint32_t rtc_bkp          = 0x40002800;
      static constexpr uint32_t tim14            = 0x40002000;
      static constexpr uint32_t tim13            = 0x40001C00;
      static constexpr uint32_t tim12            = 0x40001800;
      static constexpr uint32_t tim7             = 0x40001400;
      static constexpr uint32_t tim6             = 0x40001000;
      static constexpr uint32_t tim5             = 0x40000C00;
      static constexpr uint32_t tim4             = 0x40000800;
      static constexpr uint32_t tim3             = 0x40000400;
      static constexpr uint32_t tim2             = 0x40000000;
      //- --------------------- ~APB1 -----------------------
   };
}}

#endif	/* QUAN_STM32_F4_PERIPH_MAP_HPP_INCLUDED */
