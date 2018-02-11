#ifndef QUAN_CONVERSION_DOUBLE_CONVERT_HPP_INCLUDED
#define QUAN_CONVERSION_DOUBLE_CONVERT_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

#include <quan/convert.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <climits>
#include <cstdint>
#include <cctype>
#else
#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <ctype.h>
#endif

#include <quan/conversion/basic_char_ptr_converter.hpp>

 // define QUAN_DETAIL_FLOAT_CONVERT_DEBUG

namespace quan{ namespace detail{

	template<> struct converter <double, char*> : basic_char_ptr_converter
   {
     
     private:
      enum class float_tok{ DIGIT,EXP,SIGN,POINT,END,UNKNOWN};

		static float_tok get_tok(char ch)
		{
			if ((ch >= '0') && (ch <= '9')){
				return float_tok::DIGIT;
			}
			switch (ch){
			case '.':
			  return float_tok::POINT;
			case 'E':
			case 'e':
				return float_tok::EXP;
			case '+':
			case '-':
				return float_tok::SIGN;
			case '\0':
				return float_tok::END;
			default:
				return float_tok::UNKNOWN;
			}
		}

  public:

		double operator()(const char* str, long maxlen = LONG_MAX )
		{
          reset();
          m_conversion_error=0;
			 int length = strnlen(str, maxlen); // length - terminating0
          if ( length < 1){
            m_conversion_error = -1 ; 
        #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
            std::cout << "invalid string length 1\n";
        #endif
				return 0.0f;
          }
			 int sign = 1;
			 size_t pos = 0;
			 double result = 0;
          while(isspace(str[pos])){
            ++pos;
            --length;
          }
          if ( length < 1){
            m_conversion_error = -1 ; // invalid string length
         #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
            std::cout << "invalid string length 2\n";
         #endif
				return 0.0f;
			 }
			 auto curtok = get_tok(str[pos]);
			 if (curtok == float_tok::SIGN){
            if ( length < 2){
               m_conversion_error = -1;
            #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
               std::cout << "invalid string length 3\n";
            #endif
               return 0.0f;
            }
            if (str[pos] == '-' ){
					sign = -1;
				}
				curtok = get_tok(str[++pos]);
			 }
          // startpos to chek digits
          uint32_t before_digit_count=0;
          uint32_t after_digit_count = 0;
			 while (curtok == float_tok::DIGIT){
              if (++before_digit_count > 20){
                 m_conversion_error = -1 ; // too many digits
                  #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
                  std::cout << "too many digits\n";
                  #endif
				     return 0.0f;
              }
				  result = result * 10.f + atoi(str[pos]);
				  curtok = get_tok(str[++pos]);
			 }
			 
			 if (curtok == float_tok::POINT){
				 curtok = get_tok(str[++pos]);  
				 if ( curtok == float_tok::DIGIT){
					uint64_t divisor = 1;
					uint64_t ifract = 0;
					while ( (curtok == float_tok::DIGIT) && (++ after_digit_count < 20) ){
						ifract = ifract * 10 + atoi(str[pos]);
						curtok = get_tok(str[++pos]);
						divisor *= 10;
					}
					result += static_cast<double>(ifract)/divisor;
				 } else{ // no after digits
					 if ( before_digit_count == 0){ // means that point was first and no digits after-- illegal
						  m_conversion_error= -1;
                    #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
                    std::cout << "illegal point\n";
                    #endif
						  return 0.0f;
					 }
				 }
			 }
			 if (curtok == float_tok::EXP){
            if ((before_digit_count ==0) && ( after_digit_count == 0)){
                  m_conversion_error= -1;
                  #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
                  std::cout << "illegal exp\n";
                  #endif
						return 0.0f;
            }
				int64_t exp_val = 0;
				int powsign = 1;
				int pow_count = 0;
				curtok = get_tok(str[++pos]);  
				if ( curtok == float_tok::SIGN){
					if (str[pos] == '-'){
						 powsign = -1;
					}
					curtok = get_tok(str[++pos]);  
				}
				while (curtok == float_tok::DIGIT){
					if (++pow_count == 20){
						m_conversion_error= -1;
                  #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
                  std::cout << "too many digits in pow\n";
                  #endif
						return 0.0f;
					}
					exp_val = exp_val * 10 + atoi(str[pos]);
					curtok = get_tok(str[++pos]);
				}
				double power = 1;
				while (exp_val-- > 0){
					power *= 10;
				}
				if ( powsign == 1){
					result *= power;
				}else{
					result /= power;
				}
			 }
          if ( pos == 0){
             #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
             std::cout << "no value\n";
            #endif
             m_conversion_error= -1;
			    return 0.0f;
          }
          m_parse_length = pos;
			 return( sign == 1)?result : -result;
		}

     };
}}

#endif // QUAN_CONVERSION_DOUBLE_CONVERT_HPP_INCLUDED
