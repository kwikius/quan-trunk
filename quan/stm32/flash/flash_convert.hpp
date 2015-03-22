#ifndef QUAN_STM32_FLASH_FLASH_CONVERT_HPP_INCLUDED
#define QUAN_STM32_FLASH_FLASH_CONVERT_HPP_INCLUDED

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

#include <cstdint>
#include <quan/dynarray.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/dynarray.hpp>
#include <quan/stm32/flash.hpp>
#include <quan/stm32/detail/flash.hpp>

namespace quan{ namespace stm32{ namespace flash{

   template <typename T> struct text_convert;

   template <typename T>
   struct flash_convert{
      // ok wout user io call report errors
      static bool set (const char* symbol_name, T const & value)
      {
         int32_t symbol_index =-1;
         if (quan::stm32::flash::detail::validate(
               symbol_name,quan::stm32::flash::get_flash_typeid<T>(),symbol_index)
         ){
            quan::dynarray<uint8_t> bytestream {sizeof(T), symbol_table::on_malloc_failed};
            if ( bytestream.good() && quan::stm32::flash::detail::type_to_bytestream(&value,bytestream, sizeof(T)) ){
               auto const & symtab = quan::stm32::flash::get_app_symbol_table();
               return symtab.write_symbol(symbol_index, bytestream);
            }
         }
         return false;
      }
       // ok wout user io call report errors
      static bool get(const char* symbol_name, T & value_out)
      {
         int32_t symbol_index = -1;
         if (quan::stm32::flash::detail::validate(symbol_name,quan::stm32::flash::get_flash_typeid<T>(),symbol_index)){
            auto const & symtab = quan::stm32::flash::get_app_symbol_table();
            quan::dynarray<uint8_t> bytestream {sizeof(T),symbol_table::on_malloc_failed};
            if (bytestream.good() && symtab.read_symbol(symbol_index, bytestream)){
               return quan::stm32::flash::detail::bytestream_to_type(bytestream,&value_out, sizeof(T));
            }
         }
         return false;
       }

       // require user io
       static bool text_to_bytestream(
         quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & text_in,
          bool (*pfn_check)(void* value))
      {
         T value ;
         if (!text_convert<T>::text_to_type(text_in, &value)){
            return false;
         }
         if ( ! pfn_check((void*) &value)){
            return false;
         }
         return quan::stm32::flash::detail::type_to_bytestream(&value,dest, sizeof(T));
      }

      // require user io
      static bool bytestream_to_text(
         quan::dynarray<char>& dest, quan::dynarray<uint8_t> const & src)
      {
          T value ;
          if (!quan::stm32::flash::detail::bytestream_to_type(src,&value,sizeof(T))){
            return false;
          }
          return text_convert<T>::type_to_text(&value,dest);
      }
   };
   
   template <typename T>
   inline 
   bool get_flash_value(const char* name, T & value)
   {
      if ( get_app_symbol_table().is_symbol_name_defined_in_flash(name)){
         return flash_convert<T>::get(name,value);
      }else{
         return false;
      }
   }

   // n.b use with caution
   // The system WILL be locked for several ms while the var is written
   // inadvisable to call after init!!!
   template <typename T>
   inline 
   bool set_flash_value(const char* name, T const & value)
   {
      if ( get_app_symbol_table().is_valid_symbol_name(name)){
         return flash_convert<T>::set(name,value);
      }else{
         return false;
      }
   }

}}} // quan::stm32::flash

#endif
