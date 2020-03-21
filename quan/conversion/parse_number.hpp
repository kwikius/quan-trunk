#ifndef QUAN_CONVERSION_FLOAT_CONVERT_HPP_INCLUDED
#define QUAN_CONVERSION_FLOAT_CONVERT_HPP_INCLUDED
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

namespace quan{ namespace detail{

	struct number_parser : basic_char_ptr_converter
   {
      enum class num_tok{ DIGIT,EXP,SIGN,POINT,END,UNKNOWN};
      enum class num_type {UNKNOWN, FLOAT, INT };

		static num_tok get_tok(char ch)
		{
			if ((ch >= '0') && (ch <= '9')){
				return num_tok::DIGIT;
			}
			switch (ch){
			case '.':
			  return num_tok::POINT;
			case 'E':
			case 'e':
				return num_tok::EXP;
			case '+':
			case '-':
				return num_tok::SIGN;
			case '\0':
				return num_tok::END;
			default:
				return num_tok::UNKNOWN;
			}
		}
      
		num_type operator()(const char* str,  double * double_result, int64_t * int_result,long maxlen = LONG_MAX )
		{
// state1
          reset();
          //holder for result
          union{
            int64_t int_value;
            double float_value;
          }u;
          u.int_value = 0;
          u.float_value = 0.0;
          num_type number_type = num_type::INT;
          m_conversion_error=0;
			 int length = strnlen(str, maxlen); // length - terminating0
          
          if ( length < 1){
            m_conversion_error = -1 ; 
        #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
            std::cout << "invalid string length 1\n";
        #endif
				return num_type::UNKNOWN;
          }
			 int sign = 1;
          int pos = 0;
			// float result = 0;
          while(isspace(str[pos])){
            ++pos;
            --length;
          }
          if ( length < 1){
            m_conversion_error = -1 ; // invalid string length
         #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
            std::cout << "invalid string length 2\n";
         #endif
				return num_type::UNKNOWN;
			 }
			 auto curtok = get_tok(str[pos]);
			 if (curtok == num_tok::SIGN){
            if ( length < 2){
               m_conversion_error = -1;
            #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
               std::cout << "invalid string length 3\n";
            #endif
               return num_type::UNKNOWN;
            }
            if (str[pos] == '-' ){
					sign = -1;
				}
				curtok = get_tok(str[++pos]);
			 }
          // startpos to chek digits
          uint32_t before_digit_count=0;
          uint32_t after_digit_count = 0;
          
			 while (curtok == num_tok::DIGIT){

              if (++before_digit_count > 20){
                 m_conversion_error = -1 ; // too many digits
                  #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
                  std::cout << "too many digits\n";
                  #endif
				     return num_type::UNKNOWN;
              }
				  u.int_value = u.int_value * 10 + atoi(str[pos]);
				  curtok = get_tok(str[++pos]);
			 }
			 
			 if (curtok == num_tok::POINT){
             number_type = num_type::FLOAT;
             u.float_value = u.int_value;
				 curtok = get_tok(str[++pos]);  
				 if ( curtok == num_tok::DIGIT){
					uint64_t divisor = 1;
					uint64_t ifract = 0;
					while ( (curtok == num_tok::DIGIT) && (++ after_digit_count < 20) ){
						ifract = ifract * 10 + atoi(str[pos]);
						curtok = get_tok(str[++pos]);
						divisor *= 10;
					}
					u.float_value += static_cast<double>(ifract)/divisor;
				 } else{ // no after digits
					 if ( before_digit_count == 0){ // means that point was first and no digits after-- illegal
						  m_conversion_error= -1;
                    #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
                    std::cout << "illegal point\n";
                    #endif
						  return num_type::UNKNOWN;
					 }
				 }
			 }
			 if (curtok == num_tok::EXP){
            if (  number_type == num_type::INT){
               u.float_value = u.int_value;
               number_type = num_type::FLOAT;
            }
            
            if ((before_digit_count ==0) && ( after_digit_count == 0)){
                  m_conversion_error= -1;
                  #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
                  std::cout << "illegal exp\n";
                  #endif
						return num_type::UNKNOWN;
            }
				int64_t exp_val = 0;
				int powsign = 1;
				int pow_count = 0;
				curtok = get_tok(str[++pos]);  
				if ( curtok == num_tok::SIGN){
					if (str[pos] == '-'){
						 powsign = -1;
					}
					curtok = get_tok(str[++pos]);  
				}
				while (curtok == num_tok::DIGIT){
					if (++pow_count == 20){
						m_conversion_error= -1;
                  #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
                  std::cout << "too many digits in pow\n";
                  #endif
						return num_type::UNKNOWN;
					}
					exp_val = exp_val * 10 + atoi(str[pos]);
					curtok = get_tok(str[++pos]);
				}
				double power = 1;
				while (exp_val-- > 0){
					power *= 10;
				}
				if ( powsign == 1){
					u.float_value *= power;
				}else{
					u.float_value /= power;
				}
			 }
          if ( pos == 0){
             #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
             std::cout << "no value\n";
            #endif
             m_conversion_error= -1;
			    return num_type::UNKNOWN;
          }
          m_parse_length = pos;
          if ( curtok != num_tok::END){
          #if defined (QUAN_DETAIL_FLOAT_CONVERT_DEBUG)
             std::cout << "unexpected token\n";
            #endif
             return num_type::UNKNOWN;
          }
          if (  number_type == num_type::FLOAT){
              if ( sign == -1){
                 *double_result = -u.float_value;
              }else{
                  *double_result = u.float_value;
              }
              return num_type::FLOAT;
          }else{
              if ( sign == -1){
                 *int_result = -u.int_value;
              }else{
                  *int_result = u.int_value;
              }
              return num_type::INT;
          }
			 
		}

     };
}}

#endif // QUAN_CONVERSION_FLOAT_CONVERT_HPP_INCLUDED
