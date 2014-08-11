#ifndef QUAN_STM32_F4_SYSCFG_EXTI_HPP_INCLUDED
#define QUAN_STM32_F4_SYSCFG_EXTI_HPP_INCLUDED
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

#include <quan/stm32/gpio/pin.hpp>
#include <quan/stm32/gpio/typedefs.hpp>

#include <quan/stm32/f4/syscfg/module.hpp>
#include <quan/stm32/f4/exti/module.hpp>
#include <stm32f4xx.h>

namespace quan{ namespace stm32{

   namespace detail{
      template<typename Port>
      struct get_exti_port_offset;

      template <>struct  get_exti_port_offset<quan::stm32::gpioa>{
         static constexpr uint8_t value = 0;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpiob>{
         static constexpr uint8_t value = 1;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpioc>{
         static constexpr uint8_t value = 2;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpiod>{
         static constexpr uint8_t value = 3;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpioe>{
         static constexpr uint8_t value = 4;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpiof>{
         static constexpr uint8_t value = 5;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpiog>{
         static constexpr uint8_t value = 6;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpioh>{
         static constexpr uint8_t value = 7;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpioi>{
         static constexpr uint8_t value = 8;
      };


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
       quan::stm32::exti::get()->ftsr.bb_setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type clear_exti_falling_edge()
   {
       quan::stm32::exti::get()->ftsr.bb_clearbit<P::pin_value>(); 
   }
  
   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type set_exti_rising_edge()
   {
       quan::stm32::exti::get()->rtsr.bb_setbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type clear_exti_rising_edge()
   {
       quan::stm32::exti::get()->rtsr.bb_clearbit<P::pin_value>();
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
        quan::stm32::exti::get()->imr.bb_setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type disable_exti_interrupt()
   {
      quan::stm32::exti::get()->imr.bb_clearbit<P::pin_value>(); 
   }


   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type enable_exti_event()
   {
      quan::stm32::exti::get()->emr.bb_setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type disable_exti_event()
   {
       quan::stm32::exti::get()->emr.bb_clearbit<P::pin_value>();   
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type generate_software_interrupt()
   {
      quan::stm32::exti::get()->swier.bb_setbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
     ,bool
   >::type is_event_pending()
   {
       return quan::stm32::exti::get()->pr.bb_getbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
     ,void
   >::type clear_event_pending()
   {
      quan::stm32::exti::get()->pr.bb_setbit<P::pin_value>();
   }

}}

#endif // QUAN_STM32_F4_SYSCFG_EXTI_HPP_INCLUDED
