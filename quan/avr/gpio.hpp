#ifndef QUAN_AVR_GPIO_HPP_INCLUDED
#define QUAN_AVR_GPIO_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */


#include <quan/avr/gpio_typedefs.hpp>
#include <quan/avr/gpio/pin.hpp>
#include <quan/std/tr1/is_same.hpp>
#include <quan/avr/gpio/mode.hpp>

namespace quan{ namespace avr{

      

      template <typename P, typename Mode>
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::avr::gpio::Pin,P>,
            std::is_same<Mode,quan::avr::gpio::mode::input>
         >
      >::type
      setmode()
      {
        *(reinterpret_cast<volatile uint8_t*>(P::port_type::ddr_type::address)) &= ~(1 << P::pin_value);
      }

      
      template <typename P, typename Mode>
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::avr::gpio::Pin,P>,
            std::is_same<Mode,quan::avr::gpio::mode::output>
         >
      >::type
      setmode()
      {
        *(reinterpret_cast<volatile uint8_t*>(P::port_type::ddr_type::address)) |= (1 << P::pin_value);
      }

      template <typename P>
      typename quan::where_<
         quan::is_model_of<quan::avr::gpio::Pin,P>
      >::type
      set()
      {
        *(reinterpret_cast<volatile uint8_t*>(P::port_type::port_type::address)) |= (1 << P::pin_value);
      }

       template <typename P>
      typename quan::where_<
         quan::is_model_of<quan::avr::gpio::Pin,P>
      >::type
      clear()
      {
        *(reinterpret_cast<volatile uint8_t*>(P::port_type::port_type::address)) &= ~(1 << P::pin_value);
      }     
} }

#endif // QUAN_AVR_GPIO_HPP_INCLUDED
