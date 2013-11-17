#ifndef QUAN_STM32_F0_PERIPH_MAP_HPP_INCLUDED
#define QUAN_STM32_F0_PERIPH_MAP_HPP_INCLUDED

namespace quan{ namespace stm32f0{

   struct periph_map{
      static constexpr uint32_t gpiof = 0x48001400;
      static constexpr uint32_t gpiod = 0x48000C00; 
      static constexpr uint32_t gpioc = 0x48000800 ;
      static cosntexpr uint32_t gpiob = 0x48000400;                       

   };
}} 


#endif // QUAN_STM32_F0_PERIPH_MAP_HPP_INCLUDED
