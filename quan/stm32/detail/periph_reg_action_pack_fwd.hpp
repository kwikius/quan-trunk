#ifndef QUAN_STM32_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
#define QUAN_STM32_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
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

namespace quan{ namespace stm32{ namespace detail{

/*
   A List of PeriphRegActions required to implement the settings specified by Setting
   to the Entity.
   Settings are specific to the Entity
   so far Entities include
      stm32::gpio::Pin
      stm32::Usart
*/
  template <typename Entity, typename Setting, typename Where = void>
  struct periph_reg_action_pack;

}}}

#endif // QUAN_STM32_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
