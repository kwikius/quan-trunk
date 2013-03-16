#ifndef QUAN_STM32F4_GPIO_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_HPP_INCLUDED
/*
 Copyright (c) 2013 Andy Little 

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

#include <quan/stm32f4/config.hpp>

#include <quan/bit.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/identity.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/low_bits_mask.hpp>
#include <quan/meta/count_if.hpp>
#include <quan/meta/is_model_of.hpp>
#include <quan/stm32f4/gpio/pin.hpp>
#include <quan/stm32f4/gpio_typedefs.hpp>
#include <quan/stm32f4/gpio/module_enable.hpp>
#include <quan/stm32f4/gpio/module_disable.hpp>
#include <quan/stm32f4/gpio/module_reset.hpp>
#include <quan/stm32f4/detail/get_gpio_reg.hpp>
#include <quan/stm32f4/detail/periph_reg_actions.hpp>
#include <quan/stm32f4/gpio/detail/periph_reg_action_pack.hpp>
#include <quan/stm32f4/gpio/detail/add_periph_reg_action.hpp>

namespace quan{ namespace stm32f4{

   template< typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32f4::gpio::Pin,P>
   >::type  complement()
   {
      P::port_type::get()->odr.template xor_equals<
         quan::bit<typename P::value_type>(P::pin_value)
      >();
   }

   template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32f4::gpio::Pin,P>,
       bool
   >::type get()
   {
      return P::port_type::get()-> idr.template bb_getbit<P::pin_value>();
   }

   template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32f4::gpio::Pin,P>,
       void
   >::type set()
   {
       P::port_type::get()-> odr.template bb_setbit<P::pin_value>();
   }

    template <typename P>
   inline typename quan::where_<
       quan::is_model_of<quan::stm32f4::gpio::Pin,P>,
       void
   >::type clear()
   {
       P::port_type::get()-> odr.template bb_clearbit<P::pin_value>();
   }


   template <typename Pin, typename ... Listof_Setting>
   typename quan::where_<quan::is_model_of<quan::stm32f4::gpio::Pin, Pin> >::type
    apply()
   { 
       typedef quan::meta::type_sequence<Listof_Setting...> periph_reg_settings_list;

  
      // check for invalid combinations of flags
//#########################################################################
      typedef  quan::meta::count_if < 
         periph_reg_settings_list, quan::meta::is_model_of<quan::stm32f4::gpio::Mode> 
      > num_mode_settings;

      static_assert(num_mode_settings::value < 2, "cannot set more than one mode");
//##########################################################################
         // add look up special function
      typedef  quan::meta::count_if < 
         periph_reg_settings_list, quan::meta::is_model_of<quan::stm32f4::gpio::AlternateFunction> 
      > num_alt_fun_settings;
      static_assert(num_alt_fun_settings::value < 2, "cannot set more than one alternate function");
      
      static_assert( (num_mode_settings::value  * num_alt_fun_settings::value ) == 0,
        "cannot set both alternate function and mode");
//##########################################################################
   
     //quan::stm32f4::gpio::detail apply_pin_list_of_settings<Pin,Listof_PinSettings>();
     // turn the settings into a list of actions on peripheral registers
      typedef typename quan::meta::transform<
         periph_reg_settings_list, quan::stm32f4::detail::make_periph_reg_action_pack<Pin> 
      >::type packed_actions;

      typedef typename quan::meta::fold<
         packed_actions,quan::meta::type_sequence<>,
         quan::stm32f4::detail::unpack_actions 
      >::type periph_reg_actions;

      typedef typename Pin::port_type module;

      quan::meta::for_each<
         typename module::periph_reg_list,quan::stm32f4::detail::apply_periph_reg_actions<module,periph_reg_actions> 
      >()();
   };

/*
void apply( Pin, action_list)
{
   // group first by module of the periph_reg_action.  hope that the compiler will put the address of the module in a register !
   // so check that all actions do apply to this module
   for_each ( periph_reg_action in action_list){ assert (periph_reg_action.module == module);}

   // group next by periph_reg. hope that the compiler will put the address of the periph_reg
   // as an immediate offset from the module, so limiting use of module!
   for_each ( periph_reg in module.periph_reg_list){

      action_list reg_actions = copy_if( periph_reg_action in action_list, {periph_reg_action.periph_reg == periph_reg;} );

      // group by type of periph_reg_action
      foreach( action_type in action_types ) {

         action_list explicit_actions = copy_if( periph_reg_action in reg_actions, {periph_reg_action.type == action_type;} )

         // fold all these into one periph_reg_action
         // e.g  reg |= a ; reg|= b --> reg |= (a | b) ;
         // reg &= a; rega &= b; -->  reg &= (a & b);
         if ( ! empty(action_list){

            periph_reg_action c ?= fold(periph_reg_action in actions, c, { concat(c, periph_reg_action);} );

            // finally emit the periph_reg_action
            apply(c);
         }
      }    
   }       
} 
*/

}}

#endif // QUAN_STM32F$_GPIO_HPP_INCLUDED
