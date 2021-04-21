#ifndef QUAN_NORDIC_NRF51_PERIPH_MAP_HPP_INCLUDED
#define QUAN_NORDIC_NRF51_PERIPH_MAP_HPP_INCLUDED

namespace quan::nordic{

/*
code                  at 0x00000000
FICR                  at 0x10000000
UICR                  at 0x10001000
data ram              at 0x20000000      
APB peripherals start at 0x40000000
AHB peripherals start at 0x50000000
APB peripherals also have an id where address = 0x40000000 + (id << 12)
*/

   struct periph_map{
     
     static constexpr uint32_t ficr   = 0x10000000; // read only config
     static constexpr uint32_t uicr   = 0x10001000; // use configurable config
     // APB ---------------------------------------
     //{
     static constexpr uint32_t clock  = 0x40000000; 
     static constexpr uint32_t power  = 0x40000000;
     static constexpr uint32_t mpu    = 0x40000000;
     //}
     static constexpr uint32_t radio  = 0x40001000;
     static constexpr uint32_t uart0  = 0x40002000;
     //{
     static constexpr uint32_t spi0   = 0x40003000;
     static constexpr uint32_t twi0   = 0x40003000;
     //}
     //{
     static constexpr uint32_t spi1   = 0x40004000;
     static constexpr uint32_t spis1  = 0x40004000;
     static constexpr uint32_t twi1   = 0x40004000;
     //}
     static constexpr uint32_t gpiote = 0x40006000;
     static constexpr uint32_t adc    = 0x40007000;
     static constexpr uint32_t timer0 = 0x40008000;
     static constexpr uint32_t timer1 = 0x40009000;
     static constexpr uint32_t timer2 = 0x4000A000;
     static constexpr uint32_t rtc0   = 0x4000B000;
     static constexpr uint32_t temp   = 0x4000C000;
     static constexpr uint32_t rng    = 0x4000D000;
     static constexpr uint32_t ecb    = 0x4000E000;
     static constexpr uint32_t aar    = 0x4000F000;
     static constexpr uint32_t ccm    = 0x4000F000;
     static constexpr uint32_t wdt    = 0x40010000;
     static constexpr uint32_t rtc1   = 0x40011000;
     static constexpr uint32_t qdec   = 0x40012000;
     static constexpr uint32_t lpcomp = 0x40013000;
     static constexpr uint32_t swi0   = 0x40014000;
     static constexpr uint32_t swi1   = 0x40015000;
     static constexpr uint32_t swi2   = 0x40016000;
     static constexpr uint32_t swi3   = 0x40017000;
     static constexpr uint32_t swi4   = 0x40018000;
     static constexpr uint32_t swi5   = 0x40019000;
     static constexpr uint32_t nvmc   = 0x4001E000;
     static constexpr uint32_t ppi    = 0x4001F000;
     static constexpr uint32_t rtc2   = 0x40024000;
    // APB------------------------------------------
     static constexpr uint32_t gpio   = 0x50000000;

   };

}  // quan::nordic

#endif // QUAN_NORDIC_NRF51_PERIPH_MAP_HPP_INCLUDED
