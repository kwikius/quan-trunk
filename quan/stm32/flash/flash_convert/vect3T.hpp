#ifndef QUAN_STM32_FLASH_FLASH_CONVERT_VECT3T_HPP_INCLUDED
#define QUAN_STM32_FLASH_FLASH_CONVERT_VECT3T_HPP_INCLUDED


#include <cstring>
#include <cstdio>
#include <quan/user.hpp>
#include <quan/dynarray.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/convert.hpp>
#include <quan/conversion/float_convert.hpp>
#include <quan/conversion/int_convert.hpp>
#include <quan/stm32/flash.hpp>
#include <quan/stm32/flash/flash_convert.hpp>
#include <quan/stm32/flash/flash_error.hpp>
#if defined QUAN_FLASH_DEBUG
#include <iostream>
#endif

namespace quan{ namespace stm32{ namespace flash{ namespace detail{

   template <typename T> struct text_convert_impl;

   template <typename T> struct text_convert_impl<quan::three_d::vect<T> > {
      private:
      static const char* get_input_template() { return "expected [value,value,value]";}
      public:
      static bool text_to_type(quan::dynarray<char> const & text_in, void* value_out)
      {
         if ( !value_out){
#if defined QUAN_FLASH_DEBUG
    std::cout << "(1) unexpected nullptr\n";
#endif
            quan::error(fn_any, quan::detail::unexpected_nullptr);
            return false;
         }
         if ( text_in.get() == nullptr){
#if defined QUAN_FLASH_DEBUG
    std::cout << "(2) unexpected nullptr\n";
#endif
            quan::error(fn_any, quan::detail::unexpected_nullptr);
            return false;
         }
         size_t length = text_in.get_num_elements();
         if ((text_in.get_num_elements() < 7)  ) {
#if defined QUAN_FLASH_DEBUG
    std::cout << text_in.get_num_elements() << " : (3) too few elements\n";
#endif
            user_error(get_input_template());
            return false;
         }
         if ( *(text_in.get() + (length-1)) != '\0'){
#if defined QUAN_FLASH_DEBUG
    std::cout << "(4) unterminated string constant\n";
#endif
            quan::error(fn_any,quan::detail::unterminated_string_constant);
            return false;
         }

      // copy text_in 
         quan::dynarray<char> src {text_in.get_num_elements(),symbol_table::on_malloc_failed};
         if (! src.good()) {
            // should have reported
#if defined QUAN_FLASH_DEBUG
    std::cout << "(5) bad dynarray\n";
#endif
            return false;
         }
         memcpy (src.get(),text_in.get(),text_in.get_num_elements());

         const char* ptr = src.get();
         while ( isspace(*ptr) ){
            ++ptr;
         }
         if ( *ptr != '['){
#if defined QUAN_FLASH_DEBUG
    std::cout << "(6) expected [\n";
#endif
            user_error(get_input_template());
            return false;
         }
         const char delims[] = {',',',',']'};
         quan::three_d::vect<T> temp;
         for (size_t i = 0; i < 3; ++i) {
            if (*(++ptr) == '\0'){
#if defined QUAN_FLASH_DEBUG
    std::cout << "(7) unexpected end of input\n";
#endif
               user_error(get_input_template());
               return false;
            }
            quan::detail::converter<T, char*> conv;
            temp[i] = conv(ptr);
            if (conv.get_errno() == 0) {
               ptr += conv.get_parse_length();
               while ( isspace(*ptr)){
                  ++ptr;
               }
               if ( *ptr == delims[i] ){
                   continue;
               }else{
                  user_message("parse failed");
                  if (*ptr != '\0'){
                     user_message(" at \"");
                     user_error(ptr);
                     user_message("\"\n");
                  }else{
                     user_message("\n");
                  }
                  user_error(get_input_template());
                  return false;
               }
            }else{
               user_error("failed to parse values");
               return false;
            }
         }
         quan::three_d::vect<T>* typed_value_out = (quan::three_d::vect<T> *)value_out;
         *typed_value_out = temp;
         return true;
      }
    };

}}}} // quan::stm32::flash::detail



#endif // QUAN_STM32_FLASH_FLASH_CONVERT_VECT3T_HPP_INCLUDED
