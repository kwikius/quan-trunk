
#include <quan/lexer/buffer.hpp>
#include <string>
#include <iostream>

int main()
{
    quan::lexer::buffer<char> buf(2);

    std::ifstream in("out1.csv");
    std::string str;
    std::streampos pos=0;
    while ( in && ! in.eof()){
      buf.reload(in,pos);
      for( auto val = buf.read_cursor();
            val != buf.eof_value() ;
               val = buf.read_cursor() ){
         buf.inc_cursor();
      }
      std::streamoff num = buf.get_lookahead();
      str.append(buf.begin(),num);
      pos += num;

    }
    std::cout  << "|" << str  << "|\n";
}
