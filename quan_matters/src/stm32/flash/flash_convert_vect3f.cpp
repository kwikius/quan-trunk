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
#include <quan/three_d/vect.hpp>
#include <quan/dynarray.hpp>
#include <quan/conversion/float_convert.hpp>
#include <quan/conversion/float_to_ascii.hpp>
#include <quan/error.hpp>
#include <quan/stm32/flash.hpp>
#include <quan/stm32/flash/flash_convert/vect3f.hpp>
#include <quan/stm32/flash/flash_error.hpp>

/*
  flash type conversion functions for vect3f
  text to bytestream converts from user representation to the flash memory representation
  bytestream_to_text converts from flash memory representation to user comprehensible string

  user rep is "[float,float,float]"
  flash rep is  a sequence of 3 floats, for the x,y,z values
*/

/*
namespace{
    const char expected_float[] = "expected [float,float,float]";
}

  template <> struct text_convert<quan::three_d::vect<float> > {
   bool text_to_type(quan::dynarray<char> const & text_in, void* value_out)
   {

      if ((text_in.get_num_elements() < 7) ||  (text_in.get() [0] != '[') ) {
         user_error(expected_float);
         return false;
      }
   // copy src_in else will be corrupted
      quan::dynarray<char> src {text_in.get_num_elements() -1,main_alloc_failed};
      if (! src.good()) {
         // has reported
         return false;
      }
      // copy but ignore leading '['
      memcpy (src.get(),text_in.get()+1,text_in.get_num_elements()-1); 
     

      const char* delims[] = {",",",","]"};
      quan::three_d::vect<float> temp;
      // user_message("in mag string conv...\n");
      for (size_t i = 0; i < 3; ++i) {
         char* sptr = (i==0) ? reinterpret_cast<char*> (src.get()):nullptr;
         char* f = strtok (sptr,delims[i]);
         if (f == nullptr) {
            user_error(expected_float);
            return false;
         }
         quan::detail::converter<float, char*> fconv;
         temp[i] = fconv (f);
         if (fconv.get_errno()) {
            user_error("invalid float");
            return false;
         }
      }
      quan::three_d::vect<float>* typed_value_out = (quan::three_d::vect<float>*)value_out;
      *typed_value_out = temp;
      return true;
   }

   bool type_to_text(const void* value_in, quan::dynarray<char> & text_out)
   {
      char buf[100];
      int const result = sprintf (buf,"[%.3f,%.3f,%.3f]",conv.val[0],conv.val[1],conv.val[2]);
      if ( (result <= 0) || (result >= 100)) {
         quan::error(fn_rep_to_cstring_Vect3F, quan::detail::bad_float_range);
         return false;
      }
      if (!text_out.realloc (result)) {
         main_alloc_failed();
         return false;
      }
      strcpy (text_out.get(), buf);
      return true;
   }
}; // struct

/*
   // set symbol name in flash to runtime value
   bool quan::stm32::flash::flash_convert<quan::three_d::vect<float> >::set 
      (const char* symbol_name, quan::three_d::vect<float> const & value)
   {
      // add check on type
      // add check on range
      auto const & symtab = get_app_symbol_table();
      int32_t const sym_index = symtab.get_index (symbol_name);
      if (sym_index == -1) {
            // shouldnt get here
         return false;
      }
      union {
         uint8_t ar[sizeof (float) * 3];
         float vals[3];
      } uconv;
      for (uint8_t i = 0U; i < 3U; ++i) {
            uconv.vals[i] = value[i];
      }
      quan::dynarray<uint8_t> bytestream {sizeof (float) * 3, main_alloc_failed};
      if (!bytestream.good()) {
         return false;
      }
      memcpy (bytestream.get(), uconv.ar, sizeof (float) * 3);
      return symtab.write_symbol(sym_index, bytestream);
      
   }
   
   // read symbol name in flash to runtime value
   bool quan::stm32::flash::flash_convert<quan::three_d::vect<float> >::get 
      (const char* symbol_name, quan::three_d::vect<float> & dest)
   {
      // get string from flash
      auto const & symtab = get_app_symbol_table();
      int32_t const sym_index = symtab.get_index (symbol_name);
      if (sym_index == -1) {
            // shouldnt get here
            return false;
         }
      uint32_t const length = symtab.get_symbol_storage_size(sym_index);
      quan::dynarray<uint8_t> bytestream {length, main_alloc_failed};
      if (!bytestream.good()) {
         return false;
      }
      if (!symtab.read_symbol(sym_index, bytestream)) {
         return false;
      }

      union {
         uint8_t ar[sizeof (float) * 3];
         float vals[3];
      } uconv;
      
      memcpy (uconv.ar, bytestream.get(), length);
      for (uint8_t i = 0; i < 3U; ++i) {
            dest[i] = uconv.vals[i];
         }
      return true;
   }


// convert user text to a bytestream
bool quan::stm32::flash::flash_convert<quan::three_d::vect<float> >::text_to_bytestream(
      quan::dynarray<uint8_t>& dest, quan::dynarray<char> const & src_in
      , bool (*pfn_check)(void* value))
{
   if ((src_in.get_num_elements() < 7) ||  (src_in.get() [0] != '[') ) {
      user_error(expected_float);
      return false;
   }
// copy src_in else will be corrupted
   quan::dynarray<char> src {src_in.get_num_elements() -1,main_alloc_failed};
   if (! src.good()) {
      // has reported
      return false;
   }
   // ignore leading '['
   memcpy (src.get(),src_in.get()+1,src_in.get_num_elements()-1); 
   union {
      uint8_t ar[sizeof (float) * 3];
      float vals[3];
   } uconv;
   
   const char* delims[] = {",",",","]"};

   // user_message("in mag string conv...\n");
   for (size_t i = 0; i < 3; ++i) {
      char* sptr = (i==0) ? reinterpret_cast<char*> (src.get()):nullptr;
      char* f = strtok (sptr,delims[i]);
      if (f == nullptr) {
         user_error(expected_float);
         return false;
      }
      quan::detail::converter<float, char*> fconv;
      uconv.vals[i] = fconv (f);
      if (fconv.get_errno()) {
         user_error("invalid float");
         return false;
      }
   }
   //####### validate the result with callback
   quan::three_d::vect<float> check_val{uconv.vals[0],uconv.vals[1],uconv.vals[2]};
   if ( ! pfn_check((void*)&check_val) ){
      return false;
   }
   //##############################################
   if (!dest.realloc (sizeof (float) * 3)) {
      main_alloc_failed();
      return false;
   }
   memcpy (dest.get(),uconv.ar,sizeof (float) * 3);
   return true;
}

// a sequence of 3 floats
bool quan::stm32::flash::flash_convert<quan::three_d::vect<float> >::bytestream_to_text(
      quan::dynarray<char>& dest, quan::dynarray<uint8_t> const & src)
{
   if (src.get_num_elements() != sizeof (float) *3) {
      quan::error(fn_rep_to_cstring_Vect3F,
            quan::detail::stm32_flash_page_corrupted);
      return false;
   }
   
   union {
      uint8_t ar[sizeof (float) *3];
      float val[3];
   } conv;
   memcpy(conv.ar,src.get(),sizeof (float) *3);

   char buf[100];

   int const result = sprintf (buf,"[%.3f,%.3f,%.3f]",conv.val[0],conv.val[1],conv.val[2]);
   if ( (result <= 0) || (result >= 100)) {
      quan::error(fn_rep_to_cstring_Vect3F, quan::detail::bad_float_range);
      return false;
   }
  
   if (!dest.realloc (result)) {
      main_alloc_failed();
      return false;
   }
   strcpy (dest.get(), buf);
   return true;
}
*/
