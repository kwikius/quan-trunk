#ifndef QUAN_STM32_PERIPH_REG_ACTIONS_APPLY_HPP_INCLUDED
#define QUAN_STM32_PERIPH_REG_ACTIONS_APPLY_HPP_INCLUDED
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

#include <quan/meta/is_model_of.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/low_bits_mask.hpp>
#include <quan/meta/count_if.hpp>
#include <quan/meta/for_each.hpp>
#include <quan/meta/fold.hpp>
#include <quan/meta/transform.hpp>
#include <quan/meta/type_sequence.hpp>
#include <quan/stm32/module.hpp>
#include <quan/stm32/detail/periph_reg_actions.hpp>

namespace quan{ namespace stm32{

   template <typename E, typename ... Listof_Setting>
   typename quan::where_<
      quan::is_model_of<quan::stm32::Module,typename quan::stm32::get_module<E>::type> 
   >::type
    apply()
   { 
      typedef typename detail::periph_reg_action_list_check<E>::template apply<
         Listof_Setting...
      >::type periph_reg_settings_list;
     
      typedef typename quan::meta::transform<
         periph_reg_settings_list, quan::stm32::detail::make_periph_reg_action_pack<E> 
      >::type packed_actions;

      //compress actions where possible
      typedef typename quan::meta::fold<
         packed_actions,quan::meta::type_sequence<>,
         quan::stm32::detail::unpack_actions 
      >::type periph_reg_actions;

      typedef typename get_module<E>::type module_type;

      static_assert(
         quan::is_model_of<quan::meta::TypeSequence_, typename module_type::periph_reg_list>::value == true,
         "periph_reg_list must be a  model of TypeSequence_"
      );
      // apply the list of actions
     
      quan::meta::for_each<
         typename module_type::periph_reg_list,quan::stm32::detail::apply_periph_reg_actions<module_type,periph_reg_actions> 
     >{}();
   }

}}//quan::stm32

#endif // QUAN_STM32_PERIPH_REG_ACTIONS_APPLY_HPP_INCLUDED
