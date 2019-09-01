#ifndef QUAN_STM32_F0_SYSCFG_MODULE_HPP_INCLUDED
#define QUAN_STM32_F0_SYSCFG_MODULE_HPP_INCLUDED

#ifndef QUAN_STM32F0
#error dont include directly
#endif

#include <quan/stm32/f0/periph_map.hpp>
#include <quan/stm32/periph_reg.hpp>

namespace quan{ namespace stm32 {

   struct syscfg {

      typedef uint32_t value_type;
      typedef syscfg type;
      static constexpr uint32_t address = quan::stm32::periph_map::syscfg_comp;

      typedef quan::stm32::periph_reg<type,0x00> cfgr1_type;

      typedef quan::stm32::periph_reg<type,0x18> cfgr2_type;

      cfgr1_type cfgr1;
private:
      uint32_t padding1;
public:
      volatile uint32_t exticr[4];
      cfgr2_type cfgr2;

      static constexpr syscfg* get(){ return reinterpret_cast<syscfg*>(address);}
      
  private:
      syscfg() = delete;
      syscfg(syscfg const &) = delete;
      syscfg& operator = (syscfg const & ) = delete;

   };

}} //quan::stm32

#endif // QUAN_STM32_F0_SYSCFG_HPP_INCLUDED
