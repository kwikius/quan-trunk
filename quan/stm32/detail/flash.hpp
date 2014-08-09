#ifndef QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
#define QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED

#include <cstdint>

/*
  need to write impl dependent on processor
*/

namespace quan {namespace stm32 {namespace flash { namespace detail{

   // pagenum is id of page to erase
   bool erase (int32_t page_num);

   void * get_page_address (int32_t page_num);
   uint32_t get_page_size (int32_t page_num);
   int32_t get_page_num (void * address);

   bool write (const volatile uint8_t* dest, const uint8_t* buf, int32_t bytes);

   inline bool write (const volatile uint8_t* dest, uint8_t val)
   {
      return write (dest,&val,1);
   }
   
   bool read (uint8_t* buf,const volatile uint8_t * src, int32_t bytes);
    
}}}}//quan::stm32::flash::detail

#endif // QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
