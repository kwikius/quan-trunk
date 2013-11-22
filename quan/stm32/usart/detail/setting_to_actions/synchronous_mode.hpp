#ifndef QUAN_STM32_USART_SETTING_TO_ACTIONS_SYNCHRONOUS_MODE_HPP_INCLUDED
#define QUAN_STM32_USART_SETTING_TO_ACTIONS_SYNCHRONOUS_MODE_HPP_INCLUDED

#include <quan/stm32/usart/detail/setting_to_actions/settings_to_action_macro.hpp>

namespace quan{ namespace stm32{ namespace usart{ namespace detail{

   // OK for F0, F4
   // CR2:CLKEN
   QUAN_STM32_USART_SETTING_TO_ACTION(synchronous_mode, cr2, 11)

}}}}

#endif // QUAN_STM32_USART_SETTING_TO_ACTIONS_SYNCHRONOUS_MODE_HPP_INCLUDED
