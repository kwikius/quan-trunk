#ifndef QUAN_STM32_USART_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
#define QUAN_STM32_USART_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
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

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/and.hpp>

#include <quan/stm32/usart/module.hpp>
#include <quan/stm32/detail/periph_reg_action_pack_fwd.hpp>
#include <quan/stm32/usart/settings.hpp>
#include <quan/stm32/usart/detail/setting_to_actions.hpp>

namespace quan{ namespace stm32{ namespace detail{

   template< typename U,  typename S>
   struct periph_reg_action_pack<
      U,S,
      typename quan:: where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::Usart,U>,
            quan::is_model_of<quan::stm32::usart::Setting,S>
         >
      >::type
   >{
      template <typename Listof_PeriphRegAction>
      struct apply{
         //typedef typename S::template apply<Listof_PeriphRegAction,U>::type type;
         typedef typename quan::stm32::usart::detail::setting_to_actions<
            S
         >::template apply<Listof_PeriphRegAction,U>::type type;
      };
   };

}}}//quan::stm32::detail

#endif // QUAN_STM32_USART_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
