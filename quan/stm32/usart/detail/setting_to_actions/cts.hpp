#ifndef QUAN_STM32_USART_SETTING_TO_ACTIONS_CTS_HPP_INCLUDED
#define QUAN_STM32_USART_SETTING_TO_ACTIONS_CTS_HPP_INCLUDED

#include <quan/stm32/usart/detail/setting_to_actions/settings_to_action_macro.hpp>

namespace quan{ namespace stm32{ namespace usart{ namespace detail{
 
   // Enable CTS (cr3 bit 9)
   QUAN_STM32_USART_SETTING_TO_ACTION(cts, cr3, 9)

}}}}

#endif // QUAN_STM32_USART_SETTING_TO_ACTIONS_CTS_HPP_INCLUDED
