#ifndef QUAN_STM32F4_DETAIL_GET_BUS_SPEED_HZ_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_GET_BUS_SPEED_HZ_HPP_INCLUDED

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
