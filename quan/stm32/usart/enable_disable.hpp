#ifndef QUAN_STM32_USART_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_USART_ENABLE_DISABLE_HPP_INCLUDED

#include <quan/stm32/usart/module.hpp>
#include <quan/is_model_of.hpp>

namespace quan{ namespace stm32{

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   enable()
   {    
#if defined QUAN_STM32F4
      constexpr uint8_t enable_bit = 13;
#else 
#if defined QUAN_STM32F0
      constexpr uint8_t enable_bit = 0;
#else
#error need to define for processor
#endif
#endif
      U::get()->cr1.template setbit<enable_bit>();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   disable()
   {    
#if defined QUAN_STM32F4
      constexpr uint8_t enable_bit = 13;
#else 
#if defined QUAN_STM32F0
      constexpr uint8_t enable_bit = 0;
#else
#errot need to define for processor
#endif
#endif
      U::get()->cr1.template clearbit<enable_bit>();
   }

}}

#endif // QUAN_STM32_USART_ENABLE_DISABLE_HPP_INCLUDED
