#ifndef QUAN_STM32_DETAIL_PERIPH_REG_ACTION_FWD_HPP_INCLUDED
#define QUAN_STM32_DETAIL_PERIPH_REG_ACTION_FWD_HPP_INCLUDED

namespace quan{ namespace stm32{ namespace detail{

  /*
   Represents an action to be applied to a PeriphReg
   PeriphReg is a model of PeriphReg ( see  quan/stm32/periph_reg.hpp)
   PeriphRegActionFnTag is one of the quan operator functor tags from binary_op
   Value is the value to apply using the function described by PeriphRegActionFnTag
  */
   template <
      typename PeriphReg,
      typename PeriphRegActionFnTag,
      typename PeriphReg::value_type Value
   >
   struct periph_reg_action;

}}}

#endif // QUAN_STM32_DETAIL_PERIPH_REG_ACTION_PACK_FWD_HPP_INCLUDED
