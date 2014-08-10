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
 along with this program. If not, see http://www.gnu.org/licenses.
*/
#include <quan/stm32/detail/flash.hpp>
#include <cstring>

namespace {
   // N.B pagesize must be > (sizeof all data + sizeof largest data + 14)
   constexpr uint16_t page_size= 39;
   uint8_t page0[page_size];
   uint8_t page1[page_size];
}

void* quan::stm32::flash::detail::get_page_address (int32_t page_num)
{
   switch (page_num) {
   case 1:
      return page0;
   case 2:
      return page1;
   default:
      return nullptr;
   }
}

int32_t quan::stm32::flash::detail::get_page_num (void * address_in)
{
   uint8_t* address = reinterpret_cast<uint8_t*> (address_in);
   if ( (address >= page0) && (address < (page0 + page_size))) {
      return 1;
   } else {
      if ( (address >= page1) && (address < (page1 + page_size))) {
         return 2;
      } else {
         return -1;
      }
   }
}
 
 
uint32_t quan::stm32::flash::detail::get_page_size (int32_t page_num)
{
   return page_size;
}
 
 
bool quan::stm32::flash::detail::erase (int32_t page_num)
{
   void * page = get_page_address (page_num);
   if (page != nullptr) {
      memset (page,0xFF,page_size);
      return true;
   } else {
      return false;
   }
}

bool quan::stm32::flash::detail::write (const volatile uint8_t* dest, const uint8_t* buf, int32_t bytes)
{
   memcpy ((uint8_t*)dest,buf,bytes);
   return true;
}

bool quan::stm32::flash::detail::read (uint8_t* buf,const volatile uint8_t * src, int32_t bytes)
{
   memcpy (buf, (uint8_t const *) src,bytes);
   return true;
}
 

 
