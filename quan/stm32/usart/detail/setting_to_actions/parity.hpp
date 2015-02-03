#ifndef QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_PARITY_HPP_INCLUDED
#define QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_PARITY_HPP_INCLUDED
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

#include <quan/stm32/usart/detail/setting_to_actions_fwd.hpp>
#include <quan/stm32/detail/make_boolean_action.hpp>
#include <quan/meta/push_back.hpp>

namespace quan{ namespace stm32{ namespace usart{ namespace detail{

   // ok on F0 and F4 
   // Reg CR1
   // PCE = bit(10)
   // PCE = 0 to disable parity checking
   template<> 
   struct setting_to_actions<quan::stm32::usart::parity::none> {
      template <typename ListOfActions,typename U> struct apply {
         typedef typename quan::stm32::detail::make_boolean_action<
            false, typename U::cr1_type,10
         >::type action_type;
         typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
      };
   };

   // enable parity and set to odd
   // ok on F0 and F4
   // Reg CR1
   // PCE = bit(10)
   // PCE = 1 to enable parity checking
   // PS = bit(9)
   // PS = 1 for odd parity
   template<> 
   struct setting_to_actions<quan::stm32::usart::parity::odd> {
      template <typename ListOfActions,typename U> struct apply{
         typedef typename U::value_type value_type;
         static constexpr value_type mask_value = quan::bit<value_type>(10) | quan::bit<value_type>(9);
         typedef quan::stm32::detail::periph_reg_action<typename U::cr1_type,quan::meta::bit_or,mask_value> action_type;
         typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
      };
   };

   // enable parity and set to even
   // ok on F0 and F4
   // Reg CR1
   // PCE = bit(10)
   // PCE = 1 to enable parity checking
   // PS = bit(9)
   // PS = 0 for even parity
   template<> 
   struct setting_to_actions<quan::stm32::usart::parity::even>{
      template <typename ListOfActions,typename U> struct apply{
         typedef typename U::value_type value_type;
         typedef typename quan::stm32::detail::periph_reg_action<
            typename U::cr1_type,quan::meta::bit_or,quan::bit<value_type>(10)
         > or_action_type;
         typedef typename quan::stm32::detail::periph_reg_action<
            typename U::cr1_type,quan::meta::bit_and,~quan::bit<value_type>(9)
         > and_action_type;
         typedef typename quan::meta::push_back<ListOfActions,or_action_type>::type list_of_actions1_type;
         typedef typename quan::meta::push_back<list_of_actions1_type,and_action_type>::type type;
      };
   };

}}}}

#endif // QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_PARITY_HPP_INCLUDED
