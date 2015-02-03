#ifndef QUAN_STM32_F4_TIM_DETAIL_MODULE_ENABLE_HPP_INCLUDED
#define QUAN_STM32_F4_TIM_DETAIL_MODULE_ENABLE_HPP_INCLUDED
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

#include <quan/stm32/f4/rcc.hpp>
#include <quan/stm32/tim/module.hpp>
#include <quan/stm32/tim/typedefs.hpp>

namespace quan{ namespace stm32{ namespace tim{ namespace detail{

    // enable the require port

    template<typename T>
    struct module_enable;

    template<typename T>
    struct module_disable;

    template<typename T>
    struct module_reset;
   
    #define QUAN_STM32_MODULE_ENR( TimX, RegNum, Bit) \
     template <> struct module_enable<quan::stm32:: TimX >{\
      void operator()() const\
      {\
         quan::stm32::rcc::get()-> apb ## RegNum ## enr.setbit< Bit >();\
      }\
     };\
\
      template <> struct module_disable<quan::stm32:: TimX >{\
      void operator()() const\
      {\
         quan::stm32::rcc::get()-> apb ## RegNum ## enr.clearbit< Bit >();\
      }\
     };\
\
      template <> struct module_reset<quan::stm32:: TimX >{\
      void operator()() const\
      {\
         quan::stm32::rcc::get()-> apb ## RegNum ## rstr.setbit< Bit >();\
         quan::stm32::rcc::get()-> apb ## RegNum ## rstr.clearbit< Bit >();\
      }\
     };

      QUAN_STM32_MODULE_ENR(tim1,2,0) 
      QUAN_STM32_MODULE_ENR(tim2,1,0) 
      QUAN_STM32_MODULE_ENR(tim3,1,1)
      QUAN_STM32_MODULE_ENR(tim4,1,2)
      QUAN_STM32_MODULE_ENR(tim5,1,3)
      QUAN_STM32_MODULE_ENR(tim6,1,4) 
      QUAN_STM32_MODULE_ENR(tim7,1,5)
      QUAN_STM32_MODULE_ENR(tim8,2,1)
      QUAN_STM32_MODULE_ENR(tim9,2,16)
      QUAN_STM32_MODULE_ENR(tim10,2,17) 
      QUAN_STM32_MODULE_ENR(tim11,2,18)
      QUAN_STM32_MODULE_ENR(tim12,1,6)
      QUAN_STM32_MODULE_ENR(tim13,1,7)
      QUAN_STM32_MODULE_ENR(tim14,1,8) 

#undef QUAN_STM32_MODULE_ENR

    
}}}}// quan::stm32::tim::detail

#endif // QUAN_STM32_F4_DETAIL_MODULE_ENABLE_HPP_INCLUDED
