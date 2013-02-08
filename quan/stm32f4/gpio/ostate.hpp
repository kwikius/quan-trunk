#ifndef QUAN_STM32F4_GPIO_OSTATE_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_OSTATE_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/stm32f4/gpio/setting.hpp>

namespace quan{ namespace stm32f4{ namespace gpio{

   struct OState; // Concept

   template <bool V>
    struct ostate_value{
      static constexpr bool value = V;
   };

   struct ostate{

      typedef ostate_value<true> high;
      typedef ostate_value<false> low;

   };

}}}

namespace quan{ namespace impl{

   template <bool V>
   struct is_model_of_impl<
			quan::stm32f4::gpio::OState,
			quan::stm32f4::gpio::ostate_value<V> 
	> : quan::meta::true_{};

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32f4::gpio::Setting,
			quan::stm32f4::gpio::ostate_value<V> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32F4_GPIO_OSTATE_HPP_INCLUDED
