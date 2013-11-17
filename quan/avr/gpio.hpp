#ifndef QUAN_AVR_GPIO_HPP_INCLUDED
#define QUAN_AVR_GPIO_HPP_INCLUDED


#include <quan/avr/gpio_typedefs.hpp>
#include <quan/avr/gpio/pin.hpp>
#include <quan/std/tr1/is_same.hpp>
#include <quan/avr/gpio/mode.hpp>

namespace quan{ namespace avr{

      

      template <typename P, typename Mode>
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::avr::gpio::Pin,P>,
            std::is_same<Mode,quan::avr::gpio::mode::input>
         >
      >::type
      setmode()
      {
        *(reinterpret_cast<volatile uint8_t*>(P::port_type::ddr_type::address)) &= ~(1 << P::pin_value);
      }

      
      template <typename P, typename Mode>
      typename quan::where_<
         quan::meta::and_<
            quan::is_model_of<quan::avr::gpio::Pin,P>,
            std::is_same<Mode,quan::avr::gpio::mode::output>
         >
      >::type
      setmode()
      {
        *(reinterpret_cast<volatile uint8_t*>(P::port_type::ddr_type::address)) |= (1 << P::pin_value);
      }

      template <typename P>
      typename quan::where_<
         quan::is_model_of<quan::avr::gpio::Pin,P>
      >::type
      set()
      {
        *(reinterpret_cast<volatile uint8_t*>(P::port_type::port_type::address)) |= (1 << P::pin_value);
      }

       template <typename P>
      typename quan::where_<
         quan::is_model_of<quan::avr::gpio::Pin,P>
      >::type
      clear()
      {
        *(reinterpret_cast<volatile uint8_t*>(P::port_type::port_type::address)) &= ~(1 << P::pin_value);
      }     
} }

#endif // QUAN_AVR_GPIO_HPP_INCLUDED
