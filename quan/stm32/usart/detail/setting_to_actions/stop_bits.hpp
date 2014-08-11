#ifndef QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_STOP_BITS_HPP_INCLUDED
#define QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_STOP_BITS_HPP_INCLUDED
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

/*
00: 1 Stop bit
01: 0.5 Stop bit  (n/a on stm32f0)
10: 2 Stop bits
11: 1.5 Stop bit

*/
      template <>
      struct setting_to_actions<quan::stm32::usart::stop_bits<1> >{
         //0,0
         template <typename ListOfActions,typename U> struct apply{
           typedef typename U::value_type value_type;
           static constexpr value_type mask_value = ~(quan::bit<value_type>(12) | quan::bit<value_type>(13));
           typedef quan::stm32::detail::periph_reg_action<typename U::cr2_type,quan::meta::bit_and,mask_value> action_type;
           typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };
// 0.5 stop bits n/a on stm32f0
#ifdef QUAN_STM32F4
      template <>
      struct setting_to_actions<quan::stm32::usart::stop_bits<1,2> >{
         // 0,1
         template <typename ListOfActions,typename U> struct apply{
            typedef typename U::value_type value_type;
            typedef typename quan::stm32::detail::periph_reg_action<
               typename U::cr2_type,quan::meta::bit_or,quan::bit<value_type>(12)
            > or_action_type;
            typedef typename quan::stm32::detail::periph_reg_action<
               typename U::cr2_type,quan::meta::bit_and,~quan::bit<value_type>(13)
            > and_action_type;
            typedef typename quan::meta::push_back<ListOfActions,or_action_type>::type list_of_actions1_type;
            typedef typename quan::meta::push_back<list_of_actions1_type,and_action_type>::type type;
         };
      };
#endif

      template <>
      struct setting_to_actions<quan::stm32::usart::stop_bits<2> >{
         // 1,0
         template <typename ListOfActions,typename U> struct apply{
            typedef typename U::value_type value_type;
            typedef typename quan::stm32::detail::periph_reg_action<
               typename U::cr2_type,quan::meta::bit_or,quan::bit<value_type>(13)
            > or_action_type;
            typedef typename quan::stm32::detail::periph_reg_action<
               typename U::cr2_type,quan::meta::bit_and,~quan::bit<value_type>(12)
            > and_action_type;
            typedef typename quan::meta::push_back<ListOfActions,or_action_type>::type list_of_actions1_type;
            typedef typename quan::meta::push_back<list_of_actions1_type,and_action_type>::type type;
         };
      };

      template <>
      struct setting_to_actions<quan::stm32::usart::stop_bits<3,2> >{
         //1,1
          template <typename ListOfActions,typename U> struct apply{
           typedef typename U::value_type value_type;
           static constexpr value_type mask_value = (quan::bit<value_type>(12) | quan::bit<value_type>(13));
           typedef quan::stm32::detail::periph_reg_action<typename U::cr2_type,quan::meta::bit_or,mask_value> action_type;
           typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

}}}}

#endif // QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_STOP_BITS_HPP_INCLUDED
