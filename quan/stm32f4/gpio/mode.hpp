#ifndef QUAN_STM32F4_GPIO_MODE_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_MODE_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>

#include <quan/stm32f4/gpio/setting.hpp>

namespace quan{ namespace stm32f4{ namespace gpio{

   struct Mode; // Concept 

   template <uint32_t V>
   struct mode_value{

         static constexpr uint32_t value = V;
         static constexpr uint32_t numbits = 2;
   };

   struct AlternateFunction; // Concept

   template <uint32_t N>
   struct alternate_function{

     static constexpr uint32_t value = N;
     static constexpr uint32_t numbits = 4;
     
   };

   struct mode{
     
      typedef mode_value<0b00> input;
      typedef mode_value<0b01> output;
      typedef mode_value<0b10> alternate_function;
      typedef mode_value<0b11> analog;
      
      typedef quan::stm32f4::gpio::alternate_function<0> af0;
      typedef quan::stm32f4::gpio::alternate_function<1> af1;
      typedef quan::stm32f4::gpio::alternate_function<2> af2;
      typedef quan::stm32f4::gpio::alternate_function<3> af3;
      typedef quan::stm32f4::gpio::alternate_function<4> af4;
      typedef quan::stm32f4::gpio::alternate_function<5> af5;
      typedef quan::stm32f4::gpio::alternate_function<6> af6;
      typedef quan::stm32f4::gpio::alternate_function<7> af7;
      typedef quan::stm32f4::gpio::alternate_function<8> af8;
      typedef quan::stm32f4::gpio::alternate_function<9> af9;
      typedef quan::stm32f4::gpio::alternate_function<10> a10;
      typedef quan::stm32f4::gpio::alternate_function<11> af11;
      typedef quan::stm32f4::gpio::alternate_function<12> af12;
      typedef quan::stm32f4::gpio::alternate_function<13> af13;
      typedef quan::stm32f4::gpio::alternate_function<14> af14;
      typedef quan::stm32f4::gpio::alternate_function<15> af15;

   };

}}} // quan::stm32f4::gpio

namespace quan{ namespace impl{

    // make port a model of Port
   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32f4::gpio::Mode,
			quan::stm32f4::gpio::mode_value<V> 
	> : quan::meta::true_{};

   template <uint32_t V>
   struct is_model_of_impl<
			quan::stm32f4::gpio::Setting,
			quan::stm32f4::gpio::mode_value<V> 
	> : quan::meta::true_{};

   template <uint32_t N>
   struct is_model_of_impl<
			quan::stm32f4::gpio::AlternateFunction,
			quan::stm32f4::gpio::alternate_function<N> 
	> : quan::meta::true_{};

   template <uint32_t N>
   struct is_model_of_impl<
			quan::stm32f4::gpio::Setting,
			quan::stm32f4::gpio::alternate_function<N> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32F4_GPIO_MODE_HPP_INCLUDED
