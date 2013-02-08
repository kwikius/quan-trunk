#ifndef QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_FWD_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_FWD_HPP_INCLUDED

#include <quan/operators/binary_operator_functors.hpp>

namespace quan{ namespace stm32f4{ namespace detail{

  template <typename PeriphReg, typename PeriphRegActionFnTag, typename PeriphReg::value_type N >
  struct periph_reg_action;

}}}

#endif // QUAN_STM32F4_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
