#ifndef QUAN_STM32F4_GPIO_OSPEED_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_OSPEED_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/stm32f4/gpio/setting.hpp>

namespace quan{ namespace stm32f4{ namespace gpio{

   struct OSpeed; // Concept

   template <uint32_t V>
   struct ospeed_value{
      static constexpr uint32_t value = V;
      static constexpr uint32_t numbits = 2;
   };

   struct ospeed{
  
     typedef ospeed_value<0b00> slow;
     typedef ospeed_value<0b01> medium_slow;
     typedef ospeed_value<0b10> medium_fast;
     typedef ospeed_value<0b11> fast; 

   };

}}}

namespace quan{ namespace impl{

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32f4::gpio::OSpeed,
			quan::stm32f4::gpio::ospeed_value<V> 
	> : quan::meta::true_{};

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32f4::gpio::Setting,
			quan::stm32f4::gpio::ospeed_value<V> 
	> : quan::meta::true_{};

}}




#endif // QUAN_STM32F4_GPIO_OSPEED_HPP_INCLUDED
