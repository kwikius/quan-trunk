#ifndef QUAN_STM32_GPIO_MODULE_HPP_INCLUDED
#define QUAN_STM32_GPIO_MODULE_HPP_INCLUDED
/*

 Copyright (c) 2012 Andy Little

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

#include <quan/stm32/config.hpp>
#include <quan/stm32/periph_reg.hpp>
#include <quan/stm32/module.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/type_sequence.hpp>

namespace quan{ namespace stm32{ 

    struct Gpio; // Archetype

    namespace gpio{

      template <uint32_t Address> 
      struct module{

         typedef uint32_t value_type;
         static constexpr value_type address = Address;

         typedef module type;

         typedef quan::stm32::periph_reg<type,0x0>  moder_type;
         typedef quan::stm32::periph_reg<type,0x04> otyper_type;
         typedef quan::stm32::periph_reg<type,0x08> ospeedr_type;
         typedef quan::stm32::periph_reg<type,0x0C> pupdr_type;
         typedef quan::stm32::periph_reg<type,0x10> idr_type;
         typedef quan::stm32::periph_reg<type,0x14> odr_type;
         typedef quan::stm32::periph_reg<type,0x18> bsrr_type;
         typedef quan::stm32::periph_reg<type,0x1C> lckr_type;
         typedef quan::stm32::periph_reg<type,0x20> afrl_type;
         typedef quan::stm32::periph_reg<type,0x24> afrh_type;
#if defined(QUAN_STM32F0) || defined (QUAN_STM32L4)
         typedef quan::stm32::periph_reg<type,0x28> brr_type;
#endif
         moder_type     moder;
         otyper_type    otyper;
         ospeedr_type   ospeedr;
         pupdr_type     pupdr;
         idr_type       idr;
         odr_type       odr;
         bsrr_type      bsrr;
         lckr_type      lckr;
         afrl_type      afrl;
         afrh_type      afrh;
#if defined(QUAN_STM32F0) || defined (QUAN_STM32L4)
         brr_type       brr;
#endif
         typedef quan::meta::type_sequence<  
            moder_type ,
            otyper_type ,
            ospeedr_type ,
            pupdr_type ,
            idr_type ,
            odr_type ,
            bsrr_type ,
            lckr_type ,
            afrl_type ,
            afrh_type 
#if defined(QUAN_STM32F0) || defined (QUAN_STM32L4)
           , brr_type 
#endif
         > periph_reg_list;

         static constexpr module* get(){ return reinterpret_cast<module*>(Address);}

      private:
         
         module() = delete;
         module(module const &) = delete;
         module& operator = (module const & ) = delete;
      };

}}} //quan::stm32::gpio

namespace quan{ namespace impl{

    // is a model of quan::stm32::Gpio
   template <uint32_t Address>
   struct is_model_of_impl<
      quan::stm32::Gpio,
      quan::stm32::gpio::module<Address> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32F4_GPIO_MODULE_HPP_INCLUDED

