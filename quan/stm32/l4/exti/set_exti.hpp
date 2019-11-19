#ifndef QUAN_STM32_L4_SYSCFG_EXTI_HPP_INCLUDED
#define QUAN_STM32_L4_SYSCFG_EXTI_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */
#include <quan/stm32/l4/config.hpp>
#include <quan/stm32/gpio/pin.hpp>
#include <quan/stm32/gpio/typedefs.hpp>

#include <quan/stm32/l4/syscfg/module.hpp>
#include <quan/stm32/l4/exti/module.hpp>
#include <stm32l4xx.h>

namespace quan{ namespace stm32{

   namespace detail{
      template<typename Port>
      struct get_exti_port_offset;
#if defined QUAN_STM32_HAS_GPIOA
      template <>struct  get_exti_port_offset<quan::stm32::gpioa>{
         static constexpr uint8_t value = 0;
      };
#endif
#if defined QUAN_STM32_HAS_GPIOB
      template <>struct  get_exti_port_offset<quan::stm32::gpiob>{
         static constexpr uint8_t value = 1;
      };
#endif
#if defined QUAN_STM32_HAS_GPIOC
      template <>struct  get_exti_port_offset<quan::stm32::gpioc>{
         static constexpr uint8_t value = 2;
      };
#endif
#if defined QUAN_STM32_HAS_GPIOD
      template <>struct  get_exti_port_offset<quan::stm32::gpiod>{
         static constexpr uint8_t value = 3;
      };
#endif
#if defined QUAN_STM32_HAS_GPIOE
      template <>struct  get_exti_port_offset<quan::stm32::gpioe>{
         static constexpr uint8_t value = 4;
      };
#endif
#if defined QUAN_STM32_HAS_GPIOF
      template <>struct  get_exti_port_offset<quan::stm32::gpiof>{
         static constexpr uint8_t value = 5;
      };
#endif
#if defined QUAN_STM32_HAS_GPIOG
      template <>struct  get_exti_port_offset<quan::stm32::gpiog>{
         static constexpr uint8_t value = 6;
      };
#endif
#if defined QUAN_STM32_HAS_GPIOH
      template <>struct  get_exti_port_offset<quan::stm32::gpioh>{
         static constexpr uint8_t value = 7;
      };
#endif
#if defined QUAN_STM32_HAS_GPIOI
      template <>struct  get_exti_port_offset<quan::stm32::gpioi>{
         static constexpr uint8_t value = 8;
      };
#endif

      template <uint8_t PinValue>struct get_exti_irq_num{
            static_assert(PinValue < 16,"invalid pin value");
            static constexpr IRQn_Type value = (PinValue < 10 )? EXTI9_5_IRQn : EXTI15_10_IRQn;
      };

      template <> struct get_exti_irq_num<0> { 
         static constexpr IRQn_Type value = EXTI0_IRQn;
      };

      template <> struct get_exti_irq_num<1> { 
         static constexpr IRQn_Type value = EXTI1_IRQn;
      };

      template <> struct get_exti_irq_num<2> { 
         static constexpr IRQn_Type value = EXTI2_IRQn;
      };

      template <> struct get_exti_irq_num<3> { 
         static constexpr IRQn_Type value = EXTI3_IRQn;
      };

      template <> struct get_exti_irq_num<4> { 
         static constexpr IRQn_Type value = EXTI4_IRQn;
      };
      
   }

/*
   exti mode. exti module bits are same to the port bit num

   enable or disable interrupt ( mask)
   rising or falling edge
   generate an interrupt by writing to the exti swier
   
   want event 
*/

   template <typename P>
   inline 
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type set_exti_syscfg()
   {
      constexpr uint8_t reg_port_val 
         = quan::stm32::detail::get_exti_port_offset<typename P::port_type>::value;
   
      constexpr uint8_t exti_idx = P::pin_value / 0x04;
  
      constexpr uint8_t exti_offset = P::pin_value % 0x04;
    
      constexpr uint32_t reg_or_val = reg_port_val << (exti_offset * 0x04);
       
      constexpr uint32_t reg_clear_val =  ~(0xF << (exti_offset * 0x04));
       
      uint32_t const regval 
         = quan::stm32::syscfg::get()->exticr[exti_idx] & reg_clear_val;
      quan::stm32::syscfg::get()->exticr[exti_idx] = regval | reg_or_val;
      
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type set_exti_falling_edge()
   {
       quan::stm32::exti::get()->ftsr1.bb_setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type clear_exti_falling_edge()
   {
       quan::stm32::exti::get()->ftsr1.bb_clearbit<P::pin_value>(); 
   }
  
   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type set_exti_rising_edge()
   {
       quan::stm32::exti::get()->rtsr1.bb_setbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type clear_exti_rising_edge()
   {
       quan::stm32::exti::get()->rtsr1.bb_clearbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type nvic_enable_exti_irq()
   {
      ::NVIC_EnableIRQ(quan::stm32::detail::get_exti_irq_num<P::pin_value>::value);
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type enable_exti_interrupt()
   {
      quan::stm32::exti::get()->imr1.bb_setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type disable_exti_interrupt()
   {
      quan::stm32::exti::get()->imr1.bb_clearbit<P::pin_value>(); 
   }


   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type enable_exti_event()
   {
      quan::stm32::exti::get()->emr1.bb_setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type disable_exti_event()
   {
       quan::stm32::exti::get()->emr1.bb_clearbit<P::pin_value>();   
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type generate_software_interrupt()
   {
      quan::stm32::exti::get()->swier1.bb_setbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
     ,bool
   >::type is_event_pending()
   {
       return quan::stm32::exti::get()->pr1.bb_getbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
     ,void
   >::type clear_event_pending()
   {
      quan::stm32::exti::get()->pr1.bb_setbit<P::pin_value>();
   }

}}

#endif // QUAN_STM32_F4_SYSCFG_EXTI_HPP_INCLUDED
