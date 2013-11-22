#ifndef QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_DATA_BITS_HPP_INCLUDED
#define QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_DATA_BITS_HPP_INCLUDED

#include <quan/stm32/usart/detail/setting_to_actions_fwd.hpp>
#include <quan/stm32/detail/make_boolean_action.hpp>
#include <quan/meta/push_back.hpp>

namespace quan{ namespace stm32{ namespace usart{ namespace detail{
// ok on F4,F0
      // CR1
      // M = bit(12) word length
      // M = 0 word length = 8 bits
      
      template<> 
      struct setting_to_actions<quan::stm32::usart::data_bits<8> >{
             template <typename ListOfActions,typename U> struct apply {
            typedef typename quan::stm32::detail::make_boolean_action<
               false, typename U::cr1_type,12
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

// ok on F4,F0
      // CR1
      // M = bit(12) word length
      // M = 1 word length = 9 bits

      template<> 
      struct setting_to_actions<quan::stm32::usart::data_bits<9> >{
             template <typename ListOfActions,typename U> struct apply {
            typedef typename quan::stm32::detail::make_boolean_action<
               true, typename U::cr1_type,12
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };
}}}}

#endif // QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_DATA_BITS_HPP_INCLUDED
