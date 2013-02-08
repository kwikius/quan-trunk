#ifndef QUAN_STM32F4_GPIO_MODULE_ENABLE_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_MODULE_ENABLE_HPP_INCLUDED

#include <quan/stm32f4/gpio/module.hpp>
#include <quan/stm32f4/rcc.hpp>
#include <quan/stm32f4/gpio/detail/rcc_bit_offset.hpp>
#include <quan/is_model_of.hpp>
#include <quan/where.hpp>

namespace quan{ namespace stm32f4{

    // enable the require port
    template<typename P> inline
    typename quan::where_<quan::is_model_of<quan::stm32f4::Gpio,P> >::type
    module_enable()
    {
        static constexpr uint32_t bit_offset 
            = quan::stm32f4::gpio::detail::rcc_bit_offset<P>::value;

        quan::stm32f4::rcc::get()->ahb1enr. template setbit<bit_offset>();
    }

}}// quan::stm32f4

#endif // QUAN_STM32F4_GPIO_MODULE_ENABLE_HPP_INCLUDED
