#ifndef QUAN_STM32_UNDEFINED_REG_HPP_INCLUDED
#define QUAN_STM32_UNDEFINED_REG_HPP_INCLUDED
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

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/not.hpp>

namespace quan{ namespace stm32 { 

   struct UndefinedPeriphReg; // Archetype

   template <typename Module, uint32_t Offset>
   struct undefined_reg{

      typedef Module module_type;
      typedef typename module_type::value_type value_type;
      static constexpr uint32_t address_offset = Offset;
      static constexpr uint32_t address =  module_type::address + address_offset;

      typedef undefined_reg type;

      private:
      value_type reserved;

      undefined_reg() = delete;
      undefined_reg(undefined_reg const &)= delete;
      undefined_reg& operator = (undefined_reg const &) = delete;

   };

}}

namespace quan{ namespace impl{

      template <typename Module, uint32_t Offset>
      struct is_model_of_impl<
         quan::stm32::UndefinedPeriphReg,
         quan::stm32::undefined_reg<Module,Offset> 
      > : quan::meta::true_{};

}}

namespace quan{ namespace stm32 {namespace detail {

       struct periph_reg_is_defined{

            template <typename PeriphReg> struct apply{
                  typedef quan::meta::not_<quan::is_model_of<quan::stm32::UndefinedPeriphReg,PeriphReg> > type;
            };
       };
   }

}}

#endif // QUAN_STM32_UNDEFINED_REG_HPP_INCLUDED
