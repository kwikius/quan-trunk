#ifndef QUAN_STM32F4_GPIO_PIN_HPP_INCLUDED
#define QUAN_STM32F4_GPIO_PIN_HPP_INCLUDED

#include <quan/stm32f4/gpio/module.hpp>
#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/numbits.hpp>

namespace quan{ namespace stm32f4{ namespace gpio{

  struct Pin; // Concept

  // a Pin consists of a port and a bit position
  template <typename Port,typename Port::value_type Pos> struct pin{
      typedef Port port_type;
      typedef typename port_type::value_type value_type;
      static_assert( (Pos < quan::meta::numbits<value_type>::value) ,
         "bit pos out of range in quan::stm32f4::gpio::pin" );
      static const typename Port::value_type pin_value = Pos;
  };

}}}

namespace quan{ namespace impl{

  template <typename P, typename P::value_type Pos>
  struct is_model_of_impl<
      quan::stm32f4::gpio::Pin,quan::stm32f4::gpio::pin<P,Pos>,
      typename quan::where_<
         quan::is_model_of<quan::stm32f4::Gpio,P> 
      >::type 
   > : quan::meta::true_{};

}}


#endif // QUAN_STM32F4_GPIO_PIN_HPP_INCLUDED
