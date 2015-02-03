#ifndef QUAN_STM32_F4_SYSCFG_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_F4_SYSCFG_MODULE_ENABLE_DISABLE_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
