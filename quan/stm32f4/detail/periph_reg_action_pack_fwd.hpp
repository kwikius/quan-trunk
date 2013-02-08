#ifndef QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED

namespace quan{ namespace stm32f4{namespace detail{

/*
  The collection of actions to apply to registers to apply the settings in S
  to Pin P
*/
  template <typename P, typename S, typename Where = void>
  struct periph_reg_action_pack;

}}}

#endif // QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
