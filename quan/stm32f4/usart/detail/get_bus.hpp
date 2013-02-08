#ifndef QUAN_STM32F4_USART_DETAIL_GET_BUS_HPP_INCLUDED
#define QUAN_STM32F4_USART_DETAIL_GET_BUS_HPP_INCLUDED

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
