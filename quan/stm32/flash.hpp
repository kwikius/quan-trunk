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
#include <quan/stm32/flash/flash_type_tags.hpp>

namespace quan {namespace stm32 {namespace flash {

   // The symbol table entry structure for a flash variable
   struct symtab_entry_t {
      const char* const name;  // user name of the symbol
      uint32_t const type_tag;  // id representing the type of the variable
      bool (*pfn_validity_check)(void*); //range check function 
      const char * const info; // some help about the flash variable
      bool readonly;  // if the value is readonly ( not writable from user flash menu)
   };

   struct symbol_table{
      symbol_table(){}

      // TODO symbol_indexes should be int32_t!!!
      // add a function to get the typeid of a symbol_name or index
      typedef bool (*pfn_check_function)(void*);
      typedef bool (*pfn_text_to_bytestream)(
         quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & src, bool (*pfn)(void*));
      typedef bool (*pfn_bytestream_to_text)(quan::dynarray<char>& dest, quan::dynarray<uint8_t> const & src);

// virtual functions mainly to get at attributes of the flash vars
      virtual uint16_t get_symbol_storage_size(int32_t symbol_index)const =0;
      virtual uint16_t get_symtable_size()const =0;
      virtual bool get_readonly_status(int32_t symbol_index,bool & result)const=0;
      virtual int32_t get_index( const char* const symbol_name) const = 0;
      virtual const char* get_name(int32_t symbol_index) const = 0;
      virtual const char* get_info(int32_t symbol_index) const = 0;
       // requires valid symbol_index -- not checked
      virtual pfn_check_function get_check_function(int32_t symbol_index)const = 0;

      virtual bool init() const=0;
      virtual bool get_typeid(int32_t symbol_index, uint32_t & dest) const = 0;

 //-------------------------------non virtual ----------------------
      uint32_t get_typeid_no_check(int32_t symbol_index)const
         { uint32_t dest; get_typeid(symbol_index,dest); return dest;}

      // requires valid symbol_index -- not checked
      pfn_text_to_bytestream get_text_to_bytestream_fun( int32_t symbol_index) const;
      // requires valid symbol_index -- not checked
      pfn_bytestream_to_text get_bytestream_to_text_fun( int32_t symbol_index) const;
      // symbol_index actually is valid
      bool is_valid_symbol_index(int32_t symbol_index) const ;
      bool is_valid_symbol_name(const char* symbol_name) const;
      // exists and has been defined in flash rather than undef
      bool is_symbol_name_defined_in_flash(const char* symbol_name) const;
      bool is_symbol_index_defined_in_flash(int32_t symbol_index)const ;
      // index of symbol or -1 if not found
      int32_t get_index( quan::dynarray<char> const & symbol_name) const;
      bool read_symbol (int32_t symbol_index, quan::dynarray<uint8_t> & buffer)const;
      bool write_symbol(int32_t symbol_index, quan::dynarray<uint8_t> const & buffer)const;
     // bool have_symbol(int32_t symbol_index)const;
      bool write_from_text (int32_t symbol_index,quan::dynarray<char> const & value)const;
      bool read_to_text(int32_t symbol_index, quan::dynarray<char> & value)const;

      static bool flash_init();
               // todo setup an alloc fail fun
      static void on_malloc_failed() {}
         symbol_table(symbol_table const &) = delete;
         symbol_table& operator = (symbol_table const &) = delete;


      static pfn_bytestream_to_text bytestream_to_text[flash_type_tags::NumTypeTags];
      static pfn_text_to_bytestream text_to_bytestream[flash_type_tags::NumTypeTags];
      static uint32_t type_tag_to_size[];

   };

   // must be implemented by the app
   symbol_table const & get_app_symbol_table();
   template <typename T> struct get_flash_typeid_impl;
   template <typename T> uint32_t get_flash_typeid();

   bool flash_menu();

}}}
 
#endif // QUAN_STM32_FLASH_HPP_INCLUDED
 
