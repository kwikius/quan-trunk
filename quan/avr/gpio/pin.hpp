#ifndef QUAN_AVR_GPIO_PIN_HPP_INCLUDED
#define QUAN_AVR_GPIO_PIN_HPP_INCLUDED
/*
 Copyright (c) 2012-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/avr/gpio/module.hpp>
#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/numbits.hpp>

namespace quan{ namespace avr{ namespace gpio{

  struct Pin; // Archetype

  // a Pin consists of a port and a bit position
  template <typename Port,typename Port::value_type Pos> struct pin{
      typedef Port port_type;
      typedef typename port_type::value_type value_type;
      static_assert( (Pos < quan::meta::numbits<value_type>::value) ,
         "bit pos out of range in quan::avr::gpio::pin" );
      static const typename Port::value_type pin_value = Pos;
  };

}}}

namespace quan{ namespace impl{

  template <typename Port, typename Port::value_type Pos>
  struct is_model_of_impl<
      quan::avr::gpio::Pin,quan::avr::gpio::pin<Port,Pos>,
      typename quan::where_<
         quan::is_model_of<quan::avr::Gpio,Port> 
      >::type 
   > : quan::meta::true_{};

}}

#endif // QUAN_AVR_GPIO_PIN_HPP_INCLUDED
