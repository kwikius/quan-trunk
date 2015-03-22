
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
#include <cctype>
#include <quan/user.hpp>
#include <quan/dynarray.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/conversion/float_convert.hpp>
#include <quan/conversion/itoa.hpp>
#include <quan/stm32/flash/flash_error.hpp>
#include <quan/stm32/flash.hpp>

namespace {
   // expect <symbol name> = <value>
   bool parse_symbol_assignment (
      quan::dynarray<char> const & input,
      quan::dynarray<char> & symbol, 
      quan::dynarray<char> & value)
   {
      if ( input.get() == nullptr){
         quan::error(fn_any,quan::detail::unexpected_nullptr);
         return false;
      }
      // TODO alternative to strtok
      char* const symbol_part = strtok(input.get()," \t");
      char* const value_part  = strtok(nullptr," \t");

      if (symbol_part == nullptr) {
         quan::user_error ("expected symbol");
         return false;
      }
      if (value_part == nullptr) {
         quan::user_error("expected value");
         return false;
      }
      size_t const symbol_len = strlen (symbol_part);
      if ( symbol_len > 256){
          quan::user_error ("symbol too long");
         return false;
      }
      if (! symbol.realloc(symbol_len + 1)) {
         quan::error (fn_parse_input,quan::detail::out_of_heap_memory);
         return false;
      }
      size_t const value_len = strlen(value_part);
      if ( value_len > 256){
          quan::user_error ("value too long");
         return false;
      }
      if (! value.realloc(value_len +1)) {
         quan::error (fn_parse_input,quan::detail::out_of_heap_memory);
         return false;
      }
      strcpy (symbol.get(), symbol_part);
      strcpy (value.get(), value_part);
      return true;
   }

   bool set_symbol_value (quan::dynarray<char> const & input)
   {
      quan::dynarray<char> symbol {20,quan::stm32::flash::symbol_table::on_malloc_failed};
      quan::dynarray<char> value {20,quan::stm32::flash::symbol_table::on_malloc_failed};
      
      if (! (symbol.good() && value.good())) {
         return false;
      }
      if (!parse_symbol_assignment (input,symbol,value)) {
         return quan::get_num_errors() == 0;
      }
      auto const & symtab = quan::stm32::flash::get_app_symbol_table();
      
      int32_t const symbol_index = symtab.get_index (symbol);
      if (symbol_index == -1) {
         quan::user_error ("symbol not found");
         return quan::get_num_errors() == 0;
      }
      bool is_readonly = false;
      if (!symtab.get_readonly_status (symbol_index,is_readonly)) {
         //shouldnt get here
         return false;
      }
      quan::user_message("\n");
      if (is_readonly) {
         quan::user_error ("symbol is readonly");
         return true;
      }
      // writing flash stops the world
      quan::user_message("parsing input.....\n");
      quan::user_flush_sptx();
      bool const result =  symtab.write_from_text (symbol_index,value) ;
      if (result) {
         quan::user_message("data written to flash\n");
      } else {
         quan::user_message("parse failed\n");
      }
      return quan::get_num_errors() == 0;
   }
   /*
      show list of flash symbols with values
      n.b symbol could be valid but not set
   */
   size_t strnlen(const char* str, size_t maxlen){
      for (uint32_t i = 0; i < maxlen; ++i){
         if (str[i] == '\0'){
            return i-1;
         }
      }
      return maxlen;
   }
   bool local_show_symbol (uint16_t symbol_index)
   {
      auto const & symtab = quan::stm32::flash::get_app_symbol_table();
      if (symtab.is_symbol_index_defined_in_flash(symbol_index)) {
         quan::dynarray<char> value {1,quan::stm32::flash::symbol_table::on_malloc_failed};
         if (!value.good()) {
            return false;
         }
         if (symtab.read_to_text (symbol_index,value)) {
           
            quan::user_message (symtab.get_name (symbol_index));
            quan::user_message (" : ");
            //check the value
            // show sixe of value .get
            const char* v = value.get();
            if ( !v){
               quan::user_message("read failed please report\n");
               return false;
            }
            if (strnlen(v,200) == 200){
               quan::user_message("read failed badly string long please report!\n");
               return false;
            }
            quan::user_message( value.get());
            quan::user_message ("\n");
            return true;
         } else {
            return quan::get_num_errors() == 0;
         }
      } else {
         const char* name = symtab.get_name (symbol_index);
         if (name){
            quan::user_message(name);
            quan::user_message(" : #undef#\n");
         }else{
            quan::user_error("symbol not found");
         }
         return true;
      }
   }

   bool show_symbols (quan::dynarray<char> const & opt_symbol)
   {
      auto const & symtab = quan::stm32::flash::get_app_symbol_table();
      if (strlen (opt_symbol.get()) > 0) {
         int32_t symbol_index = symtab.get_index (opt_symbol);
         if (symbol_index == -1) {
            quan::user_error ("symbol not found");
            return true;
         } else {
            quan::user_message("\n");
            return local_show_symbol (symbol_index);
         }
      } else {
         quan::user_message ("\n------flash symbols-------\n");
         for (uint16_t i = 0; i < symtab.get_symtable_size(); ++i) {
            if (! local_show_symbol (i)) {
               return false;
            }
         }
         quan::user_message ("--------------------------\n");
         return true;
      }
   }
    
