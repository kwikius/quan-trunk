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
#include <stm32f4xx.h>
/*
after Jack Crossfire << after PX4
http://www.rcgroups.com/forums/showthread.php?t=2031526
*/
// 
static inline uint32_t getFPSCR(void)
{
  uint32_t result;
  asm volatile ("vmrs %0, FPSCR\n" : "=r"(result)  );
  return result;
}

static inline void setFPSCR(uint32_t control_reg)
{
   asm volatile("vmsr FPSCR, %0\n" : : "r"(control_reg));
}
// crash unless 
static inline void push_FPregs()
{
  
  asm volatile ("vpush {s0-s31}" : : : "sp");
}

static inline void pop_FPregs()
{
 asm volatile ("vpop {s0-s31}" : : :"sp");
}

// enable FPU
/* Set CONTROL.FPCA so that we always get the extended context frame
 * with the volatile FP registers stacked above the basic context.
 */
void funfunfun(){
   push_FPregs();
 	uint32_t regval = getFPSCR(); 
   regval  |= (1 << 2);
  	setFPSCR(regval);

   pop_FPregs();
	
/* Ensure that FPCCR.LSPEN is disabled, so that we don't have to contend
 * with the lazy FP context save behaviour.  Clear FPCCR.ASPEN since we
 * are going to turn on CONTROL.FPCA for all contexts.
 */
//FPU->FPCCR &= ~((1 << 31) | (1 << 30));

/* Enable full access to CP10 and CP11 */
	//SCB->CPACR |= ((3 << (2*10)) | (3 << (2*11)));
}

