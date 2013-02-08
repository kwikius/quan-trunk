#ifndef QUAN_STM32F4_GPIO_DETAIL_RCC_BIT_OFFSET_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_DETAIL_RCC_BIT_OFFSET_HPP_INCLUDED

#include <quan/stm32f4/gpio_typedefs.hpp>

namespace quan{ namespace stm32f4{namespace gpio { namespace detail{
       /*
          for getting the rcc bit for
          enable reset etc
       */
         template<typename P>
         struct rcc_bit_offset;

         template<>
         struct rcc_bit_offset<quan::stm32f4::gpioa>{
            
            static const uint32_t value = 0;
         };

         template<>
         struct rcc_bit_offset<quan::stm32f4::gpiob>{
            static const uint32_t value = 1;
         };
         
         template<>
         struct rcc_bit_offset<quan::stm32f4::gpioc>{
            static const uint32_t value = 2;
         };

         template<>
         struct rcc_bit_offset<quan::stm32f4::gpiod>{
            static const uint32_t value = 3;
         };

         template<>
         struct rcc_bit_offset<quan::stm32f4::gpioe>{
            static const uint32_t value = 4;
         };

         template<>
         struct rcc_bit_offset<quan::stm32f4::gpiof>{
            static const uint32_t value = 5;
         };

         template<>
         struct rcc_bit_offset<quan::stm32f4::gpiog>{
            static const uint32_t value = 6;
         };

         template<>
         struct rcc_bit_offset<quan::stm32f4::gpioh>{
            static const uint32_t value = 7;
         };

         template<>
         struct rcc_bit_offset<quan::stm32f4::gpioi>{
            static const uint32_t value = 8;
         };

}}}}// quan::sdtm32f4::gpio::detail


#endif // QUAN_STM32F4_GPIO_DETAIL_RCC_BIT_OFFSET_HPP_INCLUDED
