#ifndef QUAN_TO_STRING_HPP_INCLUDED
#define QUAN_TO_STRING_HPP_INCLUDED
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
#include <iostream>

namespace quan{

   
   template <typename Char,typename T>
   inline
   std::basic_string<Char> to_string( T const & v)
   {
      std::basic_ostringstream<Char> ostr;
      ostr << v;
      return ostr.str();
   }

  
  
   
   template<>
   inline
   std::wstring to_string<wchar_t>( std::string const & v)
   {
      typedef std::ctype<wchar_t> cty;
      auto const & ct = std::use_facet<cty>(std::locale());
      std::wstring str;
      auto end = v.end();
      for (auto i = v.begin(); i != end; ++i){
        str += ct.widen(*i);
      }
      return str;
   }

   template<>
   inline
   std::string to_string<char>( std::wstring const & v)
   {
      typedef std::ctype<wchar_t> cty;
      auto const & ct = std::use_facet<cty>(std::locale());
      std::string str;
      auto end = v.end();
      for (auto i = v.begin(); i != end; ++i){
        str += ct.narrow(*i,'?');
      }
      return str;
   }

   // char type for backward compatibility
   template <typename T>
   std::string to_string( T const & v)
   {
      std::basic_ostringstream<char> s;
      s << v;
      return s.str();
   }

}
#endif
