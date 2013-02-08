#ifndef QUAN_STM32F4_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED

#include <quan/meta/push_back.hpp>

namespace quan{ namespace stm32f4{  namespace detail{

  /*
    default add_perip_reg_action function
*/
   template <
      typename Listof_PeriphRegAction, typename PeriphRegOrAction, typename PeriphRegAndAction, 
      typename Module, typename PeriphRegSetting, typename Where = void
   >
   struct add_periph_reg_action{
       typedef typename quan::meta::push_back<
            typename quan::meta::push_back<Listof_PeriphRegAction,PeriphRegOrAction>::type ,PeriphRegAndAction
      >::type type;
   };

}}}

#endif // QUAN_STM32F4_DETAIL_ADD_PERIPH_REG_ACTION_HPP_INCLUDED
