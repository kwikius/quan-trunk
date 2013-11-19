#ifndef QUAN_STM32_GPIO_OTYPE_HPP_INCLUDED
#define QUAN_STM32_GPIO_OTYPE_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/stm32/gpio/setting.hpp>

namespace quan{ namespace stm32{ namespace gpio{

   struct OType; //Concept

   template <uint32_t V>
   struct otype_value{

      static constexpr uint32_t value = V;
      static constexpr uint32_t numbits = 1;

   };

   struct otype{
  
     typedef otype_value<0b0> push_pull;
     typedef otype_value<0b1> open_drain;
    
   };

}}}

namespace quan{ namespace impl{

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32::gpio::OType,
			quan::stm32::gpio::otype_value<V> 
	> : quan::meta::true_{};

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32::gpio::Setting,
			quan::stm32::gpio::otype_value<V> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32_GPIO_OTYPE_HPP_INCLUDED
