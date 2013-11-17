#ifndef QUAN_AVR_PERIPH_MAP_HPP_INCLUDED
#define QUAN_AVR_PERIPH_MAP_HPP_INCLUDED

#include <stdint.h>

namespace quan{
    namespace avr{
        struct periph_map{
            // nb offsets of 0 are at pinxx
             static constexpr uint8_t gpiob = 0x03;
             static constexpr uint8_t gpioc = 0x06;
             static constexpr uint8_t gpiod = 0x09;
        };

   }
}
#endif // QUAN_AVR_PERIPH_MAP_HPP_INCLUDED
