#ifndef QUAN_STM32_PUSH_POP_FP_HPP_INCLUDED
#define QUAN_STM32_PUSH_POP_FP_HPP_INCLUDED
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

#include <cstdint>
#if defined QUAN_STM32F4
#include <stm32f4xx.h>
#else
#error "need to define processor"
#endif

namespace quan{ namespace stm32{

   inline void push_FPregs()
   {
#ifdef QUAN_STM32F4
     uint32_t fpscr = __get_FPSCR();
     asm volatile ("push {%0}\n" : : "r"(fpscr): "sp");
     asm volatile ("vpush.64 {d0-d15}" : : : "sp");
#else
#endif
   }

   inline void pop_FPregs()
   {
#ifdef QUAN_STM32F4
    asm volatile ("vpop.64 {d0-d15}" : : :"sp");
    uint32_t fpscr;
    asm volatile ("pop {%0}\n" : "=r"(fpscr) : : "sp");
    __set_FPSCR(fpscr);
#else
#endif
   }

}}// quan::stm32

#endif // QUAN_STM32_PUSH_POP_FP_HPP_INCLUDED
