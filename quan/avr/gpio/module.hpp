#ifndef QUAN_AVR_GPIO_MODULE_HPP_INCLUDED
#define QUAN_AVR_GPIO_MODULE_HPP_INCLUDED

/*
for avr gcc defines  see http://www.nongnu.org/avr-libc/user-manual/using_tools.html
*/
#include <stdint.h>
#include <quan/avr/periph_reg.hpp>
#include <quan/is_model_of.hpp>
//#include <quan/avr/periph_map.hpp>

namespace quan{ namespace avr{ 

   struct Gpio; // Archetype

   namespace gpio{
   #if defined(__AVR_ATmega328P__)
      template <uint8_t Address> 
      struct module{
         typedef uint8_t value_type;
         static constexpr value_type address = Address;
         typedef module type;
         typedef quan::avr::periph_reg<type,0x0>  pin_type;
         typedef quan::avr::periph_reg<type,0x1>  ddr_type;
         typedef quan::avr::periph_reg<type,0x2>  port_type;
      };
   #else
   #error need to define processor
   #endif 
 }
}}


namespace quan{ namespace impl{

    // make module a model of quan::stm32f4::Gpio
   template <uint8_t Address>
   struct is_model_of_impl<
      quan::avr::Gpio,
      quan::avr::gpio::module<Address> 
	> : quan::meta::true_{};

}}

#endif // QUAN_AVR_GPIO_MODULE_HPP_INCLUDED
