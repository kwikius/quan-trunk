#include <quan/stm32/systick.hpp>

volatile int64_t quan::stm32::detail::systick_tick::current = 0;

extern "C" void Systick_Handler() __attribute__ ((interrupt ("IRQ")));
extern "C" void SysTick_Handler()
{
   ++quan::stm32::detail::systick_tick::current;
}

