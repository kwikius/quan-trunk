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
}

   bool quan::stm32::flash::flash_convert<bool>::set (const char* symbol_name, bool const & value)
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
      if ( type_id  != quan::stm32::flash::get_flash_typeid<bool>()){
      //that type of symbol name is right
         user_error("symbol is not a bool");
         return false;
      }
      quan::dynarray<uint8_t> bytestream {sizeof (uint8_t), main_alloc_failed};
      if (!bytestream.good()) {
            return false;
      }
      *bytestream.get() = (value == true) ? 1 : 0;
      return symtab.write_symbol(symbol_index, bytestream);
   }
   
   bool quan::stm32::flash::flash_convert<bool>::get (const char* symbol_name, bool & value)
   {
      auto const & symtab = quan::stm32::flash::get_app_symbol_table();
      int32_t const symbol_index = symtab.get_index (symbol_name);
      if (symbol_index == -1) {
         // shouldnt get here
         return false;
      }
      uint32_t type_id = 0;
      if ( !symtab.get_typeid(symbol_index,type_id)){
          user_error("unknown error please report");
         //shouldnt fail here as index checked
         return false;
      }
      if ( type_id  != quan::stm32::flash::get_flash_typeid<bool>()){
      //that type of symbol name is right
         user_error("symbol is not a bool");
         return false;
      }
      uint32_t const length = symtab.get_symbol_storage_size (symbol_index);
      quan::dynarray<uint8_t> bytestream {length, main_alloc_failed};
      if (!bytestream.good()) {
         return false;
      }

      if (!symtab.read_symbol(symbol_index, bytestream)) {
         return false;
      }
      value = (*bytestream.get() == 1) ? true : false;
      return true;
   }

bool quan::stm32::flash::flash_convert<bool>::text_to_bytestream(
      quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & src,
       bool (*pfn_check)(void* value))
{
// text to value of type
     // input is "true" or "false"
     uint8_t val = 0;
     if (src.get_num_elements() == 5) {
          if ( strcmp(src.get(),"true") == 0 ) {
               val = 1;
          } else {
               user_error(expected_bool);
               return false;
          }
     } else {
          if ( src.get_num_elements() == 6) {
               if ( strcmp(src.get(),"false") != 0 ) {
                    user_error(expected_bool);
                    return false;
               }
          } else {
               user_error(expected_bool);
               return false;
          }
     }
     bool check_val = val== 1?true:false;
     if ( ! pfn_check((void*) &check_val)){
         return false;
     }
// value to bytestream
  //   static_assert(sizeof(bool) == sizeof(uint8_t), "invalid bool size");
     if (!dest.realloc (sizeof(uint8_t))) {
          main_alloc_failed();
          return false;
     }
     *dest.get() = val;
//
     return true;
}

bool quan::stm32::flash::flash_convert<bool>::bytestream_to_text(
      quan::dynarray<char>& dest, quan::dynarray<uint8_t> const & src)
{
  // bytestream to value
    if (src.get_num_elements() != sizeof (bool)) {
      quan::error(fn_rep_to_cstring_Bool,
      quan::detail::stm32_flash_page_corrupted);
      return false;
   }
   uint8_t val = *src.get();
   //sort of
// value to text
   if ( val == 0){ // false
       if (!dest.realloc (6)) { 
            main_alloc_failed();
          return false;
        }
        strcpy(dest.get(),"false");
        return true;
   }else{
      if (val == 1){
         if (!dest.realloc (5)) { 
          main_alloc_failed();
          return false;
        }
        strcpy(dest.get(),"true");
        return true;
      }else{
         quan::error(fn_rep_to_cstring_Bool,
         quan::detail::stm32_flash_page_corrupted);
         return false;
      }
   }
}
