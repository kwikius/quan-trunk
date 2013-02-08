#ifndef QUAN_STM32F4_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED


#include <quan/meta/if.hpp>
#include <quan/stm32f4/detail/periph_reg_action_fwd.hpp>

namespace quan{ namespace stm32f4{ namespace detail {

   template <bool B, typename Reg,  uint32_t BitPos>
   struct make_boolean_action{
      typedef Reg reg_type;
      typedef typename reg_type::value_type value_type;
      static  constexpr value_type mask = B ? quan::bit<value_type>(BitPos) : ~quan::bit<value_type>(BitPos);
      typedef typename quan::meta::if_c<(B),quan::meta::bit_or, quan::meta::bit_and>::type tag_type;
      typedef quan::stm32f4::detail::periph_reg_action<reg_type,tag_type,mask > type;
   };

}}} //quan::stm32f4::detail

#endif // QUAN_STM32F4_DETAIL_MAKE_BOOLEAN_ACTION_HPP_INCLUDED
