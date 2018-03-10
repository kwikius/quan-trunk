#ifndef QUAN_STM32_TIM_MODULE_HPP_INCLUDED
#define QUAN_STM32_TIM_MODULE_HPP_INCLUDED
/*

 Copyright (c) 2012 Andy Little 11/11/2012

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
 
*/
#include <quan/stm32/config.hpp>
#include <quan/stm32/module.hpp>
#include <quan/stm32/periph_reg.hpp>
#include <quan/stm32/undefined_reg.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/type_sequence.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/copy_if.hpp>
#include <quan/stm32/tim/detail/has_periph_reg_xx.hpp>

namespace quan{ namespace stm32{

  struct Tim; // Archetype
   
    namespace tim {

       template <uint32_t N>
       struct channel;
     
       template <uint32_t Address>
       struct module{

         typedef uint32_t value_type;
         static constexpr value_type address = Address;

         typedef module type;
         
  #define QUAN_STM32_IF_HAS_REG( Name , Address)  \
   typedef typename quan::meta::eval_if< \
      quan::stm32::tim::detail::has_ ## Name <type>, \
      quan::stm32::periph_reg<type, Address >, \
      quan::stm32::undefined_reg<type, Address >  \
   >::type Name ## _type;

  #define QUAN_STM32_IF_HAS_FLOAT_REG(Name,Address) \
   typedef typename quan::meta::if_<  \
      quan::stm32::tim::detail::has_ ## Name <type>, \
      volatile uint32_t, \
      quan::stm32::undefined_reg<type, Address >  \
   >::type Name ## _type;

         typedef quan::stm32::periph_reg<type,0x0>  cr1_type;
         QUAN_STM32_IF_HAS_REG(cr2,0x04)
         QUAN_STM32_IF_HAS_REG(smcr,0x08)
         typedef quan::stm32::periph_reg<type,0x0C> dier_type;
         typedef quan::stm32::periph_reg<type,0x10> sr_type;
         typedef quan::stm32::periph_reg<type,0x14> egr_type;
         QUAN_STM32_IF_HAS_REG(ccmr1,0x18)
         QUAN_STM32_IF_HAS_REG(ccmr2,0x1C)
         QUAN_STM32_IF_HAS_REG(ccer,0x20)
         typedef volatile uint32_t cnt_type;
         typedef volatile uint32_t psc_type; 
         typedef volatile uint32_t arr_type;
         QUAN_STM32_IF_HAS_FLOAT_REG(rcr,0x30)
         typedef volatile uint32_t ccr1_type;
         typedef volatile uint32_t ccr2_type;
         typedef volatile uint32_t ccr3_type;
         typedef volatile uint32_t ccr4_type;
         QUAN_STM32_IF_HAS_REG(bdtr,0x44)
         QUAN_STM32_IF_HAS_REG(dcr,0x48)
         typedef volatile uint32_t dmar_type;
#if !defined(QUAN_STM32L4)
         QUAN_STM32_IF_HAS_REG(or_,0x50)
#else
         QUAN_STM32_IF_HAS_REG(or1,0x50)
         QUAN_STM32_IF_HAS_REG(ccmr3,0x54)
         QUAN_STM32_IF_HAS_FLOAT_REG(ccr5,0x58)
         QUAN_STM32_IF_HAS_FLOAT_REG(ccr6,0x5C)
         QUAN_STM32_IF_HAS_REG(or2,0x60)
         QUAN_STM32_IF_HAS_REG(or3,0x64)
#endif

#undef QUAN_STM32_IF_HAS_REG
#undef QUAN_STM32_IF_HAS_FLOAT_REG
                                         
         cr1_type cr1;
         cr2_type cr2;                      
         smcr_type smcr;
         dier_type dier;
         sr_type sr;
         egr_type egr;
         ccmr1_type ccmr1;
         ccmr2_type ccmr2;
         ccer_type ccer;
         cnt_type cnt;
         psc_type psc;
         arr_type arr;
         rcr_type rcr;
         ccr1_type ccr1;
         ccr2_type ccr2;
         ccr3_type ccr3;
         ccr4_type ccr4;
         bdtr_type bdtr;                               
         dcr_type dcr; 
         dmar_type dmar;
#if !defined(QUAN_STM32L4)
         or__type or_ ;
#else
         or1_type or1;
         ccmr3_type ccmr3;
         ccr5_type ccr5;
         ccr6_type ccr6;
         or2_type or2;
         or3_type or3;
#endif

         // remove any undefined registers from lookup
         typedef typename quan::meta::copy_if<
            quan::meta::type_sequence<  
               cr1_type,
               cr2_type,                    
               smcr_type,
               dier_type,
               sr_type,
               egr_type,
               ccmr1_type,
               ccmr2_type,
               ccer_type,
               cnt_type,
               psc_type,
               arr_type,
               rcr_type,
               ccr1_type,
               ccr2_type,
               ccr3_type,
               ccr4_type,
               bdtr_type,
               dcr_type,
               dmar_type,
#if !defined(QUAN_STM32L4)
               or__type
#else
               or1_type,
               ccmr3_type,
               ccr5_type,
               ccr6_type,
               or2_type,
               or3_type
#endif
            >,
            quan::stm32::detail::periph_reg_is_defined  
         >::type periph_reg_list;

         static constexpr module* get(){ return reinterpret_cast<module*>(address);}

       private:
         
         module() = delete;
         module(module const &) = delete;
         module& operator = (module const & ) = delete;
      };

   }//tim
}}//quan::stm32

namespace quan{ namespace impl{

    // make module a model of quan::stm32::Tim
   template <uint32_t Address>
   struct is_model_of_impl<
      quan::stm32::Tim,
      quan::stm32::tim::module<Address> 
	> : quan::meta::true_{};

     // make port a model of Usart
   template <uint32_t Address>
   struct is_model_of_impl<
      quan::stm32::Module,
      quan::stm32::tim::module<Address> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32F4_TIM_MODULE_HPP_INCLUDED
