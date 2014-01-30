#ifndef QUAN_STM32_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED

#include <quan/stm32/i2c/module.hpp>
#include <quan/stm32/i2c/detail/module_enable_disable.hpp>
#include <quan/is_model_of.hpp>

namesapce quan{ namespace stm32 {

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::I2C,U> >::type 
   module_enable()
   {    
      quan::stm32::i2c::detail::module_enable<U>{}();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::I2C,U> >::type 
   module_disable()
   {    
      quan::stm32::i2c::detail::module_disable<U>{}();
   }

   template<typename U> inline
   typename quan::where_<quan::is_model_of< quan::stm32::I2C,U> >::type 
   module_reset()
   {    
      quan::stm32::i2c::detail::module_reset<U>{}();
   }

}}

#endif // QUAN_STM32_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
