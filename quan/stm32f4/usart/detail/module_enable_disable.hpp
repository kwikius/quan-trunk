#ifndef QUAN_STM32F4_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED
#define QUAN_STM32F4_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED

#include <quan/stm32f4/usart_typedefs.hpp>
#include <quan/stm32f4/rcc.hpp>

namespace quan{ namespace stm32f4{ namespace usart{ namespace detail{

   template <typename Usart>
   struct module_enable;

   template <typename Usart>
   struct module_disable;

   template <typename Usart>
   struct module_reset;

#define QUAN_STM32F4_MODULE_ENR( UsartX, RegNum, Bit) \
     template <> struct module_enable<quan::stm32f4:: UsartX >{\
      void operator()() const\
      {\
         quan::stm32f4::rcc::get()-> apb ## RegNum ## enr.setbit< Bit >();\
      }\
     };\
\
      template <> struct module_disable<quan::stm32f4:: UsartX >{\
      void operator()() const\
      {\
         quan::stm32f4::rcc::get()-> apb ## RegNum ## enr.clearbit< Bit >();\
      }\
     };\
\
      template <> struct module_reset<quan::stm32f4:: UsartX >{\
      void operator()() const\
      {\
         quan::stm32f4::rcc::get()-> apb ## RegNum ## rstr.setbit< Bit >();\
         quan::stm32f4::rcc::get()-> apb ## RegNum ## rstr.clearbit< Bit >();\
      }\
     };

   QUAN_STM32F4_MODULE_ENR(usart1,2,4)
   QUAN_STM32F4_MODULE_ENR(usart2,1,17)
   QUAN_STM32F4_MODULE_ENR(usart3,1,18)
   QUAN_STM32F4_MODULE_ENR(uart4,1,19)
   QUAN_STM32F4_MODULE_ENR(uart5,1,20)
   QUAN_STM32F4_MODULE_ENR(usart6,2,5)

#undef   QUAN_STM32F4_MODULE_ENR

}}}}//quan::stm32f4::usart::detail


#endif // QUAN_STM32F4_USART_DETAIL_MODULE_ENABLE_DISABLE_HPP_INCLUDED
