#ifndef QUAN_STM32_FLASH_HPP_INCLUDED
#define QUAN_STM32_FLASH_HPP_INCLUDED

#include <cstdint>

namespace quan {namespace stm32 {namespace flash {

   // return -1 if corrupt
   // n.b. only returns num since last firmware update
   int32_t get_write_count();

   
}}}
 
#endif // QUAN_STM32_FLASH_HPP_INCLUDED
 