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

      // TODO symbol_indexes should be int32_t!!!
      // add a function to get the typeid of a symbol_name or index
      typedef bool (*pfn_check_function)(void*);
      typedef bool (*pfn_text_to_bytestream)(
         quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & src, bool (*pfn)(void*));
      typedef bool (*pfn_bytestream_to_text)(quan::dynarray<char>& dest, quan::dynarray<uint8_t> const & src);

// virtual functions mainly to get at attributes of the flash vars
      virtual uint16_t get_symbol_storage_size(uint16_t symbol_index)const =0;
      virtual uint16_t get_symtable_size()const =0;
      virtual bool get_readonly_status(uint16_t symbol_index,bool & result)const=0;
      virtual int32_t get_index( const char* const symbol_name) const = 0;
      virtual const char* get_name(uint16_t symbol_index) const = 0;
      virtual const char* get_info(uint16_t symbol_index) const = 0;
      virtual pfn_check_function get_check_function(uint16_t symbol_index)const = 0;
      virtual pfn_text_to_bytestream get_text_to_bytestream_fun( uint16_t symbol_index) const =0;
      virtual pfn_bytestream_to_text get_bytestream_to_text_fun( uint16_t symbol_index) const =0;
      virtual bool init() const=0;
      virtual bool get_typeid(uint16_t symbol_index, uint32_t & dest) const = 0;
 //-------------------------------non virtual ----------------------
      // symbolindex  actually is in symbol table
      bool exists(uint16_t symbol_index) const ;
      // exists and has been defined rather than undef
      bool is_defined(const char* symbol_name) const;
      int32_t get_index( quan::dynarray<char> const & symbol_name) const;
      bool read_symbol (uint16_t symbol_index, quan::dynarray<uint8_t> & buffer)const;
      bool write_symbol(uint16_t symbol_index, quan::dynarray<uint8_t> const & buffer)const;
      bool have_symbol(uint16_t symbol_index)const;
      bool write_from_text (uint16_t symbol_index,quan::dynarray<char> const & value)const;
      bool read_to_text(uint16_t symbol_index, quan::dynarray<char> & value)const;
     
               // todo setup an alloc fail fun
      static void on_malloc_failed() {}
         symbol_table(symbol_table const &) = delete;
         symbol_table& operator = (symbol_table const &) = delete;
   };

   // must be implemented by the app
   symbol_table const & get_app_symbol_table();
   template <typename T> struct get_flash_typeid_impl;
   template <typename T> uint32_t get_flash_typeid();

   bool flash_menu();

}}}
 
#endif // QUAN_STM32_FLASH_HPP_INCLUDED
 
