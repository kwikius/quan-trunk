#ifndef QUAN_CONVERSION_BASIC_CHAR_PTR_CONVERTER_HPP_INCLUDED
#define QUAN_CONVERSION_BASIC_CHAR_PTR_CONVERTER_HPP_INCLUDED

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cstdint>
#else
#include <stdint.h>
#endif

/*
   conversion from a string to some type
   used as a base class for int and float converters
*/

namespace quan{ namespace detail{

   struct basic_char_ptr_converter{

       int get_errno()const {return m_conversion_error;}
       uint32_t get_parse_length() const { return m_parse_length;}

   protected:
      basic_char_ptr_converter():m_conversion_error{0}, m_parse_length{0}{}

      void reset()
      {
         m_conversion_error = 0;
         m_parse_length = 0;
      }

      static int atoi(char ch)
      {
         return ch - '0';
      }

      static int32_t strnlen( const char* str, int32_t maxlen)
      {
         if ( str){
            for (int32_t i =0; i < maxlen; ++i){
               if ( str[i] =='\0'){
                  return i;
                }
            }
         }
         return -1;
      }

      int m_conversion_error;
      uint32_t  m_parse_length;
   };

}} // quan::detail

#endif // QUAN_CONVERSION_BASIC_CHAR_PTR_CONVERTER_HPP_INCLUDED
