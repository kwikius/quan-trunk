#ifndef QUAN_STM32_DETAIL_PERIPH_REG_ACTION_FWD_HPP_INCLUDED
#define QUAN_STM32_DETAIL_PERIPH_REG_ACTION_FWD_HPP_INCLUDED
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
   Represents an action to be applied to a PeriphReg
   PeriphReg is a model of PeriphReg ( see  quan/stm32/periph_reg.hpp)
   PeriphRegActionFnTag is one of the quan operator functor tags from binary_op
   Value is the value to apply using the function described by PeriphRegActionFnTag
  */
   template <
      typename PeriphReg,
      typename PeriphRegActionFnTag,
      typename PeriphReg::value_type Value
   >
   struct periph_reg_action;

}}}

#endif // QUAN_STM32_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
