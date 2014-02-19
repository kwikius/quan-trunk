#ifndef QUAN_STM32_F4_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32_F4_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED

#include <quan/stm32/i2c/typedefs.hpp>
#include <quan/stm32/f4/rcc.hpp>

namespace quan { namespace stm32{

   namespace i2c{ namespace detail{
         
      template <typename I2CP> struct rcc_bit_offset;

      template <>struct rcc_bit_offset<quan::stm32::i2c1>{
               static const uint32_t value = 21;
      };

      template <>struct rcc_bit_offset<quan::stm32::i2c2>{
               static const uint32_t value = 22;
      };

      template <>struct rcc_bit_offset<quan::stm32::i2c3>{
               static const uint32_t value = 23;
      };
   }}

    template<typename I2CP> inline
    typename quan::where_<quan::is_model_of<quan::stm32::I2C,I2CP> >::type
    module_enable()
    {
        static constexpr uint32_t bit_offset 
            = quan::stm32::i2c::detail::rcc_bit_offset<I2CP>::value;
        quan::stm32::rcc::get()->apb1enr. template setbit<bit_offset>();
    }

    template<typename I2CP> inline
    typename quan::where_<quan::is_model_of<quan::stm32::I2C,I2CP> >::type
    module_disable()
    {
        static constexpr uint32_t bit_offset 
            = quan::stm32::i2c::detail::rcc_bit_offset<I2CP>::value;
        quan::stm32::rcc::get()->apb1enr. template clearbit<bit_offset>();
    }

    template<typename I2CP> inline
    typename quan::where_<quan::is_model_of<quan::stm32::I2C,I2CP> >::type
    module_reset()
    {
        static constexpr uint32_t bit_offset 
            = quan::stm32::i2c::detail::rcc_bit_offset<I2CP>::value;

        quan::stm32::rcc::get()->apb1rstr. template setbit<bit_offset>();
        quan::stm32::rcc::get()->apb1rstr. template clearbit<bit_offset>();
    }
}} // quan::stm32

#endif // QUAN_STM32_F4_I2C_MODULE_ENABLE_DISABLE_HPP_INCLUDED
