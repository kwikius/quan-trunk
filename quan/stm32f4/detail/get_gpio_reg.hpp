#ifndef QUAN_STM32F4_GPIO_GET_GPIO_REG_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_GET_GPIO_REG_HPP_INCLUDED

#include <quan/stm32f4/gpio/module.hpp>
#include <quan/stm32f4/detail/get_reg.hpp>

namespace quan{ namespace stm32f4{ namespace detail{

    #define QUAN_GET_GPIO( PeriphReg ) QUAN_STM32F4_GET_REG( quan::stm32f4::Gpio, PeriphReg )

    QUAN_GET_GPIO(moder)
    QUAN_GET_GPIO(otyper)
    QUAN_GET_GPIO(ospeedr)
    QUAN_GET_GPIO(pupdr)
    QUAN_GET_GPIO(idr)
    QUAN_GET_GPIO(odr)
    QUAN_GET_GPIO(bsrr)
    QUAN_GET_GPIO(lckr)
    QUAN_GET_GPIO(afrl)
    QUAN_GET_GPIO(afrh)

   #undef QUAN_GET_GPIO

}}}//quan::stm32f4::detail

#endif // QUAN_STM32F4_GPIO_GET_GPIO_REG_HPP_INCLUDED
