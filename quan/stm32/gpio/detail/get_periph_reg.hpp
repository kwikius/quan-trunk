#ifndef QUAN_STM32_GPIO_DETAIL_GET_PERIPH_REG_HPP_INCLUDED
#define QUAN_STM32_GPIO_DETAIL_GET_PERIPH_REG_HPP_INCLUDED
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

#include <quan/stm32/gpio/module.hpp>
#include <quan/stm32/gpio/settings.hpp>

#include <quan/stm32/gpio/pin.hpp>
#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/if.hpp>

namespace quan{ namespace stm32{ namespace gpio{ namespace detail{

   //meta::TypeFunction
   template <typename Pin, typename Setting, typename Where = void> 
   struct get_periph_reg;

   /*
      metafunction to
      return the moder register for port mode settings for a pin
   */
   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::Mode,Setting> 
         >
      >::type
   >{
      typedef typename Pin::port_type::moder_type type;
   };

    /*
      metafunction to 
      return the OType register for port Otype settings for a pin
   */
   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::OType,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type::otyper_type type;
   };

   /*
      mettafunction to
      return the Pupd reg for Pupd settings for a pin
   */
   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::Pupd,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type::pupdr_type type;
   };

   /*
      metafunction to
      return the ospeedr_rge for a pin
   */
   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::OSpeed,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type::ospeedr_type type;
   };


   /*
      metafunction to return the ostate reg for a pin
   */
   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::OState,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type::odr_type type;
   };

   /*
      get alternate function setting reg for a pin
   */

   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::AlternateFunction,Setting>
         >
      >::type
   >{
      typedef typename quan::meta::if_c< (Pin::pin_value < 8),
         typename Pin::port_type::afrl_type,
         typename Pin::port_type::afrh_type
      >::type type;
   };

}}}} 

#endif // QUAN_STM32_GPIO_DETAIL_GET_PERIPH_REG_HPP_INCLUDED
