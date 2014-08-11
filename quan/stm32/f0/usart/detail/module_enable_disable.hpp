#ifndef QUAN_STM32_F0_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_F0_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED
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

#if !defined QUAN_STM32F0
#error only for stm32f0
#endif

#include <quan/stm32/usart/typedefs.hpp>
#include <quan/stm32/f0/rcc.hpp>

namespace quan{ namespace stm32{ namespace usart{ namespace detail{

   template <typename Usart>
   struct module_enable;

   template <typename Usart>
   struct module_disable;

   template <typename Usart>
   struct module_reset;


#define QUAN_STM32F0_MODULE_ENR( UsartX, RegNum, Bit) \
     template <> struct module_enable<quan::stm32:: UsartX >{\
      void operator()() const\
      {\
         quan::stm32::rcc::get()-> apb ## RegNum ## enr.setbit< Bit >();\
      }\
     };\
\
      template <> struct module_disable<quan::stm32:: UsartX >{\
      void operator()() const\
      {\
         quan::stm32::rcc::get()-> apb ## RegNum ## enr.clearbit< Bit >();\
      }\
     };\
\
      template <> struct module_reset<quan::stm32:: UsartX >{\
      void operator()() const\
      {\
         quan::stm32::rcc::get()-> apb ## RegNum ## rstr.setbit< Bit >();\
         quan::stm32::rcc::get()-> apb ## RegNum ## rstr.clearbit< Bit >();\
      }\
     };

   /* usart 1
   mod en/dis    rcc->apb2enr  bit(14)
   mod res       rcc->apb2rstr bit(14)
   */
   /* usart2
   mod en/dis    rcc->apb1enr bit17
   mod res       rcc->apb1rstr bit 17
   */
   QUAN_STM32F0_MODULE_ENR(usart1,2,14)
   QUAN_STM32F0_MODULE_ENR(usart2,1,17)

#undef   QUAN_STM32F0_MODULE_ENR

}}}}//quan::stm32::usart::detail


#endif // QUAN_STM32_F0_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED
