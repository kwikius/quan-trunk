#ifndef QUAN_STM32_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED
#define QUAN_STM32_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED
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

#include <quan/bit.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/operators/binary_operator_functors.hpp>

#include <quan/stm32/detail/periph_reg_action_fwd.hpp>

namespace quan{ namespace stm32{ namespace detail {

   /*
      metafunction to create either an or_action  to set bit(BitPos) in PeriphReg if B is true
      or an and_action to clear BitPos in PeriphReg if B == false

     PeriphReg is a model of PeriphReg
   */

   template <typename PeriphReg,  uint32_t BitPos>
   struct make_or_action{
      typedef PeriphReg reg_type;
      typedef typename reg_type::value_type value_type;
      typedef quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_or,quan::bit<value_type>(BitPos) > type;
   };

   template <typename PeriphReg,  uint32_t BitPos>
   struct make_and_action{
      typedef PeriphReg reg_type;
      typedef typename reg_type::value_type value_type;
      typedef quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_and,~quan::bit<value_type>(BitPos) > type;
   };

   template <bool B, typename PeriphReg,  uint32_t BitPos> 
   struct make_boolean_action : quan::meta::eval_if_c<B,make_or_action<PeriphReg,BitPos>,make_and_action<PeriphReg,BitPos> >{};

}}} //quan::stm32::detail

#endif // QUAN_STM32F4_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED
