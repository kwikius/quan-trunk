#ifndef QUAN_STM32_F0_GPIO_MODULE_ENABLE_HPP_INCLUDED
#define QUAN_STM32_F0_GPIO_MODULE_ENABLE_HPP_INCLUDED
/*
 Copyright (c) 2012-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/stm32/gpio/module.hpp>
#include <quan/stm32/f0/rcc.hpp>
#include <quan/stm32/f0/gpio/detail/rcc_bit_offset.hpp>
#include <quan/is_model_of.hpp>
#include <quan/where.hpp>

namespace quan{ namespace stm32{

    // enable the required port
    template<typename P> inline
    typename quan::where_<quan::is_model_of<quan::stm32::Gpio,P> >::type
    module_enable()
    {
        static constexpr uint32_t bit_offset 
            = quan::stm32::gpio::detail::rcc_bit_offset<P>::value;

        quan::stm32::rcc::get()->ahbenr. template setbit<bit_offset>();
    }

}}// quan::stm32f4

#endif // QUAN_STM32F4_GPIO_MODULE_ENABLE_HPP_INCLUDED
