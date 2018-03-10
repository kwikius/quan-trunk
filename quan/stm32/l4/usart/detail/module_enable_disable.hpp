#ifndef QUAN_STM32_L4_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_L4_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED
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


#if !defined QUAN_STM32L4
#error only for stm32L4
#endif
#include <quan/stm32/config.hpp>
#include <quan/stm32/usart/typedefs.hpp>
#include <quan/stm32/l4/rcc.hpp>

namespace quan{ namespace stm32{ namespace usart{ namespace detail{

   template <typename Usart>
   struct module_enable;

   template <typename Usart>
   struct module_disable;

   template <typename Usart>
   struct module_reset;

   #if QUAN_STM32_HAS_USART1
   template <> struct module_enable<quan::stm32::usart1>{
      void operator()() const
      {
         quan::stm32::rcc::get()->apb2enr.setbit<14>();
      }
   };

   template <> struct module_disable<quan::stm32::usart1>{
      void operator()() const
      {
         quan::stm32::rcc::get()->apb2enr.clearbit<14>();
      }
   };

   template <> struct module_reset<quan::stm32::usart1>{
      void operator()() const
      {
         quan::stm32::rcc::get()->apb2rstr.setbit<14>();
         quan::stm32::rcc::get()->apb2rstr.clearbit<14>();
      }
   };
   #endif

   #if QUAN_STM32_HAS_USART2
   template <> struct module_enable<quan::stm32::usart2>{
      void operator()() const
      {
         quan::stm32::rcc::get()->apb1enr1.setbit<17>();
      }
   };

   template <> struct module_disable<quan::stm32::usart2>{
      void operator()() const
      {
         quan::stm32::rcc::get()->apb1enr1.clearbit<17>();
      }
   };

   template <> struct module_reset<quan::stm32::usart2>{
      void operator()() const
      {
         quan::stm32::rcc::get()-> apb1rstr1.setbit<17>();
         quan::stm32::rcc::get()-> apb1rstr1.clearbit<17>();
      }
   };
   #endif

   #if QUAN_STM32_HAS_USART3
   template <> struct module_enable<quan::stm32::usart3>{
      void operator()() const
      {
         quan::stm32::rcc::get()->apb1enr1.setbit<18>();
      }
   };

   template <> struct module_disable<quan::stm32::usart3>{
      void operator()() const
      {
         quan::stm32::rcc::get()->apb1enr1.clearbit<18>();
      }
   };

   template <> struct module_reset<quan::stm32::usart3>{
      void operator()() const
      {
         quan::stm32::rcc::get()-> apb1rstr1.setbit<18>();
         quan::stm32::rcc::get()-> apb1rstr1.clearbit<18>();
      }
   };
   #endif


}}}}//quan::stm32::usart::detail


#endif // QUAN_STM32_F0_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED
