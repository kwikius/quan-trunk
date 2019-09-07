#ifndef QUAN_STM32_L4_CONFIG_HPP_INCLUDED
#define QUAN_STM32_L4_CONFIG_HPP_INCLUDED

#ifndef QUAN_STM32L4
#error dont include directly
#endif

#if defined QUAN_STM32L432
   #include <quan/stm32/l4/config_stm32l432.hpp>
#else
   #if defined QUAN_STM32L412
      #include <quan/stm32/l4/config_stm32l412.hpp>
   #else
      #error need to define header for this L4 processor 
   #endif
#endif

#endif // QUAN_STM32_L4_CONFIG_HPP_INCLUDED
