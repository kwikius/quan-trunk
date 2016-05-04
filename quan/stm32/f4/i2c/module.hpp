#ifndef QUAN_STM32_F4_I2C_MODULE_HPP_INCLUDED
#define QUAN_STM32_F4_I2C_MODULE_HPP_INCLUDED
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

#ifndef QUAN_STM32F4
#error dont include directly
#endif

#include <quan/stm32/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>

namespace quan{ namespace stm32 {

 struct I2C; // Archetype

    namespace i2c{

       template <uint32_t Address> 
       struct module{
            typedef uint32_t value_type;
            typedef module type;
            typedef quan::stm32::periph_reg< type,  0x00>  cr1_type;
            typedef quan::stm32::periph_reg< type,  0x04>  cr2_type;
            typedef quan::stm32::periph_reg< type,  0x08>  oar1_type;
            typedef quan::stm32::periph_reg< type,  0x0C>  oar2_type;
            typedef volatile uint8_t                       dr_type; // (0x10)
            typedef quan::stm32::periph_reg< type,  0x14>  sr1_type;
            typedef quan::stm32::periph_reg< type,  0x18>  sr2_type;
            typedef quan::stm32::periph_reg< type,  0x1C>  ccr_type;
            typedef quan::stm32::periph_reg< type,  0x20>  trise_type;

            static constexpr uint32_t address = Address;

            cr1_type  cr1;
            cr2_type  cr2;
            oar1_type  oar1;
            oar2_type  oar2;
            dr_type    dr;
      private:
            uint8_t padding1[3];
      public:   
            sr1_type  sr1;
            sr2_type  sr2;
            ccr_type  ccr;
            trise_type  trise;

            typedef quan::meta::type_sequence<  
               cr1_type,
               cr2_type,
               oar1_type,
               oar2_type,
               sr1_type,
               sr2_type,
               ccr_type,
               trise_type
            > periph_reg_list;

            static constexpr module* get(){ return reinterpret_cast<module*>(address);}

         private:
               module() = delete;
               module(module const &) = delete;
               module& operator = (module const & ) = delete;                                           
       };
    
   } // i2c
}} // quan:stm32

#endif // QUAN_STM32_F4_I2C_MODULE_HPP_INCLUDED
