#ifndef QUAN_CONVERSION_FLOAT_CONVERT_HPP_INCLUDED
#define QUAN_CONVERSION_FLOAT_CONVERT_HPP_INCLUDED

#include <quan/convert.hpp>
#include <climits>
#include <cstdint>

namespace quan{ namespace detail{

	template<> struct converter <float, char*>
   {
      converter():conversion_error{0}{}
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

		static int atoi(char ch)
		{
			return ch - '0';
		}

      static long strlen( const char* str)
      {
         for (long i =0; i < LONG_MAX; ++i){
            if ( str[i] =='\0'){
               return i;
             }
         }
         return -1;
      }
    
      int conversion_error;

  public:

      int get_errno()const {return conversion_error;}
    

		float operator()(const char* str)
		{
          conversion_error=0;
			 int length = strlen(str);
			 if ( length == 0){
				return 0.0f;
			 }
			 int sign = 1;
			 std::size_t pos = 0;
			 float result = 0;
			 auto curtok = get_tok(str[pos]);
			 if (curtok == float_tok::SIGN){
				if (str[pos] =='-'){
					sign = -1;
				}
				curtok = get_tok(str[++pos]);
			 }
			 while (curtok == float_tok::DIGIT){
				  result = result * 10.f + atoi(str[pos]);
				  curtok = get_tok(str[++pos]);
			 }
			
			 if (curtok == float_tok::POINT){
				 curtok = get_tok(str[++pos]);  
				 if ( curtok == float_tok::DIGIT){
					uint64_t divisor = 1;
					uint64_t ifract = 0;
					uint64_t count = 0;
					while ( (curtok == float_tok::DIGIT) && (++count < 20) ){
						ifract = ifract * 10 + atoi(str[pos]);
						curtok = get_tok(str[++pos]);
						divisor *= 10;
					}
					result += static_cast<float>(ifract)/divisor;
				 } else{
					 if ( pos == 1){ // means that point was first and no digits after-- illegal
						  conversion_error= -1;
						  return result;
					 }
				 }
			 }
			 if (curtok == float_tok::EXP){
				int64_t exp_val = 0;
				int powsign = 1;
				int count = 0;
				curtok = get_tok(str[++pos]);  
				if ( curtok == float_tok::SIGN){
					if (str[pos] == '-'){
						 powsign = -1;
					}
					curtok = get_tok(str[++pos]);  
				}
				while (curtok == float_tok::DIGIT){
					if (count == 20){
						conversion_error= -1;
						return result;
					}
					exp_val = exp_val * 10 + atoi(str[pos]);
					curtok = get_tok(str[++pos]);
				}
				float power = 1;
				while (exp_val-- > 0){
					power *= 10;
				}
				if ( powsign == 1){
					result *= power;
				}else{
					result /= power;
				}
			 }
          
			 return( sign == 1)?result : -result;
		}

     };
}}

#endif // QUAN_CONVERSION_FLOAT_CONVERT_HPP_INCLUDED
