#ifndef QUAN_STM32_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED
#define QUAN_STM32_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED

#include <quan/bit.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/operators/binary_operator_functors.hpp>

#include <quan/stm32/detail/periph_reg_action_fwd.hpp>

namespace quan{ namespace stm32{ namespace detail {

   /*
      metafunction to create either an or_action  to set bit(BitPos) in PeriphReg if B is true
      or an and_action to clear BitPos in PeriphReg if B == false

     PeriphReg is a model of PeriphReg
   */

   template <typename PeriphReg,  uint32_t BitPos>
   struct make_or_action{
      typedef PeriphReg reg_type;
      typedef typename reg_type::value_type value_type;
      typedef quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_or,quan::bit<value_type>(BitPos) > type;
   };

   template <typename PeriphReg,  uint32_t BitPos>
   struct make_and_action{
      typedef PeriphReg reg_type;
      typedef typename reg_type::value_type value_type;
      typedef quan::stm32::detail::periph_reg_action<PeriphReg,quan::meta::bit_and,~quan::bit<value_type>(BitPos) > type;
   };

   template <bool B, typename PeriphReg,  uint32_t BitPos> 
   struct make_boolean_action : quan::meta::eval_if_c<B,make_or_action<PeriphReg,BitPos>,make_and_action<PeriphReg,BitPos> >{};

}}} //quan::stm32::detail

#endif // QUAN_STM32F4_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED
