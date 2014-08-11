#ifndef QUAN_STM32F4_USART_DETAIL_GET_BUS_HPP_INCLUDED
#define QUAN_STM32F4_USART_DETAIL_GET_BUS_HPP_INCLUDED
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

#include <quan/stm32f4/detail/get_bus.hpp>
#include <quan/stm32f4/usart_typedefs.hpp>


namespace quan{ namespace stm32f4{ namespace detail{


    template <> struct get_bus<quan::stm32f4::usart1>
    {
       typedef quan::stm32f4::detail::apb2 type;
    };

    template <> struct get_bus<quan::stm32f4::usart2>
    {
       typedef quan::stm32f4::detail::apb1 type;
    };

    template <> struct get_bus<quan::stm32f4::usart3>
    {
       typedef quan::stm32f4::detail::apb1 type;
    };

    template <> struct get_bus<quan::stm32f4::uart4>
    {
       typedef quan::stm32f4::detail::apb1 type;
    };

    template <> struct get_bus<quan::stm32f4::uart5>
    {
       typedef quan::stm32f4::detail::apb1 type;
    };

    template <> struct get_bus<quan::stm32f4::usart6>
    {
       typedef quan::stm32f4::detail::apb2 type;
    };

}}}

#endif // QUAN_STM32F4_USART_GET_BUS_HPP_INCLUDED
