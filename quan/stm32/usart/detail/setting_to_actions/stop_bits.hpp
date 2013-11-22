#ifndef QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_STOP_BITS_HPP_INCLUDED
#define QUAN_STM32_USART_DETAIL_SETTING_TO_ACTIONS_STOP_BITS_HPP_INCLUDED

#include <quan/stm32/usart/detail/setting_to_actions_fwd.hpp>
#include <quan/stm32/detail/make_boolean_action.hpp>
#include <quan/meta/push_back.hpp>

namespace quan{ namespace stm32{ namespace usart{ namespace detail{

/*
00: 1 Stop bit
01: 0.5 Stop bit
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
            typedef typename quan::meta::push_back<ListOfActions,or_action_type>::type list_of_actions1_type;;
            typedef typename quan::meta::push_back<list_of_actions1_type,and_action_type>::type type;
         };
      };

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
            typedef typename quan::meta::push_back<ListOfActions,or_action_type>::type list_of_actions1_type;;
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
