#ifndef QUAN_STM32_GPIO_DETAIL_GET_PERIPH_REG_HPP_INCLUDED
#define QUAN_STM32_GPIO_DETAIL_GET_PERIPH_REG_HPP_INCLUDED

#include <quan/stm32/gpio/module.hpp>
#include <quan/stm32/gpio/settings.hpp>

#include <quan/stm32/gpio/pin.hpp>
#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/if.hpp>

namespace quan{ namespace stm32{ namespace gpio{ namespace detail{

   //meta::TypeFunction
   template <typename Pin, typename Setting, typename Where = void> 
   struct get_periph_reg;

   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::Mode,Setting> 
         >
      >::type
   >{
      typedef typename Pin::port_type::moder_type type;
   };

   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::OType,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type::otyper_type type;
   };

   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::Pupd,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type::pupdr_type type;
   };


   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::OSpeed,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type::ospeedr_type type;
   };


   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::OState,Setting>
         >
      >::type
   >{
      typedef typename Pin::port_type::odr_type type;
   };


   template<typename Pin,typename Setting>
   struct get_periph_reg<Pin,Setting,
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::stm32::gpio::Pin,Pin>,
            quan::is_model_of<quan::stm32::gpio::AlternateFunction,Setting>
         >
      >::type
   >{
      typedef typename quan::meta::if_c< (Pin::pin_value < 8),
         typename Pin::port_type::afrl_type,
         typename Pin::port_type::afrh_type
      >::type type;
   };

}}}} 

#endif // QUAN_STM32_GPIO_DETAIL_GET_PERIPH_REG_HPP_INCLUDED
