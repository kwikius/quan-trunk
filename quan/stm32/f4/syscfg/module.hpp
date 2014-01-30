#ifndef QUAN_STM32_F4_SYSCONFIG_MODULE_HPP_INCLUDED
#define QUAN_STM32_F4_SYSCONFIG_MODULE_HPP_INCLUDED

#ifndef QUAN_STM32F4
#error dont include directly
#endif

#include <quan/stm32/f4/periph_map.hpp>
#include <quan/stm32/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>


namespace quan{ namespace stm32 {

   struct SysCfg ;// Archetype

   namespace syscfg_impl{

      struct module{
            typedef uint32_t value_type;
            typedef module type;
            static const uint32_t address = quan::stm32::periph_map::syscfg;

            typedef quan::stm32::periph_reg<type,0x00> memrmp_type;
            typedef quan::stm32::periph_reg<type,0x04> pmc_type;

            typedef quan::stm32::periph_reg<type,0x20> cmpcr_type;

            memrmp_type mem_rmp;
            pmc_type pmc;
            volatile uint32_t exticr[4];
        private:
            volatile uint32_t padding[2];
        public:
            cmpcr_type cmpcr;
            
            static module* get(){ return reinterpret_cast<module*>(address);}
            
        private:
            module() = delete;
            module(module const &) = delete;
            module& operator = (module const & ) = delete; 
      };

   }// sycfg_impl

}}// quan::stm32

#endif // QUAN_STM32_F4_SYSCONFIG_MODULE_HPP_INCLUDED
