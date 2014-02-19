#ifndef QUAN_STM32_SYSTICK_HPP_INCLUDED
#define QUAN_STM32_SYSTICK_HPP_INCLUDED

#include <cstdint>
#include <quan/time.hpp>

#if defined QUAN_STM32F4
#include <stm32f4xx.h>
#elif defined QUAN_STM32F3
#include <stm32f3xx.h>
#elif defined QUAN_STM32F0
#include <stm32f0xx.h>
#else
#error need to define stm32 processor
#endif

namespace quan{namespace stm32{ namespace detail{

   inline void disable_systick_irq()
   {
      SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
   }
   inline void enable_systick_irq()
   {
      SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
   }
   struct systick_tick{
      static volatile int64_t current;
   };
   
}}}

namespace quan{ namespace stm32{

   inline quan::time_<int64_t>::ms millis()
   {
      int64_t result;
      quan::stm32::detail::disable_systick_irq();
      result = stm32::detail::systick_tick::current;
      quan::stm32::detail::enable_systick_irq();
      return quan::time_<int64_t>::ms{result};
   }

}}

#endif // QUAN_STM32_SYSTICK_HPP_INCLUDED
