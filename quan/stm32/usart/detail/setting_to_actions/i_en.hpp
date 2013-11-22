#ifndef QUAN_STM32_USART_SETTING_TO_ACTIONS_I_EN_HPP_INCLUDED
#define QUAN_STM32_USART_SETTING_TO_ACTIONS_I_EN_HPP_INCLUDED

#include <quan/stm32/usart/detail/setting_to_actions/settings_to_action_macro.hpp>

namespace quan{ namespace stm32{ namespace usart{ namespace detail{

      QUAN_STM32_USART_SETTING_TO_ACTION(i_en::cts   , cr3,10)
      QUAN_STM32_USART_SETTING_TO_ACTION(i_en::lbd   , cr2, 6)
      QUAN_STM32_USART_SETTING_TO_ACTION(i_en::txe   , cr1,7)
      QUAN_STM32_USART_SETTING_TO_ACTION(i_en::tc    , cr1,6)
      QUAN_STM32_USART_SETTING_TO_ACTION(i_en::rxne  , cr1,5)
      QUAN_STM32_USART_SETTING_TO_ACTION(i_en::idle  , cr1,4)
      QUAN_STM32_USART_SETTING_TO_ACTION(i_en::pe    , cr1,8)
      QUAN_STM32_USART_SETTING_TO_ACTION(i_en::error , cr3,0)

}}}}

#endif // QUAN_STM32_USART_SETTING_TO_ACTIONS_I_EN_HPP_INCLUDED
