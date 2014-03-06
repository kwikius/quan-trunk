#ifndef QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_SETTINGS_TO_ACTION_MACRO_HPP_INCLUDED
#define QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_SETTINGS_TO_ACTION_MACRO_HPP_INCLUDED

#include <quan/stm32/usart/detail/setting_to_actions_fwd.hpp>
#include <quan/stm32/detail/make_boolean_action.hpp>
#include <quan/meta/push_back.hpp>

#define QUAN_STM32_USART_SETTING_TO_ACTION(Struct, Register, Bit) \
   template <bool Value>\
   struct setting_to_actions< quan::stm32::usart:: Struct <Value> >{\
      template <typename ListOfActions,typename U> struct apply{\
         typedef typename quan::stm32::detail::make_boolean_action<\
            Value, typename U:: Register ## _type, Bit \
         >::type action_type;\
         typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;\
      };\
   };

#endif // QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_SETTINGS_TO_ACTION_MACRO_HPP_INCLUDED
