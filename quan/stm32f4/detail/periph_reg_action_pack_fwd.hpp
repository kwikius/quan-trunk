#ifndef QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED

namespace quan{ namespace stm32f4{namespace detail{

/*
   A List of PeriphRegActions required to implement the settings specified by Setting
   to the Entity.
   Settings are specific to the Entity
   so far Entities include
      stm32::gpio::Pin
      stm32::Usart
*/
  template <typename Entity, typename Setting, typename Where = void>
  struct periph_reg_action_pack;

}}}

#endif // QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
