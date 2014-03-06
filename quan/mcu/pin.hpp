#ifndef QUAN_MCU_PIN_HPP_INCLUDED
#define QUAN_MCU_PIN_HPP_INCLUDED
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


#include <quan/meta/numbits.hpp>

namespace quan{  namespace mcu{

 // struct Pin; // Archetype

  // a Pin consists of a port and a bit position
  template <typename Port,typename Port::value_type Pos> struct pin{
      typedef Port port_type;
      typedef typename port_type::value_type value_type;
      static_assert( Pos < static_cast<typename Port::value_type>(quan::meta::numbits<value_type>::value) ,
         "bit pos out of range in quan::mcu::pin" );
      static const typename Port::value_type pin_value = Pos;
  };

}}

#endif // QUAN_STM32F4_GPIO_PIN_HPP_INCLUDED
