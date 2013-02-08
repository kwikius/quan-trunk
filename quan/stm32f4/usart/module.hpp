#ifndef QUAN_STM32F4_USART_MODULE_HPP_INCLUDED
#define QUAN_STM32F4_USART_MODULE_HPP_INCLUDED

#include <quan/stm32f4/periph_reg.hpp>
#include <quan/meta/type_sequence.hpp>

namespace quan{ namespace stm32f4{ 

    struct Usart; // Archetype

    namespace usart{

       template <uint32_t Address> 
       struct module{
            typedef uint32_t value_type;
            typedef module type;
            typedef quan::stm32f4::periph_reg< type,  0x00>  sr_type;
            typedef volatile uint16_t                        dr_type;
            typedef quan::stm32f4::periph_reg< type,  0x08>  brr_type;
            typedef quan::stm32f4::periph_reg< type,  0x0C>  cr1_type;
            typedef quan::stm32f4::periph_reg< type,  0x10>  cr2_type;
            typedef quan::stm32f4::periph_reg< type,  0x14>  cr3_type;
            typedef quan::stm32f4::periph_reg< type,  0x18>  gtpr_type;

            static const uint32_t address = Address;

            sr_type  sr;
            dr_type  dr;
      private:
            uint16_t reserved1;
      public:
            brr_type  brr;
            cr1_type  cr1;
            cr2_type  cr2;
            cr3_type  cr3;
            gtpr_type  gtpr;

            typedef quan::meta::type_sequence<  
                sr_type
               ,brr_type
               ,cr1_type
               ,cr2_type
               ,cr3_type
               ,gtpr_type
            > periph_reg_list;

            static module* get(){ return reinterpret_cast<module*>(address);}

         private:
               module() = delete;
               module(module const &) = delete;
               module& operator = (module const & ) = delete;                                           
       };
    
}}} // quan:stm32f4::usart

namespace quan{ namespace impl{

   // make port a model of Usart
   template <uint32_t Address>
   struct is_model_of_impl<
			quan::stm32f4::Usart,
			quan::stm32f4::usart::module<Address> 
	> : quan::meta::true_{};

}}

#endif // QUAN_STM32F4_USART_MODULE_HPP_INCLUDED

