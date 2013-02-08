#ifndef QUAN_FROM_STRING_HPP_INCLUDED
#define QUAN_FROM_STRING_HPP_INCLUDED

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
