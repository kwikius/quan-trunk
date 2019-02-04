#ifndef QUAN_CONVERSION_INT_CONVERT_HPP_INCLUDED
#define QUAN_CONVERSION_INT_CONVERT_HPP_INCLUDED

#include <cctype>
#include <cstdint>
#include <cstring>
#include <quan/meta/integer_max.hpp>
#include <quan/meta/integer_min.hpp>
#include <quan/convert.hpp>
#include <quan/conversion/basic_char_ptr_converter.hpp>

/*
# space  ' \t'
# digit   '0'..'9'
# sign   '+-'
# anything_else  ^ (space | digit | sign)  
Int = space* sign? digit+
*/

namespace quan{ namespace detail{

   template <typename IntType>
   struct int_from_char_ptr_converter : basic_char_ptr_converter
   {
   private:
      enum class int_tok{ DIGIT,SIGN,ANYTHINGELSE};

      // tokeniser
      static int_tok get_tok (char ch)
      {
         if ((ch >= '0') && (ch <= '9')){
            return int_tok::DIGIT;
         }
         if (( ch == '+' ) || ( ch == '-')){
            return int_tok::SIGN;
         }
         return int_tok::ANYTHINGELSE;
      }

   public:
      IntType operator()(const char* str, size_t maxlen = 100U)
      {
          reset();  // reset error and parse idxs
           
          int length = strnlen(str,maxlen); 
          if ( length < 1){
            m_conversion_error = -1;
          //  std::cout << length << " expected integer 1\n";
            return 0;
          }
          int sign = 1;
          uint32_t pos = 0U;
          while ( isspace(str[pos])){
             ++pos;
            --length;
          }
          if ( length < 1){
           //  std::cout << "expected integer 2\n";
             m_conversion_error = -1;
            return 0;
          }
          auto curtok = get_tok(str[pos]);
          if (curtok == int_tok::SIGN){
            if (str[pos] =='-'){
               sign = -1;
            }
            curtok = get_tok(str[++pos]);
          }
          int numdigits = 0;
          int64_t result = 0;
          while( curtok == int_tok::DIGIT){
            if (  ++numdigits > 10){
               // std::cout << "too many digits\n";
               m_conversion_error = -1;
               return 0;
            }
            result = result * 10 + atoi(str[pos]);
            curtok = get_tok(str[++pos]);
          }
          if ( numdigits == 0){
              // std::cout << "expected digits\n";
               m_conversion_error = -1;
               return 0;
          }
          if ( sign == 1) {
            if( result > quan::meta::integer_max<IntType>::value){
             //  std::cout << " bad range\n";
               m_conversion_error = -1;
               return 0;
            }
          }else{ 
            result *= -1;
            if( result < quan::meta::integer_min<IntType>::value){
            //   std::cout << " bad range\n";
               m_conversion_error = -1;
               return 0;
            }
          }
          m_parse_length = pos;
          return static_cast<IntType>(result);
      }
   };

   template<> struct converter <int32_t, char*> : int_from_char_ptr_converter<int32_t>{};
   template<> struct converter <int16_t, char*> : int_from_char_ptr_converter<int16_t>{};   
   template<> struct converter <int8_t, char*> : int_from_char_ptr_converter<int8_t>{}; 

   template<> struct converter <uint32_t, char*> : int_from_char_ptr_converter<uint32_t>{};
   template<> struct converter <uint16_t, char*> : int_from_char_ptr_converter<uint16_t>{};   
   template<> struct converter <uint8_t, char*> : int_from_char_ptr_converter<uint8_t>{}; 
}}




#endif // QUAN_CONVERSION_INT_CONVERT_HPP_INCLUDED
