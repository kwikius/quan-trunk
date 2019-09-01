#ifndef QUAN_STM32_F4_SPI_MODULE_HPP_INCLUDED1
#define QUAN_STM32_F4_SPI_MODULE_HPP_INCLUDED1

#ifndef QUAN_STM32F4
#error dont include directly
#endif

#include <quan/stm32/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>

namespace quan { namespace stm32{

   struct Spi; // Archetype

   namespace spi{
      
      template <uint32_t Address> 
      struct module{
            typedef uint32_t value_type;
            static constexpr uint32_t address = Address;
            typedef module type;
            typedef quan::stm32::periph_reg< type,  0x00>  cr1_type;
            typedef quan::stm32::periph_reg< type,  0x04>  cr2_type;
            typedef quan::stm32::periph_reg< type,  0x08>  sr_type;
            typedef volatile uint16_t                      dr_type;
            typedef volatile uint16_t                      crcpr_type;
            typedef volatile uint16_t                      rxcrcr_type;
            typedef volatile uint16_t                      txcrcr_type;
            typedef quan::stm32::periph_reg< type,  0x1C>  i2scfgr_type;
            typedef quan::stm32::periph_reg< type,  0x20>  i2spr_type;
   
            cr1_type  cr1;
            cr2_type  cr2;
            sr_type   sr;
            dr_type   dr;
      private:
            uint16_t reserved1;
      public:
            crcpr_type crcpr;
      private:
            uint16_t reserved2;
      public:
            rxcrcr_type rxcrcr;
      private:
            uint16_t reserved3;
      public:
            txcrcr_type txcrcr;
      private:
            uint16_t reserved4;
      public:
            i2scfgr_type i2scfgr;
            i2spr_type i2spr;

            typedef quan::meta::type_sequence<   
               cr1_type
               ,cr2_type
               ,sr_type
               ,i2scfgr_type
               ,i2spr_type
            > periph_reg_list;

            static constexpr module* get(){ return reinterpret_cast<module*>(address);}

         private:
               module() = delete;
               module(module const &) = delete;
               module& operator = (module const & ) = delete;   

      };
   } //spi

}} //quan::stm32

#endif // QUAN_STM32_F4_SPI_MODULE_HPP_INCLUDED1
