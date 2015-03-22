#ifndef QUAN_STM32_FLASH_CONVERT_BOOL_HPP_INCLUDED
#define QUAN_STM32_FLASH_CONVERT_BOOL_HPP_INCLUDED

#include <cstring>
#include <cstdio>
#include <quan/dynarray.hpp>
#include <quan/user.hpp>
#include <quan/stm32/flash.hpp>
#include <quan/stm32/flash/flash_convert.hpp>
#include <quan/stm32/flash/flash_error.hpp>

namespace quan{ namespace stm32{ namespace flash{

    // apply requires implementation by the app
    // to return the id for the type
    template<> struct get_flash_typeid_impl<bool> 
    { static uint32_t apply();};

    template <> struct text_convert<bool>{

      static bool text_to_type(quan::dynarray<char> const & text_in, void* value_out)
      {
         if ( ! value_out) return false;
         bool * typed_value_out = (bool*) value_out;
         if (text_in.get_num_elements() == 5) {
            if ( strcmp(text_in.get(),"true") == 0 ) {
               *typed_value_out = true;
               return true;
            } else {
               user_error("expected \"true\" or \"false\"");
               return false;
            }
         } else {
            if ( (text_in.get_num_elements() == 6) && ( strcmp(text_in.get(),"false") == 0 ) ) {
               *typed_value_out = false;
               return true;
            } else {
               user_error("expected \"true\" or \"false\"");
               return false;
            }
         }
      }

      static bool type_to_text(const void* value_in, quan::dynarray<char> & text_out)
      {
         if ( ! value_in) return false;
         bool const * typed_value_in = (const bool*) value_in;
         if ( *typed_value_in == true){
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
         symbol_table::on_malloc_failed();
         return false;
      }
   }; 

}}}

#endif // QUAN_STM32_FLASH_CONVERT_BOOL_HPP_INCLUDED
