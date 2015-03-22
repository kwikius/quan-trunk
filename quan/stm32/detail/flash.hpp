#ifndef QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
#define QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
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
   bool type_to_bytestream(const void* value, quan::dynarray<uint8_t> & bytestream_out, uint32_t size);
   bool bytestream_to_type(quan::dynarray<uint8_t> const & bytestream_in, void* value_out, uint32_t size);
   bool validate(const char* symbol_name,uint32_t expected_typeid,int32_t & symbol_index_out);

}}}}//quan::stm32::flash::detail

#endif // QUAN_STM32_DETAIL_FLASH_HPP_INCLUDED
