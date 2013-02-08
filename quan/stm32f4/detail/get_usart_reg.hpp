#ifndef QUAN_STM32F4_GPIO_GET_USART_REG_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_GET_USART_REG_HPP_INCLUDED

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
