#ifndef QUAN_STM32_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED
#define QUAN_STM32_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED
/*
 Copyright (c) 2012-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/meta/push_back.hpp>

namespace quan{ namespace stm32{  namespace detail{

  /*
    default add_perip_reg_action function
*/
   template <
      typename Listof_PeriphRegAction, typename PeriphRegOrAction, typename PeriphRegAndAction, 
      typename Module, typename PeriphRegSetting, typename Where = void
   >
   struct add_periph_reg_action{
        static_assert(quan::is_model_of<quan::meta::TypeSequence_, Listof_PeriphRegAction>::value == true,"error");
       typedef typename quan::meta::push_back<
            typename quan::meta::push_back<Listof_PeriphRegAction,PeriphRegOrAction>::type ,PeriphRegAndAction
      >::type type;
   };

}}}

#endif // QUAN_STM32_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED
