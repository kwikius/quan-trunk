#ifndef QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
#define QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED

#include <cstdint>
#include <quan/dynarray.hpp>

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
    
   // return -1 if corrupt
   // n.b. only returns num since last firmware update
  // int32_t get_write_count();
    
   struct flash_symtab_entry_t {
      const char* const name;
      uint32_t const type_tag;
      bool (*pfn_cstring_to_rep) (quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & src);
   };
    

}}}}//quan::stm32::flash::deatil

#endif // QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
