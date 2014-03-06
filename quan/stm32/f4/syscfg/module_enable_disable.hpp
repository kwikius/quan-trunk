#ifndef QUAN_STM32_F4_SYSCFG_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_F4_SYSCFG_MODULE_ENABLE_DISABLE_HPP_INCLUDED

#include <quan/stm32/f4/syscfg/module.hpp>
#include <quan/stm32/f4/rcc.hpp>
#include <quan/where.hpp>
#include <type_traits>

namespace quan{ namespace stm32{

   template <typename S>
   typename quan::where_<std::is_same<S,quan::stm32::syscfg> >::type
   module_enable()
   {
      constexpr uint8_t rcc_apb2_syscfg_bit = 14;
      quan::stm32::rcc::get()->apb2enr.setbit<rcc_apb2_syscfg_bit>();
   }
 
}}

#endif // QUAN_STM32_F4_SYSCFG_MODULE_ENABLE_DISABLE_HPP_INCLUDED
