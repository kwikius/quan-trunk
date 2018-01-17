
#include <quan/conversion/int_convert.hpp>
#include <quan/conversion/float_convert.hpp>
#include <iostream>
int main()
{
    typedef uint32_t type;
    for (;;){
      std::cout << "input the type\n";
      std::string str;
      std::getline(std::cin,str);

      quan::detail::converter<type,char*> nconv;

      type result = nconv(str.c_str());
      if (nconv.get_errno() ==0){
         std::cout << result <<'\n';
      }else{
         std::cout << "error in conversion\n";
      }
      int input_string_length = strlen(str.c_str());
      int parse_length = nconv.get_parse_length();
      std::cout << "string length = " << input_string_length  <<'\n';
      std::cout << "parse_length = " << parse_length <<'\n';

      if ( input_string_length > parse_length){
         std::cout << str.c_str() + parse_length <<'\n';;
      }
   }
}


