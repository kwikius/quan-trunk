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
 along with this program. If not, see http://www.gnu.org/licenses.
*/
#include <quan/stm32/systick.hpp>

/*
   either use a 32 bit uint or a 64 bit signed
   The 32 bit update is atomic but will overflow in 49 days
   The 64 bit will take a while to overflow
*/

#if defined (QUAN_SYSTICK_TIMER_UINT32)
 volatile uint32_t quan::stm32::detail::systick_tick::current = 0;
#else
   quan::stm32::detail::systick_tick::current_t 
      quan::stm32::detail::systick_tick::current = {0,0};
#endif

extern "C" void Systick_Handler() __attribute__ ((interrupt ("IRQ")));
extern "C" void SysTick_Handler()
{
#if defined (QUAN_SYSTICK_TIMER_UINT32)
   ++quan::stm32::detail::systick_tick::current;
#else
   if ( quan::stm32::detail::systick_tick::current.ar[0] == 0xffffffff){
       quan::stm32::detail::systick_tick::current.ar[0] = 0;
       ++ quan::stm32::detail::systick_tick::current.ar[1];
   }else{
       ++ quan::stm32::detail::systick_tick::current.ar[0];
   }
#endif
}

