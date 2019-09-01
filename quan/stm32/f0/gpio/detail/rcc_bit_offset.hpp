#ifndef QUAN_STM32_F0_GPIO_DETAIL_RCC_BIT_OFFSET_HPP_INCLUDED
#define QUAN_STM32_F0_GPIO_DETAIL_RCC_BIT_OFFSET_HPP_INCLUDED
/*
 Copyright (c) 2012-2013 Andy Little 

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

#include <quan/stm32/gpio/typedefs.hpp>

namespace quan{ namespace stm32{ namespace gpio { namespace detail{
       /*
          for getting the rcc bit for
          enable reset etc
       */
         template<typename P>
         struct rcc_bit_offset;

         template<>
         struct rcc_bit_offset<quan::stm32::gpioa>{
            
            static constexpr uint32_t value = 17;
         };

         template<>
         struct rcc_bit_offset<quan::stm32::gpiob>{
            static constexpr uint32_t value = 18;
         };
    
         template<>
         struct rcc_bit_offset<quan::stm32::gpioc>{
            static constexpr uint32_t value = 19;
         };

         template<>
         struct rcc_bit_offset<quan::stm32::gpiod>{
            static constexpr uint32_t value = 20;
         };


         template<>
         struct rcc_bit_offset<quan::stm32::gpiof>{
            static constexpr uint32_t value = 22;
         };

}}}}// quan::sdtm32::gpio::detail


#endif // QUAN_STM32F4_GPIO_DETAIL_RCC_BIT_OFFSET_HPP_INCLUDED
