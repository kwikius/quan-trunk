#ifndef QUAN_STM32F4_TIM_DETAIL_MODULE_ENABLE_HPP_INCLUDED
#define QUAN_STM32F4_TIM_DETAIL_MODULE_ENABLE_HPP_INCLUDED

#include <quan/stm32f4/rcc.hpp>
#include <quan/stm32f4/tim/module.hpp>
#include <quan/stm32f4/tim_typedefs.hpp>

namespace quan{ namespace stm32f4{namespace tim{ namespace detail{

    // enable the require port

    template<typename T>
    struct module_enable;

    template<typename T>
    struct module_disable;

    template<typename T>
    struct module_reset;
   
    #define QUAN_STM32F4_MODULE_ENR( TimX, RegNum, Bit) \
     template <> struct module_enable<quan::stm32f4:: TimX >{\
      void operator()() const\
      {\
         quan::stm32f4::rcc::get()-> apb ## RegNum ## enr.setbit< Bit >();\
      }\
     };\
\
      template <> struct module_disable<quan::stm32f4:: TimX >{\
      void operator()() const\
      {\
         quan::stm32f4::rcc::get()-> apb ## RegNum ## enr.clearbit< Bit >();\
      }\
     };\
\
      template <> struct module_reset<quan::stm32f4:: TimX >{\
      void operator()() const\
      {\
         quan::stm32f4::rcc::get()-> apb ## RegNum ## rstr.setbit< Bit >();\
         quan::stm32f4::rcc::get()-> apb ## RegNum ## rstr.clearbit< Bit >();\
      }\
     };

      QUAN_STM32F4_MODULE_ENR(tim1,2,0)
      QUAN_STM32F4_MODULE_ENR(tim2,1,0) 
      QUAN_STM32F4_MODULE_ENR(tim3,1,1)
      QUAN_STM32F4_MODULE_ENR(tim4,1,2)
      QUAN_STM32F4_MODULE_ENR(tim5,1,3)
      QUAN_STM32F4_MODULE_ENR(tim6,1,4) 
      QUAN_STM32F4_MODULE_ENR(tim7,1,5)
      QUAN_STM32F4_MODULE_ENR(tim8,2,1)
      QUAN_STM32F4_MODULE_ENR(tim9,2,16)
      QUAN_STM32F4_MODULE_ENR(tim10,2,17) 
      QUAN_STM32F4_MODULE_ENR(tim11,2,18)
      QUAN_STM32F4_MODULE_ENR(tim12,1,6)
      QUAN_STM32F4_MODULE_ENR(tim13,1,7)
      QUAN_STM32F4_MODULE_ENR(tim14,1,8) 

#undef QUAN_STM32F4_MODULE_ENR

    
}}}}// quan::stm32f4::tim::detail

#endif // QUAN_STM32F4_DETAIL_MODULE_ENABLE_HPP_INCLUDED
