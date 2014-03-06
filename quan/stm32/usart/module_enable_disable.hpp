#ifndef QUAN_STM32_USART_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_USART_MODULE_ENABLE_DISABLE_HPP_INCLUDED

#include <quan/stm32/usart/module.hpp>
#include <quan/stm32/usart/detail/module_enable_disable.hpp>
#include <quan/is_model_of.hpp>

namespace quan{ namespace stm32{

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   module_enable()
   {    
      quan::stm32::usart::detail::module_enable<U>{}();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   module_disable()
   {    
      quan::stm32::usart::detail::module_disable<U>{}();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::Usart,U> >::type 
   module_reset()
   {    
      quan::stm32::usart::detail::module_reset<U>{}();
   }

}}//quan::stm32

#endif // QUAN_STM32_USART_MODULE_ENABLE_DISABLE_HPP_INCLUDED
