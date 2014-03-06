#ifndef QUAN_STM32_UNDEFINED_REG_HPP_INCLUDED
#define QUAN_STM32_UNDEFINED_REG_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/not.hpp>

namespace quan{ namespace stm32 { 

   struct UndefinedPeriphReg; // Archetype

   template <typename Module, uint32_t Offset>
   struct undefined_reg{

      typedef Module module_type;
      typedef typename module_type::value_type value_type;
      static constexpr uint32_t address_offset = Offset;
      static constexpr uint32_t address =  module_type::address + address_offset;

      typedef undefined_reg type;

      private:
      value_type reserved;

      undefined_reg() = delete;
      undefined_reg(undefined_reg const &)= delete;
      undefined_reg& operator = (undefined_reg const &) = delete;

   };

}}

namespace quan{ namespace impl{

      template <typename Module, uint32_t Offset>
      struct is_model_of_impl<
         quan::stm32::UndefinedPeriphReg,
         quan::stm32::undefined_reg<Module,Offset> 
      > : quan::meta::true_{};

}}

namespace quan{ namespace stm32 {namespace detail {

       struct periph_reg_is_defined{

            template <typename PeriphReg> struct apply{
                  typedef quan::meta::not_<quan::is_model_of<quan::stm32::UndefinedPeriphReg,PeriphReg> > type;
            };
       };
   }

}}

#endif // QUAN_STM32_UNDEFINED_REG_HPP_INCLUDED
