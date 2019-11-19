#ifndef QUAN_STM32_L4_SYSCFG_MODULE_HPP_INCLUDED
#define QUAN_STM32_L4_SYSCFG_MODULE_HPP_INCLUDED

#ifndef QUAN_STM32L4
#error dont include directly
#endif

#include <quan/stm32/l4/periph_map.hpp>
#include <quan/stm32/periph_reg.hpp>

namespace quan{ namespace stm32 {

   struct syscfg {

      typedef uint32_t value_type;
      typedef syscfg type;
      static constexpr uint32_t address = quan::stm32::periph_map::syscfg;

      typedef quan::stm32::periph_reg<type,0x00> memrmp_type;
      typedef quan::stm32::periph_reg<type,0x04> cfgr1_type;

      typedef quan::stm32::periph_reg<type,0x18> scsr_type;
      typedef quan::stm32::periph_reg<type,0x1C> cfgr2_type;
      typedef quan::stm32::periph_reg<type,0x20> swpr_type;
      typedef quan::stm32::periph_reg<type,0x24> skr_type;

      memrmp_type memrmp;
      cfgr1_type cfgr1;
      volatile uint32_t exticr[4];
      scsr_type  scsr;
      cfgr2_type cfgr2;
      swpr_type swpr;
      skr_type skr;

      static constexpr syscfg* get(){ return reinterpret_cast<syscfg*>(address);}
      
  private:
      syscfg() = delete;
      syscfg(syscfg const &) = delete;
      syscfg& operator = (syscfg const & ) = delete;

   };

}} //quan::stm32

#endif // QUAN_STM32_L4_SYSCFG_HPP_INCLUDED
