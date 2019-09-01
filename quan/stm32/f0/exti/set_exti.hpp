#ifndef QUAN_STM32_F0_SYSCFG_EXTI_HPP_INCLUDED
#define QUAN_STM32_F0_SYSCFG_EXTI_HPP_INCLUDED
/*
 Copyright (c) 2003-2019 Andy Little.

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

#include <quan/stm32/f0/syscfg/module.hpp>
#include <quan/stm32/f0/exti/module.hpp>
#include <stm32f0xx.h>

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
#if 0
 // N/a for exti on these ports
      template <>struct  get_exti_port_offset<quan::stm32::gpiod>{
         static constexpr uint8_t value = 3;
      };

      template <>struct  get_exti_port_offset<quan::stm32::gpioe>{
         static constexpr uint8_t value = 4;
      };
#endif
      template <>struct  get_exti_port_offset<quan::stm32::gpiof>{
         static constexpr uint8_t value = 5;
      };
/*
    EXTI0_1_IRQ
EXTI2_3_IRQ
EXTI4_15_TRQ
*/
      template <uint8_t PinValue>struct get_exti_irq_num{
         static_assert(PinValue < 16,"invalid pin value");
         static constexpr IRQn_Type value = EXTI4_15_IRQn;
      };

      template <> struct get_exti_irq_num<0> { 
         static constexpr IRQn_Type value = EXTI0_1_IRQn;
      };

      template <> struct get_exti_irq_num<1> { 
         static constexpr IRQn_Type value = EXTI0_1_IRQn;
      };

      template <> struct get_exti_irq_num<2> { 
         static constexpr IRQn_Type value = EXTI2_3_IRQn;
      };

      template <> struct get_exti_irq_num<3> { 
         static constexpr IRQn_Type value = EXTI2_3_IRQn;
      };
      
   }  // detail

/*
   
   set exti on the pin
   enable or disable exti interrupt in the NVIC
   enable or disable exti interrupt 
   enable or diable xti event
   set rising and/or falling edge
   check for pending event
   clear pending event
   generate a software interrupt by writing to the exti swier
   
*/

   template <typename P>
   inline 
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type set_exti_syscfg()
   {
      // NB Make sure SYSCFG clock is on!
      // id_flags of the pin's port to load into the sycfg exticr
      constexpr uint8_t reg_port_val 
         = quan::stm32::detail::get_exti_port_offset<typename P::port_type>::value;

      // Not all ports are available
      static_assert((reg_port_val!= 3) && (reg_port_val!= 4),"invalid ports in syscfg.exticr");
   
      // array index of exti config register  for the pin
      constexpr uint8_t exti_idx = P::pin_value / 0x04;
      
      // offset in exti config register for the pin
      constexpr uint8_t exti_offset = P::pin_value % 0x04;
    
      // value to or with reg to set config
      constexpr uint32_t reg_or_val = reg_port_val << (exti_offset * 0x04);
       
      // value to and with reg to pre-clear config
      constexpr uint32_t reg_clear_val =  ~(0xF << (exti_offset * 0x04));
       
      // get cleared reg
      uint32_t const cleared_regval 
         = quan::stm32::syscfg::get()->exticr[exti_idx] & reg_clear_val;

      // and set bits for this port
      quan::stm32::syscfg::get()->exticr[exti_idx] = cleared_regval | reg_or_val;
      
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type set_exti_falling_edge()
   {
       quan::stm32::exti::get()->ftsr.setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type clear_exti_falling_edge()
   {
       quan::stm32::exti::get()->ftsr.clearbit<P::pin_value>(); 
   }
  
   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type set_exti_rising_edge()
   {
       quan::stm32::exti::get()->rtsr.setbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type clear_exti_rising_edge()
   {
       quan::stm32::exti::get()->rtsr.clearbit<P::pin_value>();
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
        quan::stm32::exti::get()->imr.setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type disable_exti_interrupt()
   {
      quan::stm32::exti::get()->imr.clearbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type enable_exti_event()
   {
      quan::stm32::exti::get()->emr.setbit<P::pin_value>(); 
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type disable_exti_event()
   {
       quan::stm32::exti::get()->emr.clearbit<P::pin_value>();   
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
   >::type generate_software_interrupt()
   {
      quan::stm32::exti::get()->swier.setbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
     ,bool
   >::type is_event_pending()
   {
       return quan::stm32::exti::get()->pr.getbit<P::pin_value>();
   }

   template <typename P>
   inline
   typename quan::where_<
      quan::is_model_of<quan::stm32::gpio::Pin,P>
     ,void
   >::type clear_event_pending()
   {
      quan::stm32::exti::get()->pr.setbit<P::pin_value>();
   }

}}

#endif // QUAN_STM32_F0_SYSCFG_EXTI_HPP_INCLUDED
