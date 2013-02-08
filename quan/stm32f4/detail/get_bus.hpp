#ifndef QUAN_STM32F4_DETAIL_GET_BUS_HPP_INCLUDED
#define QUAN_STM32F4_DETAIL_GET_BUS_HPP_INCLUDED

namespace quan { namespace stm32f4{ namespace detail{

    struct ahb1;
    struct ahb2;

    struct apb1;
    struct apb2;

    template <typename T, typename Where = void>
    struct get_bus;

}}}


#endif // QUAN_STM32F4_GET_BUS_HPP_INCLUDED
