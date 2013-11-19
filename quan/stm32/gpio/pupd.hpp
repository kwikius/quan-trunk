#ifndef QUAN_STM32_GPIO_PUPD_HPP_INCLUDED
#define QUAN_STM32_GPIO_PUPD_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/stm32/gpio/setting.hpp>

namespace quan{ namespace stm32{ namespace gpio{

   struct Pupd; // Concept

   template <uint32_t V>
   struct pupd_value{

      static constexpr uint32_t value = V;
      static constexpr uint32_t numbits = 2;

   };

   struct pupd{
  
     typedef pupd_value<0b00> none;
     typedef pupd_value<0b01> pull_up;
     typedef pupd_value<0b10> pull_down;

   };

}}} 

namespace quan{ namespace impl{

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32::gpio::Pupd,
			quan::stm32::gpio::pupd_value<V> 
	> : quan::meta::true_{};

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32::gpio::Setting,
			quan::stm32::gpio::pupd_value<V> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32_GPIO_PUPD_HPP_INCLUDED
