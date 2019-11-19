#ifndef QUAN_STM32_L4_EXTI_MODULE_HPP_INCLUDED
#define QUAN_STM32_L4_EXTI_MODULE_HPP_INCLUDED
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

#include <quan/stm32/l4/periph_map.hpp>
#include <quan/stm32/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>

#if !defined QUAN_STM32L4
#error only for stm32L4
#endif

namespace quan{ namespace stm32{

   struct exti{
      typedef uint32_t value_type;
      typedef exti type;
      static constexpr uint32_t address = quan::stm32::periph_map::exti;

      typedef quan::stm32::periph_reg<type,0x00>  imr1_type;
      typedef quan::stm32::periph_reg<type,0x04>  emr1_type;
      typedef quan::stm32::periph_reg<type,0x08>  rtsr1_type;
      typedef quan::stm32::periph_reg<type,0x0C>  ftsr1_type;
      typedef quan::stm32::periph_reg<type,0x10>  swier1_type;
      typedef quan::stm32::periph_reg<type,0x14>  pr1_type;
//----------
      typedef quan::stm32::periph_reg<type,0x20>  imr2_type;
      typedef quan::stm32::periph_reg<type,0x24>  emr2_type;
      typedef quan::stm32::periph_reg<type,0x28>  rtsr2_type;
      typedef quan::stm32::periph_reg<type,0x2C>  ftsr2_type;
      typedef quan::stm32::periph_reg<type,0x30>  swier2_type;
      typedef quan::stm32::periph_reg<type,0x34>  pr2_type;
//-------
      imr1_type imr1;  // Interrupt mask register
      emr1_type emr1;  // Event mask register
      rtsr1_type rtsr1; // Rising trigger selection register
      ftsr1_type ftsr1;  // Falling trigger selection register
      swier1_type swier1; // Software interrupt event register
      pr1_type pr1;       // pending register
   private:
         uint32_t padding[2];
   public:
      imr2_type imr2;  // Interrupt mask register
      emr2_type emr2;  // Event mask register
      rtsr2_type rtsr2; // Rising trigger selection register
      ftsr2_type ftsr2;  // Falling trigger selection register
      swier2_type swier2; // Software interrupt event register
      pr2_type pr2;       // pending register

      static constexpr exti* get(){ return reinterpret_cast<exti*>(address);}

   private:
      exti() = delete;
      exti(exti const &) = delete;
      exti& operator = (exti const & ) = delete;
   };

}} //quan::stm32

#endif // QUAN_STM32_F0_EXTI_MODULE_HPP_INCLUDED
