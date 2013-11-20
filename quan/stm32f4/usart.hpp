#ifndef QUAN_STM32F4_USART_HPP_INCLUDED
#define QUAN_STM32F4_USART_HPP_INCLUDED

#include <quan/stm32f4/usart/module.hpp>
#include <quan/stm32f4/usart_typedefs.hpp>
#include <quan/stm32f4/usart/settings.hpp>
#include <quan/stm32f4/usart/detail/module_enable_disable.hpp>
#include <quan/stm32f4/usart/detail/periph_reg_action_pack.hpp>
#include <quan/stm32f4/detail/periph_reg_actions.hpp>
#include <quan/stm32f4/detail/get_usart_reg.hpp>
#include <quan/where.hpp>

namespace quan{ namespace stm32f4{

     template<typename U> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Usart,U> >::type 
     module_enable()
     {    
            quan::stm32f4::usart::detail::module_enable<U>{}();
     }
      
      template<typename U> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Usart,U> >::type 
     module_disable()
     {    
            quan::stm32f4::usart::detail::module_disable<U>{}();
     }

     template<typename U> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Usart,U> >::type 
     module_reset()
     {    
            quan::stm32f4::usart::detail::module_reset<U>{}();
     }

     template<typename U> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Usart,U> >::type 
     enable()
     {    
            U::get()->cr1.template setbit<13>();
     }

     template<typename U> inline
     typename quan::where_<quan::is_model_of< quan::stm32f4::Usart,U> >::type 
     disable()
     {    
            U::get()->cr1.template clearbit<13>();
     }

}}//quan::stm32f4

namespace quan {namespace stm32f4{

     template <typename U, typename... Listof_Setting>
     inline typename quan::where_<quan::is_model_of<quan::stm32f4::Usart,U> >::type
     apply()
     {
         typedef quan::meta::type_sequence<Listof_Setting...> periph_reg_settings_list;

//#########################################################################
// Todo :  check for invalid combinations of flags
//##########################################################################
   
     // turn the settings into a list of actions on peripheral registers
      typedef typename quan::meta::transform<
         periph_reg_settings_list, quan::stm32f4::detail::make_periph_reg_action_pack<U> 
      >::type packed_actions;

      typedef typename quan::meta::fold<
         packed_actions,quan::meta::type_sequence<>,
         quan::stm32f4::detail::unpack_actions 
      >::type periph_reg_actions;

      typedef U module;

      quan::meta::for_each<
         typename module::periph_reg_list,quan::stm32f4::detail::apply_periph_reg_actions<module,periph_reg_actions> 
      >()();
     }

}}


#endif // QUAN_STM32F4_USART_HPP_INCLUDED
