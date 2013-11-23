#ifndef QUAN_STM32_USART_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
#define QUAN_STM32_USART_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/and.hpp>

#include <quan/stm32/usart/module.hpp>
#include <quan/stm32/detail/periph_reg_action_pack_fwd.hpp>
#include <quan/stm32/usart/settings.hpp>

namespace quan{ namespace stm32{ namespace detail{

   template< typename U,  typename S>
   struct periph_reg_action_pack<
      U,S,
      typename quan:: where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::Usart,U>,
            quan::is_model_of<quan::stm32::usart::Setting,S>
         >
      >::type
   >{
      template <typename Listof_PeriphRegAction>
      struct apply{
         //typedef typename S::template apply<Listof_PeriphRegAction,U>::type type;
         typedef typename quan::stm32::usart::detail::setting_to_actions<
            S
         >::template apply<Listof_PeriphRegAction,U>::type type;
      };
   };

}}}//quan::stm32::detail

#endif // QUAN_STM32_USART_DETAIL_PERIPH_REG_ACTION_PACK_HPP_INCLUDED
