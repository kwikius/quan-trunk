#ifndef QUAN_STM32_FLASH_CONVERT_FLOAT_HPP_INCLUDED
#define QUAN_STM32_FLASH_CONVERT_FLOAT_HPP_INCLUDED

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
    template<> struct get_flash_typeid_impl<float> 
    { static uint32_t apply();};

    template <> struct text_convert<float>{

      private:
             static const char* get_input_template() { return "expected float";}
      public:

      static bool text_to_type(quan::dynarray<char> const & text_in, void* value_out)
      {
          if ( ! value_out) return false;
          float * typed_value_out = (float*) value_out;
          if ( text_in.get() == nullptr){
               quan::error(fn_any, quan::detail::unexpected_nullptr);
               return false;
            }
            size_t length = text_in.get_num_elements();
            if ((text_in.get_num_elements() < 2)  ) {
               user_error(get_input_template());
               return false;
            }
            if ( *(text_in.get() + (length-1)) != '\0'){
               quan::error(fn_any,quan::detail::unterminated_string_constant);
               return false;
            }
            quan::detail::converter<float,char*> conv;
            float result = conv(text_in.get());
            if (conv.get_errno() == 0) {
               *typed_value_out = result;
               return true;
            }else{
               user_error(get_input_template());
               return false;
            }
      }

      static bool type_to_text(const void* value_in, quan::dynarray<char> & text_out)
      {
         if ( ! value_in) return false;
         float const * typed_value_in = (const float*) value_in;
         char buf [100];
         float val = static_cast<float>(*typed_value_in);
         int const result = sprintf(buf,"%f",static_cast<double>(val));
         if ( (result <= 0) || (result >= 100)) {
            quan::error(fn_any, quan::detail::bad_int_range);
            return false;
         }
         if (!text_out.realloc (result +1)) {
            symbol_table::on_malloc_failed();
            return false;
         }
         strcpy (text_out.get(), buf);
         return true;
      }
   }; 

}}}

#endif // QUAN_STM32_FLASH_CONVERT_FLOAT_HPP_INCLUDED
