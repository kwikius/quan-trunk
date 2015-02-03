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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

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
