#ifndef QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_BAUD_RATE_HPP_INCLUDED
#define QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_BAUD_RATE_HPP_INCLUDED

#include <quan/stm32/usart/detail/setting_to_actions_fwd.hpp>
#include <quan/stm32/detail/make_boolean_action.hpp>
#include <quan/meta/push_back.hpp>
#include <quan/stm32/usart/detail/get_baud_rate_values.hpp>

/*
stm32f05 ref_man
25.7.4 Baud rate register (USART_BRR)

n.bF0 Baudrate can only be set when Usart is disabled


*/

namespace quan{ namespace stm32{ namespace usart{namespace detail{

   template <uint32_t BaudRate, bool Over8>
   struct setting_to_actions<quan::stm32::usart::baud_rate<BaudRate,Over8> >{

      template <typename ListOfActions,typename U> struct apply {

         typedef typename quan::stm32::detail::make_boolean_action<
            Over8, typename U::cr1_type,15
         >::type over8_type;

         typedef typename quan::stm32::detail::periph_reg_action<
            typename U::brr_type,
            quan::meta::equals,
            quan::stm32::usart::detail::get_baud_rate_values<U,BaudRate,Over8>::value
         > action_type;

         typedef typename quan::meta::push_back<ListOfActions,over8_type>::type list1_type;
         typedef typename quan::meta::push_back<list1_type,action_type>::type type;

      };

   };

}}}}

#endif // QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_BAUD_RATE_HPP_INCLUDED
