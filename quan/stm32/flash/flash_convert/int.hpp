#ifndef QUAN_STM32_FLASH_CONVERT_INT_HPP_INCLUDED
#define QUAN_STM32_FLASH_CONVERT_INT_HPP_INCLUDED

#include <cstring>
#include <cstdio>
#include <quan/dynarray.hpp>
#include <quan/user.hpp>
#include <quan/conversion/int_convert.hpp>
#include <quan/stm32/flash.hpp>
#include <quan/stm32/flash/flash_convert.hpp>
#include <quan/stm32/flash/flash_error.hpp>

namespace quan{ namespace stm32{ namespace flash{

    namespace detail{
       template <typename IntType> struct text_convert_int{
         private:
         static const char* get_input_template() { return "expected integer";}
         public:
         static bool text_to_type(quan::dynarray<char> const & text_in, void* value_out)
         {
            if ( !value_out){
               quan::error(fn_any, quan::detail::unexpected_nullptr);
               return false;
            }
            IntType * typed_value_out = (IntType*) value_out;

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
            quan::detail::converter<IntType,char*> conv;
            IntType result = conv(text_in.get());
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
            if ( ! value_in) {
               quan::error(fn_any, quan::detail::unexpected_nullptr);
               return false;
            }
            IntType const * typed_value_in = (const IntType*) value_in;
            char buf [100];
            int val = static_cast<int>(*typed_value_in);
            int const result = sprintf(buf,"%i",val);
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
      } // detail

      template <> struct text_convert<int8_t> 
         : quan::stm32::flash::detail::text_convert_int<int8_t>{};

      template <> struct text_convert<int16_t> 
         : quan::stm32::flash::detail::text_convert_int<int16_t>{};

     template <> struct text_convert<int32_t> 
         : quan::stm32::flash::detail::text_convert_int<int32_t>{};

     template <> struct text_convert<uint8_t> 
         : quan::stm32::flash::detail::text_convert_int<uint8_t>{};

     template <> struct text_convert<uint16_t> 
         : quan::stm32::flash::detail::text_convert_int<uint16_t>{};

     template <> struct text_convert<uint32_t> 
         : quan::stm32::flash::detail::text_convert_int<uint32_t>{};

         // apply requires implementation by the app
    // to return the id for the type

   template<> struct get_flash_typeid_impl<int8_t> 
   { static uint32_t apply();};
      template<> struct get_flash_typeid_impl<int16_t> 
   { static uint32_t apply();};
      template<> struct get_flash_typeid_impl<int32_t> 
   { static uint32_t apply();};
      template<> struct get_flash_typeid_impl<uint8_t> 
   { static uint32_t apply();};
      template<> struct get_flash_typeid_impl<uint16_t> 
   { static uint32_t apply();};
      template<> struct get_flash_typeid_impl<uint32_t> 
   { static uint32_t apply();};

     // n.b none for int64_t/uint64_t due to range issues ( would need separate impl)
}}}

#endif // QUAN_STM32_FLASH_CONVERT_INT_HPP_INCLUDED
