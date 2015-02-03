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

//!-!-!start-example

/*
  stm32f4  blink forever on  GPIOD,13 ( orange led on Discovery board )
  very simple. no interrupts etc.
*/

#include <cstdint>
#include <quan/stm32f4/gpio.hpp>

void delay()
{
    for ( long long i = 0; i < 2500000; ++i){
           asm("nop");
    }
}
   
using namespace quan::stm32f4;
typedef gpio::pin<gpiod,13> PD13; // A port Pin is aliased by a typedef

int main()
{
   module_enable<gpiod>();  // On the ARM architecture the GPIO ports must be switched on else no output!

   // The following function is turned into efficient assembler
   // to apply the various settings to the port pin
   apply<
      PD13
      , gpio::mode::output
      , gpio::otype::push_pull
      , gpio::pupd::none
      , gpio::ospeed::fast 
      , gpio::ostate::high // start with led ON
   >();

   while (1) {
     complement<PD13>();  
     delay();
   }
}

//!-!-!end-example

