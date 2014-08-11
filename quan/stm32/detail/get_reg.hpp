#ifndef QUAN_STM32_DETAIL_GET_REG_HPP_INCLUDED
#define QUAN_STM32_DETAIL_GET_REG_HPP_INCLUDED
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

namespace quan{ namespace stm32{ namespace detail{

   /*
     to get the PeripReg from the Module and Register_type
     preg = get_reg<Module,Member>{}()
   */
   template<typename Module,typename Member ,typename Where = void>
   struct get_reg;

}}}

  // works well to get ptr and offset in assembly
#define QUAN_STM32_GET_REG(Concept, PeriphReg)  \
   template<typename Module> \
   struct get_reg<   \
      Module,typename Module :: PeriphReg ## _type, \
      typename quan::where_< quan::is_model_of< Concept, Module > >::type \
   >{ \
         typename Module:: PeriphReg ## _type * operator()()const    \
       { return &Module::get() -> PeriphReg ;} \
   };

#endif // QUAN_STM32F4_DETAIL_GET_REG_HPP_INCLUDED
