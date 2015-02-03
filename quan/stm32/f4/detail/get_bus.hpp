#ifndef QUAN_STM32_F4_DETAIL_GET_BUS_HPP_INCLUDED
#define QUAN_STM32_F4_DETAIL_GET_BUS_HPP_INCLUDED
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


#ifndef QUAN_STM32F4
#error dont include directly
#endif

#include <quan/is_model_of.hpp>
#include <quan/stm32/f4/periph_map.hpp>

#include <quan/stm32/module.hpp>
#include <quan/undefined.hpp>
#include <quan/stm32/f4/detail/buses.hpp>

namespace quan{ namespace stm32{ namespace detail{
    
    template <typename Module, typename Where = void>
    struct get_bus;

    template <uint32_t Address, typename Where = void>
    struct get_bus_c { typedef quan::undefined type;};

   template<uint32_t Address>
   struct get_bus_c<Address,typename quan::where_c< (Address == quan::stm32::periph_map::fsmc)>::type
   >{
      typedef ahb3 type;
   };

   template<uint32_t Address>
   struct get_bus_c<Address,typename quan::where_c< 
      ((Address <= quan::stm32::periph_map::rng) && (Address >= quan::stm32::periph_map::usbotgfs)) >::type
   >{
      typedef ahb2 type;
   };

   template<uint32_t Address>
   struct get_bus_c<Address,typename quan::where_c< 
      ((Address <= quan::stm32::periph_map::usbotghs) && (Address >= quan::stm32::periph_map::gpioa)) >::type
   >{
      typedef ahb1 type;
   };


   template<uint32_t Address>
   struct get_bus_c<Address,typename quan::where_c< 
      ((Address <= quan::stm32::periph_map::tim11) && (Address >= quan::stm32::periph_map::tim1)) >::type
   >{
      typedef apb2 type;
   };

   template<uint32_t Address>
   struct get_bus_c<Address,typename quan::where_c< 
      ((Address <= quan::stm32::periph_map::dac) && (Address >= quan::stm32::periph_map::tim2)) >::type
   >{
      typedef apb1 type;
   };


   template <typename Module>
   struct get_bus<
      Module,
      typename quan::where_< quan::is_model_of<quan::stm32::Module,Module> >::type
   > : get_bus_c<Module::address>{};

}}}

#endif // QUAN_STM32F4_USART_GET_BUS_HPP_INCLUDED
