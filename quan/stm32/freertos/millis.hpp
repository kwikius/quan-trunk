#ifndef QUAN_STM32_FREERTOS_MILLIS_HPP_INCLUDED
#define QUAN_STM32_FREERTOS_MILLIS_HPP_INCLUDED

#include <FreeRTOS.h>
#include <task.h>
#include <quan/time.hpp>
/*
 TODO add call to xTaskGetSchedulerState
*/
namespace quan{ namespace stm32{
   
   inline quan::time_<int64_t>::ms millis()
   {
      return quan::time_<int64_t>::ms{
         (static_cast<int64_t>(xTaskGetTickCount()) * 1000)/configTICK_RATE_HZ
      };
   }

}}

#endif //QUAN_STM32_FREERTOS_MILLIS_HPP_INCLUDED
