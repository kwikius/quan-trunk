#ifndef QUAN_STM32F4_GPIO_GET_USART_REG_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_GET_USART_REG_HPP_INCLUDED
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

#include <quan/stm32f4/usart/module.hpp>
#include <quan/stm32f4/detail/get_reg.hpp>

namespace quan{ namespace stm32f4{ namespace detail{

    #define QUAN_GET_USART( PeriphReg ) QUAN_STM32F4_GET_REG( quan::stm32f4::Usart, PeriphReg )

    QUAN_GET_USART(sr)
    QUAN_GET_USART(dr)
    QUAN_GET_USART(brr)
    QUAN_GET_USART(cr1)
    QUAN_GET_USART(cr2)
    QUAN_GET_USART(cr3)
    QUAN_GET_USART(gtpr)


   #undef QUAN_GET_USART

}}}//quan::stm32f4::detail

#endif // QUAN_STM32F4_GPIO_GET_GPIO_REG_HPP_INCLUDED
