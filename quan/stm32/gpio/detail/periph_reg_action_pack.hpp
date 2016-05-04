#ifndef QUAN_STM32_GPIO_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
#define QUAN_STM32_GPIO_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
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

#include <type_traits>
#include <quan/operators/binary_operator_functors.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/push_back.hpp>
#include <quan/meta/low_bits_mask.hpp>
#include <quan/concepts/meta/type_sequence/for_each.hpp>

#include <quan/stm32/gpio/detail/get_periph_reg.hpp>
#include <quan/stm32/gpio/settings.hpp>
#include <quan/stm32/detail/periph_reg_action_fwd.hpp>
#include <quan/stm32/detail/periph_reg_action_pack_fwd.hpp>
#include <quan/stm32/detail/make_boolean_action.hpp>

namespace quan{ namespace stm32{ namespace detail{

/*
  OState setting is a special case because its a boolean value
*/
 template< typename Pin, typename Setting>
   struct periph_reg_action_pack<Pin,Setting,
      typename quan:: where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::OState,Setting>
        >
      >::type
   >{

      typedef typename quan::stm32::detail::make_boolean_action<
         (Setting::value),
         typename quan::stm32::gpio::detail::get_periph_reg<Pin,Setting>::type ,
         (Pin::pin_value)
      >::type action_type;

      template <typename Listof_PeriphRegAction>
      struct apply{
          typedef typename quan::meta::push_back<Listof_PeriphRegAction,action_type >::type type;
      };
   };

/*
  a functor to transform input States to output periph_reg_action
  and add actions to the list
  These are all 2 bit fields so use both  & and | action
*/
   template< typename Pin, typename Setting>
   struct periph_reg_action_pack<Pin,Setting,
      typename quan:: where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::meta::or_<
               quan::is_model_of<quan::stm32::gpio::Mode,Setting>
              , quan::is_model_of<quan::stm32::gpio::OType,Setting>
              , quan::is_model_of<quan::stm32::gpio::Pupd,Setting>
              , quan::is_model_of<quan::stm32::gpio::OSpeed,Setting>
             // , quan::is_model_of<quan::stm32::gpio::AlternateFunction,Setting>
            >
         >
      >::type
   >{
      typedef typename Pin::port_type port_type;
      typedef typename quan::stm32::gpio::detail::get_periph_reg<Pin,Setting>::type reg_type;
      typedef typename reg_type::value_type value_type;

      static constexpr value_type numbits = Setting::numbits;
      static constexpr value_type pin_value = Pin::pin_value;
      static constexpr value_type shift = pin_value * numbits;
      static constexpr value_type or_mask = Setting::value << shift;
      static constexpr value_type and_mask = ~( quan::meta::low_bits_mask<numbits>::value << shift) | or_mask;
  
      typedef quan::stm32::detail::periph_reg_action< reg_type,quan::meta::bit_or,or_mask > or_type;
      typedef quan::stm32::detail::periph_reg_action< reg_type,quan::meta::bit_and,and_mask > and_type;

      template <typename Listof_PeriphRegAction>
      struct apply{
          typedef typename quan::stm32::detail::add_periph_reg_action<
               Listof_PeriphRegAction,or_type, and_type,Pin,Setting
          >::type type;
      };
   };

/*
   The version for Alternate Functions
*/
   template< typename Pin, typename Setting>
   struct periph_reg_action_pack<Pin,Setting,
      typename quan:: where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::AlternateFunction,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type port_type;
      typedef typename quan::stm32::gpio::detail::get_periph_reg<Pin,Setting>::type reg_type;
      typedef typename reg_type::value_type value_type;

      static constexpr value_type numbits = Setting::numbits;
      static constexpr value_type pin_value =
           ( quan::meta::and_<
                quan::is_model_of< quan::stm32::gpio::AlternateFunction,Setting >,
                quan::meta::bool_<(Pin::pin_value >=8)>
            >::value )? Pin::pin_value - 8 : Pin::pin_value;
      static constexpr value_type shift = pin_value * numbits;
      static constexpr value_type or_mask = Setting::value << shift;
      static constexpr value_type and_mask = ~( quan::meta::low_bits_mask<numbits>::value << shift) | or_mask;

      typedef quan::stm32::detail::periph_reg_action< reg_type,quan::meta::bit_or,or_mask > or_type;
      typedef quan::stm32::detail::periph_reg_action< reg_type,quan::meta::bit_and,and_mask > and_type;

      template <typename Listof_PeriphRegAction>
      struct apply{
          // apply the alternate function mode as well as the actual alternate function
          typedef typename periph_reg_action_pack<
               Pin,quan::stm32::gpio::mode::alternate_function
          >:: template apply<Listof_PeriphRegAction>::type first_list_type;
          typedef typename quan::stm32::detail::add_periph_reg_action<
               first_list_type,or_type, and_type,Pin,Setting
          >::type type;
      };
   };

}}}//quan::stm32::detail

#endif // QUAN_STM32_GPIO_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
