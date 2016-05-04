#ifndef QUAN_STM32_F0_PERIPH_MAP_HPP_INCLUDED
#define QUAN_STM32_F0_PERIPH_MAP_HPP_INCLUDED
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

#ifndef QUAN_STM32F0
#error dont include directly
#endif

#include <cstdint>

namespace quan{ namespace stm32{

   struct periph_map{
      //------------------ AHB2 ---------------------
      static constexpr uint32_t    gpiof = 0x48001400;
      static constexpr uint32_t    gpiod = 0x48000C00; 
      static constexpr uint32_t    gpioc = 0x48000800;
      static constexpr uint32_t    gpiob = 0x48000400;  
      static constexpr uint32_t    gpioa = 0x48000000; 
      //----------------- ~AHB2 --------------------- 
      //------------------ AHB1 ---------------------                 
      static constexpr uint32_t      tsc = 0x40024000;   
      static constexpr uint32_t      crc = 0x40023000; 
      static constexpr uint32_t      
                         flash_interface = 0x40022000; 
      static constexpr uint32_t      rcc = 0x40021000; 
      static constexpr uint32_t      dma = 0x40020000; 
      //----------------- ~AHB1 ---------------------
      //------------------- APB ---------------------
      static constexpr uint32_t   dbgmcu = 0x40015800;
      static constexpr uint32_t    tim17 = 0x40014800; 
      static constexpr uint32_t    tim16 = 0x40014400;
      static constexpr uint32_t    tim15 = 0x40014000; 
      static constexpr uint32_t   usart1 = 0x40013800;
      static constexpr uint32_t 
                               spi1_i2s1 = 0x40013000; 
      static constexpr uint32_t     tim1 = 0x40012C00; 
      static constexpr uint32_t      adc = 0x40012400;
      static constexpr uint32_t     exti = 0x40010400;
      static constexpr uint32_t   
                             syscfg_comp = 0x40010000;
      static constexpr uint32_t      cec = 0x40007800;
      static constexpr uint32_t      dac = 0x40007400;
      static constexpr uint32_t      pwr = 0x40007000;
      static constexpr uint32_t     i2c2 = 0x40005800;
      static constexpr uint32_t     i2c1 = 0x40005400;
      static constexpr uint32_t   usart2 = 0x40004400;
      static constexpr uint32_t     spi2 = 0x40003800;
      static constexpr uint32_t     iwdg = 0x40003000;
      static constexpr uint32_t     wwdg = 0x40002C00;
      static constexpr uint32_t      rtc = 0x40002800;
      static constexpr uint32_t    tim14 = 0x40002000;
      static constexpr uint32_t     tim6 = 0x40001000;
      static constexpr uint32_t     tim3 = 0x40000400;
      static constexpr uint32_t     tim2 = 0x40000000;
      //------------------ ~APB ---------------------     
   };
}} 


#endif // QUAN_STM32_F0_PERIPH_MAP_HPP_INCLUDED
