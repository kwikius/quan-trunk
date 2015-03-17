/*
 Copyright (c) 2013 -2015 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <cstring>
#include <cstdio>
#include <quan/dynarray.hpp>
#include <quan/stm32/flash.hpp>
#include <quan/stm32/flash/flash_convert/bool.hpp>
#include <quan/stm32/flash/flash_error.hpp>

/*
  flash type conversion functions for bool
  text to bytestream converts from user representation to the flash memory representation
  bytestream_to_text converts from flash memory representation to user comprehensible string

  user rep is "true" or "false"
  flash rep is 1 byte either 1 for true or 0 for false;
*/

namespace {
   const char expected_bool[] = "expected \"true\" or \"false\"";

   bool text_to_type(quan::dynarray<char> const & text_in, bool & value_out)
   {
      if (text_in.get_num_elements() == 5) {
         if ( strcmp(text_in.get(),"true") == 0 ) {
            value_out = true;
            return true;
         } else {
            user_error(expected_bool);
            return false;
         }
      } else {
         if ( (text_in.get_num_elements() == 6) && ( strcmp(text_in.get(),"false") == 0 ) ) {
            value_out = false;
            return true;
         } else {
            user_error(expected_bool);
            return false;
         }
      }
   }

   bool type_to_text(bool const & value_in, quan::dynarray<char> & text_out)
   {
      if ( value_in == true){
         if (text_out.realloc (5)) { 
            strcpy(text_out.get(),"true");
            return true;
         }
      }else{
         if (text_out.realloc (6)) { 
            strcpy(text_out.get(),"false");
            return true;
         }
      }
      main_alloc_failed();
      return false;
   }
   
   bool type_to_bytestream(bool const & value, quan::dynarray<uint8_t> & bytestream_out)
   {
      if ( bytestream_out.realloc (sizeof(bool))) {
         memcpy(bytestream_out.get(),&value,sizeof(bool));
         return true;
      }else{
         main_alloc_failed();
         return false;
      }
   }

   bool bytestream_to_type(quan::dynarray<uint8_t> const & bytestream_in, bool & value_out)
   {
      if (bytestream_in.get_num_elements() == sizeof (bool)) {
         memcpy(&value_out,bytestream_in.get(), sizeof(bool));
         return true;
      }else{
         quan::error(fn_rep_to_cstring_Bool,quan::detail::stm32_flash_page_corrupted);
         return false;
      }
   }

   bool validate(const char* symbol_name,uint32_t expected_typeid,int32_t & symbol_index_out)
   {
      auto const & symtab = quan::stm32::flash::get_app_symbol_table();
      int32_t const symbol_index = symtab.get_index (symbol_name);
      if (symbol_index == -1) {
         return false;
      }
      uint32_t type_id = 0;
      if ( !symtab.get_typeid(symbol_index,type_id)){
          user_error("unknown error please report");
         //shouldnt fail here as index checked
         return false;
      }
      if(type_id == expected_typeid){
         symbol_index_out = symbol_index;
         return true;
      }else{
         user_error("symbol is not correct type");
         return false;
      }
   }
}// ~namespace
   
   bool quan::stm32::flash::flash_convert<bool>::set (const char* symbol_name, bool const & value)
   {
      int32_t symbol_index =-1;
      if (validate(symbol_name,quan::stm32::flash::get_flash_typeid<bool>(),symbol_index)){
         quan::dynarray<uint8_t> bytestream {sizeof(uint8_t), main_alloc_failed};
         if ( bytestream.good() && type_to_bytestream(value,bytestream) ){
            auto const & symtab = quan::stm32::flash::get_app_symbol_table();
            return symtab.write_symbol(symbol_index, bytestream);
         }
      }
      return false;
   }
   
   bool quan::stm32::flash::flash_convert<bool>::get(const char* symbol_name, bool & value_out)
   {
      int32_t symbol_index = -1;
      if (validate(symbol_name,quan::stm32::flash::get_flash_typeid<bool>(),symbol_index)){
         auto const & symtab = quan::stm32::flash::get_app_symbol_table();
         quan::dynarray<uint8_t> bytestream {sizeof(uint8_t), main_alloc_failed};
         if (bytestream.good() && symtab.read_symbol(symbol_index, bytestream)){
            return bytestream_to_type(bytestream,value_out);
         }
      }
      return false;
    }

   bool quan::stm32::flash::flash_convert<bool>::text_to_bytestream(
         quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & text_in,
          bool (*pfn_check)(void* value))
   {
      bool value = false;
      if (!text_to_type(text_in, value)){
         return false;
      }
      if ( ! pfn_check((void*) &value)){
         return false;
      }
      return type_to_bytestream(value,dest);
   }

   bool quan::stm32::flash::flash_convert<bool>::bytestream_to_text(
         quan::dynarray<char>& dest, quan::dynarray<uint8_t> const & src)
   {
       bool value = false;
       if (!bytestream_to_type(src,value)){
         return false;
       }
       return type_to_text(value,dest);
   }
