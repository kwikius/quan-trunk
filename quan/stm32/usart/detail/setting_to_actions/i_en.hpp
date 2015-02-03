#ifndef QUAN_STM32_USART_SETTING_TO_ACTIONS_I_EN_HPP_INCLUDED
#define QUAN_STM32_USART_SETTING_TO_ACTIONS_I_EN_HPP_INCLUDED
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
