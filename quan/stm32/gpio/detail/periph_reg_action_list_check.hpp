#ifndef QUAN_STM32_GPIO_DETAIL_PERIPH_REG_ACTION_LIST_CHECK_HPP_INCLUDED
#define QUAN_STM32_GPIO_DETAIL_PERIPH_REG_ACTION_LIST_CHECK_HPP_INCLUDED

#include <quan/stm32/gpio/get_module.hpp>
#include <quan/stm32/periph_reg_actions/apply.hpp>

namespace quan{ namespace stm32{

   namespace detail{
      template <typename Pin> 
      struct periph_reg_action_list_check<Pin,typename quan::where_<quan::is_model_of<quan::stm32::gpio::Pin, Pin> >::type>{

         template <typename ... List>
         struct apply{
            typedef quan::meta::type_sequence<List...> list_type;
           
            typedef  quan::meta::count_if < 
               list_type, quan::meta::is_model_of<quan::stm32::gpio::Mode> 
            > num_mode_settings;

            static_assert(num_mode_settings::value < 2, "cannot set more than one mode");
         //##########################################################################
         // add look up special function
            typedef  quan::meta::count_if < 
               list_type, quan::meta::is_model_of<quan::stm32::gpio::AlternateFunction> 
            > num_alt_fun_settings;
            static_assert(num_alt_fun_settings::value < 2, "cannot set more than one alternate function");

            static_assert( (num_mode_settings::value  * num_alt_fun_settings::value ) == 0,
            "cannot set both alternate function and mode");

            typedef list_type type;
         };
      };
   }// detail
}}

#endif // QUAN_STM32_GPIO_DETAIL_PERIPH_REG_ACTION_LIST_CHECK_HPP_INCLUDED
