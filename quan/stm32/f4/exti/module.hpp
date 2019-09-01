#ifndef QUAN_STM32_F4_EXTI_MODULE_HPP_INCLUDED
#define QUAN_STM32_F4_EXTI_MODULE_HPP_INCLUDED
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

#include <quan/stm32/f4/periph_map.hpp>
#include <quan/stm32/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>

namespace quan{ namespace stm32{

   struct exti{
         typedef uint32_t value_type;
         typedef exti type;
         static constexpr uint32_t address = quan::stm32::periph_map::exti;

         typedef quan::stm32::periph_reg<type,0x00>  imr_type;
         typedef quan::stm32::periph_reg<type,0x04>  emr_type;
         typedef quan::stm32::periph_reg<type,0x08>  rtsr_type;
         typedef quan::stm32::periph_reg<type,0x0C>  ftsr_type;
         typedef quan::stm32::periph_reg<type,0x10>  swier_type;
         typedef quan::stm32::periph_reg<type,0x14>  pr_type;
      
         imr_type imr;
         emr_type emr;
         rtsr_type rtsr;
         ftsr_type ftsr;
         swier_type swier;
         pr_type pr;
      
         static constexpr exti* get(){ return reinterpret_cast<exti*>(address);}

      private:
         exti() = delete;
         exti(exti const &) = delete;
         exti& operator = (exti const & ) = delete;

      };

}} //quan::stm32

#endif // QUAN_STM32_F4_EXTI_MODULE_HPP_INCLUDED
