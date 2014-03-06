#ifndef QUAN_STM32_GPIO_ARCHETYPE_HPP_INCLUDED
#define QUAN_STM32_GPIO_ARCHETYPE_HPP_INCLUDED

#include <quan/stm32/module.hpp>
#include <quan/is_model_of.hpp>

namespace quan{ namespace stm32{ 
   
   struct Gpio; // Archetype

}}

namespace quan{ namespace impl{

   // a model of Gpio is a model stm32::Module
   template <typename T>
   struct is_model_of_impl<
      quan::stm32::Module,T
      ,typename quan::where_<quan::is_model_of<quan::stm32::Gpio,T> >::type
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32_GPIO_ARCHETYPE_HPP_INCLUDED
