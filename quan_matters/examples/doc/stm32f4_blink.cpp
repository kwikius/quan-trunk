
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

