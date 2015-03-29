#ifndef QUAN_STM32_FLASH_CONVERT_VECT3F_HPP_INCLUDED
#define QUAN_STM32_FLASH_CONVERT_VECT3F_HPP_INCLUDED

#include <cstring>
#include <cstdio>
#include <quan/user.hpp>
#include <quan/dynarray.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/conversion/float_convert.hpp>
#include <quan/conversion/float_to_ascii.hpp>
#include <quan/stm32/flash.hpp>
#include <quan/stm32/flash/flash_convert.hpp>
#include <quan/stm32/flash/flash_error.hpp>
#include <quan/stm32/flash/flash_convert/vect3T.hpp>

namespace quan{ namespace stm32{ namespace flash{

   template <> struct text_convert<quan::three_d::vect<float> > {
      static bool text_to_type(quan::dynarray<char> const & text_in, void* value_out)
      {
         return quan::stm32::flash::detail::text_convert_impl<
               quan::three_d::vect<float> >::text_to_type(text_in,value_out);
      }

      static bool type_to_text(const void* value_in, quan::dynarray<char> & text_out)
      {
         if ( ! value_in) return false;
         char buf[100];
         // convert to typed value in
         quan::three_d::vect<float> const * tvi = (quan::three_d::vect<float> const*) value_in;
         int const result = sprintf (buf,"[%.3f,%.3f,%.3f]",
               static_cast<double>(tvi->x),
                  static_cast<double>(tvi->y),
                     static_cast<double>(tvi->z));
         if ( (result <= 0) || (result >= 100)) {
            quan::error(fn_rep_to_cstring_Vect3F, quan::detail::bad_float_range);
            return false;
         }
         if (!text_out.realloc (result+1)) {
            symbol_table::on_malloc_failed();
            return false;
         }
         strcpy (text_out.get(), buf);
         return true;
      }
   }; // struct

      // requires implementation by the application
   template<> struct get_flash_typeid_impl<quan::three_d::vect<float> > 
   { static uint32_t apply();};

}}} // quan::stm32::flash

#endif // QUAN_STM32_FLASH_CONVERT_VECT3F_HPP_INCLUDED
