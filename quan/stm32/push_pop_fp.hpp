#ifndef QUAN_STM32_PUSH_POP_FP_HPP_INCLUDED
#define QUAN_STM32_PUSH_POP_FP_HPP_INCLUDED

#include <cstdint>
#include <stm32f4xx.h>

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
