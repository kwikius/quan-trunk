#ifndef QUAN_STM32_FLASH_HPP_INCLUDED
#define QUAN_STM32_FLASH_HPP_INCLUDED

#include <cstdint>
#include <quan/dynarray.hpp>

namespace quan {namespace stm32 {namespace flash {

   struct symbol_table{
      symbol_table(){}
      
      virtual uint16_t get_symbol_storage_size(uint16_t symidx)const =0;
      virtual uint16_t get_symtable_size()const =0;
      private:
         symbol_table(symbol_table const &) = delete;
         symbol_table& operator = (symbol_table const &) = delete;
   };

   // return -1 if corrupt
   // n.b. only returns num since last firmware update
   int32_t get_write_count();
   bool read_symbol (quan::stm32::flash::symbol_table const & symtab,uint16_t symidx, quan::dynarray<uint8_t> & buffer);
   bool write_symbol (quan::stm32::flash::symbol_table const & symtab,uint16_t symidx, quan::dynarray<uint8_t> const & buffer);
   
  
}}}
 
#endif // QUAN_STM32_FLASH_HPP_INCLUDED
 