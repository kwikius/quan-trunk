#ifndef QUAN_STM32_GET_BUS_PRESCALER_VALUE_HPP_INCLUDED
#define QUAN_STM32_GET_BUS_PRESCALER_VALUE_HPP_INCLUDED

#include <quan/stm32/config.hpp>
#include <quan/stm32/detail/buses.hpp>

namespace quan{ namespace stm32{ 
   
   namespace detail{

      template <typename AxB_Bus>
      struct get_bus_prescaler_value;

   #if defined QUAN_STM32F0

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::ahb1>{
         static constexpr uint32_t value = QUAN_STM32_AHB_DIVISOR ;
      };

     template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::ahb2>{
         static constexpr uint32_t value = QUAN_STM32_AHB_DIVISOR ;
      };

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::apb>{
         static constexpr uint32_t value = QUAN_STM32_APB_DIVISOR ;
      };

   #elif defined QUAN_STM32F4

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::ahb1>{
         static constexpr uint32_t value = QUAN_STM32_AHB_DIVISOR ;
      };

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::ahb2>{
         static constexpr uint32_t value = QUAN_STM32_AHB_DIVISOR ;
      };

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::ahb3>{
         static constexpr uint32_t value = QUAN_STM32_AHB_DIVISOR ;
      };

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::apb1>{
         static constexpr uint32_t value = QUAN_STM32_APB1_DIVISOR ;
      };

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::apb2>{
         static constexpr uint32_t value = QUAN_STM32_APB2_DIVISOR ;
      };

   #elif defined QUAN_STM32L4


      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::ahb1>{
         static constexpr uint32_t value = QUAN_STM32_AHB_DIVISOR ;
      };

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::ahb2>{
         static constexpr uint32_t value = QUAN_STM32_AHB_DIVISOR ;
      };

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::apb1>{
         static constexpr uint32_t value = QUAN_STM32_APB1_DIVISOR ;
      };

      template <> 
      struct get_bus_prescaler_value<quan::stm32::detail::apb2>{
         static constexpr uint32_t value = QUAN_STM32_APB2_DIVISOR ;
      };

   #endif

   }// detail

   template <typename Bus>
   inline constexpr uint32_t get_bus_prescaler_value()
   {
      return quan::stm32::detail::get_bus_prescaler_value<Bus>::value;
   }
   
}}


#endif // QUAN_STM32_GET_BUS_PRESCALER_VALUE_HPP_INCLUDED
