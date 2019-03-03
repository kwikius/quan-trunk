#ifndef QUAN_STM32_FREERTOS_MILLIS_HPP_INCLUDED
#define QUAN_STM32_FREERTOS_MILLIS_HPP_INCLUDED

#include <FreeRTOS.h>
#include <task.h>
#include <quan/time.hpp>
/*
 TODO add call to xTaskGetSchedulerState
*/
namespace quan{ namespace stm32{
   
/*
bear in mind its only a uint32_t really! Will overflow in approx 49 days
 could change it to a uint32_t or int32_t. then 24 days?
*/

#if defined QUAN_SYSTICK_TIMER_UINT32

   inline quan::time_<uint32_t>::ms millis()
   {
      static_assert(std::is_same<TickType_t,uint32_t>::value,"unexpected freertos ticktype");
      return quan::time_<uint32_t>::ms{
         static_cast<uint32_t>(xTaskGetTickCount() * (1000U/configTICK_RATE_HZ))
      };
   }

#else
   inline quan::time_<int64_t>::ms millis()
   {
      static_assert(std::is_same<TickType_t,uint32_t>::value,"unexpected freertos ticktype");
      return quan::time_<int64_t>::ms{
         xTaskGetTickCount() * (1000/configTICK_RATE_HZ)
      };
   }
#endif

   inline quan::time_<uint32_t>::ms millis_from_isr()
   {
      static_assert(std::is_same<TickType_t,uint32_t>::value,"unexpected freertos ticktype");
      return quan::time_<uint32_t>::ms{
         xTaskGetTickCountFromISR() * (1000/configTICK_RATE_HZ)
      };
   }


}}

#endif //QUAN_STM32_FREERTOS_MILLIS_HPP_INCLUDED
