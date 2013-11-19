#ifndef QUAN_STM32_GPIO_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED
#define QUAN_STM32_GPIO_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED
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

#include <quan/stm32/detail/add_periph_reg_action.hpp>
#include <quan/is_model_of.hpp>
#include <quan/stm32/gpio/module.hpp>
#include <quan/stm32/gpio/mode.hpp>
#include <quan/stm32/gpio/detail/periph_reg_action_pack.hpp>
#include <quan/meta/push_back.hpp>
#include <quan/meta/and.hpp>


namespace quan{ namespace stm32{  namespace detail{

/*
  have to overload the default here so that alternate function is added 
  First the mode register must be set to to alternate function mode
  then the required alternate function must be applied to the 
  alternate function registers (afrl or afrh). The alternate function masks are
  in the PeripRegOrAction and PeriphRegAndAction actions
*/
  template <
   typename Listof_PeriphRegAction, typename PeriphRegOrAction, typename PeriphRegAndAction,
   typename GpioModule, typename PeriphRegSetting
  >
  struct add_periph_reg_action<Listof_PeriphRegAction, PeriphRegOrAction, PeriphRegAndAction, GpioModule, PeriphRegSetting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::Gpio,GpioModule>,
            quan::is_model_of<quan::stm32::gpio::AlternateFunction,PeriphRegSetting> 
         >
      >::type
  >{
       typedef quan::stm32::detail::periph_reg_action_pack<
         GpioModule,quan::stm32::gpio::mode::alternate_function
       > alt_fn_actions;
       typedef typename alt_fn_actions:: template apply<Listof_PeriphRegAction>::type pre_list;
       typedef typename quan::meta::push_back<
            typename quan::meta::push_back<pre_list,PeriphRegOrAction>::type ,PeriphRegAndAction
      >::type type;
  };

}}}

#endif // QUAN_STM32_GPIO_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED
