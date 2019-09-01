#ifndef QUAN_STM32_F0_USART_MODULE_HPP_INCLUDED
#define QUAN_STM32_F0_USART_MODULE_HPP_INCLUDED
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

#if ! (defined( QUAN_STM32F0 ) || defined(QUAN_STM32L4))
#error dont include directly
#endif

#include <quan/stm32/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>

namespace quan{ namespace stm32{ 

    struct Usart; // Archetype

    namespace usart{

       template <uint32_t Address> 
       struct module{
            typedef uint32_t value_type;
            typedef module type;
            typedef quan::stm32::periph_reg< type,  0x00>  cr1_type;
            typedef quan::stm32::periph_reg< type,  0x04>  cr2_type;
            typedef quan::stm32::periph_reg< type,  0x08>  cr3_type;
            typedef quan::stm32::periph_reg< type,  0x0C>  brr_type;
            typedef quan::stm32::periph_reg< type,  0x10>  gtpr_type;
            typedef quan::stm32::periph_reg< type,  0x14>  rtor_type;
            typedef quan::stm32::periph_reg< type,  0x18>  rqr_type;
            typedef quan::stm32::periph_reg< type,  0x1C>  isr_type;
            typedef quan::stm32::periph_reg< type,  0x20>  icr_type;
            typedef volatile uint32_t                      rdr_type;
            typedef volatile uint32_t                      tdr_type;
           
            static constexpr uint32_t address = Address;

            cr1_type    cr1;
            cr2_type    cr2;
            cr3_type    cr3;
            brr_type    brr;
            gtpr_type   gtpr;
            rtor_type   rtor;
            rqr_type    rqr;
            isr_type    isr;
            icr_type    icr;
            rdr_type    rdr;
            tdr_type    tdr;

            typedef quan::meta::type_sequence<  
               cr1_type
               ,cr2_type
               ,cr3_type
               ,brr_type
               ,gtpr_type
               ,rtor_type
               ,rqr_type
               ,isr_type
               ,icr_type
            > periph_reg_list;

            static constexpr module* get(){ return reinterpret_cast<module*>(address);}

         private:
            module() = delete;
            module(module const &) = delete;
            module& operator = (module const & ) = delete;                                           
       };
    
}}} // quan:stm32::usart

#endif // QUAN_STM32_F0_USART_MODULE_HPP_INCLUDED

