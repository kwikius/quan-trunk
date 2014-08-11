#ifndef QUAN_STM32F4_DETAIL_GET_BUS_SPEED_HZ_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_GET_BUS_SPEED_HZ_HPP_INCLUDED
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

//#include <quan/stm32f4/detail/system_pll_constants.hpp>
#include <quan/stm32f4/config.hpp>

namespace quan{ namespace stm32f4{ namespace detail{

    template <typename bus>
    get_bus_speed_impl;
   
    template<> struct get_bus_speed_impl<apb1>
    {
       constexpr uint32_t value = static_cast<uint32_t>(QUAN_STM32F4_SOURCE_CLOCK_Hz) / static_cast<uint32_t>(QUAN_STM32F4_APB1_DIVISOR);
    }

    template<> struct get_bus_speed_impl<apb2>
    {
       constexpr uint32_t value = static_cast<uint32_t>(QUAN_STM32F4_SOURCE_CLOCK_Hz) / static_cast<uint32_t>(QUAN_STM32F4_APB2_DIVISOR);
    }

    template <typename Bus>
    constexpr uint32_t get_bus_speed() { return get_bus_speed_impl<Bus>::value;}
    
}}}


#endif // QUAN_STM32F4_DETAIL_GET_BUS_SPEED_HZ_HPP_INCLUDED
