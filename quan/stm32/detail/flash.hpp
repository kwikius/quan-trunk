#ifndef QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
#define QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED

#include <cstdint>

namespace quan {namespace stm32 {namespace flash { namespace detail{

// detail 
   bool erase (int32_t page_num);

   void * get_page_address (int32_t page_num);
   uint32_t get_page_size (int32_t page_num);
   int32_t get_page_num (void * address);

   void write (const volatile uint8_t* dest, const uint8_t* buf, int32_t bytes);

   inline void write (const volatile uint8_t* dest, uint8_t val)
   {
      write (dest,&val,1);
   }
   
   void read (uint8_t* buf,const volatile uint8_t * src, int32_t bytes);
    
}}}}//quan::stm32::flash::deatil

#endif // QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