   bool help (quan::dynarray<char> const &);
   bool info (quan::dynarray<char> const & command_in);
   bool command_exit (quan::dynarray<char> const &);
    
   struct command {
      const char* const name;
      bool (*function) (quan::dynarray<char> const &);
      const char * info;
   };
    
   command command_array [] =
   {
      {"help",help,  "help [<opt_command>] : list available commands or opt_command info if specified."}
      ,{"info",info, "info [<opt symbol>] : show some info about the symbol or all if unspecified."}
      ,{"set", set_symbol_value, "set <symbol> <value> : set flash symbol to value."}
      ,{"show", show_symbols, "show [<opt_symbol>] : list all symbols or opt_symbol if specified."}
      ,{"exit", command_exit, "exit : exit this level."}
   };

   bool local_show_info(int32_t symbol_index)
   {    
      if (symbol_index != -1 ) {
         auto const & symtab = quan::stm32::flash::get_app_symbol_table();
         quan::user_message(symtab.get_name(symbol_index));
         quan::user_message(" : ");
         quan::user_message(symtab.get_info(symbol_index));
         quan::user_message("\n"); 
      }else{
         quan::user_error("symbol not found");
      }
      return true;
   }

   bool info (quan::dynarray<char> const & cmd_in)
   {
      quan::user_message("\n");
      auto const & symtab = quan::stm32::flash::get_app_symbol_table();
      if (cmd_in.get() && strlen (cmd_in.get()) > 0) {
         const char* symbol = strtok (cmd_in.get()," \t");
         if ( symbol){
            int32_t symbol_index = symtab.get_index(symbol);
            return local_show_info(symbol_index);
         }else{
             quan::user_error("expected symbol name");
         }
      }else{
         
         for ( int32_t i = 0; i < static_cast<int32_t>(symtab.get_symtable_size()); ++i){
            if ( ! local_show_info(i)){
               // shoulndt get here
               return false;
            }
         }
      }
      return true;
   }
    
   bool help (quan::dynarray<char> const & cmd_in)
   {
      if (strlen (cmd_in.get()) > 0) {
         bool found = false;
         for (auto const & cmd : command_array) {
            if (strcmp (cmd.name, cmd_in.get()) == 0) {
               found = true;
               quan::user_message (cmd.info);
               quan::user_message ("\n");
            }
         }
         if (found == false) {
            quan::user_error ("command not found");
         }
      } else {
         quan::user_message ("\n------available commands------\n");
         for (auto const & cmd : command_array) {
            quan::user_message (cmd.info);
            quan::user_message ("\n");
         }
         quan::user_message ("------------------------------\n");
      }
      return true;
   }
    
   bool command_exit (quan::dynarray<char> const & cmd_in)
   {
      quan::user_message ("\n >~~~~ bye :) ~~~~>\n");
      return true;
   }
}// namespace 
 
//return false if bad error(e.g out of memory etc)
bool quan::stm32::flash::flash_menu()
{
   for (;;) {
      quan::user_message ("\n");
      char buffer[110];
      int32_t idx = 0;
      // read user input to buffer
      while (1) {
         if (quan::user_in_avail()) {
            char ch = quan::user_get();
            if (ch == '\r') { // could add ret?
               buffer[idx] = '\0';
               ++idx;
               break;   // got a user string
            } else {
               if (idx > 99) {
                  quan::user_error ("input too long");
                  idx = 0;
               } else {
                  // check for valid chars, backspace etc
                  if ((ch >= ' ') && ( ch <= '~') ){
                     // ch >= space && ch <= 
                     buffer[idx] = ch;
                     ++idx;
                  }else{
                     if ( ch == '\b'){ // have a go at backspace!
                        if ( idx > 0){
                           --idx;
                        }
                     }
                     // otherwise ignore
                  }
               }
            }
         }
      }
      if (idx > 1) { // got input (1 is just a return)
         quan::dynarray<char> str1 (idx,quan::stm32::flash::symbol_table::on_malloc_failed);
         if (!str1.good()) {
            return false;
         }
         strcpy (str1.get(),buffer);
         const char* cmd_in = strtok (str1.get()," \t");
         const char* rest = strtok (nullptr,"");
         if ( (cmd_in != nullptr)) {
            bool command_found = false;
            for (command const & cmd : command_array) {
               if (strcmp (cmd_in, cmd.name) == 0) {
                  command_found = true;
                  quan::dynarray<char> rest_out {1,quan::stm32::flash::symbol_table::on_malloc_failed};
                  if (!rest_out.good()) {
                     return false;
                  }
                  *rest_out.get() = '\0';
                  if (rest) {
                     if (! rest_out.realloc (strlen (rest) + 1, 
                        quan::stm32::flash::symbol_table::on_malloc_failed)) {
                        return false;
                     }
                     strcpy (rest_out.get(),rest);
                  }
                  if (! cmd.function (rest_out)) {
                     return false;
                  }
               }
            }
            if (command_found == false) {
               quan::user_error ("command not found\n");
            } else {
               if (strcmp (cmd_in,"exit") == 0) {
                  return true;
               } else {
                  continue;
               }
            }
         }
      }
   }
   return true;
}
