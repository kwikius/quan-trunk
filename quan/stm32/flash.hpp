#ifndef QUAN_STM32_FLASH_HPP_INCLUDED
#define QUAN_STM32_FLASH_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
   bool have_symbol(quan::stm32::flash::symbol_table const & symtab,uint16_t symidx);
  
}}}
 
#endif // QUAN_STM32_FLASH_HPP_INCLUDED
 
