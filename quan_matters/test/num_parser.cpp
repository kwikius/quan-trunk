
#if 0
#include <iostream>
#define QUAN_DETAIL_FLOAT_CONVERT_DEBUG
#endif
#include <quan/conversion/parse_number.hpp>
#include <cstdio>

int main()
{
    
   for (;;){
      int64_t int_result;
      double float_result;
      char str [20] ;
      quan::detail::number_parser parser;
      printf("Enter a number:");
      // read likely vals to a string
      int ch = 0;
      int index = 0;

      while (index < 20){
         ch = getchar();
         if (parser.get_tok(ch) != quan::detail::number_parser::num_tok::UNKNOWN) {
            str[index] = ch;
            ++index;
         }else{
            str[index] = '\0';
            ++index;
            break;
         }
      }
      
      switch( parser(str,&float_result, &int_result,index)){
         case quan::detail::number_parser::num_type::INT:{
            printf("got int value %d\n",static_cast<int>(int_result));
            printf("length parsed = %u\n",parser.get_parse_length());
            break;
         }
         case quan::detail::number_parser::num_type::FLOAT:{
            printf("got float value %f\n",float_result);
            printf("length parsed = %u\n",parser.get_parse_length());
            break;
         }
         case quan::detail::number_parser::num_type::UNKNOWN:
         default:{
            printf("parse failed\n");
            break;
         }
      }
   }
}