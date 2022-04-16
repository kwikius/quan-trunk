#ifndef QUAN_STM32_L4_I2C_MODULE_HPP_INCLUDED
#define QUAN_STM32_L4_I2C_MODULE_HPP_INCLUDED

#ifndef QUAN_STM32L4
#error dont include directly
#endif

#include <quan/stm32/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>


namespace quan{ namespace stm32 {

 struct I2C; // Archetype

// N.b registers seem to be identical to STM32F0
 namespace i2c{

       template <uint32_t Address> 
       struct module{
            typedef uint32_t value_type;
            typedef module type;
            typedef quan::stm32::periph_reg< type,  0x00>  cr1_type;
            typedef quan::stm32::periph_reg< type,  0x04>  cr2_type;
            typedef quan::stm32::periph_reg< type,  0x08>  oar1_type;
            typedef quan::stm32::periph_reg< type,  0x0C>  oar2_type;
            typedef quan::stm32::periph_reg< type,  0x10>  timingr_type;
            typedef quan::stm32::periph_reg< type,  0x14>  timeoutr_type;
            typedef quan::stm32::periph_reg< type,  0x18>  isr_type;
            typedef quan::stm32::periph_reg< type,  0x1C>  icr_type;
            typedef quan::stm32::periph_reg< type,  0x20>  pecr_type;
            typedef volatile uint8_t                       rxdr_type; // (0x24)
            typedef volatile uint8_t                       txdr_type; // (0x28)

            static constexpr uint32_t address = Address;

            cr1_type       cr1;
            cr2_type       cr2;
            oar1_type      oar1;
            oar2_type      oar2;
            timingr_type   timingr;
            timeoutr_type  timeoutr;
            isr_type       isr;
            icr_type       icr;
            pecr_type      pecr;
            rxdr_type      rxdr;
      private:
            uint8_t padding1[3];
      public:   
            txdr_type      txdr;
      private:
            uint8_t padding2[3];
      public:  
            typedef quan::meta::type_sequence<  
               cr1_type,
               cr2_type,
               oar1_type,
               oar2_type,
               timingr_type,
               timeoutr_type,
               isr_type,
               icr_type,
               pecr_type
            > periph_reg_list;

            static constexpr module* get(){ return reinterpret_cast<module*>(address);}

         private:
               module() = delete;
               module(module const &) = delete;
               module& operator = (module const & ) = delete;                                           
       };
    
   } // i2c

}}

#endif // QUAN_STM32_L4_I2C_MODULE_HPP_INCLUDED
