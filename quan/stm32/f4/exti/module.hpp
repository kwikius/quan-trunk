#ifndef QUAN_STM32_F4_EXTI_MODULE_HPP_INCLUDED
#define QUAN_STM32_F4_EXTI_MODULE_HPP_INCLUDED

#include <quan/stm32/f4/periph_map.hpp>
#include <quan/stm32/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>

namespace quan{ namespace stm32{

   namespace exti_impl{

      struct module{
         typedef uint32_t value_type;
         typedef module type;
         static const uint32_t address = quan::stm32::periph_map::exti;

         typedef quan::stm32::periph_reg<type,0x00>  imr_type;
         typedef quan::stm32::periph_reg<type,0x04>  emr_type;
         typedef quan::stm32::periph_reg<type,0x08>  rtsr_type;
         typedef quan::stm32::periph_reg<type,0x0C>  ftsr_type;
         typedef quan::stm32::periph_reg<type,0x10>  swier_type;
         typedef quan::stm32::periph_reg<type,0x14>  pr_type;
      
         imr_type imr;
         emr_type emr;
         rtsr_type rtsr;
         ftsr_type ftsr;
         swier_type swier;
         pr_type pr;
      
         static module* get(){ return reinterpret_cast<module*>(address);}

      private:
         module() = delete;
         module(module const &) = delete;
         module& operator = (module const & ) = delete;

      };

   } // exti_impl

   typedef exti_impl::module exti;

}} //quan::stm32

#endif // QUAN_STM32_F4_EXTI_MODULE_HPP_INCLUDED
