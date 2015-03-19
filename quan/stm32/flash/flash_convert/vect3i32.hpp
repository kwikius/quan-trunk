#ifndef QUAN_STM32_FLASH_CONVERT_VECT3I32_HPP_INCLUDED
#define QUAN_STM32_FLASH_CONVERT_VECT3I32_HPP_INCLUDED

#include <cstdint>
#include <cstring>
#include <cstdio>
#include <quan/dynarray.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/stm32/flash.hpp>
#include <quan/error.hpp>
#include <quan/stm32/flash/flash_convert.hpp>
#include <quan/stm32/flash/flash_error.hpp>

namespace quan{ namespace stm32{ namespace flash{

   template <> struct text_convert<quan::three_d::vect<int32_t> > {
      static bool text_to_type(quan::dynarray<char> const & text_in, void* value_out)
      {
         if (! value_out) return false;
         if ((text_in.get_num_elements() < 7) ||  (text_in.get() [0] != '[') ) {
            user_error("expected [int32,int32,int32]");
            return false;
         }
      // copy src_in else will be corrupted
         quan::dynarray<char> src {text_in.get_num_elements() -1,symbol_table::on_malloc_failed};
         if (! src.good()) {
            // has reported
            return false;
         }
         // copy but ignore leading '['
         memcpy (src.get(),text_in.get()+1,text_in.get_num_elements()-1); 
        
         const char* delims[] = {",",",","]"};
         quan::three_d::vect<int32_t> temp;
         for (size_t i = 0; i < 3; ++i) {
            char* sptr = (i==0) ? reinterpret_cast<char*> (src.get()):nullptr;
            char* intval = strtok (sptr,delims[i]);
            if (intval == nullptr) {
               user_error("expected [int32,int32,int32]");
               return false;
            }
            // may need additional checks here
            temp[i] = atoi(intval);
         }
         quan::three_d::vect<int32_t>* typed_value_out = (quan::three_d::vect<int32_t> *)value_out;
         *typed_value_out = temp;
         return true;
      }

      static bool type_to_text(const void* value_in, quan::dynarray<char> & text_out)
      {
         if ( ! value_in) return false;
         char buf[100];
         // convert to typed value in
         quan::three_d::vect<int32_t> const * tvi = (quan::three_d::vect<int32_t> const*) value_in;
         int const result = sprintf (buf,"[%i,%i,%i]"
            ,static_cast<int>(tvi->x)
            ,static_cast<int>(tvi->y)
            ,static_cast<int>(tvi->z));
         if ( (result <= 0) || (result >= 100)) {
            quan::error(fn_any, quan::detail::bad_int_range);
            return false;
         }
         if (!text_out.realloc (result)) {
            symbol_table::on_malloc_failed();
            return false;
         }
         strcpy (text_out.get(), buf);
         return true;
      }
   }; // struct

      // requires implementation by the application
   template<> struct get_flash_typeid_impl<quan::three_d::vect<int32_t> > 
   { static uint32_t apply();};

}}} // quan::stm32::flash

#endif // QUAN_STM32_FLASH_CONVERT_VECT3I32_HPP_INCLUDED
