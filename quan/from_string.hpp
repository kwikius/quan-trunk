#ifndef QUAN_FROM_STRING_HPP_INCLUDED
#define QUAN_FROM_STRING_HPP_INCLUDED
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

#include <string>
#include <sstream>
#include <stdexcept>
#include <locale>

#include <quan/std/string/convert.hpp>
#include <quan/isspace.hpp>

/*
  string is considered to only represent the value.
  whitespace before after  token string is ok, but no other characters
*/

namespace quan{

   template <typename T, typename Char>
   inline
   T from_string( std::basic_string<Char> const & str)
   {    
      std::basic_istringstream<Char> s(str);
      T v;
      s >> v;
      bool failed = s.fail() ||  s.bad();
       
      while (quan::isspace<Char>(s.peek())){
          s.get();
      }
      if (failed || !s.eof() )
      {
         throw std::runtime_error(
         "failed to convert from string \"" 
            + quan::convert<char>(str) 
               + "\"");
      }      
      return v;
   }

}
#endif
